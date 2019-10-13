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
     *  @class InfoPadding
     *  Dados da tabela de símbolos para continuação de números grandes
     */
    class InfoPadding : public InterCPDado {
        public:
            /* Herdando método já implementado */
            InfoPadding (){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Class__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override {};

            /**
             *  Exibição dos dados da __CONSTANT_Class__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoClasse
     *  Dados da tabela de símbolos do tipo __CONSTANT_Class__
     */
    class InfoClasse : public InterCPDado {
        public:
            /** Estrutura dos dados da __CONSTANT_Class__ */
            u2 ind_nome = 0;

            /* Herdando método já implementado */
            explicit InfoClasse (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Class__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Class__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoRefCampo
     *  Dados da tabela de símbolos do tipo __CONSTANT_Fieldref__
     */
    class InfoRefCampo : public InterCPDado {
        private:
            /** Estrutura dos dados da __CONSTANT_Fieldref__ */
            u2 ind_classe = 0;
            u2 ind_nome_tipo = 0;

        public:
            /* Herdando método já implementado */
            explicit InfoRefCampo (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Fieldref__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Fieldref__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoNomeTipo
     *  Dados da tabela de símbolos do tipo __CONSTANT_NameAndType__
     */
    class InfoNomeTipo : public InterCPDado {
        public:
            /** Estrutura dos dados da __CONSTANT_NameAndType__ */
            u2 ind_nome = 0;
            u2 ind_descritor = 0;

            /* Herdando método já implementado */
            explicit InfoNomeTipo (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_NameAndType__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_NameAndType__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoUTF8
     *  Dados da tabela de símbolos do tipo __CONSTANT_Utf8__
     */
    class InfoUTF8 : public InterCPDado {
        private:
            /** Estrutura dos dados da __CONSTANT_Utf8__ */
            u2 tam = 0;
            std::vector<u1> bytes;

        public:
            /* Herdando método já implementado */
            explicit InfoUTF8 (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Utf8__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Utf8__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Destrutor dos dados da __CONSTANT_Utf8__
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
     *  Dados da tabela de símbolos do tipo __CONSTANT_Methodref__
     */
    class InfoRefMetodo : public InterCPDado {
        private:
            /** Estrutura dos dados da __CONSTANT_Methodref__ */
            u2 ind_classe = 0;
            u2 ind_nome_tipo = 0;

        public:
            /* Herdando método já implementado */
            explicit InfoRefMetodo (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Methodref__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Methodref__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoRefMetInterface
     *  Dados da tabela de símbolos do tipo __CONSTANT_InterfaceMethodref__
     */
    class InfoRefMetInterface : public InterCPDado {
        private:
            /** Estrutura dos dados da __CONSTANT_InterfaceMethodref__ */
            u2 ind_classe = 0;
            u2 ind_nome_tipo = 0;

        public:
            /* Herdando método já implementado */
            explicit InfoRefMetInterface (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_InterfaceMethodref__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_InterfaceMethodref__ na saída padrão com
             *  controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoString
     *  Dados da tabela de símbolos do tipo __CONSTANT_String__
     */
    class InfoString : public InterCPDado {
        private:
            /** Estrutura dos dados da __CONSTANT_String__ */
            u2 ind_string = 0;

        public:
            /* Herdando método já implementado */
            explicit InfoString (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_String__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_String__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoInteiro
     *  Dados da tabela de símbolos do tipo __CONSTANT_Integer__
     */
    class InfoInteiro : public InterCPDado {
        private:
            /** Estrutura dos dados da __CONSTANT_Integer__ */
            u4 bytes = 0;

        public:
            /* Herdando método já implementado */
            explicit InfoInteiro (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Integer__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Integer__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoFloat
     *  Dados da tabela de símbolos do tipo __CONSTANT_Float__
     */
    class InfoFloat : public InterCPDado {
        private:
            /** Estrutura dos dados da __CONSTANT_Float__ */
            u4 bytes = 0;

        public:
            /* Herdando método já implementado */
            explicit InfoFloat (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Float__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Float__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoLong
     *  Dados da tabela de símbolos do tipo __CONSTANT_Long__
     */
    class InfoLong : public InterCPDado {
        private:
            /** Estrutura dos dados da __CONSTANT_Long__ */
            u4 bytes_mais = 0;
            u4 bytes_menos = 0;

        public:
            /* Herdando método já implementado */
            explicit InfoLong (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Long__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Long__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };

    /**
     *  @class InfoDouble
     *  Dados da tabela de símbolos do tipo __CONSTANT_Double__
     */
    class InfoDouble : public InterCPDado {
        private:
            /** Estrutura dos dados da __CONSTANT_Double__ */
            u4 bytes_mais = 0;
            u4 bytes_menos = 0;

        public:
            /* Herdando método já implementado */
            explicit InfoDouble (InterTabela *const tab_simbolos) : InterCPDado(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Double__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Double__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;
    };
#endif
