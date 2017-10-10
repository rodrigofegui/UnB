#ifndef INTER_CONTROLE_HPP
    #define INTER_CONTROLE_HPP

    /**
     *  @file   InterCntrl.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/OpResult.hpp"
    #include "../Dominio/Versao.hpp"
    #include <stdio.h>

    /**
     *  @class InterCntrl
     *  Protocolo de comunicação entre a camada de
     *  Apresentação e de Serviço, para o Controle
     */
    class InterCntrl{
        public:
            /**
             *  Construção da arquitetura da aplicação,
             *  ligando a devida camada de Apresentação
             *  à devida camada de Serviço, conforme a
             *  versão da aplicação.
             *  @param versao   Versão a ser considerada na aplicação
             */
            virtual OpResult construir (const Versao &versao){};

            /**
             *  Escrita de uma dada mensagem no arquivo de
             *  Log.
             *  @param msg Mensagem a ser escrita no arquivo
             */
            virtual void escritaLog (const string &msg){};

            /**
             *  Recuperar o valor atribuído ao arquivo de Log
             *  @return Arquivo de Log manipulado
             */
            virtual FILE getArqLog () const {};

            /**
             *  Atribuição do arquivo de Log, respeitando sua
             *  integridade
             *  @param arqLog Arquivo de Log a ser manipulado
             *  na aplicação
             */
            virtual void setArqLog (const FILE *arqLog){};
    };
#endif // INTER_CONTROLE_HPP
