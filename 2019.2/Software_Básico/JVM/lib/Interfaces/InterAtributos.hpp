#ifndef INTERFACE_ATRIBUTOS_HPP
    #define INTERFACE_ATRIBUTOS_HPP

    #include <stdio.h>
    #include "../Tipos/Basicos.hpp"
    #include "InterTabela.hpp"

    class InterAtributo{
        public:
            static int flag_0_p_1;
            static int flag_0_p_2;
            static int flag_2_p_1;
            static int flag_3_p_1;
            u2 ind_nome = 0;
            u4 tam = 0;

            InterAtributo(){};

            InterAtributo(const u2 ind_nome);

            InterAtributo (const u2 ind_nome, const u4 tam);

            virtual void decodificar(FILE *arq);

            virtual void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) = 0;

            virtual void deletar();
    };
#endif
