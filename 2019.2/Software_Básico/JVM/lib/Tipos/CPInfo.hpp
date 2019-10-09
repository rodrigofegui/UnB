#ifndef TIPOS_CP_INFO_HPP
    #define TIPOS_CP_INFO_HPP

    /**
     *  @file   CPInfo.h
     *  @author Rodrigo F. Guimarães
     */
    #include "Basicos.hpp"
    #include "../Interfaces/InterTabela.hpp"
    #include "../Interfaces/InterCPDados.hpp"

    class CPInfo{
        public:
            u1 tag = 0;
            InterCPDados *dados = nullptr;

            CPInfo (){};

            explicit CPInfo (u1 tag): tag(tag) {};

            void exibir (u1 qnt_tabs);

            void deletar ();
    };
#endif
