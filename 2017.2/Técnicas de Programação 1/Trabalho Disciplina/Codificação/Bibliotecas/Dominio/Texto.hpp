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

            /*  Validação do texto a ser armazenado */
            void validar (const string &campo) throw (invalid_argument) override;
            void validarTamanho (const string &campo) throw (invalid_argument);

        public:
            /**  Tamanho máximo do Texto */
            const static int TAM_MAX = 40;

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

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };
#endif // TEXTO_H
