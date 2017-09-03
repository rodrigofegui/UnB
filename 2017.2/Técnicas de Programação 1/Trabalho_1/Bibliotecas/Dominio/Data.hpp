#ifndef DATA_H
    #define DATA_H

    /**
     *  @file   Data.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <vector>
    #include <stdexcept>
    #include "../Utilidades/Manipulacao.hpp"
    using namespace std;

    /**
     *  @class  Data
     *  Data padrão a ser utilizada na estante digital,
     *  garantindo a sua integridade
     */
    class Data{
        private:
            /*  Mensagens de erro padrão */
            const string msgErroTam = "Data fornecida com tamanho inválido!";
            const string msgErroArgDia = "Data foge da especificação de dia!";
            const string msgErroArgMes = "Data foge da especificação de mês!";
            const string msgErroArgAno = "Data foge da especificação de ano!";
            const string msgErroArg = "Data foge da formatação desejada: DD/MM/AA";

            /*  Constantes de restrição */
            const static int ANO_BASE = 1900;
            const static int DIA_MES_MIN = 1;
            const static int DIA_MAX = 31;
            const static int DIA_30 = 30;
            const static int DIA_FEV = 28;
            const static int MES_FEV = 2;
            const static int DIA_BISSEXTO = 29;
            const static int MES_MAX = 12;
            const static int DATA_TAM = 8;
            const static int DIVISAO_1 = 2;
            const static int DIVISAO_2 = 5;
            const static char DIVISOR = '/';

            const static vector<int> MES_31;

            /*  Data a ser armazenada */
            string campo;

            /*  Validação da data a ser armazenado */
            void validar (string campo) throw (invalid_argument, length_error);

        public:
            /**
             *  Atribuição da data, respeitando sua integridade
             *  @param data Data candidata à atribuição
             */
            void setCampo (string campo) throw (invalid_argument, length_error);

            /**
             *  Recuperar o valor atruibuida à data
             *  @return Data armazenada
             */
            string getCampo ();
    };

    inline string Data::getCampo(){return this->campo;}
#endif // DATA_H
