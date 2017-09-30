#ifndef INTER_ESTANTE_HPP
    #define INTER_ESTANTE_HPP

    /**
     *  @file   InterEst.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "InterApresServ.hpp"

    /**
     *  @class  InterEst
     *  Protocolo de comunicação entre a camada
     *  de Apresentação e de Serviço, para a
     *  funcionalidade da Estante.
     */
    class InterEst : public InterApresServ{
        public:
            /**
             *  Consulta de um Livro na Estante, através do título
             *  @param livro Título do livro a ser buscado
             */
            virtual OpResult consultar (const Titulo &livro){};

            /**
             *  Consulta de um Usuário na Estante, através do apelido.
             *  @param usuario Apelido do usuario a ser buscado
             */
            virtual OpResult consultar (const Apelido &usuario){};

            /**
             *  Criação de uma Resenha sobre um Livro da Estante.
             *  @param livro Livro que será redigido uma resenha
             *  @param resenha Resenha redigida
             */
            virtual OpResult criarResenha (const Livro &livro, const Resenha &resenha){};

            /**
             *  Inclusão de um exemplar de um livro à Estante pública.
             *  @param livro Livro a ser incluido na estante
             */
            virtual OpResult incluir (const Livro &livro){};

            /**
             *  Remoção de um exemplar de um livro da Estante.
             *  @param livro Exemplar do livro a ser removido
             */
            virtual OpResult remover (const Livro &livro){};

            //virtual OpResult setTroca (const Livro &livro, bool status){};
    };
#endif // INTER_ESTANTE_HPP
