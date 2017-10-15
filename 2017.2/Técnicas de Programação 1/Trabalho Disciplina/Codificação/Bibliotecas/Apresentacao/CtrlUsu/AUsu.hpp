#ifndef APRES_CTRL_USU_HPP
    #define APRES_CTRL_USU_HPP

    /**
     *  @file   AUsu.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterFunc.hpp"
    #include "../../Interfaces/InterSUsu.hpp"

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
            /** Sinalização do início do manuseio do Usuário */
            const static string MSG_INICIO;
            /** Sinalização do término da Autenticação */
            const static string MSG_FINALIZAR;
            /** Sinalização do êxito ao ler o Apelido */
            const static string MSG_LER_APE;
            /** Sinalização do êxito ao ler o Nome */
            const static string MSG_LER_NOM;
            /** Sinalização do êxito ao ler a Senha */
            const static string MSG_LER_SEN;
            /** Sinalização do êxito ao ler o Telefone */
            const static string MSG_LER_TEL;
            /** Sinalização de erro na Base de Dados */
            const static string MSG_ERRO;
            /** Sinalização de erro dúbios */
            const static string MSG_ERRO_D;

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
