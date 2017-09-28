#include "../../Bibliotecas/Dominio/Telefone.hpp"

const string Telefone::msgErroTam ("Telefone fornecido fora do tamanho padrão!");
const string Telefone::msgErroFmt ("Telefone foge da formatação permitida: (xx)-xxxxxxxxx");
const string Telefone::msgErroNum ("Telefone contém caracteres não numéricos!");

void Telefone::deletar() {delete this;}

void Telefone::validar(const string &campo) throw (invalid_argument, length_error){
    validarTamanho (campo);

    validarFormato (campo);

    validarNumerico (campo);
}

void Telefone::validarTamanho (const string &campo) throw (invalid_argument, length_error){
    if(!Manipulacao::tam(campo, TAM_MAX))
        throw length_error (msgErroTam);
}

void Telefone::validarFormato (const string &campo) throw (invalid_argument, length_error){
    if((campo.at(POS_DIV_DDD_i) != DIV_DDD_i)
       || (campo.at(POS_DIV_DDD_f) != DIV_DDD_f)
       || (campo.at(POS_DIV_NUM) != DIV_NUM))
        throw invalid_argument (msgErroFmt);
}

void Telefone::validarNumerico (const string &campo) throw (invalid_argument, length_error){
    if (!Manipulacao::eNum(campo.substr(1,2))
        || !Manipulacao::eNum(campo.substr(5)))
        throw invalid_argument (msgErroNum);
}

