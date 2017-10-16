#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdProcurar.hpp"

const string ACmdProcurar::MSG_INICIO       ("Iniciada o comando de procurar por troca de Livro.");
const string ACmdProcurar::MSG_FINALIZAR    ("Comando de procurar por troca de Livro finalizado.");
const string ACmdProcurar::MSG_LER_TIT      ("Aquisição do Título com êxito.");
const string ACmdProcurar::MSG_ERRO_D       ("Erro na entrada de login ou na Base de Dados.");

ACmdProcurar::ACmdProcurar(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdProcurar::executar(){
    Log::escrever(MSG_INICIO);

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

    cout << "Digite o título: ";
        cin.getline(buffer, Titulo::TAM_MAX);
    Log::escrever(MSG_LER_TIT);

    transf = buffer;

    Titulo *novo = new Titulo ();
    novo->setCampo(transf);

    return Resultado (novo);
}

Resultado ACmdProcurar::direcionar(const Resultado &escolha){
    Resultado result = this->servico->procurar(*(escolha.getTitulo()));

    if (result.getCampo() == Resultado::SUCESSO){
        cout << endl << "Usuário(s) disponível(is): " << endl;
        cout << "Apelido: " + result.getUsuario()->getApelido().getCampo() << endl;
    }

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdProcurar::tratarErro (){
    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdProcurar::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdProcurar::finalizar(){
    Log::escrever(MSG_FINALIZAR);
}
