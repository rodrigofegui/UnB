#ifndef APRES_CTRL_EST_CMD_CON_INC_HPP
    #define APRES_CTRL_EST_CMD_CON_INC_HPP

    /**
     *  @file   ACmdIncluir.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterCmdEst.hpp"
    #include "../../Entidade/Livro.hpp"

    /**
     *  @class  ACmdIncluir
     *  Responsável pelo comando de consulta de
     *  livro na estante
     */
    class ACmdIncluir : public TUI, public InterCmdEst{
        private:
            /*  Herdados da TUI */
            Resultado leitura ();
            Resultado direcionar (const Resultado &);
            Resultado tratarErro ();
            Resultado tratarErro (const Resultado &);
            void finalizar();
            void menu ();

            /*  Mensagens padrão */
            const static string MSG_INICIO;
            const static string MSG_FINALIZAR;
            const static string MSG_LER_TIT;
            const static string MSG_LER_AUT;
            const static string MSG_LER_GEN;
            const static string MSG_LER_DAT;
            const static string MSG_ERRO_D;

        public:
            /**
             *  Construtor padrão
             */
            ACmdIncluir(){};

            ACmdIncluir (InterSEst *);
            /*  Herdada de InterCmdEst */
            Resultado executar();
    };
#endif // APRES_CTRL_EST_CMD_CON_INC_HPP
