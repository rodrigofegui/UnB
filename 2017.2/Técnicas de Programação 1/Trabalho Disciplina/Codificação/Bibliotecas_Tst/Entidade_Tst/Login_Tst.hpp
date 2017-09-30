#ifndef LOGIN_TST_HPP
    #define LOGIN_TST_HPP

    /**
     *  @file   Login_Tst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TesteClasse.hpp"
    #include "../../Bibliotecas/Entidade/Login.hpp"

    /**
     *  @class LoginTst
     *  Responsável por testar a classe Login,
     *  a fim de garantir um correto funcionamento
     */
    class LoginTst : public TesteClasse{
        private:
            /* Corpo de Teste */
            Login *login;

            /*  Etapas do teste */
            void inicializar () override;
            void validar () override;
            void finalizar () override;

            /*  Validações unitárias */
            void validarApelido ();
            void validarSenha ();

            /*  Constantes de teste */
            Apelido apelido;
            Senha   senha;
    };
#endif // LOGIN_TST_HPP
