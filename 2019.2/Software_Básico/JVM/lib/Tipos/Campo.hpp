#ifndef TIPOS_CAMPO_HPP
    #define TIPOS_CAMPO_HPP

    #include <vector>
    #include "../Interfaces/InterTabela.hpp"
    #include "Basicos.hpp"

    class Campo {
        private:
            u1 e_metodo = 0;
        public:
            u2 flag_acesso = 0;
            u2 ind_nome = 0;
            u2 ind_descritor = 0;
            u2 tam_tab_atributos = 0;
            InterTabela *tab_atributos = nullptr;

            Campo() {};

            explicit Campo (u1 e_metodo): e_metodo(e_metodo) {};

            void decodificar(FILE *arq);

            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs);

            void deletar();
    };
#endif
