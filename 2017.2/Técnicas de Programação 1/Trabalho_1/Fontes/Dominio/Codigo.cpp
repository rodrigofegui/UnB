#include "../../Bibliotecas/Dominio/Codigo.hpp"

Codigo::Codigo(const string &campo){
    setCampo(campo);
}

void Codigo::validar (const string &campo) throw (invalid_argument, length_error){
    if (campo.size() != TAM)
        throw length_error (msgErroTam);

    if (!Manipulacao::eNum(campo))
        throw invalid_argument (Codigo::msgErroArg);
}
