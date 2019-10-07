#ifndef TABELA_SIMBOLO_HPP
    #define TABELA_SIMBOLO_HPP

    /**
     *  @file   TabSimbolo.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <string>
    #include <stdlib.h>
    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/Basicos.hpp"
    #include "../Tipos/CPInfo.hpp"

    class TabSimbolo : public InterTabela {
        private:
            std::vector<CPInfo> registros;

        public:
            TabSimbolo (){};

            explicit TabSimbolo (u2 *tam): InterTabela(tam) {};

            void decodificar (FILE *arq) override;

            void exibir (u1 qnt_tabs) override;

            void exibir (InterTabela *tab_simbolos, u1 qnt_tabs) override {};

            std::string get_nome (u2 ind_name);

            void deletar () override;
    };
#endif
