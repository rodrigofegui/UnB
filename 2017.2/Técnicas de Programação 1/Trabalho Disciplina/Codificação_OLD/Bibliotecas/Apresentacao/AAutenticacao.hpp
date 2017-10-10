#ifndef APRES_AUTENTICACAO_HPP
    #define APRES_AUTENTICACAO_HPP

    /**
     *  @file   AAutenticacao.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "ApreTUI.hpp"
    #include "../Entidade/Login.hpp"

    /**
     *  @class  AAutenticacao
     *
     */
    class AAutenticacao : public ApreTUI{
        private:
            Apelido apelido;
            Senha senha;

            void menu () override;
            void criar () override;
            OpResult configurar () throw (invalid_argument) override;
            //void servico (const OpResult &controle) override;
            void erroOp (string opCode) override;

        protected:
            /*  Login que será autenticado */
            Login *login;
    };
#endif // APRES_AUTENTICACAO_HPP
