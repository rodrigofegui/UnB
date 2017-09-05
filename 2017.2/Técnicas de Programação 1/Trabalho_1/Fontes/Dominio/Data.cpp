#include "../../Bibliotecas/Dominio/Data.hpp"

const vector<int> Data::MES_31 ({1, 3, 5, 7, 8, 10, 12});

void Data::validar (const string &campo) throw (invalid_argument, length_error){
    /*  Validação do tamanho */
    if(!Manipulacao::tam(campo, DATA_TAM))
        throw new length_error (msgErroTam);

    /*  Validação da formatação */
    if((campo.at(DIVISAO_1) != DIVISOR)
       || (campo.at(DIVISAO_2) != DIVISOR))
        throw new invalid_argument (msgErroArg);

    /*  Validação da data, preliminar */
    string dia = campo.substr(0, 2);
    if(!Manipulacao::eNum(dia.c_str())
       || !Manipulacao::intervaloF (atoi(dia.c_str()),
                                    DIA_MES_MIN, DIA_MAX))
        throw new invalid_argument (msgErroArgDia);

    /*  Validação do mês */
    string mes = campo.substr(3, 2);
    if(!Manipulacao::eNum(mes.c_str())
       || !Manipulacao::intervaloF(atoi(mes.c_str()),
                                DIA_MES_MIN, MES_MAX))
        throw new invalid_argument (msgErroArgMes);

    /*  Validação do ano */
    string ano = campo.substr(6, 2);
    if(!Manipulacao::eNum(ano.c_str()))
        throw new invalid_argument (msgErroArgAno);

    /*  Validação data, mes de 31 dias */
    if(!Manipulacao::localizar(MES_31, atoi(mes.c_str()))
       && (atoi(dia.c_str()) == DIA_MAX)
       && (atoi(mes.c_str()) != MES_FEV))
        throw new invalid_argument (msgErroArgDia);

    /*  Validação data, fevereiro */
    if ((atoi(mes.c_str()) == MES_FEV)
        && ((Manipulacao::eBissexto(ANO_BASE + atoi(ano.c_str()))
                && !Manipulacao::noLimite(atoi(dia.c_str()), DIA_BISSEXTO))
            ||(!Manipulacao::eBissexto(ANO_BASE + atoi(ano.c_str()))
                && !Manipulacao::noLimite(atoi(dia.c_str()), DIA_FEV))))
        throw new invalid_argument (msgErroArgDia);
}
