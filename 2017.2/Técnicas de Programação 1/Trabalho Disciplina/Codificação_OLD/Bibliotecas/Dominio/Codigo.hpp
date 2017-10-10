#ifndef CODIGO_H
    #define CODIGO_H

    /**
     *  @file   Codigo.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include "DominioBase.hpp"

    /**
     *  @class Codigo
     *  Código a ser atribuido a um livro da estante digital,
     *  garantindo a integridade do mesmo
     */
    class Codigo : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const static string msgErroTam;
            const static string msgErroArg;

            /*  Tamanho do código */
            const static int TAM = 5;

            /*  Validação do código a ser armazenado */
            void validar (const string &campo) throw (invalid_argument) override;
            void validarTamanho (const string &campo) throw (invalid_argument);
            void validarNumerico (const string &campo) throw (invalid_argument);

        public:
            /**
             *  Construtor padrão
             */
            Codigo (){};

            /**
             *  Construir um código, conhecendo-se o seu valor
             *  @param campo Código candidato à atribuição
             */
            Codigo (const string &campo);

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };
#endif // CODIGO_H
