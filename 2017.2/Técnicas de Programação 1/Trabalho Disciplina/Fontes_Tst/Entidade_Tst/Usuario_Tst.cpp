#include "../../Bibliotecas_Tst/Entidade_Tst/Usuario_Tst.hpp"

void UsuarioTst::inicializar (){
    cout << "Testando Entidade/Usuário:" << endl;

    this->usuario = new Usuario ();
    this->status = TesteUnitario::PASSOU;

    nome.setCampo("Rodrigo F. G.");
    apelido.setCampo("rodfg");
    telefone.setCampo("(61)-123456789");
    senha.setCampo("abcd");
}

void UsuarioTst::finalizar (){
    if(this->status)
        cout << "APROVADO!" << endl << endl;
    else cout << "REPROVADO!" << endl << endl;

    delete this->usuario;
    delete this;
}

void UsuarioTst::validar(){
    validarNome();

    validarApelido();

    validarTelefone();

    validarSenha();
}

void UsuarioTst::validarNome(){
    this->usuario->setNome(this->nome);

    if(!this->nome.equals(this->usuario->getNome()))
        this->status = TesteUnitario::FALHOU;
}

void UsuarioTst::validarApelido(){
    this->usuario->setApelido(this->apelido);

    if(!this->apelido.equals(this->usuario->getApelido()))
        this->status = TesteUnitario::FALHOU;
}

void UsuarioTst::validarTelefone(){
    this->usuario->setTelefone(this->telefone);

    if(!this->telefone.equals(this->usuario->getTelefone()))
        this->status = TesteUnitario::FALHOU;
}

void UsuarioTst::validarSenha(){
    this->usuario->setSenha(this->senha);

    if(!this->senha.equals(this->usuario->getSenha()))
        this->status = TesteUnitario::FALHOU;
}
