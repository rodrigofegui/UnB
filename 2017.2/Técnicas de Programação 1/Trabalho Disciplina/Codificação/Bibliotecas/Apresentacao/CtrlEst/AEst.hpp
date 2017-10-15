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
            const static int CRIAR_RES   = 3;
            const static int INC_LIVRO   = 4;
            const static int RMV_LIVRO   = 5;
            const static int SAIR        = 0;

            /*  Mensagens padrão */
            const static string MSG_INI;
            const static string MSG_LER;
            const static string MSG_ESC_INV;
            const static string MSG_FINALIZAR;

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

            /** Sinalização de erro dúbios */
            const static string MSG_ERRO_D;

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
