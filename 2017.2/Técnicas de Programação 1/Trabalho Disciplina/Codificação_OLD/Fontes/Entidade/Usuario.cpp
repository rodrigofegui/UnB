#include "../../Bibliotecas/Entidade/Usuario.hpp"

Usuario::Usuario (const Apelido &apelido){
    setApelido (apelido);
}

Usuario::Usuario (const Nome &nome){
    setNome (nome);
}

Usuario::Usuario (const Senha &senha){
    setSenha (senha);
}

Usuario::Usuario (const Telefone &tel){
    setTelefone (tel);
}

Usuario::Usuario(const Apelido &apelido,
                 const Nome &nome,
                 const Senha &senha,
                 const Telefone &tel){
    setApelido (apelido);
    setNome (nome);
    setSenha (senha);
    setTelefone (tel);
}

bool Usuario::equals(const Usuario &alvo){
    if (this->apelido.equals(alvo.getApelido())
        && this->nome.equals(alvo.getNome())
        && this->senha.equals(alvo.getSenha())
        && this->tel.equals(alvo.getTelefone()))
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}
