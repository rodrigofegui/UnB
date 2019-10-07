#ifndef TABELA_ATRIBUTOS_HPP
    #define TABELA_ATRIBUTOS_HPP

    #include "../Interfaces/InterTabela.hpp"
    #include "../Interfaces/InterAtributos.hpp"

    class TabAtributos : public InterTabela {
        private:
            std::vector<InterAtributo *> registros;
            InterTabela *tab_simbolos = nullptr;
            u1 attr_code = 0;

        public:
            TabAtributos (){};

            explicit TabAtributos (u2 *tam): InterTabela(tam) {};

            TabAtributos (InterTabela *tab, u2 *tam);

            TabAtributos (InterTabela *tab, u2 *tam, u1 attr_code);

            void decodificar(FILE *arq) override;

            void exibir (u1 qnt_tabs) override;

            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) override {};

            void deletar() override;
    };
#endif
