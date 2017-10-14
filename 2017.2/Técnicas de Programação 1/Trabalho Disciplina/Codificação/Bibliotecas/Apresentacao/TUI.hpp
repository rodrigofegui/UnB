#ifndef APRESENTACAO_TXT_HPP
    #define APRESENTACAO_TXT_HPP

    /**
     *  @file   TUI.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Entidade/Resultado.hpp"
    #include "../Entidade/Log.hpp"

    /**
     *  @class  TUI
     *  Protocolo para execução de uma
     *  aplicação voltada a texto
     */
    class TUI{
        private:
            /*  Constante */
            const static int LIM_TENT = 3;

            /*  Inicialização do arquivo de log */
            bool iniciouLog = false;

            /*  Tentativas de operacionalidade */
            Resultado tentar ();

        protected:
            /**
             *  Direcionamento da aplicação para
             *  as intenções do usuário.
             *  @param Escolha a ser considerada
             */
            virtual Resultado direcionar (const Resultado &) = 0;

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
             *  Finalização das atividades, garantindo a integridade
             *  do sistema
             */
            virtual void finalizar() = 0;

            /**
             *  Tratamento adequado para os eventuais
             *  erros ocorridos.
             *  @return Ambiente favorável para a continuação da aplicação
             */
            virtual Resultado tratarErro () = 0;

            /**
             *  Tratamento adequado para os eventuais
             *  erros ocorridos, sendo referidos como Resultados.
             *  @param Direcionamento do tratamento necessário
             *  @return Ambiente favorável para a continuação da aplicação
             */
            virtual Resultado tratarErro (const Resultado &) = 0;

        public:
            /**
             *  Execução, garantindo a integridade do sistema.
             */
            void executar ();
    };
#endif // APRESENTACAO_TXT_HPP
