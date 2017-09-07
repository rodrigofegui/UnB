#ifndef TITULO_TST_H
    #define TITULO_TST_H

    /**
     *  @file   Titulo_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase_Tst.hpp"
    #include "../Dominio/Titulo.hpp"

    /**
     *  @class  TituloTst
     *  Responsável por testar diversos cenários da classe Titulo,
     *  a fim de garantir um correto funcionamento
     */
    class TituloTst : public DominioBaseTst{
        private:
            /*  Etapas de teste */
            void inicializar () override;
            void validar () override;

            /*  Constantes de testes */
            const string VAL_LIM = "Lorem ipsum dolor s";
            const string VAL_ACT = "áéíóãõâêç";
            const string VAL_SIM = "Texto válido!! C ct";
            const string INV_LIM = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
            const string INV_2_SPACE = "Texto  inválido";
    };
#endif // TITULO_TST_H
