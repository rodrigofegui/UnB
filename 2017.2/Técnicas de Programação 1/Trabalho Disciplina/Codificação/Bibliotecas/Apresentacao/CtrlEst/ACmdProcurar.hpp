#ifndef APRES_CTRL_EST_CMD_PRO_HPP
    #define APRES_CTRL_EST_CMD_PRO_HPP

    /**
     *  @file   ACmdProcurar.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterCmdEst.hpp"
    #include "../../Dominio/Titulo.hpp"
    #include "../../Entidade/Usuario.hpp"

    /**
     *  @class  ACmdProcurar
     *  Responsável pelo comando de procura por
     *  trocas de livro na estante
     */
    class ACmdProcurar : public TUI, public InterCmdEst{
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
            ACmdProcurar(){};

			/**
			 *	Construtor do comando de consulta de livro,
			 *	conhecendo-se a camada de serviço
			 *	@param Camada de serviço requisitada
			 */
            ACmdProcurar (InterSEst *);

            /*  Herdada de InterCmdEst */
            Resultado executar();
    };
#endif // APRES_CTRL_EST_CMD_PRO_HPP
