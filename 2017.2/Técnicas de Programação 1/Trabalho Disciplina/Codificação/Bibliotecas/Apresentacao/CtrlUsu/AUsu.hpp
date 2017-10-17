#ifndef APRES_CTRL_USU_HPP
    #define APRES_CTRL_USU_HPP

    /**
     *  @file   AUsu.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterFunc.hpp"
    #include "../../Interfaces/InterSUsu.hpp"
	#include "../../Utilidades/Mensagem.hpp"

    /**
     *  @class  AUsu
     *  Controladora da funcionalidade de Usuário
     *  de usuário à estante virtual.
     */
    class AUsu : public TUI, public InterFunc{
        private:
            Apelido     apelido;
            Usuario     *usuario = nullptr;
            InterSUsu   *servico = nullptr;

            /*  Métodos herdados */
            Resultado direcionar (const Resultado &);
            Resultado leitura ();
            Resultado tratarErro ();
            Resultado tratarErro (const Resultado &);
			void finalizar ();

			/*	Avaliação do Resultado */
			Resultado avaliarCond ();

        protected:
            /** Apresentação das opções ao usuário
             *  da aplicação da estante */
            void menu ();

        public:
            AUsu (){};
            Resultado executar ();
            Resultado executar (const Resultado &){};
            void setServico (InterSAut *){};
            void setServico (InterSUsu *);
            void setServico (InterSEst *){};
    };

    /*  Definição dos métodos 'Set' */
    inline void AUsu::setServico (InterSUsu *servico) {this->servico = servico;}
#endif // APRES_CTRL_USU_HPP
