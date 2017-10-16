#ifndef INTER_SERV_EST_HPP
    #define INTER_SERV_EST_HPP

    /**
     *  @file   InterSEst.hpp
     *  @author Rodrigo F. Guimarães
     */
	#include "../Entidade/Log.hpp"
    #include "../Entidade/Resultado.hpp"
    #include "../Entidade/Livro.hpp"
    #include "../Entidade/Resenha.hpp"
    #include "../Dominio/Apelido.hpp"

    /**
     *  @class  InterSEst
     *  Protocolo de comunicação entre a camada
     *  de Apresentação e de Serviço, para a
     *  funcionalidade da Estante.
     */
    class InterSEst{
        public:
            /**
             *  Consulta de um Livro na Estante.
             *  @param Identificador do livro
             *  @return Resultado da operação
             */
            virtual Resultado consultar (const Titulo &)  throw (runtime_error) = 0;

            /**
             *  Consulta de um Usuário na Estante.
             *  @param Identificador do usuário
             *  @return Resultado da operação
             */
            virtual Resultado consultar (const Apelido &)  throw (runtime_error) = 0;

            /**
             *  Criação de uma Resenha sobre um Livro da Estante.
             *  @param Livro a ser resenhado
             *  @param Resenha redigida
             *  @return Resultado da operação
             */
            virtual Resultado criarResenha (const Titulo &,
                                            const Resenha &)  throw (runtime_error) = 0;

            /**
             *  Inclusão de um exemplar de um livro à Estante pública.
             *  @param Livro a ser incluído
             *  @return Resultado da operação
             */
            virtual Resultado incluir (const Livro &)  throw (runtime_error) = 0;

            /**
             *  Remoção de um exemplar de um livro da Estante.
             *  @param Exemplar a ser removido
             *  @return Resultado da operação
             */
            virtual Resultado remover (const Titulo &)  throw (runtime_error) = 0;
    };
#endif // INTER_SERV_EST_HPP
