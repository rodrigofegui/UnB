#ifndef TIPOS_EXCESSAO_HPP
    #define TIPOS_EXCESSAO_HPP

    /**
     *  @file   Excessao.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Interfaces/InterTabela.hpp"

    /**
     *  @class Excessao
     *  Excessão aos métodos existentes
     */
    class Excessao{
        private:
            /** Estrutura de uma excessão */
            u2 lin_comeco = 0;
            u2 lin_final = 0;
            u2 lin_tratamento = 0;
            u2 ind_tipo_catch = 0;

        public:
            /** Construtor padrão */
            Excessao (){};

            /**
             *  Decodificador do arquivo binário .class para uma excessão, extraindo todos
             *  os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq);

            /**
             *  Exibição de uma excessão na saída padrão, conhecendo-se a tabela de
             *  símbolos do arquivo corrente, para exibir as referências, além do controle
             *  de tabulação
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs);
    };
#endif
