#include "../../../Bibliotecas/Apresentacao/CtrlAut/AAut.hpp"

const string AAut::MSG_INICIO       ("Iniciada a funcionalidade de Autenticação.");
const string AAut::MSG_FINALIZAR    ("Funcionalida de Autenticação finalizada.");
const string AAut::MSG_LER_APE      ("Aquisição do Apelido com êxito.");
const string AAut::MSG_LER_SEN      ("Aquisição da Senha com êxito.");
const string AAut::MSG_ERRO         ("Erro na entrada de login ou de Base de Dados.");

Resultado AAut::executar (){
    Log::escrever(MSG_INICIO);

    TUI::executar();
}

void AAut::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*                   Autenticação                   *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar o login na aplicação é preciso for- *" << endl;
    cout << "* necer o apelido e a senha; lembrando que:        *" << endl;
    cout << "*     - Apelido deve ter até 5 letras;             *" << endl;
    cout << "*     - Senha deve ter 4 letras.                   *" << endl;
    cout << "****************************************************" << endl << endl;

    Manipulacao::pausar();
}

Resultado AAut::leitura(){
    string resp;
    Apelido respApelido;
    Senha respSenha;

    cout << "Digite o apelido: ";
        cin >> resp;
    respApelido.setCampo(resp);
    Log::escrever(MSG_LER_APE);

    cout << "Digite a senha: ";
        cin >> resp;
    respSenha.setCampo(resp);
    Log::escrever(MSG_LER_SEN);

    this->login = new Login (respApelido, respSenha);

    return Resultado (this->login);
}

Resultado AAut::direcionar(const Resultado &entrada){
    Resultado result = servico->autenticar(*(entrada.getLogin()));
}

Resultado AAut::tratarErro (){
    Log::escrever(MSG_ERRO);
    cout << MSG_ERRO << endl;
    Manipulacao::pausar();
    return Resultado(Resultado::ESC_SAIR);

}

Resultado AAut::tratarErro (const Resultado &evento){
    if (evento.getCampo() == Resultado::FLH_LIM)
        cout << "Foi atingido o limite de tentativas" << endl;

    return Resultado(Resultado::ESC_SAIR);
}

void AAut::finalizar(){
    delete this->servico;

    Log::escrever(MSG_FINALIZAR);
}
