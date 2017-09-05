#ifndef NOME_H
    #define NOME_H

    /**
     *  @file   Nome.hpp
     *  @author Rodrigo F. Guimarães
     */

    #include "DominioBase.hpp"

    /**
     *  @class  Nome
     *  Nome de usuário aceito na estante digital,
     *  garantindo a sua integridade
     */
    class Nome : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const string msgErroTam = "Nome fornecido além do tamanho permitido!";
            const string msgErroNum = "Há números no Nome fornecido!";
            const string msgErroSimb = "Há símbolos não permitidos no Nome fornecido!";
            const string msgErroArg = "Nome fornecido não obedece as especificações!";

            /*  Constantes de restrição */
            const static int TAM_MAX = 15;
            const string SIMB_N_PERMT = "-!\"#$%&'()*+,/:;<=>?@[\\\]_`{|}~";

            /*  Validação do nome a ser armazenado */
            void validar (const string &campo) throw (invalid_argument, length_error) override;

        public:
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
    };
#endif // NOME_H
