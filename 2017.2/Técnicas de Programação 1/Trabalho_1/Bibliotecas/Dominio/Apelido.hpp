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
            const string msgErroTam = "Apelido fornecido maior que o limite!";
            const string msgErroArg = "Apelido foge à especificação alfabética!";

            /*  Constantes de restrição */
            const static int LIM_MAX = 5;

            /*  Validação do apelido a ser armazenado */
            void validar (const string &campo) throw (invalid_argument, length_error) override;

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
    };
#endif // APELIDO_HPP
