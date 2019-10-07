#ifndef TABELA_CAMPOS_HPP
    #define TABELA_CAMPOS_HPP

    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/Campo.hpp"

    class TabCampos : public InterTabela {
        private:
            InterTabela *tab_simbolos = nullptr;
            std::vector<Campo> registros;

        public:
            TabCampos (){};

            explicit TabCampos (u2 *tam): InterTabela(tam) {};

            explicit TabCampos (InterTabela *tab, u2 *tam);

            void decodificar(FILE *arq) override;

            void exibir (u1 qnt_tabs) override {};

            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) override;

            void deletar() override;
    };
#endif
