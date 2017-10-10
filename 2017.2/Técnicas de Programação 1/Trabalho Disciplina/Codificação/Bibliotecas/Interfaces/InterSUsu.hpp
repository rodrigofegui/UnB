#ifndef INTER_SERV_USU_HPP
    #define INTER_SERV_USU_HPP

    /**
     *  @file   InterSUsu.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "InterServ.hpp"
    #include "../Entidade/Usuario.hpp"

    /**
     *  @class InterSUsu
     *  Protocolo de comunicação entre a camada
     *  de Apresentação e de Serviço, para a funcionalidade de Usuário
     */
    class InterSUsu : public InterServ{
        public:
            /**
             *  Cadastramento de um usuário na Base de Dados.
             *  @param  Usuário que será cadastrado
             *  @return Resultado da operação
             */
            virtual Resultado cadastrar (const Usuario &) throw (runtime_error) = 0;
    };
#endif // INTER_SERV_USU_HPP
