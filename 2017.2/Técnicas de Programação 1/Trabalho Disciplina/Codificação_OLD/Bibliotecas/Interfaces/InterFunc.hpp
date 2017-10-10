#ifndef INTER_FUNCIONALIDADE_HPP
    #define INTER_FUNCIONALIDADE_HPP

    /**
     *  @file   InterFunc.Hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "InterApresServ.hpp"
    #include "../Dominio/OpResult.hpp"
    #include "string"

    using namespace std;

    /**
     *  @class InterFunc
     *  Protocolo padrão para o desenvolvimento de
     *  funcionalidades presentes na aplicação.
     */
    class InterFunc{
        protected:
            /**
             *  Serviço a ser configurado
             */
            InterApresServ *servico;

        public:
            /**
             *  Execução das atividades de um dado Módulo
             *  da aplicação.
             */
            virtual OpResult executar(){};

            /**
             *  Configuração de uma funcionalidade da aplicação
             */
            OpResult setServico (InterApresServ *servico);

            void deletar(){delete this;}
    };

    inline OpResult InterFunc::setServico(InterApresServ *servico){
        this->servico = servico;

        return OpResult(OpResult::SUCESSO);
    }
#endif // INTERIM_CONTROLE_HPP
