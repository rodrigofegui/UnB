#ifndef APRES_CONTROLE_HPP
    #define APRES_CONTROLE_HPP

    /**
     *  @file   AControle.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Interfaces/InterCntrl.hpp"
    #include "../Interfaces/InterFunc.hpp"
    #include "../Dominio/Versao.hpp"

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
            InterCntrl *servCntrl;

            /*  Apresentação da tela inicial */
            OpResult apresentarTUI();

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
             *  Execução da aplicação, com controle de versão
             */
            void executar (const Versao &versao);

            /**
             *  Execução da aplicação, com a versão mais recente
             */
            void executar ();
    };
#endif // APRES_CONTROLE_HPP
