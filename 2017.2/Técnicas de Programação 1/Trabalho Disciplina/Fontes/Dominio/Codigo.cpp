#include "../../Bibliotecas/Dominio/Codigo.hpp"

const string Codigo::msgErroTam ("Código fornecido com tamanho inválido!");
const string Codigo::msgErroArg ("Código foge à especificação numérica!");


Codigo::Codigo(const string &campo){
    setCampo(campo);
}

void Codigo::deletar() {delete this;}

void Codigo::validar (const string &campo) throw (invalid_argument, length_error){
    validarTamanho (campo);

    validarNumerico (campo);
}

void Codigo::validarTamanho (const string &campo) throw (invalid_argument, length_error){
    if (campo.size() != TAM)
        throw length_error (msgErroTam);
}

void Codigo::validarNumerico (const string &campo) throw (invalid_argument, length_error){
    if (!Manipulacao::eNum(campo))
        throw invalid_argument (msgErroArg);
}
