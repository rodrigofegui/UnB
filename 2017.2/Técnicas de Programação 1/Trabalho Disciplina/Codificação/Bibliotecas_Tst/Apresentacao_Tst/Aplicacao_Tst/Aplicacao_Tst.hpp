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
			const static string MSG_TELA;

            /*  Métodos herdados */
            void menu () override;

            /*  Direcionamento para a funcionalidade */
            Resultado autenticar () override;
            Resultado usuario () override;
            Resultado estante (const Resultado &) override;
    };
#endif // APRES_APP_APLICACAO_TST_HPP
