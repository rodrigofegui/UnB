#ifndef APRES_CTRL_EST_CMD_RMV_HPP
    #define APRES_CTRL_EST_CMD_RMV_HPP

    /**
     *  @file   ACmdRemover.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterCmdEst.hpp"
    #include "../../Dominio/Titulo.hpp"

    /**
     *  @class  ACmdRemover
     *  Responsável pelo comando de remoção de
     *  um exemplar de livro na estante
     */
    class ACmdRemover : public TUI, public InterCmdEst{
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
            ACmdRemover(){};

			/**
			 *	Construtor do comando de remoção de livro,
			 *	conhecendo-se a camada de serviço
			 *	@param Camada de serviço requisitada
			 */
            ACmdRemover (InterSEst *);
            /*  Herdada de InterCmdEst */
            Resultado executar();
    };
#endif // APRES_CTRL_EST_CMD_RMV_HPP
