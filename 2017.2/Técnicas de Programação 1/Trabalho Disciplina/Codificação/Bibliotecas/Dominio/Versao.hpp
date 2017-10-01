#ifndef VERSAO_HPP
    #define VERSAO_HPP

    /**
     *  @file   Versao.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "DominioBase.hpp"

    /**
     *  @class Versao
     *  Versão da aplicação aceitos, garantindo a sua integridade
     */
    class Versao : public DominioBase{
        private:
            /*  Mensagens de Erro Padrão */
            const static string msgErro;

            /*  Validação da Versão a ser armazenada */
            void validar (const string &campo) throw (invalid_argument) override;
            void validarCadastro (const string &campo) throw (invalid_argument);

        public:
            /**
             *  Constantes de restrição
             */
            const static vector<string> VER_CADASTRADAS;

            /**
             *  Construtor padrão
             */
            Versao (){};

            /**
             *  Construtor de uma, conhecendo-se
             *  a mesma
             *  @param campo Versão candidata a atribuição
             */
            Versao(const string &campo);

            /**
             *  Destrutor padrão
             */
            void deletar() override;
    };
#endif // VERSAO_HPP
