#include "../../Bibliotecas_Tst/Entidade_Tst/Login_Tst.hpp"

void LoginTst::inicializar(){
    cout << "Testando Entidade/Login:" << endl;

    this->login = new Login ();
    this->status = TesteUnitario::PASSOU;

    apelido.setCampo("abcde");
    senha.setCampo("abcd");
}

void LoginTst::finalizar(){
    if(this->status)
        cout << "APROVADO!" << endl << endl;
    else cout << "REPROVADO!" << endl << endl;

    this->login->deletar();
    delete this;
}

void LoginTst::validar(){
    validarApelido();
    validarSenha();
}

void LoginTst::validarApelido(){
    this->login->setApelido(this->apelido);

    if(!this->apelido.equals(this->login->getApelido()))
        this->status = TesteUnitario::FALHOU;
}

void LoginTst::validarSenha(){
    this->login->setSenha(this->senha);

    if(!this->senha.equals(this->login->getSenha()))
        this->status = TesteUnitario::FALHOU;
}
