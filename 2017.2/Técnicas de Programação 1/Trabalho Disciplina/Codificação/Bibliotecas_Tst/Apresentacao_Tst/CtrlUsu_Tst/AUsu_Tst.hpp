#ifndef APRES_CTRL_USU_TST_HPP
    #define APRES_CTRL_USU_TST_HPP

    /**
     *  @file   AUsu_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../../../Bibliotecas/Apresentacao/CtrlUsu/AUsu.hpp"

    /**
     *  @class  AUsuTst
     *  Responsável por testar a funcionalidade de Usuário,
     *  a fim de garantir um correto funcionamento
     */
    class AUsuTst : public AUsu{
        private:
			/*  Controle das telas */
            static bool apresentou;

            /*  Métodos herdados */
            void menu () override;

        public:
            AUsuTst(){};
    };
#endif // APRES_CTRL_USU_TST_HPP
