#ifndef APRES_CONTROLE_HPP
    #define APRES_CONTROLE_HPP

    /**
     *  @file   AControle.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Interfaces/InterFunc.hpp"

    /**
     *  @class AControle
     *  Controle da aplicação, na camada de Apresentação
     */
    class AControle{
        private:
            /**
             *  Funcionalidades da aplicação:
             *      - Autenticação
             *      - Usuários
             *      - Estante
             */
            InterFunc *funcAut, *funcUsu, *funcEst;

            /*  Construção da camada de Serviço */
            OpResult construir ();

            void aplicacao ();

            /*  Apresentação da tela inicial */
            OpResult apresentarTUI();

            /*  Avaliação do resultado da escolha do usuário para
             *  a tela inicial */
            void avaliar (const OpResult &resultado);

            /*  Passagem de controle para a função de Autenticação */
            OpResult autenticar ();

            /*  Passagem de controle para a função de Usuário */
            OpResult usuario ();

            /*  Passagem de controle para a função da Estante */
            OpResult estante ();

            /*  Finalização da aplicação de maneira segura */
            void finalizar ();

        public:
           /**
             *  Execução da aplicação, com a versão mais recente
             */
            void executar ();
    };
#endif // APRES_CONTROLE_HPP
