#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdConUsuario.hpp"

const string ACmdConUsuario::MSG_INICIO       ("Iniciada o comando de consultar Usuario.");
const string ACmdConUsuario::MSG_FINALIZAR    ("Comando de consultar Usuário finalizado.");
const string ACmdConUsuario::MSG_LER_APE      ("Aquisição do Apelido com êxito.");
const string ACmdConUsuario::MSG_ERRO_D       ("Erro na entrada de login ou na Base de Dados.");

ACmdConUsuario::ACmdConUsuario(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdConUsuario::executar(){
    Log::escrever(MSG_INICIO);

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

    cout << "Digite o apelido: ";
        cin >> transf; getchar ();
    Log::escrever(MSG_LER_APE);

    Apelido *novo = new Apelido ();
    novo->setCampo(transf);

    return Resultado (novo);
}

Resultado ACmdConUsuario::direcionar(const Resultado &escolha){
    Resultado result = this->servico->consultar(*(escolha.getApelido()));

    if (result.getCampo() == Resultado::FLH_CON)
        cout << "Usuario não encontrado." << endl;
    else{
        cout << endl << "Usurio encontrado: " << endl;
        cout << "Nome: " + result.getUsuario()->getNome().getCampo() << endl;
        cout << "Apelido: " + result.getUsuario()->getApelido().getCampo() << endl;
        cout << "Telefone: " + result.getUsuario()->getTelefone().getCampo() << endl << endl;
    }

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdConUsuario::tratarErro (){
    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdConUsuario::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdConUsuario::finalizar(){
    Log::escrever(MSG_FINALIZAR);
}
