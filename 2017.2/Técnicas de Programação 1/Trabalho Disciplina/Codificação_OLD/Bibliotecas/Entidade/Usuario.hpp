#ifndef USUARIO_H
    #define USUARIO_H

    /**
     *  @file   Usuario.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/Apelido.hpp"
    #include "../Dominio/Nome.hpp"
    #include "../Dominio/Senha.hpp"
    #include "../Dominio/Telefone.hpp"

    /**
     *  @class  Usuario
     *  Usuario padrão aceito na estante virtual, garantindo
     *  sua integridade
     */
    class Usuario{
        private:
            /*  Domínios que compoem um Usuário */
            Apelido     apelido;
            Nome        nome;
            Senha       senha;
            Telefone    tel;

        public:
            /**
             *  Construtor padrão
             */
            Usuario (){};

            /**
             *  Construtor de um Usuário, conhecendo-se seu apelido
             *  @param apelido Apelido a ser atribuído
             */
            Usuario (const Apelido &apelido);

            /**
             *  Construtor de um Usuário, conhecendo-se seu nome
             *  @param nome Nome a ser atribuído
             */
            Usuario (const Nome &nome);

            /**
             *  Construtor de um Usuário, conhecendo-se sua senha
             *  @param senha Senha a ser atribuída
             */
            Usuario (const Senha &senha);

            /**
             *  Construtor de um Usuário, conhecendo-se seu telefone
             *  @param tel Telefone a ser atribuído
             */
            Usuario (const Telefone &tel);

            /**
             *  Construtor de um Usuário, conhecendo-se todos os
             *  dados do mesmo
             *  @param apelido Apelido a ser atribuído
             *  @param nome Nome a ser atribuído
             *  @param senha Senha a ser atribuída
             *  @param tel Telefone a ser atribuído
             */
            Usuario (const Apelido &apelido,
                     const Nome &nome,
                     const Senha &senha,
                     const Telefone &tel);

            /**
             *  Atribuição do apelido do Usuário
             *  @param apelido Apelido a ser atribuído
             */
            void setApelido (const Apelido &apelido);

            /**
             *  Recuperar o valor atribuído ao apelido do Usuário
             *  @return Apelido armazenado do Usuário
             */
            Apelido getApelido () const;

            /**
             *  Atribuição do nome do Usuário
             *  @param nnome Nome a ser atribuído
             */
            void setNome (const Nome &nome);

            /**
             *  Recuperar o valor atribuído ao nome do Usuário
             *  @return Nome armazenado do Usuário
             */
            Nome getNome () const;

            /**
             *  Atribuição da senha do Usuário
             *  @param senha Senha a ser atribuída
             */
            void setSenha (const Senha &senha);

            /**
             *  Recuperar o valor atribuído à senha do Usuário
             *  @return Senha armazenada do Usuário
             */
            Senha getSenha () const;

            /**
             *  Atribuição do telefone do Usuário
             *  @param tel Telefone a ser atribuído
             */
            void setTelefone (const Telefone &tel);

            /**
             *  Recuperar o valor atribuído ao telefone do Usuário
             *  @return Telefone armazenado do Usuário
             */
            Telefone getTelefone () const;

            /**
             *  Verificar se dois usuários são iguais
             *  @param alvo Usuários alvo de comparação
             *  @return PASSOU ou FALHOU
             */
            bool equals (const Usuario &alvo);
    };

    /*  Definição dos métodos 'Get' */
    inline Apelido Usuario::getApelido () const {return this->apelido;}
    inline Nome Usuario::getNome () const {return this->nome;}
    inline Senha Usuario::getSenha () const {return this->senha;}
    inline Telefone Usuario::getTelefone () const {return this->tel;}

    /*  Definição dos métodos 'Set' */
    inline void Usuario::setApelido (const Apelido &apelido){this->apelido = apelido;}
    inline void Usuario::setNome (const Nome &nome) {this->nome = nome;}
    inline void Usuario::setSenha (const Senha &senha) {this->senha = senha;}
    inline void Usuario::setTelefone (const Telefone &tel) {this->tel = tel;}
#endif // USUARIO_H
