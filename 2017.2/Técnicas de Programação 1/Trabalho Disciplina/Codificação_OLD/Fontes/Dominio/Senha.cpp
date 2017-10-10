#include "../../Bibliotecas/Dominio/Senha.hpp"

const string Senha::msgErroTam ("Senha fornecida fora do tamanho padrão!");
const string Senha::msgErroSimb ("Senha contém caracteres não alfabéticos!");
const string Senha::msgErroArg ("Senha fornecida não obedece as especificações!");

Senha::Senha (const string &campo){
    setCampo(campo);
}

void Senha::deletar() {delete this;}

void Senha::validar(const string &campo) throw (invalid_argument){
    validarTamanho(campo);

    validarAlfabetico(campo);

    validarDuplicata(campo);
}

void Senha::validarTamanho(const string &campo) throw (invalid_argument){
    if(!Manipulacao::tam(campo, TAM_MAX))
        throw invalid_argument (msgErroTam);
}

void Senha::validarAlfabetico(const string &campo) throw (invalid_argument){
    if(!Manipulacao::eAlfabetico(campo))
        throw invalid_argument (msgErroSimb);
}

void Senha::validarDuplicata(const string &campo) throw (invalid_argument){
    if(Manipulacao::haRepeticao(campo))
        throw invalid_argument (msgErroArg);
}
