#ifndef SENHA_H
    #define SENHA_H

    /**
     *  @file   Senha.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase.hpp"

    /**
     *  @class  Senha
     *  Senha padrão aceito na estante digital,
     *  garantindo a sua integridade
     */
    class Senha : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const static string msgErroTam;
            const static string msgErroSimb;
            const static string msgErroArg;

            /*  Constantes de restrição */
            const static int TAM_MAX = 4;

            /*  Validação do nome a ser armazenado */
            void validar (const string &campo) throw (invalid_argument) override;
            void validarTamanho (const string &campo) throw (invalid_argument);
            void validarAlfabetico (const string &campo) throw (invalid_argument);
            void validarDuplicata (const string &campo) throw (invalid_argument);

        public:
            /**
             *  Construtor padrão
             */
            Senha (){};

            /**
             *  Construtor de uma senha, conhecendo-se
             *  a mesma
             *  @param campo Senha candidata a atribuição
             */
            Senha (const string &campo);

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };

#endif // SENHA_H
