#include "../../Bibliotecas/Apresentacao/AAutenticacao.hpp"

void AAutenticacao::menu(){
    Manipulacao::limparTela();

    cout << "********************************" << endl;
    cout << "      Bem-vindo ao Login"         << endl << endl;
    cout << "  Para tanto, pede-se o seu"      << endl;
    cout << " apelido e sua senha."            << endl << endl;
    cout << "  Lembre-se:"                     << endl;
    cout << "     - Apelido até 5 letras;"     << endl;
    cout << "     - Senha com 4 letras."       << endl;
    cout << "********************************" << endl << endl;
}

void AAutenticacao::criar(){
    this->login = new Login ();
}

OpResult AAutenticacao::configurar() throw (invalid_argument){
    string leitura;

    cout << "Digite seu apelido:" << endl;
        cin >> leitura;
        this->apelido.setCampo(leitura);

    cout << "Digite sua senha:" << endl;
        cin >> leitura;
        this->senha.setCampo(leitura);

    this->login->setApelido(this->apelido);
    this->login->setSenha(this->senha);

    return OpResult(OpResult::SUCESSO);
}
/*
void servico (const OpResult &controle){
}
*/

void AAutenticacao::erroOp(string opCode){
}
