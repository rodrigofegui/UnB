#ifndef INTERFACE_TABELA_HPP
    #define INTERFACE_TABELA_HPP

    /**
     *  @file   InterTabela.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <vector>
    #include <stdio.h>
    #include "../Tipos/Basicos.hpp"

    class InterTabela {
        private:
            void erro(const u1 e_codigo);

        protected:
            u2 tam = 0;

        public:
            InterTabela ();

            explicit InterTabela (u2 tam) : tam(tam) {};

            virtual void decodificar(FILE *arq) = 0;

            virtual void exibir(int qnt_tab) = 0;

            virtual void deletar() = 0;
    };
#endif
