#ifndef INTER_FUNCIONALIDADE_HPP
    #define INTER_FUNCIONALIDADE_HPP

    /**
     *  @file   InterFunc.Hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "InterApresServ.hpp"

    /**
     *  @class InterFunc
     *  Protocolo padrão para o desenvolvimento de
     *  funcionalidades presentes na aplicação.
     */
    class InterFunc{
        public:
            /**
             *  Execução das atividades de um dado Módulo
             *  da aplicação.
             */
            virtual OpResult executar(){};

            /**
             *  Configuração de uma funcionalidade da aplicação
             */
            virtual OpResult setServico (const InterApresServ *servico){};
    };
#endif // INTERIM_CONTROLE_HPP
