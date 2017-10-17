#ifndef APRES_CTRL_EST_HPP
    #define APRES_CTRL_EST_HPP

    /**
     *  @file   AEst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterFunc.hpp"
    #include "../../Interfaces/InterSEst.hpp"
    #include "../../Interfaces/InterCmdEst.hpp"
	#include "../../Utilidades/Mensagem.hpp"

    /**
     *  @class AEst
     *  Controladora da funcionalidade da Estante
     */
    class AEst : public TUI, public InterFunc{
        private:
            Apelido     *apelido = nullptr;

            /*  Constantes de trabalho */
            const static int CON_LIVRO   = 1;
            const static int CON_USUARIO = 2;
			const static int CON_TROCA   = 3;
            const static int CRIAR_RES   = 4;
            const static int INC_LIVRO   = 5;
            const static int RMV_LIVRO   = 6;
            const static int SIN_TROCA   = 7;
            const static int SAIR        = 0;

            /*  Métodos herdados */
            Resultado leitura ();
            Resultado direcionar (const Resultado &);
            Resultado tratarErro ();
            Resultado tratarErro (const Resultado &);
			void finalizar ();

			void setApelido (Apelido *);

        protected:
            /** Camada de serviço a ser executada */
            InterSEst   *servico = nullptr;
            /** Comando a ser executado */
            InterCmdEst *cmd     = nullptr;

            /** Apresentação das opções ao usuário
             *  da aplicação da estante */
            void menu ();

        public:
            AEst (){};
            Resultado executar (){};
            Resultado executar (const Resultado &);
            void setServico (InterSAut *){};
            void setServico (InterSUsu *){};
            void setServico (InterSEst *);
    };

    /*  Definição dos métodos 'Set' */
    inline void AEst::setApelido(Apelido *apelido) {this->apelido = apelido;}
    inline void AEst::setServico (InterSEst *servico) {this->servico = servico;}
#endif // APRES_CTRL_EST_HPP
