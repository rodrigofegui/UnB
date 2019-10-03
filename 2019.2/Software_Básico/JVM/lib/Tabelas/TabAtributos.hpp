#ifndef TABELA_ATRIBUTOS_HPP
    #define TABELA_ATRIBUTOS_HPP

    #include "../Interfaces/InterTabela.hpp"
    #include "../Interfaces/InterAtributos.hpp"

    class TabAtributos : public InterTabela {
        private:
            u1 e_metodo = 0;
            std::vector<InterAtributo *> registros;

        public:
            TabAtributos (){};

            explicit TabAtributos (u2 *tam): InterTabela(tam) {};

            TabAtributos (u1 e_metodo, u2 *tam);

            void decodificar(FILE *arq) override;

            void exibir (u1 qnt_tabs) override;

            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) override {};

            void deletar() override;
    };
#endif
