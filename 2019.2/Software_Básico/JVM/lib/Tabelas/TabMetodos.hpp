#ifndef TABELA_METODOS_HPP
    #define TABELA_METODOS_HPP

    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/Campo.hpp"

    class TabMetodos : public InterTabela {
        private:
            InterTabela *tab_simbolos = nullptr;
            std::vector<Campo> registros;

        public:
            TabMetodos (){};

            explicit TabMetodos (u2 *tam): InterTabela(tam) {};

            explicit TabMetodos (InterTabela *tab, u2 *tam);

            void decodificar(FILE *arq) override;

            void exibir (u1 qnt_tabs) override {};

            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) override;

            void deletar() override;
    };
#endif
