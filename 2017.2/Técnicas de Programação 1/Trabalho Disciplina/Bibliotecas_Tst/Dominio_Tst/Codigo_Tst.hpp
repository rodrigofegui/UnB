#ifndef CODIGO_TST_H
    #define CODIGO_TST_H

    /**
     *  @file   Codigo_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../../Bibliotecas/Dominio/Codigo.hpp"

    /**
     *  @class  CodigoTst
     *  Responsável por testar diversos cenários da
     *  classe Codigo, a fim de garantir um correto
     *  funcionamento
     */
    class CodigoTst : public DominioBaseTst{
        private:
            /*  Etapas do teste */
            void inicializar() override;
            void validar() override;

            /*  Constantes de testes */
            const string VAL_MAX   = "01234";
            const string INV_LIM   = "0123456";
            const string INV_MENOS = "0124";
            const string INV_LETRA = "0as12";
    };
#endif // CODIGO_TST_H
