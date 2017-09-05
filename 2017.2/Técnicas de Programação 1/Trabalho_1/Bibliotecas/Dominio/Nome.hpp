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
     *  Nome de usuário aceito na estante digital,
     *  garantindo a sua integridade
     */
    class Nome : public DominioBase{
        private:
            /*  Mensagens de erro padrão */
            const string msgErroTam = "Nome fornecido além do tamanho permitido!";
            const string msgErroNum = "Nome fornecido contém números!";
            const string msgErroSimb = "Nome fornecido contém símbolos não permitidos!";
            const string msgErroArg = "Nome fornecido não obedece as especificações!";

            /*  Constantes de restrição */
            const static int TAM_MAX = 15;
            const string SIMB_N_PERMT = "[\-/!\"\#$%&'()*+,:;<=>?@\[\\\]^_`{|}~]+";

            /*  Validação do nome a ser armazenado */
            void validar (const string &campo) throw (invalid_argument, length_error) override;
            bool haInvSimb (const string &campo);

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
