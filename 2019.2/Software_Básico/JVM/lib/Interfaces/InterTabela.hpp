#ifndef INTERFACE_TABELA_HPP
    #define INTERFACE_TABELA_HPP

    /**
     *  @file   InterTabela.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <stdio.h>
    #include "../Tipos/Basicos.hpp"

    /**
     *  @class InterTabela
     *  Interface para as tabelas de um arquivo .class
     */
    class InterTabela {
        protected:
            /*  Ref. para o tamanho da tabela */
            u2 *tam = nullptr;

        public:
            /*  Construtor padrão */
            InterTabela ();

            /**
             *  Construtor com o conhecimento prévio do seu tamanho
             *  @param tam Tamanho a ser atribuido à tabela
             */
            explicit InterTabela (u2 *tam) : tam(tam) {};

            /**
             *  Decodificador do arquivo binário .class para uma tabela, extraindo todos
             *  os seus registros específicos
             *  @param arq Arquivo .class sob análise
             */
            virtual void decodificar (FILE *arq) = 0;

            /**
             *  Exibição da tabela na saída padrão com controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            virtual void exibir (u1 qnt_tabs) = 0;

            /**
             *  Destrutor de uma tabela e suas dependências
             */
            virtual void deletar () = 0;
    };
#endif
