#include "../../Bibliotecas/Dominio/Nome.hpp"

void Nome::validar (const string &campo) throw (invalid_argument, length_error){
    validarTamanho (campo);

    validarAlfabetico (campo);

    validarSimbolos (campo);
}

bool Nome::haInvSimb(const string &campo){
    regex exp (SIMB_N_PERMT);
    sregex_iterator end, teste(campo.begin(), campo.end(), exp);

    if ((teste != end)
        || strstr (campo.c_str(), DB_SPACE.c_str())
        || strstr (campo.c_str(), DB_PONTO.c_str()))
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}

void Nome::validarTamanho (const string &campo) throw (invalid_argument, length_error){
    if(!Manipulacao::noLimite(campo, TAM_MAX))
        throw length_error (msgErroTam);
}

void Nome::validarAlfabetico (const string &campo) throw (invalid_argument, length_error){
    if(Manipulacao::haNum(campo))
        throw invalid_argument (msgErroNum);
}

void Nome::validarSimbolos (const string &campo) throw (invalid_argument, length_error){
    if(haInvSimb(campo))
        throw invalid_argument (msgErroSimb);
}
