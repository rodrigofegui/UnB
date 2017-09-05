#ifndef DATA_TST_H
    #define DATA_TST_H

    /**
     *  @file   Data_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../Dominio/Data.hpp"

    /**
     *  @class DataTst
     *  Responsável por testar diversos cenários da classe Data,
     *  a fim de garantir um correto funcionamento
     */
    class DataTst : public DominioBaseTst{
        private:
            /*  Etapas do teste */
            void inicializar () override;
            void validar () override;

            /*  Constantes de teste */
            const string VAL_0      = "24/12/94";
            const string VAL_1      = "29/02/96";
            const string VAL_2      = "30/08/17";
            const string INV_DIA_0  = "00/12/94";
            const string INV_DIA_1  = "42/24/94";
            const string INV_MES_0  = "24/00/94";
            const string INV_MES_1  = "24/42/94";
            const string INV_ANO_0  = "24/12/xx";
            const string INV_FORM_0 = "241294";
            const string INV_FORM_1 = "24/12/1994";
            const string INV_FORM_2 = "24/12199";
            const string INV_FORM_3 = "xx/xx/xx";
            const string INV_DATA_0 = "31/09/17";
            const string INV_DATA_1 = "29/02/17";
            const string INV_DATA_2 = "31/06/17";
            const string INV_DATA_3 = "31/04/94";
    };
#endif // DATA_TST_H
