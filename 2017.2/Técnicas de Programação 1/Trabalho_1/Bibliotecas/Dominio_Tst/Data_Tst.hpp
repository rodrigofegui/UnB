#ifndef DATA_TST_H
    #define DATA_TST_H

    /**
     *  @file   Data_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/Data.hpp"
    #include "../TesteClasse.hpp"

    /**
     *  @class DataTst
     *  Responsável por testar diversos cenários da classe Data,
     *  a fim de garantir um correto funcionamento
     */
    class DataTst : public TesteClasse{
        private:
            /*  Corpo de Teste */
            Data *data;

            /*  Etapas do teste */
            void inicializar () override;
            void validar () override;
            void finalizar () override;

            /*  Validações unitárias */
            void validarCampoOk (string campo);
            void validarCampoNOk (string campo);

            /*  Dados de prova */
            const string VALIDO_0 = "24/12/94";
            const string VALIDO_1 = "29/02/96";
            const string VALIDO_2 = "30/08/17";
            const string INVALIDO_DIA_0 = "00/12/94";
            const string INVALIDO_DIA_1 = "42/24/94";
            const string INVALIDO_MES_0 = "24/00/94";
            const string INVALIDO_MES_1 = "24/42/94";
            const string INVALIDO_ANO_0 = "24/12/xx";
            const string INVALIDO_FORM_0 = "241294";
            const string INVALIDO_FORM_1 = "24/12/1994";
            const string INVALIDO_FORM_2 = "24/12199";
            const string INVALIDO_FORM_3 = "xx/xx/xx";
            const string INVALIDO_DATA_0 = "31/09/17";
            const string INVALIDO_DATA_1 = "29/02/17";
            const string INVALIDO_DATA_2 = "31/06/17";
    };
#endif // DATA_TST_H
