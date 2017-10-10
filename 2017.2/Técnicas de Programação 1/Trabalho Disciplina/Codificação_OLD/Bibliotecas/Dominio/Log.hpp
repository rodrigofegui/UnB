#ifndef LOG_HPP
    #define LOG_HPP

    /**
     *  @file   Log.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <iomanip>
    #include <ctime>
    #include <sstream>
    #include <fstream>
    #include "DominioBase.hpp"

    /**
     *  @class  Log
     *  Arquivo de log que será manipulado pela estante digital,
     *  garantindo a sua integridade
     */
    class Log : public DominioBase{
        private:
            const static string DIR_PADRAO;

            /*  Arquivo de log que será manipulado */
            fstream arqLog;

        public:
            /**
             *  Construtor padrão
             */
            Log (){};

            /**
             *  Construtor de um arquivo de log, conhecendo-se
             *  o arquivo que será manipulado
             *  @param arqLog Arquivo candidato a atribuição
             */
            Log (fstream arqLog);

            /**
             *  Recuperar o valor atribuído ao arquivo de log
             *  @return Valor armazenado no arquivo
             */
            fstream getArqlog () const;

            /**
             *  Atribuição do arquivo, respeitando a sua integridade
             *  @param arqLog Arquivo candidato a atribuição
             */
            void setArqLog (const fstream &arqLog);

            /**
             *  Extração da data corrente da execução,
             *  disponibilizando-a no formato: DD/MM/YYYY
             *  @return Data corrente da execução
             */
            static string getData ();

            /**
             *  Extração da hora corrente da execução,
             *  disponibilizando-a no formato:
             *  HH:MM:SS
             *  @return Hora corrente da execução
             */
            static string getHora ();

            /**
             *  Escrita de uma mensagem no arquivo de log
             *  @param msg Mensagem a ser escrita
             */
            void escreverMsg (const string &msg);

            static fstream criarArq();

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };
#endif // LOG_HPP
