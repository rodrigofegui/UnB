#include "../../Bibliotecas/Dominio/Texto.hpp"

const string Texto::msgErroTam ("Texto fornecido fora do tamanho padrão!");

void Texto::deletar() {delete this;}

void Texto::validar(const string &campo) throw (invalid_argument){
    validarTamanho (campo);
}

void Texto::validarTamanho (const string &campo) throw (invalid_argument){
    if(!Manipulacao::noLimite(campo, TAM_MAX))
        throw invalid_argument (msgErroTam);
}
