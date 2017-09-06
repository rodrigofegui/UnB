#include "../../Bibliotecas/Dominio/GeneroLiterario.hpp"

const vector<string> GeneroLiterario::GEN_CADASTRADO ({"EPOPEIA", "NOVELA", "CONTO", "ENSAIO", "ROMANCE"});

void GeneroLiterario::validar (const string &campo) throw (invalid_argument){
    validarCadastro (campo);
}

void GeneroLiterario::validarCadastro (const string &campo) throw (invalid_argument){
    if(!Manipulacao::localizar(GEN_CADASTRADO, Manipulacao::maiuscula(campo)))
        throw invalid_argument (msgErro);
}
