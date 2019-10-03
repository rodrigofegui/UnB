#ifndef TABELA_METODOS_HPP
    #define TABELA_METODOS_HPP

    #include "TabCampos.hpp"

    class TabMetodos : public TabCampos{
        private:
            std::vector<Campo> registros;

        public:
            TabMetodos (){};

            explicit TabMetodos (u2 *tam): TabCampos(tam) {};

            void decodificar(FILE *arq) override;

            void exibir (u1 qnt_tabs) override {};

            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs);

            void deletar();
    };
#endif
