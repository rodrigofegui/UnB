#include "../../Bibliotecas/Entidade/Login.hpp"

Login::Login(const Apelido &apelido,
             const Senha &senha){
    setApelido(apelido);
    setSenha (senha);
}

bool Login::equals(const Login &alvo) const{
    if (this->apelido.equals(alvo.getApelido())
        && this->senha.equals(alvo.getSenha()))
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}
