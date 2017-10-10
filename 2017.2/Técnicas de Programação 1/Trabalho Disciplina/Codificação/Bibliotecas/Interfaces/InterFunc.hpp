#ifndef INTER_FUNC_HPP
    #define INTER_FUNC_HPP

    /**
     *  @file   InterFunc.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "InterServ.hpp"

    /**
     *  @class  InterFunc
     *  Protocolo de realização das funções básicas da aplicação.
     */
    class InterFunc{
        public:
            /**
             *  Realização da funcionalidade,
             *  garantindo a integridade.
             *  @return Resultado da execução
             */
            virtual Resultado executar () = 0;

            /**
             *  Realização da funcionalidade,
             *  com dependência sobre execuções
             *  passadas e garantindo a integridade
             *  @param Dados úteis para a execução
             *  @return Resultado da execução.
             */
            virtual Resultado executar (const Resultado &) = 0;

            /**
             *  Atribuição da Camada de Serviço
             *  que a aplicação irá funcionar,
             *  para a dada funcionalidade.
             *  @param Camada de serviço a ser considerada
             */
            virtual void setServico (InterServ *) = 0;
    };
#endif // INTER_FUNC_HPP
