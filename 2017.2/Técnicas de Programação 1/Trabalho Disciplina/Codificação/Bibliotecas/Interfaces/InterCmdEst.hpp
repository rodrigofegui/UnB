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
			Apelido *apelido = nullptr;

        public:
			/**
			 *  Atribuição do apelido do comando
			 *  @param Apelido a ser atribuído
			 */
			void setApelido (Apelido *);

			/**
			 *  Recuperar o valor atribuído ao apelido do Comando
			 *  @return Login armazenado no Resultado
			 */
			Apelido * getApelido () const;

            /**
             *  Realização do comando, garantindo a
             *  integridade da aplicação
             */
            virtual Resultado executar() = 0;
    };

	/*  Definição dos métodos 'Get' */
	inline Apelido* InterCmdEst::getApelido () const {return this->apelido;}

	/*  Definição dos métodos 'Set' */
	inline void InterCmdEst::setApelido (Apelido *apelido) {this->apelido = apelido;}
#endif //INTER_CMD_ESTANTE_HPP
