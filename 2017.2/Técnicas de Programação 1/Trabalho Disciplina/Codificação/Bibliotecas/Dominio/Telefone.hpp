#ifndef TELEFONE_H
    #define TELEFONE_H

    /**
     *  @file   Telefone.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase.hpp"

    /**
     *  @class  Telefone
     *  Telefone padrão a ser utilizado na estante digital,
     *  garantindo a sua integridade
     */
    class Telefone : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const static string msgErroTam;
            const static string msgErroFmt;
            const static string msgErroNum;

            /*  Constantes de validação */
            const static int TAM_MAX = 14;
            const static int POS_DIV_DDD_i = 0;
            const static int POS_DIV_DDD_f = 3;
            const static int POS_DIV_NUM   = 4;
            const static char DIV_DDD_i = '(';
            const static char DIV_DDD_f = ')';
            const static char DIV_NUM   = '-';

            /*  Validação do telefone a ser armazenado */
            void validar (const string &campo) throw (invalid_argument) override;
            void validarTamanho (const string &campo) throw (invalid_argument);
            void validarFormato (const string &campo) throw (invalid_argument);
            void validarNumerico (const string &campo) throw (invalid_argument);

        public:
            /**
             *  Construtor padrão
             */
            Telefone (){};

            /**
             *  Construtor de uma data, conhecendo-se
             *  a mesma
             *  @param campo Data candidata a atribuição
             */
            Telefone (const string &campo);

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };
#endif // TELEFONE_H
