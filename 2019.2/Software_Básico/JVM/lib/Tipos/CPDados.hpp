#ifndef TIPOS_CP_DADOS_HPP
    #define TIPOS_CP_DADOS_HPP

    #include <vector>
    #include "../Interfaces/InterCPDados.hpp"

    class InfoClasse : public InterCPDados {
        private:
            u2 ind_nome = 0;

        public:
            explicit InfoClasse (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };

    class InfoRefCampo : public InterCPDados {
        private:
            u2 ind_classe = 0;
            u2 ind_nome_tipo = 0;

        public:
            explicit InfoRefCampo (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };

    class InfoNomeTipo : public InterCPDados {
        private:
            u2 ind_nome = 0;
            u2 ind_descritor = 0;

        public:
            explicit InfoNomeTipo (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };

    class InfoUTF8 : public InterCPDados {
        private:
            u2 tam = 0;
            std::vector<u1> bytes;

        public:
            explicit InfoUTF8 (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override;
    };

    class InfoRefMetodo : public InterCPDados {
        private:
            u2 ind_classe = 0;
            u2 ind_nome_tipo = 0;

        public:
            explicit InfoRefMetodo (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };

    class InfoRefMetInterface : public InterCPDados {
        private:
            u2 ind_classe = 0;
            u2 ind_nome_tipo = 0;

        public:
            explicit InfoRefMetInterface (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };

    class InfoString : public InterCPDados {
        private:
            u2 ind_string = 0;

        public:
            explicit InfoString (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };

    class InfoInteiro : public InterCPDados {
        private:
            u4 bytes = 0;

        public:
            explicit InfoInteiro (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };

    class InfoFloat : public InterCPDados {
        private:
            u4 bytes = 0;

        public:
            explicit InfoFloat (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };

    class InfoLong : public InterCPDados {
        private:
            u4 bytes_mais = 0;
            u4 bytes_menos = 0;

        public:
            explicit InfoLong (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };

    class InfoDouble : public InterCPDados {
        private:
            u4 bytes_mais = 0;
            u4 bytes_menos = 0;

        public:
            explicit InfoDouble (TabSimbolo *tab): InterCPDados (tab) {};
            void decodificar(FILE *arq) override;
            void exibir(int qnt_tabs) override;
            void deletar() override {};
    };
#endif
