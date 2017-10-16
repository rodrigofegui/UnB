#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdConLivro.hpp"

const string ACmdConLivro::MSG_INICIO       ("Iniciada o comando de consultar Livro.");
const string ACmdConLivro::MSG_FINALIZAR    ("Comando de consultar Livro finalizado.");
const string ACmdConLivro::MSG_LER_TIT      ("Aquisição do Título com êxito.");
const string ACmdConLivro::MSG_ERRO_D       ("Erro na entrada de login ou na Base de Dados.");

ACmdConLivro::ACmdConLivro(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdConLivro::executar(){
    Log::escrever(MSG_INICIO);

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

    cout << "Digite o título: ";
        cin.getline(buffer, Titulo::TAM_MAX);
    Log::escrever(MSG_LER_TIT);

    transf = buffer;

    Titulo *novo = new Titulo ();
    novo->setCampo(transf);

    return Resultado (novo);
}

Resultado ACmdConLivro::direcionar(const Resultado &escolha){
    Resultado result = this->servico->consultar(*(escolha.getTitulo()));

    if (result.getCampo() == Resultado::FLH_CON)
        cout << "Livro não encontrado." << endl;
    else{
        cout << endl << "Livro encontrado: " << endl;
        cout << "Título: " + result.getLivro()->getTitulo().getCampo() << endl;
        cout << "Autor: " + result.getLivro()->getAutor().getCampo() << endl;
        cout << "Data: " + result.getLivro()->getDataPublicacao().getCampo() << endl;
        cout << "Genero: " + result.getLivro()->getGenero().getCampo() << endl << endl;

        if (result.getResenha()){
            cout << "Resenha(s) associada(s):" << endl;
            cout << "[" + result.getResenha()->getTitulo().getCampo() + "] ";
            cout << result.getResenha()->getTexto().getCampo() << endl;
        }
    }

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdConLivro::tratarErro (){
    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdConLivro::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdConLivro::finalizar(){
    Log::escrever(MSG_FINALIZAR);
}
