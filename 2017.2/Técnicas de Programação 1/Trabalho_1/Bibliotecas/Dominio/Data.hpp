#ifndef DATA_H
    #define DATA_H

    /**
     *  @file   Data.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include "DominioBase.hpp"

    /**
     *  @class  Data
     *  Data padrão a ser utilizada na estante digital,
     *  garantindo a sua integridade
     */
    class Data : public DominioBase{
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

            /*  Validação da data a ser armazenado */
            void validar (const string &campo) throw (invalid_argument, length_error) override;

        public:
            /**
             *  Construtor padrão
             */
            Data (){};

            /**
             *  Construtor de uma data, conhecendo-se
             *  a mesma
             *  @param campo Data candidata a atribuição
             */
            Data(const string &campo);
    };
#endif // DATA_H
