#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdCriarResenha.hpp"

ACmdCriarResenha::ACmdCriarResenha(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdCriarResenha::executar(){
    Log::escrever(Mensagem::INI_EST_CRS);

    TUI::executar();

    return Resultado (Resultado::SUCESSO);
}

void ACmdCriarResenha::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*              Criação de Resenha                  *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar a criação de uma resenha é preciso  *" << endl;
    cout << "* fornecer o título do livro e a resenha;          *" << endl;
    cout << "* lembrando que:                                   *" << endl;
    cout << "*     - Título deve ter até 20 letras;             *" << endl;
    cout << "*     - Resenha é composta por:                    *" << endl;
    cout << "*          + Título, até 20 letras;                *" << endl;
    cout << "*          + Texto, até 40 caracteres.             *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado ACmdCriarResenha::leitura(){
    char buffer[Titulo::TAM_MAX], buffer2[Texto::TAM_MAX];
    string transf;

	Log::escrever (Mensagem::LEITURA);

    cout << Mensagem::LER_TIT_LVR;
        cin.getline(buffer, Titulo::TAM_MAX);
        transf = buffer;
	        Titulo *livro = new Titulo ();
	        livro->setCampo(transf);
	Log::escrever(Mensagem::AQS_TIT);

    cout << Mensagem::LER_TIT_RES;
        cin.getline(buffer, Titulo::TAM_MAX);
        transf = buffer;
	        Titulo resenha;
	        resenha.setCampo(transf);
	Log::escrever(Mensagem::AQS_TIT);

     cout << Mensagem::LER_TXT;
        cin.getline(buffer2, Texto::TAM_MAX);
        transf = buffer2;
		    Texto resenhaB;
		    resenhaB.setCampo(transf);
	Log::escrever(Mensagem::AQS_TXT);

        Resenha *nova = new Resenha ();
        nova->setTitulo (resenha);
        nova->setTexto (resenhaB);
	Log::escrever(Mensagem::CRI_RES);

    return Resultado (livro, nova);
}

Resultado ACmdCriarResenha::direcionar(const Resultado &escolha){
    this->servico->criarResenha(*(escolha.getTitulo()), *(escolha.getResenha()));

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdCriarResenha::tratarErro (){
    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdCriarResenha::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdCriarResenha::finalizar(){
    Log::escrever(Mensagem::FIM_EST_CRS);
}
