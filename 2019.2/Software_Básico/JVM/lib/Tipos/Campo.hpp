#ifndef TIPOS_CAMPO_HPP
    #define TIPOS_CAMPO_HPP

    #include <vector>
    #include "../Interfaces/InterTabela.hpp"
    #include "Basicos.hpp"

    class Campo {
        private:
            InterTabela *tab_simbolos = nullptr;
        public:
            u2 flag_acesso = 0;
            u2 ind_nome = 0;
            u2 ind_descritor = 0;
            u2 tam_tab_atributos = 0;
            InterTabela *tab_atributos = nullptr;

            Campo() {};

            explicit Campo (InterTabela *tab);

            void decodificar(FILE *arq);

            void exibir (u1 qnt_tabs);

            void deletar();
    };
#endif
