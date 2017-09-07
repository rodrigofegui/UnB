#include "../../Bibliotecas/Dominio/Titulo.hpp"

const string Titulo::msgErroTam ("Título fornecido fora do tamanho padrão!");
const string Titulo::msgErroArg ("Título fornecido não obedece as especificações!");

const string Titulo::DB_SPACE ("  ");

void Titulo::validar(const string &campo) throw (invalid_argument, length_error){
    validarTamanho(campo);

    validarSimbolos(campo);
}

void Titulo::validarTamanho(const string &campo) throw (invalid_argument, length_error){
    if(!Manipulacao::noLimite(campo, TAM_MAX))
        throw length_error (msgErroTam);
}

void Titulo::validarSimbolos(const string &campo) throw (invalid_argument, length_error){
    if(strstr (campo.c_str(), DB_SPACE.c_str()))
        throw invalid_argument (msgErroArg);
}
