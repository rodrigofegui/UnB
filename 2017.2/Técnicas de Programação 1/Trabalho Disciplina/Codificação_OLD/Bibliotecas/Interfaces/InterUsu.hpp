#ifndef INTER_USUARIO_HPP
    #define INTER_USUARIO_HPP

    /**
     *  @file   InterUsu.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "InterApresServ.hpp"
    #include "../Entidade/Usuario.hpp"

    /**
     *  @class  InterUsu
     *  Protocolo de comunicação entre a camada de
     *  Apresentação e de Serviço, para a funcionalidade
     *  de Usuário.
     */
    class InterUsu : public InterApresServ{
        public:
            /**
             *  Cadastramento de um usuário na Base de Dados.
             *  @param usuario  Usuario candidato a cadastro
             */
            virtual OpResult cadastrar (const Usuario &usuario){};
    };
#endif // INTER_USUARIO_HPP
