#ifndef APELIDO_TST_H
    #define APELIDO_TST_H

    /**
     *  @file   Apelido_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../Dominio/Apelido.hpp"

    /**
     *  @class ApelidoTst
     *  Responsável por testar diversos cenários da classe Apelido,
     *  a fim de garantir um correto funcionamento
     */
    class ApelidoTst : public DominioBaseTst{
        private:
            /*  Etapas do teste */
            void inicializar () override;
            void validar () override;

            /*  Constantes de testes    */
            const string VAL_LIM_LETRAS   = "abcde";
            const string VAL_MENOS_LETRAS = "ABCD";
            const string INV_LIM_NUM      = "12345";
            const string INV_ALFANUM      = "abc2";
            const string INV_ALFA_SIMB    = "!!asC";
    };
#endif // APELIDO_TST_H
