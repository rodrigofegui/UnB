#ifndef APRES_CTRL_EST_CMD_CON_U_HPP
    #define APRES_CTRL_EST_CMD_CON_U_HPP

    /**
     *  @file   ACmdConUsuario.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterCmdEst.hpp"
    #include "../../Entidade/Usuario.hpp"

    /**
     *  @class  ACmdConUsuario
     *  Responsável pelo comando de consulta de
     *  usuario na estante
     */
    class ACmdConUsuario : public TUI, public InterCmdEst{
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
            const static string MSG_LER_APE;
            const static string MSG_ERRO_D;

        public:
            /**
             *  Construtor padrão
             */
            ACmdConUsuario(){};

			/**
			 *	Construtor do comando de consulta de usuário,
			 *	conhecendo-se a camada de serviço
			 *	@param Camada de serviço requisitada
			 */
            ACmdConUsuario (InterSEst *);
            /*  Herdada de InterCmdEst */
            Resultado executar();
    };
#endif // APRES_CTRL_EST_CMD_CON_U_HPP
