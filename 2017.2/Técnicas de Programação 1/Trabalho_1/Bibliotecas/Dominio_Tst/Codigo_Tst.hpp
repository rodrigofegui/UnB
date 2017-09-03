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

            const string valido_Max = "01234";
            const string invalido_Limite = "0123456";
            const string invalido_Menos = "0124";
            const string invalido_Letra = "0as12";
    };
#endif // CODIGO_TST_H
