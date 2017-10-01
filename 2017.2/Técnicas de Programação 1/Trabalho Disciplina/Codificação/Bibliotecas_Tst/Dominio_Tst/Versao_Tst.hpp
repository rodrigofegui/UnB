#ifndef VERSAO_TST_HPP
    #define VERSAO_TST_HPP

    /**
     *  @file   Versao_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../../Bibliotecas/Dominio/Versao.hpp"

    /**
     *  @class  VersaoTst
     *  Responsável por testar diversos cenários da classe
     *  Versao, a fim de garantir um correto funcionamento
     */
    class VersaoTst : public DominioBaseTst{
        private:
            /*  Etapas do teste */
            void inicializar() override;
            void validar() override;

            /*  Constantes de teste */
            const string VAL_REG[2] = {"1.0",
                                       "Latest"};
            const string INV[3] = {  "Ver1.0",
                                     "Ver",
                                     "DRAMA"};
    };
#endif // VERSAO_TST_HPP
