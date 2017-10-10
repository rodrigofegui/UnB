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
            const static string msgErroTam;
            const static string msgErroArgDia;
            const static string msgErroArgMes;
            const static string msgErroArgAno;
            const static string msgErroArg;

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
            void validar (const string &campo) throw (invalid_argument) override;
            void validarTamanho (const string &campo) throw (invalid_argument);
            void validarFormato (const string &campo) throw (invalid_argument);
            void validarDia (const string &campo) throw (invalid_argument);
            void validarMes (const string &campo) throw (invalid_argument);
            void validarAno (const string &campo) throw (invalid_argument);
            void validarData () throw (invalid_argument);
            void validarFevereiro () throw (invalid_argument);

            /*  Partes de uma data */
            string dia, mes, ano;

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

            /**
             *  Recuperar o valor atribuído ao dia
             *  @return Dia armazenado
             */
            int getDia() const;

            /**
             *  Recuperar o valor atribuído ao mês
             *  @return Mês armazenado
             */
            int getMes() const;

            /**
             *  Recuperar o valor atribuído ao ano
             *  @return Ano armazenado
             */
            int getAno() const;

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };

    inline int Data::getDia() const{return atoi(this->dia.c_str());}
    inline int Data::getMes() const{return atoi(this->mes.c_str());}
    inline int Data::getAno() const{return atoi(this->ano.c_str());}
#endif // DATA_H
