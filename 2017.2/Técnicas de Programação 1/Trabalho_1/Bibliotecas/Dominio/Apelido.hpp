#ifndef APELIDO_HPP
    #define APELIDO_HPP

    /**
     *  @file   Apelido.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <iostream>
    #include <stdexcept>
    #include "../Utilidades/TesteUnitario.hpp"
    #include "../Utilidades/Manipulacao.hpp"

    using namespace std;

    /**
     *  Apelido a ser dado ao usuário da estande digital,
     *  garantindo a integridade do mesmo
     */
    class Apelido{
        private:
            const static int LIM_MAX = 5;

            string campo;

            bool validar (string campo) throw (invalid_argument, length_error);

        public:
            /**
             *  Construtor padrão
             */
            Apelido ();

            /**
             *  Valor atribuído ao apelido
             *  @return Apelido em si
             */
            string getCampo();

            /**
             *  Atribuição do apelido, respeitando sua integridade
             *  @param campo Apelido candidato a atribuição
             */
            bool setCampo (string campo) throw (invalid_argument, length_error);

            /**
             *  Destrutor padrão
             */
            void deletar ();

    };

    inline string Apelido::getCampo () {return this->campo;}
    inline void Apelido::deletar() {delete this;}
#endif // APELIDO_HPP
