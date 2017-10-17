#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdConLivro.hpp"

ACmdConLivro::ACmdConLivro(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdConLivro::executar(){
    Log::escrever(Mensagem::INI_EST_CON_LVR);

    TUI::executar();

    return Resultado (Resultado::SUCESSO);
}

void ACmdConLivro::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*               Consulta de Livro                  *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar a consulta de um livro é preciso    *" << endl;
    cout << "* fornecer algum título ; lembrando que:           *" << endl;
    cout << "*     - Título deve ter até 20 letras.             *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado ACmdConLivro::leitura(){
    char buffer[Titulo::TAM_MAX];
    string transf;

	Log::escrever (Mensagem::LEITURA);

    cout << Mensagem::LER_TIT;
        cin.getline(buffer, Titulo::TAM_MAX);
    	transf = buffer;
		    Titulo *novo = new Titulo ();
		    novo->setCampo(transf);
	Log::escrever(Mensagem::AQS_TIT);

    return Resultado (novo);
}

Resultado ACmdConLivro::direcionar(const Resultado &escolha){
    Resultado result = this->servico->consultar(*(escolha.getTitulo()));

    if (result.getCampo() == Resultado::FLH_CON){
		Log::escrever (Mensagem::FLH_LVR);
		cout << Mensagem::FLH_LVR << endl;

    }else{
        cout << endl << Mensagem::SUC_EST_CON_LVR << endl;
        cout << Mensagem::LBL_TIT + result.getLivro()->getTitulo().getCampo() << endl;
        cout << Mensagem::LBL_ATR + result.getLivro()->getAutor().getCampo() << endl;
        cout << Mensagem::LBL_DAT + result.getLivro()->getDataPublicacao().getCampo() << endl;
        cout << Mensagem::LBL_GEN + result.getLivro()->getGenero().getCampo() << endl << endl;

		Log::escrever(Mensagem::SUC_EST_CON_LVR);
		Log::escrever(Mensagem::LBL_TIT + result.getLivro()->getTitulo().getCampo());
		Log::escrever(Mensagem::LBL_ATR + result.getLivro()->getAutor().getCampo());
		Log::escrever(Mensagem::LBL_DAT + result.getLivro()->getDataPublicacao().getCampo());
		Log::escrever(Mensagem::LBL_GEN + result.getLivro()->getGenero().getCampo());

        if (result.getResenha()){
            cout << Mensagem::SUC_EST_CON_LVR_RES << endl;
            cout << "[" + result.getResenha()->getTitulo().getCampo() + "] ";
            cout << result.getResenha()->getTexto().getCampo() << endl;

			Log::escrever(Mensagem::SUC_EST_CON_LVR_RES);
			Log::escrever("[" + result.getResenha()->getTitulo().getCampo() + "] "
							+ result.getResenha()->getTexto().getCampo());
        }
    }

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdConLivro::tratarErro (){
    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdConLivro::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdConLivro::finalizar(){
    Log::escrever(Mensagem::FIM_EST_CON_LVR);
}
