#ifndef TABELA_ATRIBUTOS_HPP
    #define TABELA_ATRIBUTOS_HPP

    /**
     *  @file   TabAtributos.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <vector>
    #include "../Interfaces/InterAtributo.hpp"
    #include "../Interfaces/InterTabela.hpp"

    /**
     *  @class TabAtributos
     *  Tabela de atributos, sejam os do arquivo .class em si quanto os de um método
     */
    class TabAtributos : public InterTabela {
        private:
            /** Tabela de símbolos que está vinculada */
            InterTabela *tab_simbolos = nullptr;
            /** Conteúdo da tabela em si */
            std::vector<InterAtributo*> registros;

        public:
            /** Construtor padrão */
            TabAtributos (){};

            /**
             *  Construtor com o conhecimento prévio do seu tamanho
             *  @param tam Tamanho a ser atribuido à tabela
             */
            explicit TabAtributos (u2 *tam);

            /**
             *  Construtor com o conhecimento prévio tanto do seu tamanho quanto da tabela
             *  de símbolos que está vinculada
             *  @param tam Tamanho a ser atribuido à tabela
             *  @param tab_simbolos Tabela de símbolos que está vinculada
             */
            explicit TabAtributos (u2 *tam, InterTabela *tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para a tabela de atributos
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
