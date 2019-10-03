#ifndef INTERFACE_ATRIBUTOS_HPP
    #define INTERFACE_ATRIBUTOS_HPP

    #include <stdio.h>
    #include "../Tipos/Basicos.hpp"

    class InterAtributo{
        public:
            u2 ind_nome = 0;
            u4 tam = 0;

            InterAtributo(){};

            InterAtributo (const u2 ind_nome, const u4 tam);

            void decodificar(FILE *arq);

            virtual void exibir (u1 qnt_tabs) = 0;

            virtual void deletar() = 0;
    };
#endif
