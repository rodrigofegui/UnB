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

        public:
            /**
             *  Construtor padrão
             */
            ACmdIncluir(){};

			/**
			 *	Construtor do comando de inserção de livro,
			 *	conhecendo-se a camada de serviço
			 *	@param Camada de serviço requisitada
			 */
            ACmdIncluir (InterSEst *);
            /*  Herdada de InterCmdEst */
            Resultado executar();
    };
#endif // APRES_CTRL_EST_CMD_CON_INC_HPP
