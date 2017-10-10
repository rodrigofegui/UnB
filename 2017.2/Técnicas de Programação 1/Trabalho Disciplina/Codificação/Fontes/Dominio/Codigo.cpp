#include "../../Bibliotecas/Dominio/Codigo.hpp"

const string Codigo::msgErroTam ("Código fornecido com tamanho inválido!");
const string Codigo::msgErroArg ("Código foge à especificação numérica!");


Codigo::Codigo(const string &campo){
    setCampo(campo);
}

void Codigo::deletar() {delete this;}

void Codigo::validar (const string &campo) throw (invalid_argument){
    validarTamanho (campo);

    validarNumerico (campo);
}

void Codigo::validarTamanho (const string &campo) throw (invalid_argument){
    if (campo.size() != TAM)
        throw invalid_argument (msgErroTam);
}

void Codigo::validarNumerico (const string &campo) throw (invalid_argument){
    if (!Manipulacao::eNum(campo))
        throw invalid_argument (msgErroArg);
}
