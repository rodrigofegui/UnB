#ifndef LOGIN_HPP
    #define LOGIN_HPP

    /**
     *  @file Login.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/Apelido.hpp"
    #include "../Dominio/Senha.hpp"

    /**
     *  @class Login
     *  Login padrão aceito na estante virtual,
     *  garantindo sua integridade
     */
    class Login{
        private:
            /*  Domínios que compoem um login */
            Apelido apelido;
            Senha   senha;

        public:
            /**
             *  Construtor padrão
             */
            Login(){};

            /**
             *  Construtor de um login, conhecendo-se todos os
             *  dados públicos do mesmo
             *  @param apelido  Apelido do usuário
             *  @param senha    Senha do usuário
             */
            Login (const Apelido &apelido,
                   const Senha &senha);

            /**
             *  Atribuição do apelido do Login
             *  @param apelido Apelido do usuário
             */
            void setApelido (const Apelido &apelido);

            /**
             *  Recuperar o valor atribuído ao apelido do Login
             *  @return Apelido do Login
             */
            Apelido getApelido () const;

            /**
             *  Atribuição da senha do Login
             *  @param senha Senha do usuário
             */
            void setSenha (const Senha &senha);

            /**
             *  Recuperar o valor atribuído à senha do Login
             *  @return Senha do Login
             */
            Senha getSenha () const;

            /**
             *  Destrutor padrão
             */
            void deletar () const;
    };

    /*  Definição dos métodos 'Get' */
    inline Apelido Login::getApelido() const{return this->apelido;};
    inline Senha Login::getSenha() const{return this->senha;};

    /*  Definição dos métodos 'Set' */
    inline void Login::setApelido(const Apelido &apelido){this->apelido = apelido;};
    inline void Login::setSenha(const Senha &senha){this->senha = senha;};

     /*  Definição do destrutor padrão */
    inline void Login::deletar() const{delete this;}
#endif // LOGIN_HPP
