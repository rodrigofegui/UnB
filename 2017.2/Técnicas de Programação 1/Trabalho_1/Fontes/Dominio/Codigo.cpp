#include "../../Bibliotecas/Dominio/Codigo.hpp"

void Codigo::setCampo (string campo) throw (invalid_argument, length_error){
    validar(campo);
    this->campo = campo;
}

void Codigo::validar (string campo) throw (invalid_argument, length_error){
    if (!Manipulacao::tam(campo, Codigo::TAM))
        throw length_error (Codigo::msgErroTam);

    if (!Manipulacao::eNum(campo))
        throw invalid_argument (Codigo::msgErroArg);
}
