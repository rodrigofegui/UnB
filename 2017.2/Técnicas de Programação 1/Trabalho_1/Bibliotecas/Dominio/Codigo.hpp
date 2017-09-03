#ifndef CODIGO_H
    #define CODIGO_H

    /**
     *  @file   Codigo.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include <iostream>
    #include <stdexcept>
    #include "../Utilidades/Manipulacao.hpp"

    /**
     *  @class Codigo
     *  Código a ser atribuido a um livro da estante digital,
     *  garantindo a integridade do mesmo
     */
    class Codigo{
        private:
            /*  Mensagens de erro padrão */
            const string msgErroTam = "Código fornecido com tamanho inválido!";
            const string msgErroArg = "Código foge à especificação numérica!";

            /*  Tamanho do código */
            const static int TAM = 5;

            /*  Código a ser armazenado */
            string campo;

            /*  Validação do código a ser armazenado */
            void validar (string campo) throw (invalid_argument, length_error);

        public:
            /**
             *  Construtor padrão
             */
            Codigo ();

            /**
             *  Construir um código, conhecendo-se o seu valor
             *  @param campo Código candidato à atribuição
             */
            Codigo (string campo);

            /**
             *  Atribuição do código, respeitando sua integridade
             *  @param campo Código candidato à atribuição
             */
            void setCampo (string campo) throw (invalid_argument, length_error);

            /**
             *  Recuperar o valor atribuido ao campo
             *  @return Código armazenado
             */
            string getCampo ();
    };

    inline string Codigo::getCampo (){return this->campo;}
#endif // CODIGO_H
