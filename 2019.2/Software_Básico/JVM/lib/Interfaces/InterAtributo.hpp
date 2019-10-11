#ifndef INTERFACE_ATRIBUTO_HPP
    #define INTERFACE_ATRIBUTO_HPP

    /**
     *  @file   InterAtributo.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <stdio.h>
    #include "InterTabela.hpp"
    #include "../Tipos/Basicos.hpp"

    /**
     *  @class InterAtributo
     *  Interface para todos os tipos de atributos de um arquivo .class
     */
    class InterAtributo {
        public:
            /** Variáveis comuns a todos os atributos */
            u2 ind_nome = 0;
            u4 tam = 0;

            /** Construtor padrão */
            InterAtributo (){};

            /**
             *  Construtor com o conhecimento prévio do índice do nome
             *  @param ind_nome Índice do nome
             */
            explicit InterAtributo (const u2 ind_nome);

            /**
             *  Decodificador do arquivo binário .class para um atributo, extraindo todos
             *  os seus campos específicos, caso exista, além do índice do nome e do seu
             *  tamanho
             *  @param arq Arquivo .class sob análise
             */
            virtual void decodificar (FILE *arq);

            /**
             *  Exibição do atributo na saída padrão, conhecendo-se a tabela de símbolos
             *  do arquivo corrente, para exibir as referências, além do controle de
             *  tabulação
             *  @param tab_simbolos Tabela de símbolos do arquivo .class
             *  @param qnt_tabs Quantidade de TABs
             */
            virtual void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) = 0;

            /**
             *  Destrutor de um atributo e suas eventuais dependências
             */
            virtual void deletar ();
    };
#endif
