#ifndef TABELA_METODOS_HPP
    #define TABELA_METODOS_HPP

    /**
     *  @file   TabMetodos.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/Campo.hpp"

    /**
     *  @class TabMetodos
     *  Tabela de métodos do arquivo .class
     */
    class TabMetodos : public InterTabela {
        private:
            /** Tabela de símbolos que está vinculada */
            InterTabela *tab_simbolos = nullptr;
            /** Conteúdo da tabela em si */
            std::vector<Campo> registros;

        public:
            /** Construtor padrão */
            TabMetodos (){};

            /**
             *  Construtor com o conhecimento prévio do seu tamanho
             *  @param tam Tamanho a ser atribuido à tabela
             */
            explicit TabMetodos (u2 *tam);

            /**
             *  Construtor com o conhecimento prévio tanto do seu tamanho quanto da tabela
             *  de símbolos que está vinculada
             *  @param tam Tamanho a ser atribuido à tabela
             *  @param tab_simbolos Tabela de símbolos que está vinculada
             */
            explicit TabMetodos (u2 *tam, InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para a tabela de métodos
             *  @param arq Arquivo .class sob análise
             *  @returns 0 se não aconteceu problemas na decodificação, caso contrário
             *  outro número
             */
            u1 decodificar (FILE *arq) override;

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
