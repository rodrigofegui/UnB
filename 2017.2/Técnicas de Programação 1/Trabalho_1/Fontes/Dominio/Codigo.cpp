#include "../../Bibliotecas/Dominio/Codigo.hpp"

Codigo::Codigo(){}

Codigo::Codigo(string campo){
    setCampo(campo);
}

void Codigo::setCampo (string campo) throw (invalid_argument, length_error){
    validar(campo);
    this->campo = campo;
}

void Codigo::validar (string campo) throw (invalid_argument, length_error){
    if (campo.size() != TAM)
        throw length_error (msgErroTam);

    if (!Manipulacao::eNum(campo))
        throw invalid_argument (Codigo::msgErroArg);
}
