#ifndef TIPOS_ARQ_CLASS_HPP
    #define TIPOS_ARQ_CLASS_HPP

    /**
     *  @file   ArqClass.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <stdio.h>
    #include "../Interfaces/InterTabela.hpp"
    #include "Basicos.hpp"

    /**
     *  @class ArqClass
     *  Arquivo .class a ser manipulado
     */
    class ArqClass {
        private:
            u1 e_principal = 0;
            FILE *arq = nullptr;

            u4 codigo = 0;
            u2 versao_min = 0;
            u2 versao_max = 0;
            u2 tam_tab_simbolo = 0;
            InterTabela *tab_simbolo = nullptr;
            u2 flag_acesso = 0;
            u2 class_atual = 0;
            u2 class_super = 0;
            u2 tam_tab_interfaces = 0;
            InterTabela *tab_interfaces = nullptr;
            u2 tam_tab_campos = 0;
            InterTabela *tab_campos = nullptr;
            u2 tam_tab_metodos = 0;
            InterTabela *tab_metodos = nullptr;
            u2 tam_tab_atributos = 0;
            InterTabela *tab_atributos = nullptr;

            void check_valido();

            void erro(const u1 e_codigo);

            void exibir_versao_java(u2 versao);

        public:
            /*  Construtor padrão */
            ArqClass ();

            /** Construtor sabendo o arquivo fonte
             *  @param arq Arquivo .class a ser lido
             */
            explicit ArqClass (FILE *arq);

            /** Construtor sabendo o arquivo fonte
             *  @param nome_arq Nome do arquivo .class a ser lido
             */
            explicit ArqClass (const char *nome_arq);

            void decodificar();

            void exibir();

            void reset();

            void deletar();
    };
#endif
