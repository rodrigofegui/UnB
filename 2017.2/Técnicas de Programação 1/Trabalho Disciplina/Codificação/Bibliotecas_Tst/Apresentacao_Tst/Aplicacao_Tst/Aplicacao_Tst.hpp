#ifndef APRES_APP_APLICACAO_TST_HPP
    #define APRES_APP_APLICACAO_TST_HPP

    /**
     *  @file   Aplicacao_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../../../Bibliotecas/Apresentacao/Aplicacao/Aplicacao.hpp"

    /**
     *  @class  AplicacaoTst
     *  Responsável por testar a aplicação,
     *  a fim de garantir um correto funcionamento
     */
    class AplicacaoTst : public Aplicacao{
        private:
            /*  Controle das telas*/
            bool apresentou = false;

            /*  Métodos herdados */
            void menu () override;

            /*  Direcionamento para a funcionalidade */
            Resultado autenticar () override;
            Resultado usuario () override;
            Resultado estante () override;
    };
#endif // APRES_APP_APLICACAO_TST_HPP
