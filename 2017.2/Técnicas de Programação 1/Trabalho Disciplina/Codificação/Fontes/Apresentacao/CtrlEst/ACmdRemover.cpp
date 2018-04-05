#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdRemover.hpp"

ACmdRemover::ACmdRemover(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdRemover::executar(){
    Log::escrever(Mensagem::INI_EST_RMV_LVR);

    TUI::executar();

    return Resultado (Resultado::SUCESSO);
}

void ACmdRemover::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*                Remoção de Livro                  *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar a remoção de um livro é preciso     *" << endl;
    cout << "* fornecer algum título; lembrando que:            *" << endl;
    cout << "*     - Título deve ter até 20 letras.             *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado ACmdRemover::leitura(){
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

Resultado ACmdRemover::direcionar(const Resultado &escolha){
    this->servico->remover(*(escolha.getTitulo()));

    Manipulacao::pausar();

    escolha.clear();
    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdRemover::tratarErro (){
    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdRemover::tratarErro (const Resultado &evento){
    evento.clear();
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdRemover::finalizar(){
    delete this;
    Log::escrever(Mensagem::FIM_EST_RMV_LVR);
}
