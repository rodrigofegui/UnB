#ifndef APRES_CTRL_EST_CMD_CON_L_HPP
    #define APRES_CTRL_EST_CMD_CON_L_HPP

    /**
     *  @file   ACmdConLivro.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterCmdEst.hpp"
    #include "../../Dominio/Titulo.hpp"
    #include "../../Entidade/Livro.hpp"

    /**
     *  @class  ACmdConLivro
     *  Responsável pelo comando de consulta de
     *  livro na estante
     */
    class ACmdConLivro : public TUI, public InterCmdEst{
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
            ACmdConLivro(){};

			/**
			 *	Construtor do comando de consulta de livro,
			 *	conhecendo-se a camada de serviço
			 *	@param Camada de serviço requisitada
			 */
            ACmdConLivro (InterSEst *);
            /*  Herdada de InterCmdEst */
            Resultado executar();
    };
#endif // APRES_CTRL_EST_CMD_CON_L_HPP
