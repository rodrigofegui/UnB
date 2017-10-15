#ifndef INTER_CMD_ESTANTE_HPP
	#define INTER_CMD_ESTANTE_HPP

	/**
	 *  @file   InterCmdEst.hpp
	 *  @author Rodrigo F. Guimarães
     */
    #include "InterSEst.hpp"
    #include "../Entidade/Log.hpp"
    #include "../Entidade/Resultado.hpp"

    /**
     *  @class  InterCmdEst
     *  Protocolo de realização dos comandos da
     *  funcionalidade da Estante
     */
    class InterCmdEst{
        protected:
            /**  Camada de serviço a ser executada */
            InterSEst *servico;

        public:
            /**
             *  Realização do comando, garantindo a
             *  integridade da aplicação
             */
            virtual Resultado executar() = 0;
    };
#endif //INTER_CMD_ESTANTE_HPP
