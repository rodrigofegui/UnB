#include "../../Bibliotecas/Dominio/Apelido.hpp"

const string Apelido::msgErroTam ("Apelido fornecido maior que o limite!");
const string Apelido::msgErroArg ("Apelido foge à especificação alfabética!");

Apelido::Apelido(const string &campo){
    setCampo(campo);
}

void Apelido::validar (const string &campo) throw (invalid_argument, length_error){
    validarTamanho (campo);

    validarLetras (campo);
}

void Apelido::validarTamanho (const string &campo) throw (invalid_argument, length_error){
    if (!Manipulacao::noLimite(campo, Apelido::LIM_MAX))
        throw length_error (msgErroTam);
}

void Apelido::validarLetras (const string &campo) throw (invalid_argument, length_error){
    if(!Manipulacao::eAlfabetico(campo))
        throw invalid_argument (msgErroArg);
}
