#ifndef TELEFONE_TST_H
    #define TELEFONE_TST_H

    /**
     *  @file   Telefone_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../../Bibliotecas/Dominio/Telefone.hpp"

    /**
     *  @class  TelefoneTst
     *  Responsável por testar diversos cenários da class Telefone,
     *  a fim de garantir um correto funcionamento
     */
    class TelefoneTst : public DominioBaseTst{
        private:
            /*  Etapas de teste */
            void inicializar() override;
            void validar() override;

            /*  Constantes de teste */
            const string VAL         =  "(61)-123456789";
            const string INV_TAM     =  "61123456789";
            const string INV_NUM     =  "(61)-12E4S6789";
            const string INV_FRMT[3] = {"61-12345678912",
                                        "(61)1234567890",
                                        "61 12345678901"};
    };
#endif // TELEFONE_TST_H
