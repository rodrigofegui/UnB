#ifndef INTERFACE_CP_DADOS_HPP
    #define INTERFACE_CP_DADOS_HPP

    #include <stdio.h>
    #include "../Tabelas/TabSimbolo.hpp"

    class TabSimbolo;

    class InterCPDados{
        protected:
            TabSimbolo *tab = NULL;

        public:
            InterCPDados(){};

            explicit InterCPDados (TabSimbolo *tab): tab(tab){};

            virtual void decodificar(FILE *arq) = 0;

            virtual void exibir(int qnt_tabs) = 0;

            virtual void deletar() = 0;
    };
#endif
