#ifndef TEXTO_H
    #define TEXTO_H

    /**
     *  @file   Texto.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase.hpp"

    /**
     *  @class  Texto
     *  Texto padrão a ser utilizado na estante digital,
     *  garantindo a sua integridade
     */
    class Texto : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const static string msgErroTam;

            /*  Constantes de validação */
            const static int TAM_MAX = 40;

            /*  Validação do texto a ser armazenado */
            void validar (const string &campo) throw (invalid_argument, length_error) override;
            void validarTamanho (const string &campo) throw (invalid_argument, length_error);

        public:
            /**
             *  Construtor padrão
             */
            Texto (){};

            /**
             *  Construtor de um texto, conhecendo-se
             *  o mesmo
             *  @param campo Texto candidato a atribuição
             */
            Texto(const string &campo);
    };
#endif // TEXTO_H
