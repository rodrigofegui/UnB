#ifndef INTER_CONTROLE_HPP
    #define INTER_CONTROLE_HPP

    /**
     *  @file   InterCtrl.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "InterApresServ.hpp"

    /**
     *  @class InterCtrl
     *  Protocolo padrão para o desenvolvimento de
     *  funcionalidades presentes na aplicação.
     */
    class InterCtrl{
        public:
            /**
             *  Execução das atividades de um dado Módulo
             *  da aplicação.
             */
            virtual void executar(){};

            /**
             *  Configuração de uma funcionalidade da aplicação
             */
            virtual void setServico (const InterApresServ *servico){};
    };
#endif // INTERIM_CONTROLE_HPP
