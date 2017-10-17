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

        public:
            /**
             *  Construtor padrão
             */
            ACmdCriarResenha(){};

			/**
			 *	Construtor do comando de criar resenha, conhecendo-se
			 *	a camada de serviço
			 *	@param Camada de serviço requisitada
			 */
            ACmdCriarResenha (InterSEst *);
            /*  Herdada de InterCmdEst */
            Resultado executar();
    };
#endif //APRES_CTRL_EST_CMD_CRI_RESENHA_HPP
