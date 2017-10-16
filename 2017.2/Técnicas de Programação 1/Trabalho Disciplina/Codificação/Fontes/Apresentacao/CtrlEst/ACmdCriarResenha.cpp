#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdCriarResenha.hpp"

const string ACmdCriarResenha::MSG_INICIO       ("Iniciada o comando de consultar Livro.");
const string ACmdCriarResenha::MSG_FINALIZAR    ("Comando de consultar Livro finalizado.");
const string ACmdCriarResenha::MSG_LER_TXT      ("Aquisição do Texto com êxito.");
const string ACmdCriarResenha::MSG_LER_TIT      ("Aquisição do Título com êxito.");
const string ACmdCriarResenha::MSG_ERRO_D       ("Erro na entrada de login ou na Base de Dados.");

ACmdCriarResenha::ACmdCriarResenha(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdCriarResenha::executar(){
    Log::escrever(MSG_INICIO);

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

    cout << "Digite o título do livro: ";
        cin.getline(buffer, Titulo::TAM_MAX);
        Log::escrever(MSG_LER_TIT);

        transf = buffer;

        Titulo *livro = new Titulo ();
        livro->setCampo(transf);

    cout << "Digite o título da resenha: ";
        cin.getline(buffer, Titulo::TAM_MAX);
        Log::escrever(MSG_LER_TIT);

        transf = buffer;

        Titulo resenha;
        resenha.setCampo(transf);

     cout << "Digite o corpo da resenha: ";
        cin.getline(buffer2, Texto::TAM_MAX);
        Log::escrever(MSG_LER_TXT);

        transf = buffer2;

        Texto resenhaB;
        resenhaB.setCampo(transf);

        Resenha *nova = new Resenha ();
        nova->setTitulo (resenha);
        nova->setTexto (resenhaB);
    return Resultado (livro, nova);
}

Resultado ACmdCriarResenha::direcionar(const Resultado &escolha){
    this->servico->criarResenha(*(escolha.getTitulo()), *(escolha.getResenha()));

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdCriarResenha::tratarErro (){
    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdCriarResenha::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdCriarResenha::finalizar(){
    Log::escrever(MSG_FINALIZAR);
}
