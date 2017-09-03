#ifndef APELIDO_TST_HPP
    #define APELIDO_TST_HPP

    /**
     *  @file   Apelido_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include "../Dominio/Apelido.hpp"
    #include "../TesteClasse.hpp"


    /**
     *  @class ApelidoTst
     *  Responsável por testar diversos cenários da classe Apelido,
     *  a fim de garantir um correto funcionamento
     */
    class ApelidoTst : public TesteClasse{
        private:
            /*  Corpo de teste */
            Apelido *apelido;

            /*  Validações unitárias */
            void inicializar () override;
            void finalizar () override;
            void validar () override;
            void validarCampo(string campo, bool cond);
            void validarCampoOk (string campo);
            void validarCampoNOk (string campo);

            /*  Constantes de testes    */
            const string CORRETO_LIM_LETRAS = "abcde";
            const string CORRETO_MENOS_LETRAS = "ABCD";
            const string ERRADO_LIM_NUM = "12345";
            const string ERRADO_ALFANUM = "abc2";
            const string ERRADO_ALFA_SIMB = "!!asC";
    };
#endif // APELIDO_TST_HPP
