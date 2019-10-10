#ifndef TIPOS_ATRIBUTOS_HPP
    #define TIPOS_ATRIBUTOS_HPP

    /**
     *  @file   Atributos.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <vector>
    #include "../Tabelas/TabAtributos.hpp"
    #include "../Tipos/Excessao.hpp"

    /**
     *  @class AttrCode
     *  Atributo do tipo <<Code>>, presente somente nos métodos
     */
    class AttrCode : public InterAtributo {
        private:
            /*  Tabela de símbolos que está vinculado */
            InterTabela *tab_simbolos = nullptr;

            /*  Estrutura de um atributo <<Code>> */
            u2 max_pilha = 0;
            u2 max_locais = 0;
            u4 tam_codigo = 0;
            std::vector<u1> codigo;
            u2 tam_tab_excessao = 0;
            std::vector<Excessao> tab_excessao;
            u2 tam_tab_atributos = 0;
            TabAtributos *tab_atributos = nullptr;

        public:
            /*  Construtor padrão */
            AttrCode (){};

            /**
             *  Construtor com o conhecimento prévio do índice do nome
             *  @param ind_nome Índice do nome
             */
            explicit AttrCode (const u2 ind_nome);

            /**
             *  Construtor com o conhecimento prévio tanto do índice do nome quanto da
             *  tabela de símbolos que está vinculado
             *  @param ind_nome Índice do nome
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit AttrCode (const u2 ind_nome, InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para o atributo <<Code>>,
             *  extraindo todos os seus campos, além do índice do nome e do seu tamanho,
             *  caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição do atributo <<Code>> na saída padrão, conhecendo-se a tabela de
             *  símbolos do arquivo corrente, para exibir as referências, além do controle
             *  de tabulação
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo <<Code>> e suas dependências
             */
            void deletar () override;
    };

    /**
     *  @class AttrLinhaNum
     *  Atributo do tipo <<LineNumberTable>>, comulmente associados aos atributos <<Code>>
     */
    class AttrLinhaNum : public InterAtributo {
        private:
            /*  Estrutura dos número de um atributo <<LineNumberTable>> */
            typedef struct info_num {
                u2 pc_comeco;
                u2 lin_num;
            } InfoNumero;

            /*  Estrutura de um atributo <<LineNumberTable>> */
            u2 tam_tab_valores = 0;
            std::vector<InfoNumero> tab_valores;

        public:
            /*  Construtor padrão */
            AttrLinhaNum () {};

            /**
             *  Construtor com o conhecimento prévio do índice do nome
             *  @param ind_nome Índice do nome
             */
            explicit AttrLinhaNum (const u2 ind_nome);

            /**
             *  Decodificador do arquivo binário .class para o atributo
             *  <<LineNumberTable>>, extraindo todos os seus campos, além do índice do
             *  nome e do seu tamanho, caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição do atributo <<LineNumberTable>> na saída padrão, conhecendo-se
             *  a tabela de símbolos do arquivo corrente, para exibir as referências,
             *  além do controle de tabulação
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo <<LineNumberTable>> e suas dependências
             */
            void deletar () override;
    };

    /**
     *  @class AttrArqFonte
     *  Atributo do tipo <<SourceFile>>
     */
    class AttrArqFonte : public InterAtributo {
        private:
            /*  Estrutura de um atributo <<Code>> */
            u2 ind = 0;

        public:
            /*  Construtor padrão */
            AttrArqFonte (){};

            /**
             *  Construtor com o conhecimento prévio do índice do nome
             *  @param ind_nome Índice do nome
             */
            explicit AttrArqFonte (const u2 ind_nome);

            /**
             *  Decodificador do arquivo binário .class para o atributo <<SourceFile>>,
             *  extraindo todos os seus campos, além do índice do nome e do seu tamanho,
             *  caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição do atributo <<SourceFile>> na saída padrão, conhecendo-se a
             *  tabela de símbolos do arquivo corrente, para exibir as referências,
             *  além do controle de tabulação
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo <<SourceFile>> e suas dependências
             */
            void deletar () override;
    };

    /**
     *  @class AttrSilenciado
     *  Atributo sem tipo tratável
     */
    class AttrSilenciado : public InterAtributo {
        public:
            /*  Construtor padrão */
            AttrSilenciado (){};

            /**
             *  Construtor com o conhecimento prévio do índice do nome
             *  @param ind_nome Índice do nome
             */
            explicit AttrSilenciado (const u2 ind_nome);

            /**
             *  Decodificador do arquivo binário .class para o atributo não tratável para
             *  o seu índice do nome e o seu tamanho, caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição do atributo não tratável na saída padrão, conhecendo-se a
             *  tabela de símbolos do arquivo corrente, para exibir as referências,
             *  além do controle de tabulação
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo não tratável e suas dependências
             */
            void deletar () override;
    };
#endif
