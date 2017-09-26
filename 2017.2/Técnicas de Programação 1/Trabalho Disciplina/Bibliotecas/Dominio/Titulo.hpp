#ifndef TITULO_H
    #define TITULO_H

    /**
     *  @file   Titulo.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase.hpp"
    #include <string.h>

    /**
     *  @class Titulo
     *  Título padrão a ser utilizado na estante digital,
     *  garantindo a sua integridade
     */
    class Titulo : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const static string msgErroTam;
            const static string msgErroArg;

            /*  Constantes de validação */
            const static int TAM_MAX = 20;
            const static string DB_SPACE;

            /*  Validação do texto a ser armazenado */
            void validar (const string &campo) throw (invalid_argument, length_error) override;
            void validarTamanho (const string &campo) throw (invalid_argument, length_error);
            void validarSimbolos (const string &campo) throw (invalid_argument, length_error);

        public:
            /**
             *  Construtor padrão
             */
            Titulo (){};

            /**
             *  Construtor de um título, conhecendo-se
             *  o mesmo
             *  @param campo Titulo candidato a atribuição
             */
            Titulo(const string &campo);

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };
#endif // TITULO_H
