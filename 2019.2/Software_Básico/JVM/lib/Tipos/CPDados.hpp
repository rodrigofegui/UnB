#ifndef TIPOS_CP_DADOS_HPP
    #define TIPOS_CP_DADOS_HPP

    /**
     *  @file   CPDados.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <string>
    #include <vector>
    #include "../Interfaces/InterCPDado.hpp"

    /**
     *  @class InfoClasse
     *  Dados da tabela de símbolos do tipo <<CONSTANT_Class>>
     */
    class InfoClasse : public InterCPDados {
        public:
            /*  Estrutura dos dados da <<CONSTANT_Class>> */
            u2 ind_nome = 0;

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoClasse (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_Class>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_Class>> na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_Class>>
             */
            void deletar () override {};
    };

    /**
     *  @class InfoRefCampo
     *  Dados da tabela de símbolos do tipo <<CONSTANT_Fieldref>>
     */
    class InfoRefCampo : public InterCPDados {
        private:
            /*  Estrutura dos dados da <<CONSTANT_Fieldref>> */
            u2 ind_classe = 0;
            u2 ind_nome_tipo = 0;

        public:
            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoRefCampo (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_Fieldref>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_Fieldref>> na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_Fieldref>>
             */
            void deletar () override {};
    };

    /**
     *  @class InfoNomeTipo
     *  Dados da tabela de símbolos do tipo <<CONSTANT_NameAndType>>
     */
    class InfoNomeTipo : public InterCPDados {
        public:
            /*  Estrutura dos dados da <<CONSTANT_NameAndType>> */
            u2 ind_nome = 0;
            u2 ind_descritor = 0;

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoNomeTipo (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_NameAndType>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_NameAndType>> na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_NameAndType>>
             */
            void deletar () override {};
    };

    /**
     *  @class InfoUTF8
     *  Dados da tabela de símbolos do tipo <<CONSTANT_Utf8>>
     */
    class InfoUTF8 : public InterCPDados {
        private:
            /*  Estrutura dos dados da <<CONSTANT_Utf8>> */
            u2 tam = 0;
            std::vector<u1> bytes;

        public:
            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoUTF8 (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_Utf8>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_Utf8>> na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_Utf8>>
             */
            void deletar () override;

            /**
             *  Recuperação da string armazenada
             *  @return A string em UTF-8
             */
            std::string get_string ();
    };

    /**
     *  @class InfoRefMetodo
     *  Dados da tabela de símbolos do tipo <<CONSTANT_Methodref>>
     */
    class InfoRefMetodo : public InterCPDados {
        private:
            /*  Estrutura dos dados da <<CONSTANT_Methodref>> */
            u2 ind_classe = 0;
            u2 ind_nome_tipo = 0;

        public:
            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoRefMetodo (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_Methodref>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_Methodref>> na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_Methodref>>
             */
            void deletar () override {};
    };

    /**
     *  @class InfoRefMetInterface
     *  Dados da tabela de símbolos do tipo <<CONSTANT_InterfaceMethodref>>
     */
    class InfoRefMetInterface : public InterCPDados {
        private:
            /*  Estrutura dos dados da <<CONSTANT_InterfaceMethodref>> */
            u2 ind_classe = 0;
            u2 ind_nome_tipo = 0;

        public:
            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoRefMetInterface (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_InterfaceMethodref>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_InterfaceMethodref>> na saída padrão com
             *  controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_InterfaceMethodref>>
             */
            void deletar () override {};
    };

    /**
     *  @class InfoString
     *  Dados da tabela de símbolos do tipo <<CONSTANT_String>>
     */
    class InfoString : public InterCPDados {
        private:
            /*  Estrutura dos dados da <<CONSTANT_String>> */
            u2 ind_string = 0;

        public:
            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoRefMetInterface (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_String>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_String>> na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_String>>
             */
            void deletar () override {};
    };

    /**
     *  @class InfoInteiro
     *  Dados da tabela de símbolos do tipo <<CONSTANT_Integer>>
     */
    class InfoInteiro : public InterCPDados {
        private:
            /*  Estrutura dos dados da <<CONSTANT_Integer>> */
            u4 bytes = 0;

        public:
            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoInteiro (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_Integer>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_Integer>> na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_Integer>>
             */
            void deletar () override {};
    };

    /**
     *  @class InfoFloat
     *  Dados da tabela de símbolos do tipo <<CONSTANT_Float>>
     */
    class InfoFloat : public InterCPDados {
        private:
            /*  Estrutura dos dados da <<CONSTANT_Float>> */
            u4 bytes = 0;

        public:
            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoFloat (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_Float>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_Float>> na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_Float>>
             */
            void deletar () override {};
    };

    /**
     *  @class InfoLong
     *  Dados da tabela de símbolos do tipo <<CONSTANT_Long>>
     */
    class InfoLong : public InterCPDados {
        private:
            /*  Estrutura dos dados da <<CONSTANT_Long>> */
            u4 bytes_mais = 0;
            u4 bytes_menos = 0;

        public:
            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoLong (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_Long>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_Long>> na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_Long>>
             */
            void deletar () override {};
    };

    /**
     *  @class InfoDouble
     *  Dados da tabela de símbolos do tipo <<CONSTANT_Double>>
     */
    class InfoDouble : public InterCPDados {
        private:
            /*  Estrutura dos dados da <<CONSTANT_Double>> */
            u4 bytes_mais = 0;
            u4 bytes_menos = 0;

        public:
            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoDouble (InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  <<CONSTANT_Double>>, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da <<CONSTANT_Double>> na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da <<CONSTANT_Double>>
             */
            void deletar () override {};
    };
#endif
