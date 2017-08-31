#include "../../Bibliotecas/Dominio/Apelido.hpp"

Apelido::Apelido(){

}

bool Apelido::setCampo(string campo) throw (invalid_argument, length_error){
    validar(campo);
    this->campo = campo;

    return TesteUnitario::PASSOU;
}

bool Apelido::validar (string campo) throw (invalid_argument, length_error){
    if (!Manipulacao::noLimite(campo, Apelido::LIM_MAX))
        throw length_error ("Campo fornecido maior que o limite!");

    if(!Manipulacao::eAlfabetico(campo))
        throw invalid_argument ("Campo foge à especificação alfabética!");
}
