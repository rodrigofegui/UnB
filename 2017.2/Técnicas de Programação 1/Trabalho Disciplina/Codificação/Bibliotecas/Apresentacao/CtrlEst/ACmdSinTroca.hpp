#ifndef APRES_CTRL_EST_CMD_SIN_TROCA_HPP
    #define APRES_CTRL_EST_CMD_SIN_TROCA_HPP

    /**
     *  @file   ACmdSinTroca.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../TUI.hpp"
    #include "../../Interfaces/InterCmdEst.hpp"
    #include "../../Dominio/Titulo.hpp"
	#include "../../Entidade/Usuario.hpp"

    /**
     *  @class  ACmdSinTroca
     *  Responsável pelo comando de sinalização da
     *  disponibilidade ou não para troca de
     *  livro na estante
     */
    class ACmdSinTroca : public TUI, public InterCmdEst{
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
			const static string MSG_LER_DIS;
            const static string MSG_ERRO_D;

        public:
            /**
             *  Construtor padrão
             */
            ACmdSinTroca(){};

			/**
			 *	Construtor do comando de consulta de livro,
			 *	conhecendo-se a camada de serviço
			 *	@param Camada de serviço requisitada
			 */
            ACmdSinTroca (InterSEst *);

			/**
			 *	Construtor do comando de consulta de livro,
			 *	conhecendo-se a camada de serviço e seu
			 *	apelido
			 *	@param Camada de serviço requisitada
			 *	@param @param Apelido a ser atribuído
			 */
            ACmdSinTroca (InterSEst *, Apelido *);

            /*  Herdada de InterCmdEst */
            Resultado executar();
    };
#endif // APRES_CTRL_EST_CMD_SIN_TROCA_HPP
