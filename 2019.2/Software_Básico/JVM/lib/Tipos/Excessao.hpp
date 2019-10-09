#ifndef TIPOS_EXCESSAO_HPP
    #define TIPOS_EXCESSAO_HPP

    #include "Basicos.hpp"
    #include "../Interfaces/InterTabela.hpp"

    class Excessao{
        private:
            u2 lin_comeco = 0;
            u2 lin_final = 0;
            u2 lin_tratamento = 0;
            u2 ind_tipo_catch = 0;

        public:
            Excessao(){};

            void decodificar (FILE *arq);

            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs);
    };

#endif
