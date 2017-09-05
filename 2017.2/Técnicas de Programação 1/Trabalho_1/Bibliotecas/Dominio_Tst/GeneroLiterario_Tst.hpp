#ifndef GENERO_LITERARIO_TST_H
    #define GENERO_LITERARIO_TST_H

    /**
     *  @file   GeneroLiterario_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../Dominio/GeneroLiterario.hpp"

    /**
     *  @class GeneroLiterarioTst
     *  Responsável por testar diversos cenários da classe
     *  Gênero Literário, a fim de garantir um correto funcionamento
     */
    class GeneroLiterarioTst : public DominioBaseTst{
        private:
            /*  Etapas do teste */
            void inicializar() override;
            void validar() override;

            /*  Constantes de teste */
            const string VAL_REG[5] = {"EPOPEIA",
                                       "NOVELA",
                                       "CONTO",
                                       "ENSAIO",
                                       "ROMANCE"};
            const string INV[4] = {  "AVENTURA",
                                     "FICCAO",
                                     "FICÇÃO",
                                     "DRAMA"};
    };
#endif // GENERO_LITERARIO_H
