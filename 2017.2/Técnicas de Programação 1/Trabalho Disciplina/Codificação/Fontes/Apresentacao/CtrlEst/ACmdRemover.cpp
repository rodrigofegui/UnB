#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdRemover.hpp"

const string ACmdRemover::MSG_INICIO       ("Iniciada o comando de remoção de Livro.");
const string ACmdRemover::MSG_FINALIZAR    ("Comando de remoção de Livro finalizado.");
const string ACmdRemover::MSG_LER_TIT      ("Aquisição do Título com êxito.");
const string ACmdRemover::MSG_ERRO_D       ("Erro na entrada de login ou na Base de Dados.");

ACmdRemover::ACmdRemover(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdRemover::executar(){
    Log::escrever(MSG_INICIO);

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

    cout << "Digite o título: ";
        cin.getline(buffer, Titulo::TAM_MAX);
    Log::escrever(MSG_LER_TIT);

    transf = buffer;

    Titulo *novo = new Titulo ();
    novo->setCampo(transf);

    return Resultado (novo);
}

Resultado ACmdRemover::direcionar(const Resultado &escolha){
    this->servico->remover(*(escolha.getTitulo()));

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdRemover::tratarErro (){
    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdRemover::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdRemover::finalizar(){
    Log::escrever(MSG_FINALIZAR);
}
