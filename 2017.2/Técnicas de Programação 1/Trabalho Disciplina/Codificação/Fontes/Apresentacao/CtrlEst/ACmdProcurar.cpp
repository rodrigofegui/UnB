#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdProcurar.hpp"

ACmdProcurar::ACmdProcurar(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdProcurar::executar(){
    Log::escrever(Mensagem::INI_EST_CON_TRC);

    TUI::executar();

    return Resultado (Resultado::SUCESSO);
}

void ACmdProcurar::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*            Procura por Troca de Livro            *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar a procura por troca de um livro é   *" << endl;
    cout << "* preciso fornecer algum título; lembrando que:    *" << endl;
    cout << "*     - Título deve ter até 20 letras.             *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado ACmdProcurar::leitura(){
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

Resultado ACmdProcurar::direcionar(const Resultado &escolha){
    Resultado result = this->servico->procurar(*(escolha.getTitulo()));

    if (result.getCampo() == Resultado::SUCESSO){
        cout << endl << Mensagem::SUC_EST_CON_TRC << endl;
        cout << Mensagem::LBL_APE + result.getUsuario()->getApelido().getCampo() << endl;

		Log::escrever (Mensagem::SUC_EST_CON_TRC);
		Log::escrever (Mensagem::LBL_APE + result.getUsuario()->getApelido().getCampo());
    }

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdProcurar::tratarErro (){
    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdProcurar::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdProcurar::finalizar(){
    Log::escrever(Mensagem::FIM_EST_CON_TRC);
}
