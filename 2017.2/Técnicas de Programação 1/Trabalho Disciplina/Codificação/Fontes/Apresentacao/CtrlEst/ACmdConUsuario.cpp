#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdConUsuario.hpp"

ACmdConUsuario::ACmdConUsuario(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdConUsuario::executar(){
    Log::escrever(Mensagem::INI_EST_CON_USR);

    TUI::executar();

    return Resultado (Resultado::SUCESSO);
}

void ACmdConUsuario::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*               Consulta de Usuário                *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar a consulta de um usuário é preciso  *" << endl;
    cout << "* fornecer algum apelido; lembrando que:           *" << endl;
    cout << "*     - Apelido deve ter até 5 letras.             *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado ACmdConUsuario::leitura(){
    string transf;

	Log::escrever(Mensagem::LEITURA);

    cout << Mensagem::LER_APE;
        cin >> transf; getchar ();
    		Apelido *novo = new Apelido ();
    		novo->setCampo(transf);
	Log::escrever(Mensagem::AQS_APE);

    return Resultado (novo);
}

Resultado ACmdConUsuario::direcionar(const Resultado &escolha){
    Resultado result = this->servico->consultar(*(escolha.getApelido()));

    if (result.getCampo() == Resultado::FLH_CON){
		Log::escrever(Mensagem::FLH_USR);
        cout << Mensagem::FLH_USR << endl;
    }else{
        cout << endl << Mensagem::SUC_EST_CON_USR << endl;
        cout << Mensagem::LBL_NOM + result.getUsuario()->getNome().getCampo() << endl;
        cout << Mensagem::LBL_APE + result.getUsuario()->getApelido().getCampo() << endl;
        cout << Mensagem::LBL_TEL + result.getUsuario()->getTelefone().getCampo() << endl << endl;

		Log::escrever (Mensagem::SUC_EST_CON_USR);
		Log::escrever (Mensagem::LBL_NOM + result.getUsuario()->getNome().getCampo());
		Log::escrever (Mensagem::LBL_APE + result.getUsuario()->getApelido().getCampo());
		Log::escrever (Mensagem::LBL_TEL + result.getUsuario()->getTelefone().getCampo());
    }

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdConUsuario::tratarErro (){
    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdConUsuario::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdConUsuario::finalizar(){
    Log::escrever(Mensagem::FIM_EST_CON_USR);
}
