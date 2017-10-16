#ifndef APRES_CTRL_EST_CMD_CRI_RESENHA_HPP
    #define APRES_CTRL_EST_CMD_CRI_RESENHA_HPP

    /**
     *  @file   ACmdCriarResenha.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterCmdEst.hpp"
    #include "../../Entidade/Resenha.hpp"

    /**
     *  @class  ACmdCriarResenha
     *  Responsável pelo comando de criar uma resenha
     *  na estante
     */
    class ACmdCriarResenha : public TUI, public InterCmdEst{
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
            const static string MSG_LER_TXT;
            const static string MSG_LER_TIT;
            const static string MSG_ERRO_D;

        public:
            /**
             *  Construtor padrão
             */
            ACmdCriarResenha(){};

            ACmdCriarResenha (InterSEst *);
            /*  Herdada de InterCmdEst */
            Resultado executar();
    };
#endif //APRES_CTRL_EST_CMD_CRI_RESENHA_HPP
