#include "../../../Bibliotecas/Apresentacao/Aplicacao/Aplicacao.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlAut/AAut.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlUsu/AUsu.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/AEst.hpp"

void Aplicacao::menu (){
    Manipulacao::limparTela();

    Log::escrever(Mensagem::INI_APP);

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

    Log::escrever(Mensagem::LEITURA);
    cout << Mensagem::LER_ESC;
    	cin >> resp; getchar ();

	switch (resp) {
		case AUTENTICAR:
			return Resultado(Resultado::ESC_AUTENTICAR);;
		case CADASTRAR:
			return Resultado(Resultado::ESC_CADASTRAR);
		case SAIR:
			return Resultado(Resultado::ESC_SAIR);
		default:
		    Log::escrever(Mensagem::FLH_ESC);
			cout << Mensagem::FLH_ESC << endl;
		    return Resultado(Resultado::FALHA);
	}
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

    escolha.clear();

	return Resultado(Resultado::FALHA);
}

Resultado Aplicacao::autenticar(){
    Log::escrever(Mensagem::RED_AUT);

	this->func = new AAut ();
	// FALTA O SERVICO
	return this->func->executar();
}

Resultado Aplicacao::usuario(){
    Log::escrever(Mensagem::RED_USU);

	this->func = new AUsu ();
	// FALTA O SERVICO
	return this->func->executar();
}

Resultado Aplicacao::estante(const Resultado &apelido){
    Log::escrever(Mensagem::RED_EST);

	this->func = new AEst ();
	// FALTA O SERVICO
	return this->func->executar(apelido);
}

Resultado Aplicacao::tratarErro (){ return Resultado(Resultado::FALHA);}

Resultado Aplicacao::tratarErro (const Resultado &evento){
    if (evento.getCampo() == Resultado::FLH_LIM){
		Log::escrever (Mensagem::FLH_LIM);
        cout << Mensagem::FLH_LIM << endl;
        evento.clear();
        return Resultado(Resultado::ESC_SAIR);
    }

    if (evento.getCampo() == Resultado::ESC_SAIR)
        evento.clear();
        return evento;

    evento.clear();
    return Resultado (Resultado::FALHA);
}

void Aplicacao::finalizar(){
    delete this;

    Log::escrever(Mensagem::FIM_APP);
}
