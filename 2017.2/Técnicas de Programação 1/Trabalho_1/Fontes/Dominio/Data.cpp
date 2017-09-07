#include "../../Bibliotecas/Dominio/Data.hpp"

const string Data::msgErroTam ("Data fornecida com tamanho inválido!");
const string Data::msgErroArgDia ("Data foge da especificação de dia!");
const string Data::msgErroArgMes ("Data foge da especificação de mês!");
const string Data::msgErroArgAno ("Data foge da especificação de ano!");
const string Data::msgErroArg ("Data foge da formatação permitida: DD/MM/AA");

const vector<int> Data::MES_31 ({1, 3, 5, 7, 8, 10, 12});

void Data::validar (const string &campo) throw (invalid_argument, length_error){
    validarTamanho (campo);

    validarFormato (campo);

    validarDia (campo);

    validarMes (campo);

    validarAno (campo);

    validarData ();

    validarFevereiro ();
}

void Data::validarTamanho (const string &campo) throw (invalid_argument, length_error){
    if(!Manipulacao::tam(campo, DATA_TAM))
        throw length_error (msgErroTam);
}

void Data::validarFormato (const string &campo) throw (invalid_argument, length_error){
    if((campo.at(DIVISAO_1) != DIVISOR)
       || (campo.at(DIVISAO_2) != DIVISOR))
        throw invalid_argument (msgErroArg);
}

void Data::validarDia (const string &campo) throw (invalid_argument, length_error){
    this->dia = campo.substr(0, 2);

    if(!Manipulacao::eNum(dia.c_str())
       || !Manipulacao::intervaloF (atoi(dia.c_str()),
                                    DIA_MES_MIN, DIA_MAX)){
        this->dia.clear();
        throw invalid_argument (msgErroArgDia);
    }
}

void Data::validarMes (const string &campo) throw (invalid_argument, length_error){
    this->mes = campo.substr(3, 2);

    if(!Manipulacao::eNum(mes.c_str())
       || !Manipulacao::intervaloF(atoi(mes.c_str()),
                                DIA_MES_MIN, MES_MAX)){
        this->mes.clear();
        throw invalid_argument (msgErroArgMes);
    }
}

void Data::validarAno (const string &campo) throw (invalid_argument, length_error){
    this->ano = campo.substr(6, 2);
    if(!Manipulacao::eNum(ano.c_str())){
        this->ano.clear();
        throw invalid_argument (msgErroArgAno);
    }

}

void Data::validarData () throw (invalid_argument, length_error){
    if(!Manipulacao::localizar(MES_31, atoi(this->mes.c_str()))
       && (atoi(this->dia.c_str()) == DIA_MAX)
       && (atoi(this->mes.c_str()) != MES_FEV)){
        this->dia.clear();
        this->mes.clear();
        this->ano.clear();
        throw invalid_argument (msgErroArgDia);
    }
}

void Data::validarFevereiro () throw (invalid_argument, length_error){
    if ((atoi(this->mes.c_str()) == MES_FEV)
        && ((Manipulacao::eBissexto(ANO_BASE + atoi(this->ano.c_str()))
                && !Manipulacao::noLimite(atoi(this->dia.c_str()), DIA_BISSEXTO))
            ||(!Manipulacao::eBissexto(ANO_BASE + atoi(this->ano.c_str()))
                && !Manipulacao::noLimite(atoi(this->dia.c_str()), DIA_FEV)))){
        this->dia.clear();
        this->mes.clear();
        this->ano.clear();
        throw invalid_argument (msgErroArgDia);
    }
}

