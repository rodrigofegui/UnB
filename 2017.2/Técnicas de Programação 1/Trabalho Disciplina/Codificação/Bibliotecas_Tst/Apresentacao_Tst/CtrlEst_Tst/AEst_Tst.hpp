#ifndef APRES_CTRL_EST_TST_HPP
    #define APRES_CTRL_EST_TST_HPP

    /**
     *  @file   AEst_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../../../Bibliotecas/Apresentacao/CtrlEst/AEst.hpp"

    /**
     *  @class  AEstTst
     *  Responsável por testar a funcionalidade de Usuário,
     *  a fim de garantir um correto funcionamento
     */
    class AEstTst : public AEst{
        private:
            void menu() override;

        public:
            AEstTst (){};
    };
#endif // APRES_CTRL_EST_TST_HPP
