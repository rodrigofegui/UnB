#include "../../Bibliotecas/Dominio/Versao.hpp"

const string Versao::msgErro ("Versão não registrada!");

const vector<string> Versao::VER_CADASTRADAS ({"1.0", "Latest"});

void Versao::deletar() {delete this;}

void Versao::validar (const string &campo) throw (invalid_argument){
    validarCadastro (campo);
}

void Versao::validarCadastro (const string &campo) throw (invalid_argument){
    if(!Manipulacao::localizar(VER_CADASTRADAS, campo))
        throw invalid_argument (msgErro);
}
