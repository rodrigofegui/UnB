#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdSinTroca.hpp"

ACmdSinTroca::ACmdSinTroca(InterSEst *servico){
    this->servico = servico;
}

ACmdSinTroca::ACmdSinTroca(InterSEst *servico, Apelido *apelido){
    this->servico = servico;
    this->apelido = apelido;
}

Resultado ACmdSinTroca::executar(){
    Log::escrever(Mensagem::INI_EST_STR);

    TUI::executar();

    return Resultado (Resultado::SUCESSO);
}

void ACmdSinTroca::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*            Sinalizar Troca de Livro              *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar a sinalização da disponibilidade ou *" << endl;
    cout << "* não para troca de um livro é preciso fornecer    *" << endl;
    cout << "* algum título; lembrando que:                     *" << endl;
    cout << "*     - Título deve ter até 20 letras.             *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado ACmdSinTroca::leitura(){
    char buffer[Titulo::TAM_MAX];
    string transf;

	Log::escrever (Mensagem::LEITURA);

    cout << Mensagem::LER_TIT;
        cin.getline(buffer, Titulo::TAM_MAX);
    		transf = buffer;
	    Titulo *novo = new Titulo ();
	    novo->setCampo(transf);
	Log::escrever(Mensagem::AQS_TIT);

    cout << Mensagem::LER_DSP;
        cin >> transf; getchar ();
    Log::escrever(Mensagem::AQS_DSP);

    if (transf == "S")
        return Resultado (novo, true);
    else
        return Resultado (novo, false);
}

Resultado ACmdSinTroca::direcionar(const Resultado &escolha){
    Resultado result = this->servico->sinTroca(*(this->apelido), *(escolha.getTitulo()), escolha.getDisponibilidade());

    if (escolha.getDisponibilidade()){
        cout << Mensagem::SUC_EST_CON_TRC << endl;
        cout << Mensagem::LBL_APE + result.getUsuario()->getApelido().getCampo() << endl;

		Log::escrever(Mensagem::SUC_EST_CON_TRC);
		Log::escrever(Mensagem::LBL_APE + result.getUsuario()->getApelido().getCampo());
    }

    Manipulacao::pausar();

    escolha.clear();
    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdSinTroca::tratarErro (){
    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdSinTroca::tratarErro (const Resultado &evento){

    evento.clear();
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdSinTroca::finalizar(){
    delete this;

    Log::escrever(Mensagem::FIM_EST_STR);
}
