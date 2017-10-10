#include "../../Bibliotecas/Dominio/Titulo.hpp"

const string Titulo::msgErroTam ("Título fornecido fora do tamanho padrão!");
const string Titulo::msgErroArg ("Título fornecido não obedece as especificações!");
const string Titulo::DB_SPACE ("  ");

void Titulo::deletar() {delete this;}

void Titulo::validar(const string &campo) throw (invalid_argument){
    validarTamanho(campo);

    validarSimbolos(campo);
}

void Titulo::validarTamanho(const string &campo) throw (invalid_argument){
    if(!Manipulacao::noLimite(campo, TAM_MAX))
        throw invalid_argument (msgErroTam);
}

void Titulo::validarSimbolos(const string &campo) throw (invalid_argument){
    if(strstr (campo.c_str(), DB_SPACE.c_str()))
        throw invalid_argument (msgErroArg);
}
