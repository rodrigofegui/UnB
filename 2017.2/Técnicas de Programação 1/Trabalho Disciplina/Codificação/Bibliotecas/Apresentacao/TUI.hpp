#ifndef APRESENTACAO_TXT_HPP
    #define APRESENTACAO_TXT_HPP

    /**
     *  @file   TUI.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/Resultado.hpp"

    /**
     *  @class  TUI
     *  Protocolo para execução de uma
     *  aplicação voltada a texto
     */
    class TUI{
        private:
            /*  Constante */
            const static int LIM_TENT = 3;

            /*  Tentativas de operacionalidade */
            void tentar ();

        protected:
            /**
             *  Direcionamento da aplicação para
             *  as intenções do usuário.
             *  @param Escolha a ser considerada
             */
            virtual void direcionar (const Resultado &) = 0;

            /**
             *  Leitura dos dados de entrada dos usuário,
             *  garantindo a integridade do sistema.
             *  @return Resultado da operação
             */
            virtual Resultado leitura () = 0;

            /**
             *  Apresentação dos dados/informações úteis
             *  para o usuário, minimizando os problemas
             *  operacionais.
             */
            virtual void menu () = 0;

            /**
             *  Tratamento adequado para os eventuais
             *  erros ocorridos.
             *  @param Direcionamento do tratamento necessário
             */
            virtual void tratarErro () = 0;

        public:
            /**
             *  Execução, garantindo a integridade do sistema.
             */
            void executar ();
    };
#endif // APRESENTACAO_TXT_HPP
