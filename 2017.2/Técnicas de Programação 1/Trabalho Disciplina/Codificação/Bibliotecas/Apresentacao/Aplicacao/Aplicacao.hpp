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
			const static string MSG_TELA;
			const static string MSG_AGD_LEITURA;
			const static string MSG_ESC_INV;

            /*  Constantes de trabalho */
            const static int AUTENTICAR = 1;
            const static int CADASTRAR  = 2;
            const static int SAIR       = 0;

            /*  Métodos herdados */
            Resultado direcionar (const Resultado &);
            Resultado leitura ();
            Resultado tratarErro ();
            Resultado tratarErro (const Resultado &);
			void finalizar ();

        protected:
			/** Sinalização do redirecionamento para a Autenticação */
			const static string MSG_ESC_AUT;
			/** Sinalização do redirecionamento para o Usuário */
			const static string MSG_ESC_USU;
			/** Sinalização do redirecionamento para a Estante Virtual */
			const static string MSG_ESC_EST;

			/** Funcionalidade a ser executada */
            InterFunc *func = nullptr;

            /** Direcionamento para a funcionalidade de Autenticação */
            virtual Resultado autenticar ();
            /** Direcionamento para a funcionalidade de Usuário */
            virtual Resultado usuario ();
            /** Direcionamento para a funcionalidade da Estante */
            virtual Resultado estante (const Resultado &);

            /** Apresentação das opções ao usuário
             *  da aplicação da estante */
            void menu ();
    };

#endif // APRES_APP_APLICACAO_HPP
