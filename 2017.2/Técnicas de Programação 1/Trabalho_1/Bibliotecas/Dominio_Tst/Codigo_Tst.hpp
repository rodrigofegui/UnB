#ifndef CODIGO_TST_H
    #define CODIGO_TST_H

    /**
     *  @file   Codigo_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */

     #include "../Dominio/Codigo.hpp"
     #include "../TesteClasse.hpp"

    /**
     *  @class  CodigoTst
     *  Responsável por testar diversos cenários da
     *  classe Codigo, a fim de garantir um correto
     *  funcionamento
     */
    class CodigoTst : public TesteClasse{
        private:
            /*  Corpo de teste */
            Codigo *codigo;

            /*  Etapas do teste */
            void inicializar() override;
            void validar() override;
            void finalizar() override;

            /*  Validações unitárias */
            void validarCampoOk (string campo);
            void validarCampoNOk (string campo);

            const string VALIDO_MAX = "01234";
            const string INVALIDO_LIM = "0123456";
            const string INVALIDO_MENOS = "0124";
            const string INVALIDO_LETRA = "0as12";
    };
#endif // CODIGO_TST_H
