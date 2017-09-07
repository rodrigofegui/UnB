#include "../../Bibliotecas/Dominio/Texto.hpp"

void Texto::validar(const string &campo) throw (invalid_argument, length_error){
    validarTamanho (campo);
}

void Texto::validarTamanho (const string &campo) throw (invalid_argument, length_error){
    if(!Manipulacao::noLimite(campo, TAM_MAX))
        throw length_error (msgErroTam);
}
