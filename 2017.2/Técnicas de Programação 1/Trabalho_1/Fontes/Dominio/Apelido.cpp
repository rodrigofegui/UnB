#include "../../Bibliotecas/Dominio/Apelido.hpp"

Apelido::Apelido(const string &campo){
    setCampo(campo);
}

void Apelido::validar (const string &campo) throw (invalid_argument, length_error){
    if (!Manipulacao::noLimite(campo, Apelido::LIM_MAX))
        throw new length_error (msgErroTam);

    if(!Manipulacao::eAlfabetico(campo))
        throw new invalid_argument (msgErroArg);
}
