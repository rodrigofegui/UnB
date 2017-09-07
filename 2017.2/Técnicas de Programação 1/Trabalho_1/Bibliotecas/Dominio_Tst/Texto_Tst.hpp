#ifndef TEXTO_TST_H
    #define TEXTO_TST_H

    /**
     *  @file   Texto_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../Dominio/Texto.hpp"

    /**
     *  @class  TextoTst
     *  Responsável por testar diversos cenários da classe Texto,
     *  a fim de garantir um correto funcionamento
     */
    class TextoTst : public DominioBaseTst{
        private:
            /*  Etapas de teste */
            void inicializar () override;
            void validar () override;

            /*  Constantes de teste */
            const string VAL_MENOS = "Programador testando o seu código!";
            const string VAL_LIM   = "Lorem ipsum dolor sit amet, consectetur";
            const string INV_LIM   = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    };
#endif // TEXTO_TST_H
