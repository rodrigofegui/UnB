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
            u1 e_principal;
            FILE *arq = nullptr;

            u4 codigo;
            u2 versao_min;
            u2 versao_max;
            u2 tam_tab_simbolo;
            InterTabela *tab_simbolo = nullptr;
            u2 flag_acesso;
            u2 class_atual;
            u2 class_super;
            u2 tam_tab_interfaces;
            InterTabela *tab_interfaces = nullptr;
            u2 tam_tab_campos;
            InterTabela *tab_campos = nullptr;
            u2 tam_tab_metodos;
            InterTabela *tab_metodos = nullptr;
            u2 tam_tab_atributos;
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
