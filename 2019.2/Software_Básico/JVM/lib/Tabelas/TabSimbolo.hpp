#ifndef TABELA_SIMBOLO_HPP
    #define TABELA_SIMBOLO_HPP

    /**
     *  @file   TabSimbolo.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <stdlib.h>
    #include "../Interfaces/InterTabela.hpp"
    #include "../Uteis/Flags_Tags.hpp"
    #include "../Tipos/Basicos.hpp"
    #include "../Tipos/CPInfo.hpp"

    class TabSimbolo : public InterTabela {
        private:
            std::vector<CPInfo> registros;

        public:
            TabSimbolo (){};
            explicit TabSimbolo (u2 *tam): InterTabela(tam) {};

            void decodificar(FILE *arq) override;

            void exibir(int qnt_tab) override;

            void deletar() override;
    };
#endif
