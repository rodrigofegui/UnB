#ifndef APRES_TUI_HPP
    #define APRES_TUI_HPP

    /**
     *  @file   ApresTUI.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Interfaces/InterFunc.hpp"
    #include <stdexcept>

    /**
     *  @class  ApresTUI
     */
    class ApreTUI : public InterFunc{
        private:
            /*  Máximo de tentativas para a execução */
            const static int MAX_TENTATIVAS = 3;

            /*  Execução das tentativas */
            void tentativas ();

        protected:
            /**
             *  Apresentação das opções de operações ao usuário da aplicação.
             */
            virtual void menu (){};

            /**
             *  Criação dos objetos requeridos pela funcionalidade específica.
             */
            virtual void criar (){};

            /**
             *  Configuração dos objetos requeridos, previamente criados,
             *  pela funcionalidade específica, garantindo a integridade
             *  dos mesmos.
             *  @return Condição das configurações
             */
            virtual OpResult configurar () throw (invalid_argument){};

            /**
             *  Ativação da camada de serviço
             *  @param controle Controle do serviço a ser executado
             */
            virtual void servico (const OpResult &controle){};

            /**
             *  Tratamento de erros
             */
            virtual void erroOp (string opCode){};

        public:
            OpResult executar() override;
    };
#endif // APRES_TUI_HPP
