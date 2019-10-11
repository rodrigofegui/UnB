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
     *  Dados da tabela de símbolos do tipo __CONSTANT_Class__
     */
    class InfoClasse : public InterCPDado {
        public:
            /** Estrutura dos dados da __CONSTANT_Class__ */
            u2 ind_nome = 0;

            /** Construtor padrão */
            InfoClasse (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoClasse (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Class__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Class__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
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
            /** Construtor padrão */
            InfoRefCampo (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoRefCampo (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Fieldref__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Fieldref__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
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

            /** Construtor padrão */
            InfoNomeTipo (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoNomeTipo (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_NameAndType__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_NameAndType__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
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
            /** Construtor padrão */
            InfoUTF8 (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoUTF8 (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Utf8__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Utf8__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

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
            /** Construtor padrão */
            InfoRefMetodo (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoRefMetodo (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Methodref__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Methodref__ na saída padrão com controle
             *  de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
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
            /** Construtor padrão */
            InfoRefMetInterface (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoRefMetInterface (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_InterfaceMethodref__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_InterfaceMethodref__ na saída padrão com
             *  controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
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
            /** Construtor padrão */
            InfoString (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoString (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_String__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_String__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
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
            /** Construtor padrão */
            InfoInteiro (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoInteiro (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Integer__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Integer__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
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
            /** Construtor padrão */
            InfoFloat (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoFloat (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Float__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Float__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
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
            /** Construtor padrão */
            InfoLong (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoLong (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Long__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Long__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
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
            /** Construtor padrão */
            InfoDouble (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InfoDouble (InterTabela *tab_simbolos) : InterCPDado(tab_simbolos){}

            /**
             *  Decodificador do arquivo binário .class para os dados da
             *  __CONSTANT_Double__, extraindo todos os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição dos dados da __CONSTANT_Double__ na saída padrão com controle de
             *  tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;
    };
#endif
