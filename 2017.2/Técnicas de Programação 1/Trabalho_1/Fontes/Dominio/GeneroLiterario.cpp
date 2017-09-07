#include "../../Bibliotecas/Dominio/GeneroLiterario.hpp"

const string GeneroLiterario::msgErro ("Gênero não registrado!");

const vector<string> GeneroLiterario::GEN_CADASTRADO ({"EPOPEIA", "NOVELA", "CONTO", "ENSAIO", "ROMANCE"});

void GeneroLiterario::validar (const string &campo) throw (invalid_argument){
    validarCadastro (campo);
}

void GeneroLiterario::validarCadastro (const string &campo) throw (invalid_argument){
    if(!Manipulacao::localizar(GEN_CADASTRADO, campo))
        throw invalid_argument (msgErro);
}
