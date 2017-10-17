#include "../../../Bibliotecas/Apresentacao/CtrlUsu/AUsu.hpp"

Resultado AUsu::executar(){
    Log::escrever(Mensagem::INI_USR);

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

	Log::escrever (Mensagem::LEITURA);

    cout << Mensagem::LER_APE;
        cin >> resp; getchar ();
        this->apelido.setCampo(resp);
    Log::escrever(Mensagem::AQS_APE);

    cout << Mensagem::LER_NOM;
        cin.getline(buffer, Nome::TAM_MAX);
        respNome.setCampo(buffer);
    Log::escrever(Mensagem::AQS_NOM);

    cout << Mensagem::LER_SEN;
        cin >> resp; getchar ();
        respSenha.setCampo(resp);
    Log::escrever(Mensagem::AQS_SEN);

    cout << Mensagem::LER_TEL;
        cin >> resp; getchar ();
        respTel.setCampo(resp);
    Log::escrever(Mensagem::AQS_TEL);

    if (this->usuario)
        this->usuario->deletar();

    this->usuario = new Usuario (this->apelido, respNome, respSenha, respTel);
	Log::escrever (Mensagem::CRI_USR);

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

    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado AUsu::tratarErro(const Resultado &evento){
    if (evento.getCampo() == Resultado::FLH_CAD){
		Log::escrever (Mensagem::ERR_USU_EXI);
		cout << Mensagem::ERR_USU_EXI << endl;
        Manipulacao::pausar();
    }

    return Resultado (Resultado::ESC_SAIR);
}

Resultado AUsu::avaliarCond (){
	if(!this->apelido.getCampo().empty()){
		Log::escrever(Mensagem::SUC_USR + this->apelido.getCampo());
		Resultado res (&this->apelido);
		res.setCampo(Resultado::SUCESSO);
		return res;
	}

	Log::escrever (Resultado::FALHA);
	return Resultado (Resultado::FALHA);
}

void AUsu::finalizar(){
    if (this->servico)
        delete this->servico;

    if (this->usuario)
        this->usuario->deletar();

    Log::escrever(Mensagem::FIM_USR);
}
