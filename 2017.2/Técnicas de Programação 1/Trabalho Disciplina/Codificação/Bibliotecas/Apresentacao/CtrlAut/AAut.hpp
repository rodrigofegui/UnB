#ifndef APRES_CTRL_AUT_HPP
    #define APRES_CTRL_AUT_HPP

    /**
     *  @file   AAut.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterFunc.hpp"
    #include "../../Interfaces/InterSAut.hpp"
    #include "../../Entidade/Login.hpp"

    /**
     *  @class  AAut
     *  Controladora da funcionalidade de Autenticação
     *  de usuário à estante virtual.
     */
    class AAut : public TUI, public InterFunc{
        private:
            Apelido     apelido;
            Login       *login = nullptr;
            InterSAut   *servico = nullptr;

            /*  Métodos herdados */
            Resultado direcionar (const Resultado &);
            Resultado leitura ();
            Resultado tratarErro ();
            Resultado tratarErro (const Resultado &);
			void finalizar ();

        protected:
            /*  Mensagens padrão */
            const static string MSG_INICIO;
            const static string MSG_FINALIZAR;
            const static string MSG_LER_APE;
            const static string MSG_LER_SEN;
            const static string MSG_ERRO;
            const static string MSG_ERRO_D;

            /*  Métodos herdados */
            void menu ();

        public:
            AAut (){};
            Resultado executar ();
            Resultado executar (const Resultado &){};
            void setServico (InterSAut *);
            void setServico (InterSUsu *){};
            void setServico (InterSEst *){};
    };

    /*  Definição dos métodos 'Set' */
    inline void AAut::setServico (InterSAut *servico) {this->servico = servico;}
#endif // APRES_CTRL_AUT_HPP
