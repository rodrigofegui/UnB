#include "../../Bibliotecas/Dominio/Nome.hpp"

void Nome::validar (const string &campo) throw (invalid_argument, length_error){
    //*
    if(!Manipulacao::noLimite(campo, TAM_MAX))
        throw length_error (msgErroTam);

    if(Manipulacao::haNum(campo))
        throw invalid_argument (msgErroNum);

    if(haInvSimb(campo))
        throw invalid_argument (msgErroSimb);
}

bool Nome::haInvSimb(const string &campo){
    regex exp (SIMB_N_PERMT);
    sregex_iterator end, teste(campo.begin(), campo.end(), exp);

    if (teste != end)
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}
