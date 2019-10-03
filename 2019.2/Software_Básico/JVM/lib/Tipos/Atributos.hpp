#ifndef TIPOS_ATRIBUTOS_HPP
    #define TIPOS_ATRIBUTOS_HPP

    #include <vector>
    #include "../Interfaces/InterAtributos.hpp"

    class AttrU1 : public InterAtributo {
        private:
            std::vector<u1> dados;

        public:
            AttrU1() {};

            explicit AttrU1 (const u2 ind_nome, const u4 tam): InterAtributo(ind_nome, tam){};

            void decodificar(FILE *arq);

            void exibir(u1 qnt_tabs) override;

            void deletar() override;
    };

    class AttrU2 : public InterAtributo {
        public:
            u2 ind = 0;

            AttrU2() {};

            explicit AttrU2 (const u2 ind_nome, const u4 tam): InterAtributo(ind_nome, tam){};

            void decodificar(FILE *arq);

            void exibir(u1 qnt_tabs) override;

            void deletar() override {};
    };

    class AttrCode : public InterAtributo {
        private:
            u2 max_pilha = 0;
            u2 max_locais = 0;
            u4 tam_codigo = 0;
            std::vector<u1> codigo;
            u2 tam_tab_excessao = 0;
            // Excessao *tab_excessao;
            u2 tam_tab_atributos = 0;
            InterAtributo *tab_atributos = nullptr;

        public:
            AttrCode() {};

            explicit AttrCode (const u2 ind_nome, const u4 tam): InterAtributo(ind_nome, tam){};

            void decodificar(FILE *arq);

            void exibir(u1 qnt_tabs) override;

            void deletar() override;
    };

    class AttrLinhaNum : public InterAtributo {
        private:
            u2 tam_tab_valores = 0;

        public:
            AttrLinhaNum() {};

            explicit AttrLinhaNum (const u2 ind_nome, const u4 tam): InterAtributo(ind_nome, tam){};

            void decodificar(FILE *arq);

            void exibir(u1 qnt_tabs) override;

            void deletar() override {};
    };
#endif
