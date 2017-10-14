#include "../../../Bibliotecas/Apresentacao/CtrlAut/AAut.hpp"

const string AAut::MSG_INICIO       ("Iniciada a funcionalidade de Autenticação.");
const string AAut::MSG_FINALIZAR    ("Funcionalidade de Autenticação finalizada.");
const string AAut::MSG_LER_APE      ("Aquisição do Apelido com êxito.");
const string AAut::MSG_LER_SEN      ("Aquisição da Senha com êxito.");
const string AAut::MSG_ERRO         ("Usuário inexistente na Base de Dados.");
const string AAut::MSG_ERRO_D       ("Erro na entrada de login ou de Base de Dados.");

Resultado AAut::executar (){
    Log::escrever(MSG_INICIO);

    TUI::executar();

    if(!this->apelido.getCampo().empty()){
        Resultado res (&this->apelido);
        res.setCampo(Resultado::SUCESSO);
        return res;
    }

    return Resultado (Resultado::FALHA);
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
}

Resultado AAut::leitura(){
    string resp;
    Senha respSenha;

    cout << "Digite o apelido: ";
        cin >> resp;
        getchar();
    this->apelido.setCampo(resp);
    Log::escrever(MSG_LER_APE);

    cout << "Digite a senha: ";
        cin >> resp;
        getchar();
    respSenha.setCampo(resp);
    Log::escrever(MSG_LER_SEN);

    if (!this->login)
        this->login = new Login (this->apelido, respSenha);
    else{
        this->login->setApelido(this->apelido);
        this->login->setSenha(respSenha);
    }

    return Resultado (this->login);
}

Resultado AAut::direcionar(const Resultado &entrada){
    Resultado result = servico->autenticar(*(entrada.getLogin()));

    if(result.getCampo() != Resultado::SUCESSO)
        this->apelido.setCampo("");
    else
        result.setCampo(Resultado::ESC_SAIR);

    return result;
}

Resultado AAut::tratarErro (){
    this->apelido.setCampo("");

    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);

}

Resultado AAut::tratarErro (const Resultado &evento){
    if (evento.getCampo() == Resultado::FLH_AUT){
        cout << MSG_ERRO << endl;
        Manipulacao::pausar();
    }

    return Resultado(Resultado::ESC_SAIR);
}

void AAut::finalizar(){
    if (this->servico)
        delete this->servico;

    if (this->login)
        this->login->deletar();

    Log::escrever(MSG_FINALIZAR);
}
