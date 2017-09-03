#ifndef CODIGO_H
    #define CODIGO_H

    /**
     *  @file   Codigo.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include <iostream>
    #include <stdexcept>
    #include "../Utilidades/Manipulacao.hpp"

    class Codigo{
        private:
            /*  Mensagens de erro padrão */
            const string msgErroTam = "Campo fornecido com tamanho inválido!";
            const string msgErroArg = "Campo foge à especificação numérica!";

            /*  Tamanho do código */
            const static int TAM = 5;

            /*  Código a ser armazenado */
            string campo;

            /*  Validação do código a ser armazenado */
            void validar (string campo) throw (invalid_argument, length_error);

        public:
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
