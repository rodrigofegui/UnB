#ifndef APRES_CTRL_AUT_HPP
    #define APRES_CTRL_AUT_HPP

    /**
     *  @file   AAut.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterFunc.hpp"
    #include "../../Interfaces/InterSAut.hpp"
	#include "../../Utilidades/Mensagem.hpp"

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

			/*	Avaliação do Resultado */
			Resultado avaliarCond ();

        protected:
            /** Sinalização do término da Autenticação */
            const static string MSG_FINALIZAR;
            /** Sinalização do êxito ao ler o Apelido */
            const static string MSG_LER_APE;
            /** Sinalização do êxito ao ler a Senha */
            const static string MSG_LER_SEN;
            /** Sinalização de erro dúbios */
            const static string MSG_ERRO_D;

            /** Apresentação das opções ao usuário
             *  da aplicação da estante */
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
