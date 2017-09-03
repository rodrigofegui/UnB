#include "../../Bibliotecas/Dominio/GeneroLiterario.hpp"

const vector<string> GeneroLiterario::GEN_CADASTRADO ({"EPOPEIA", "NOVELA", "CONTO", "ENSAIO", "ROMANCE"});

void GeneroLiterario::setCampo(string campo) throw (invalid_argument){
    validar(campo);
    this->campo = Manipulacao::maiuscula(campo);
}


void GeneroLiterario::validar (string campo) throw (invalid_argument){
    if(!Manipulacao::localizar(GEN_CADASTRADO, Manipulacao::maiuscula(campo)))
        throw invalid_argument (msgErro);
}
