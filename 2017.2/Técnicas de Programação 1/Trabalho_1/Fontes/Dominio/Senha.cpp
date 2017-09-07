#include "../../Bibliotecas/Dominio/Senha.hpp"

const string Senha::msgErroTam ("Senha fornecida fora do tamanho padrão!");
const string Senha::msgErroSimb ("Senha contém caracteres não alfabéticos!");
const string Senha::msgErroArg ("Senha fornecida não obedece as especificações!");

void Senha::validar(const string &campo) throw (invalid_argument, length_error){
    validarTamanho(campo);

    validarAlfabetico(campo);

    validarDuplicata(campo);
}

void Senha::validarTamanho(const string &campo) throw (invalid_argument, length_error){
    if(!Manipulacao::tam(campo, TAM_MAX))
        throw length_error (msgErroTam);
}

void Senha::validarAlfabetico(const string &campo) throw (invalid_argument, length_error){
    if(!Manipulacao::eAlfabetico(campo))
        throw invalid_argument (msgErroSimb);
}

void Senha::validarDuplicata(const string &campo) throw (invalid_argument, length_error){
    if(Manipulacao::haRepeticao(campo))
        throw invalid_argument (msgErroArg);
}
