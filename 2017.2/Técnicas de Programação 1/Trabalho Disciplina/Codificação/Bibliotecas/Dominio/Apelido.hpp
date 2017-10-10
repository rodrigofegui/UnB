#ifndef APELIDO_HPP
    #define APELIDO_HPP

    /**
     *  @file   Apelido.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase.hpp"

    /**
     *  @class Apelido
     *  Apelido a ser dado ao usuário da estande digital,
     *  garantindo a integridade do mesmo
     */
    class Apelido : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const static string msgErroTam;
            const static string msgErroArg;

            /*  Constantes de restrição */
            const static int LIM_MAX = 5;

            /*  Validação do apelido a ser armazenado */
            void validar (const string &campo) throw (invalid_argument) override;
            void validarTamanho (const string &campo) throw (invalid_argument);
            void validarLetras (const string &campo) throw (invalid_argument);

        public:
            /**
             *  Construtor padrão
             */
            Apelido (){};

            /**
             *  Construtor de um apelido, conhecendo-se
             *  o mesmo
             *  @param campo Apelido candidato a atribuição
             */
            Apelido(const string &campo);

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };
#endif // APELIDO_HPP
