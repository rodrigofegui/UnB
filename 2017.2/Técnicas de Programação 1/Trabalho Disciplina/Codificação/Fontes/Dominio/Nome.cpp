#include "../../Bibliotecas/Dominio/Nome.hpp"

const string Nome::msgErroTam ("Nome fornecido além do tamanho permitido!");
const string Nome::msgErroNum ("Nome fornecido contém números!");
const string Nome::msgErroSimb ("Nome fornecido contém símbolos não permitidos!");
const string Nome::msgErroArg ("Nome fornecido não obedece as especificações!");

const string Nome::SIMB_N_PERMT ("[-/!\"#$%&'()*+,:;<=>?@\[\\\]^_`{|}~]+");
const string Nome::DB_SPACE ("  ");
const string Nome::DB_PONTO ("..");

void Nome::deletar() {delete this;}

void Nome::validar (const string &campo) throw (invalid_argument){
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

void Nome::validarTamanho (const string &campo) throw (invalid_argument){
    if(!Manipulacao::noLimite(campo, TAM_MAX))
        throw invalid_argument (msgErroTam);
}

void Nome::validarAlfabetico (const string &campo) throw (invalid_argument){
    if(Manipulacao::haNum(campo))
        throw invalid_argument (msgErroNum);
}

void Nome::validarSimbolos (const string &campo) throw (invalid_argument){
    if(haInvSimb(campo))
        throw invalid_argument (msgErroSimb);
}
