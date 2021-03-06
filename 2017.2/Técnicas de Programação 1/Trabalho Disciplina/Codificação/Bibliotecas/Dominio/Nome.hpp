#ifndef NOME_H
    #define NOME_H

    /**
     *  @file   Nome.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include "DominioBase.hpp"
    #include <regex>

    /**
     *  @class  Nome
     *  Nome padrão aceito na estante digital,
     *  garantindo a sua integridade
     */
    class Nome : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const static string msgErroTam;
            const static string msgErroNum;
            const static string msgErroSimb;
            const static string msgErroArg;

            /*  Constantes de restrição */
            const static string SIMB_N_PERMT;
            const static string DB_SPACE;
            const static string DB_PONTO;

            /*  Validação do nome a ser armazenado */
            void validar (const string &campo) throw (invalid_argument) override;
            void validarTamanho (const string &campo) throw (invalid_argument);
            void validarAlfabetico (const string &campo) throw (invalid_argument);
            void validarSimbolos (const string &campo) throw (invalid_argument);
            bool haInvSimb (const string &campo);

        public:
			/**	Tamanho máximo de um Nome */
			const static int TAM_MAX = 15;

            /**
             *  Construtor padrão
             */
            Nome (){};

            /**
             *  Construtor de um nome, conhecendo-se
             *  o mesmo
             *  @param campo Nome candidato a atribuição
             */
            Nome(const string &campo);

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };
#endif // NOME_H
