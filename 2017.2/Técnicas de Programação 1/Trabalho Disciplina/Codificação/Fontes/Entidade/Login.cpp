#include "../../Bibliotecas/Entidade/Login.hpp"

Login::Login(const Apelido &apelido,
             const Senha &senha){
    setApelido(apelido);
    setSenha (senha);
}
