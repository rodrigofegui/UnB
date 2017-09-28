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
