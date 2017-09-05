#ifndef GENERO_LITERARIO_H
    #define GENERO_LITERARIO_H

    /**
     *  @file   GeneroLiterario.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include "DominioBase.hpp"

    /**
     *  @class  GeneroLiterario
     *  Gêneros literários aceitos na estante digital,
     *  garantindo a sua integridade
     */
    class GeneroLiterario : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const string msgErro = "Gênero não registrado!";

            /*  Constantes de restrição */
            const static vector<string> GEN_CADASTRADO;

            /*  Validação do gênero a ser armazenado */
            void validar (const string &campo) throw (invalid_argument) override;

        public:
            /**
             *  Construtor padrão
             */
            GeneroLiterario (){};

            /**
             *  Construtor de um gênero literário, conhecendo-se
             *  o mesmo
             *  @param campo Gênero candidato a atribuição
             */
            GeneroLiterario(const string &campo);
    };
#endif // GENERO_LITERARIO_H
