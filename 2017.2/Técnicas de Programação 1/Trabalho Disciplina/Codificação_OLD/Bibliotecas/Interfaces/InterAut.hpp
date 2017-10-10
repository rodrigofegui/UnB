#ifndef INTER_AUTENTICACAO_HPP
    #define INTER_AUTENTICACAO_HPP

    /**
     *  @file   InterAut.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "InterApresServ.hpp"
    #include "../Entidade/Login.hpp"
    #include "../Dominio/OpResult.hpp"

    /**
     *  @class  InterAut
     *  Protocolo de comunicação entre a camada de
     *  Apresentação e de Serviço, para a funcionalidade
     *  de Autenticação.
     */
    class InterAut : public InterApresServ{
        public:
            /**
             *  Autenticar login de usuário, conforme registro
             *  na Base de Dados
             *  @param login Login candidato
             */
            virtual OpResult autenticar (const Login &login){};
    };
#endif // INTER_AUTENTICACAO_HPP
