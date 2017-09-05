#ifndef NOME_TST_H
    #define NOME_TST_H

    /**
     *  @file   Nome_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../Dominio/Nome.hpp"

    /**
     *  @class  NomeTst
     *  Responsável por testar diversos cenários da classe Nome,
     *  a fim de garantir um correto funcionamento
     */
    class NomeTst : public DominioBaseTst{
        private:
            /*  Etapas do teste */
            void inicializar() override;
            void validar() override;

            /*  Constantes de teste */
            const string VAL[3]      ={"Rodrigo FErrei.",
                                       "Rodrigo F. G.",
                                       "Rodrigo.F.G"};
            const string INV_NUM     = "r0dr1g0";
            const string INV_SIMB    = "rodrigo@fgui";
            const string INV_TAM     = "Rodrigo Ferreira";
            const string INV_2_SPACE = "RODRIGO  FG";
            const string INV_2_PONTO = "RODRIGO..FG";
    };
#endif // NOME_TST_H
