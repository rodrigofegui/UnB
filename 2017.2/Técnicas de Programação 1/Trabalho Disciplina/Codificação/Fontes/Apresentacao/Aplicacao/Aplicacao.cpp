#include "../../../Bibliotecas/Apresentacao/Aplicacao/Aplicacao.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlAut/AAut.hpp"

const string Aplicacao::MSG_FINALIZAR   ("Aplicação finalizada.");
const string Aplicacao::MSG_AGD_LEITURA ("Leitura das opções do usuário na Tela inicial da aplicação.");
const string Aplicacao::MSG_ESC_INV     ("Leitura de um valor fora do intervalo.");
const string Aplicacao::MSG_ESC_AUT     ("Redirecionando a aplicação para a Autenticação.");
const string Aplicacao::MSG_ESC_USU     ("Redirecionando a aplicação para o Usuário.");
const string Aplicacao::MSG_ESC_EST     ("Redirecionando a aplicação para a Estante.");


void Aplicacao::menu (){
    Manipulacao::limparTela();

    cout << "****************************************************" << endl;
    cout << "*                     Bem-Vindo                    *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* São lhe oferecidas as opções:                    *" << endl;
    printf ("*    %d - Login: Caso já tenha cadastro;            *\n", Aplicacao::AUTENTICAR);
    printf ("*    %d - Cadastro: Caso seja a primeira vez na     *\n", Aplicacao::CADASTRAR);
    cout << "* plataforma;                                      *" << endl;
    printf ("*    %d - Sair.                                     *\n", Aplicacao::SAIR);
    cout << "****************************************************" << endl << endl;
}

Resultado Aplicacao::leitura(){
    int resp = 0;

    Log::escrever(MSG_AGD_LEITURA);
    cout << "Digite a sua escolha: ";

    cin >> resp;
        getchar ();

    if (resp == Aplicacao::AUTENTICAR)
        return Resultado(Resultado::ESC_AUTENTICAR);

    if (resp == Aplicacao::CADASTRAR)
        return Resultado(Resultado::ESC_CADASTRAR);

    if (resp == Aplicacao::SAIR)
        return Resultado(Resultado::ESC_SAIR);

    cout << "Fora do intervalo desejável!" << endl << endl;
    Log::escrever(MSG_ESC_INV);
    return Resultado(Resultado::FALHA);
}

Resultado Aplicacao::direcionar (const Resultado &escolha){
	if (escolha.getCampo() == Resultado::ESC_SAIR)
		return escolha;

	Resultado preliminar;

    if (escolha.getCampo() == Resultado::ESC_AUTENTICAR)
        preliminar = autenticar();

    else if (escolha.getCampo() == Resultado::ESC_CADASTRAR)
        preliminar = usuario();

	if (preliminar.getCampo() == Resultado::SUCESSO)
		return estante (preliminar);

	return Resultado(Resultado::FALHA);
}

Resultado Aplicacao::autenticar(){
    Log::escrever(MSG_ESC_AUT);
    cout << "Autenticar..." << endl;
    Manipulacao::pausar();

	this->func = new AAut ();
	return this->func->executar();
}

Resultado Aplicacao::usuario(){
    Log::escrever(MSG_ESC_USU);
    cout << "Usuário..." << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}

Resultado Aplicacao::estante(const Resultado &apelido){
    Log::escrever(MSG_ESC_EST);
    cout << "Estante..." << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}

void Aplicacao::finalizar(){
    Log::escrever(MSG_FINALIZAR);
}

Resultado Aplicacao::tratarErro (){ return Resultado(Resultado::FALHA);}

Resultado Aplicacao::tratarErro (const Resultado &evento){
    if (evento.getCampo() == Resultado::FLH_LIM){
        cout << "Foi atingido o limite de tentativas" << endl;
        return Resultado(Resultado::ESC_SAIR);
    }

    if (evento.getCampo() == Resultado::ESC_SAIR)
        return evento;

    return Resultado (Resultado::FALHA);
}
