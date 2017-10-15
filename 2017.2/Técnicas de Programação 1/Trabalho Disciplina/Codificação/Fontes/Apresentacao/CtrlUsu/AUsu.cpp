#include "../../../Bibliotecas/Apresentacao/CtrlUsu/AUsu.hpp"

const string AUsu::MSG_INICIO       ("Iniciada a funcionalidade de Usuário.");
const string AUsu::MSG_FINALIZAR    ("Funcionalidade de Usuário finalizada.");
const string AUsu::MSG_LER_APE      ("Aquisição do Apelido com êxito.");
const string AUsu::MSG_LER_NOM      ("Aquisição do Nome com êxito.");
const string AUsu::MSG_LER_SEN      ("Aquisição da Senha com êxito.");
const string AUsu::MSG_LER_TEL      ("Aquisição do Telefone com êxito.");
const string AUsu::MSG_ERRO         ("Usuário existente na Base de Dados.");
const string AUsu::MSG_ERRO_D       ("Erro na entrada de login ou de Base de Dados.");

Resultado AUsu::executar(){
    Log::escrever(MSG_INICIO);

    TUI::executar();

    return avaliarCond();
}

void AUsu::menu(){
    Manipulacao::limparTela();

    cout << "****************************************************" << endl;
    cout << "*                      Usuário                     *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar o cadastramento na aplicação é pre- *" << endl;
    cout << "* ciso fornecer um apelido, um nome, uma senha e   *" << endl;
    cout << "* um telefone; lembrando que:                      *" << endl;
    cout << "*     - Apelido deve ter até 5 letras;             *" << endl;
    cout << "*     - Nome deve ter até 15 símbolos, como:       *" << endl;
    cout << "*          + Letras, espaço ou ponto.              *" << endl;
    cout << "*     - Senha deve ter 4 letras.                   *" << endl;
    cout << "*     - Telefone deve estar na forma:              *" << endl;
    cout << "*          + (xx)-xxxxxxxx.                        *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado AUsu::leitura(){
    char        buffer[Nome::TAM_MAX];
    string      resp;
    Nome        respNome;
    Senha       respSenha;
    Telefone    respTel;

    cout << "Digite um apelido: ";
        cin >> resp; getchar ();
        this->apelido.setCampo(resp);
        Log::escrever(MSG_LER_APE);

    cout << "Digite um nome: ";
        cin.getline(buffer, Nome::TAM_MAX);
        respNome.setCampo(buffer);
        Log::escrever(MSG_LER_NOM);

    cout << "Digite uma senha: ";
        cin >> resp; getchar ();
        respSenha.setCampo(resp);
        Log::escrever(MSG_LER_SEN);

    cout << "Digite um telefone: ";
        cin >> resp; getchar ();
        respTel.setCampo(resp);
        Log::escrever(MSG_LER_TEL);

    if (this->usuario)
        this->usuario->deletar();

    this->usuario = new Usuario (this->apelido, respNome, respSenha, respTel);

    return Resultado (this->usuario);
}

Resultado AUsu::direcionar(const Resultado &entrada){
    Resultado result = servico->cadastrar(*(entrada.getUsuario()));

    if (result.getCampo() != Resultado::SUCESSO)
        this->apelido.clear();
    else
        result.setCampo(Resultado::ESC_SAIR);

    return result;
}

Resultado AUsu::tratarErro(){
    this->apelido.clear();

    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado AUsu::tratarErro(const Resultado &evento){
    if (evento.getCampo() == Resultado::FLH_CAD){
        cout << MSG_ERRO << endl;
        Manipulacao::pausar();
    }

    return Resultado (Resultado::ESC_SAIR);
}

Resultado AUsu::avaliarCond (){
	if(!this->apelido.getCampo().empty()){
		Resultado res (&this->apelido);
		res.setCampo(Resultado::SUCESSO);
		return res;
	}

	return Resultado (Resultado::FALHA);
}

void AUsu::finalizar(){
    if (this->servico)
        delete this->servico;

    if (this->usuario)
        this->usuario->deletar();

    Log::escrever(MSG_FINALIZAR);
}
