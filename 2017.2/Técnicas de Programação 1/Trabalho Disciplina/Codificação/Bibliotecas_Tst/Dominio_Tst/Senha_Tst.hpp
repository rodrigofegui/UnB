#ifndef SENHA_TST_H
    #define SENHA_TST_H

    /**
     *  @file   Senha_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../../Bibliotecas/Dominio/Senha.hpp"

    /**
     *  @class  SenhaTst
     *  Responsável por testar diversos cenários da class Senha,
     *  a fim de garantir um correto funcionamento
     */
    class SenhaTst : public DominioBaseTst{
        private:
            /*  Etapas do teste */
            void inicializar() override;
            void validar() override;

            /*  Constantes de teste */
            const string INV_TAM = "ABCDEF";
            const string INV_NUM = "0I2E";
            const string INV_REP[2] = {"AABB",
                                       "aBcA"};
            const string INV_SIM = "@bcd";
            const string VAL[3] = {"abcd",
                                   "aBcD",
                                   "ABCD"};
    };
#endif // SENHA_TST_H
