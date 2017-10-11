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

        protected:
            /*  Direcionamento para a funcionalidade */
            virtual Resultado autenticar ();
            virtual Resultado usuario ();
            virtual Resultado estante ();

            /*  Métodos herdados */
            void menu ();
    };

#endif // APRES_APP_APLICACAO_HPP
