#ifndef LOG_HPP
    #define LOG_HPP

    /**
     *  @file   Log.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <string>
    #include <time.h>
    #include <iomanip>

    using namespace std;
    /**
     *  @class  Log
     *  Arquivo de log padrão aceito na estante
     *  virtual, legitimando seu manuseio
     */
    class Log{
        private:
            /*  Constantes de trabalho */
            const static string DIR_PADRAO;
            const static string FMT_DATA;
            const static string FMT_HORA;

            /*  Caminho para o arquivo de log*/
            static string diretorio;
            static string nome;

            static string getTempo (const string &);

        public:
            /**
             *  Construtor padrão
             */
            Log();

            /**
             *  Construtor de um Log, conhecendo-se
             *  o diretório de armazenamento.
             *  @param Diretório de armazenamento
             */
            Log (string);

            /**
             *  Construtor de um Log, conhecendo-se
             *  o diretório de armazenamento e o nome
             *  do arquivo.
             *  @param Diretório de armazenamento
             *  @param Nome do arquivo
             */
            Log (string,
                 string);

            /**
             *  Inicialização do arquivo de log,
             *  com a construção do cabeçalho devido
             */
            static void iniciar ();

            /**
             *  Atribuição do diretório do arquivo.
             *  @param  Diretório de armazenamento
             */
            static void setDiretorio (string);

            /**
             *  Recuperar o valor atribuído ao diretório
             *  do arquivo.
             *  @return Diretório de armazenamento
             */
            static string getDiretorio ();

            /**
             *  Atribuição do nome do arquivo.
             *  @param  Nome do arquivo
             */
            static void setNome (string);

            /**
             *  Recuperar o valor atribuído ao nome
             *  do arquivo
             *  @return Nome do arquivo
             */
            static string getNome ();

            /**
             *  Construção do nome de arquivo padrão
             *  @return Nome de arquivo aconselhado
             */
            static string nomePadrao ();

            /**
             *  Escrita de uma dada mensagem no arquivo de log
             *  @param Mensagem a ser escrita
             */
            static void escrever (string);

            /**
             *  Recuperar o valor atribuído à data
             *  de execução da aplicação
             *  @return Data da execução no formato
             *  DD-MM-YYYY
             */
            static string getData ();

            /**
             *  Recuperar o valor atribuído à hora
             *  de execução da aplicação
             *  @return Hora da execução no formato
             *  hh:mm:ss
             */
            static string getHora ();

            /**
             *  Destrutor padrão
             */
            void deletar() const;
    };

    /*  Definição dos métodos 'Get' */
    inline string Log::getDiretorio (){return Log::diretorio;}
    inline string Log::getNome() {return Log::nome;}

    /*  Definição dos métodos 'Set' */
    inline void Log::setDiretorio (string diretorio){Log::diretorio = diretorio;}
    inline void Log::setNome (string nome){Log::nome = nome;}

    /*  Definição do destrutor padrão */
    inline void Log::deletar() const{delete this;}
#endif // LOG_HPP
