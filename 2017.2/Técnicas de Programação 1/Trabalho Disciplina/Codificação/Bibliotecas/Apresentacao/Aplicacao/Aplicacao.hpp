#ifndef APRES_APP_APLICACAO_HPP
    #define APRES_APP_APLICACAO_HPP

    /**
     *  @file   Aplicacao.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterFunc.hpp"

    /**
     *  @class  Aplicacao
     *  Controladora geral da aplicação:
     *  estante de livros. Linkando, a nível macro,
     *  as funcionalidades principais do sistema.
     */
    class Aplicacao : public TUI{
        private:
			/*	Mensagem padrao */
			const static string MSG_FINALIZAR;
			const static string MSG_AGD_LEITURA;
			const static string MSG_ESC_INV;

            /*  Constantes de trabalho */
            const static int AUTENTICAR = 1;
            const static int CADASTRAR  = 2;
            const static int SAIR       = 0;

            /*  Arquivo de Log */
            //Log arqLog;
            /*  Funcionalidade a ser trabalhada */
            InterFunc *func;

            /*  Métodos herdados */
            Resultado direcionar (const Resultado &);
            Resultado leitura ();
            Resultado tratarErro ();
            Resultado tratarErro (const Resultado &);
			void finalizar ();

        protected:
			/**	Mensagem padrão */
			const static string MSG_ESC_AUT;
			const static string MSG_ESC_USU;
			const static string MSG_ESC_EST;

            /*  Direcionamento para a funcionalidade */
            virtual Resultado autenticar ();
            virtual Resultado usuario ();
            virtual Resultado estante ();

            /*  Métodos herdados */
            void menu ();
    };

#endif // APRES_APP_APLICACAO_HPP
