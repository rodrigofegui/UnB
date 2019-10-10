#ifndef TABELA_CAMPOS_HPP
    #define TABELA_CAMPOS_HPP

    /**
     *  @file   TabCampos.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/Campo.hpp"

    /**
     *  @class TabCampos
     *  Tabela de campos do arquivo .class
     */
    class TabCampos : public InterTabela {
        private:
            /*  Tabela de símbolos que está vinculada */
            InterTabela *tab_simbolos = nullptr;
            /*  Conteúdo da tabela em si */
            std::vector<Campo> registros;

        public:
            /*  Construtor padrão */
            TabCampos (){};

            /**
             *  Construtor com o conhecimento prévio do seu tamanho
             *  @param tam Tamanho a ser atribuido à tabela
             */
            explicit TabCampos (u2 *tam);

            /**
             *  Construtor com o conhecimento prévio tanto do seu tamanho quanto da tabela
             *  de símbolos que está vinculada
             *  @param tam Tamanho a ser atribuido à tabela
             *  @param tab_simbolos Tabela de símbolos que está vinculada
             */
            explicit TabCampos (u2 *tam, InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para a tabela de campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq) override;

            /**
             *  Exibição da tabela na saída padrão com controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor da tabela e suas dependências
             */
            void deletar () override;
    };
#endif
