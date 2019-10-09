#ifndef INTERFACE_CP_DADOS_HPP
    #define INTERFACE_CP_DADOS_HPP

    #include <stdio.h>
    #include "InterTabela.hpp"

    class InterCPDados{
        protected:
            InterTabela *tab_simbolos = nullptr;

        public:
            InterCPDados(){};

            explicit InterCPDados (InterTabela *tab): tab_simbolos(tab){};

            virtual void decodificar(FILE *arq) = 0;

            virtual void exibir(u1 qnt_tabs) = 0;

            virtual void deletar() = 0;
    };
#endif
