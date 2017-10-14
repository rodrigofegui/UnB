#ifndef APRES_CTRL_AUT_TST_HPP
    #define APRES_CTRL_AUT_TST_HPP

    /**
     *  @file   AAut_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../../../Bibliotecas/Apresentacao/CtrlAut/AAut.hpp"

    /**
     *  @class AAutTst
     *  Responsável por testar a funcionalidade de Autenticação,
     *  a fim de garantir um correto funcionamento
     */
    class AAutTst : public AAut{
        private:
            /*  Controle das telas */
            bool apresentou = false;

            /*  Métodos herdados */
            void menu () override;

        public:
            AAutTst (){};
    };
#endif // APRES_CTRL_AUT_TST_HPP
