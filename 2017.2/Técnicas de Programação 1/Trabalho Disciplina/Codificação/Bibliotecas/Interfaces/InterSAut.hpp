#ifndef INTER_SERV_AUT_HPP
    #define INTER_SERV_AUT_HPP

    /**
     *  @file   InterSAut.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Entidade/Log.hpp"
    #include "../Entidade/Login.hpp"
    #include "../Entidade/Resultado.hpp"
	#include "../Utilidades/Mensagem.hpp"

    /**
     *  @class InterSAut
     *  Protocolo de comunicação entre a camada de
     *  Apresentação e de Serviço, para a funcionalidade de Autenticação.
     */
    class InterSAut{
        public:
            /**
             *  Autenticar login de usuário, conforme
             *  registro na Base de Dados.
             *  @param Login a ser autenticado
             *  @return Resultado da operação
             */
            virtual Resultado autenticar (const Login &) throw (runtime_error) = 0;
    };
#endif // INTER_SERV_AUT_HPP
