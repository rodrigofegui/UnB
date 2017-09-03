#ifndef GENERO_LITERARIO_H
    #define GENERO_LITERARIO_H

    /**
     *  @file   GeneroLiterario.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include <iostream>
    #include <stdexcept>
    #include "../Utilidades/Manipulacao.hpp"
    using namespace std;

    /**
     *  @class  GeneroLiterario
     *  Gêneros literários aceitos na estante digital,
     *  garantindo a sua integridade
     */
    class GeneroLiterario{
        private:
            /*  Mensagens de erro padrão */
            const string msgErro = "Gênero não registrado!";

            /*  Constantes de restrição */
            const static vector<string> GEN_CADASTRADO;

            /*  Gênero a ser armazenado */
            string campo;

            /*  Validação do gênero a ser armazenado */
            void validar (string campo) throw (invalid_argument);

        public:
            /**
             *  Atribuição do gênero literário, respeitando
             *  sua integridade
             *  @param campo Gênero candidato à atribuição
             */
            void setCampo (string campo) throw (invalid_argument);

            /**
             *  Recuperar o valor atribuída ao gênero
             *  @return Gênero armazenado
             */
            string getCampo();

    };
inline string GeneroLiterario::getCampo(){return this->campo;}
#endif // GENERO_LITERARIO_H
