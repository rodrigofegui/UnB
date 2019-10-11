#ifndef TIPOS_ARQ_CLASS_HPP
    #define TIPOS_ARQ_CLASS_HPP

    /**
     *  @file   ArqClass.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <string>
    #include "../Interfaces/InterTabela.hpp"

    /**
     *  @class ArqClass
     *  Representação de um arquivo .class
     */
    class ArqClass {
        private:
            /** Controle do arquivo .class original */
            char *nome_arq;
            FILE *arq = nullptr;

            /** Flag sobre a existência de um método <main> no arquivo */
            u1 tem_main = 0;

            /** Estrutura de um arquivo .class */
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

            /** Verifica se o arquivo conectado é válido */
            void check_valido ();

            void erro (const u1 e_codigo);

            std::string get_versao_java (u2 versao);

        public:
            /** Construtor padrão */
            ArqClass (){};

            /**
             *  Construtor com o conhecimento prévio do arquivo .class indiretamente
             *  @param nome_arq Nome do arquivo .class a ser lido
             */
            explicit ArqClass (char *nome_arq);

            /**
             *  Decodificador do arquivo binário .class
             */
            void decodificar ();

            /**
             *  Exibição do arquivo .class na saída padrão
             */
            void exibir ();

            /**
             *  Destrutor do arquivo .class e suas dependências
             */
            void deletar ();
    };
#endif
