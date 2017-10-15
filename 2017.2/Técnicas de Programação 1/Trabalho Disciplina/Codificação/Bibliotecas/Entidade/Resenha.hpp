#ifndef RESENHA_H
    #define RESENHA_H

    /**
     *  @file   Resenha.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/Texto.hpp"
    #include "../Dominio/Titulo.hpp"

    /**
     *  @class  Resenha
     *  Resenha padrão aceita na estante virtual, garantindo
     *  sua integridade
     */
    class Resenha{
        private:
            /*  Domínios que compoem uma Resenha */
            Texto   texto;
            Titulo  titulo;

        public:
            /**
             *  Construtor padrão
             */
            Resenha (){};

            /**
             *  Construtor de uma Resenha, conhecendo-se seu texto
             *  @param txt Texto a ser atribuído
             */
            Resenha (const Texto &txt);

            /**
             *  Construtor de uma Resenha, conhecendo-se seu título
             *  @param titulo Título a ser atribuído
             */
            Resenha (const Titulo &titulo);

            /**
             *  Construtor de uma Resenha, conhecendo-se todos os
             *  seus dados
             *  @param txt Texto a ser atribuído
             *  @param titulo Título a ser atribuído
             */
            Resenha (const Texto &txt,
                     const Titulo &titulo);

            /**
             *  Atribuição do texto da Resenha
             *  @param txt Texto a ser atribuído
             */
            void setTexto (const Texto &txt);

            /**
             *  Recuperar o valor atribuído ao texto da Resenha
             *  @return Texto armazenado na Resenha
             */
            Texto getTexto() const;

            /**
             *  Atribuição do título da Resenha
             *  @param titulo Título a ser atribuído
             */
            void setTitulo (const Titulo &titulo);

            /**
             *  Recuperar o valor atribuído ao título da Resenha
             *  @return Título armazenado na Resenha
             */
            Titulo getTitulo() const;

            /**
             *  Verificar se duas resenhas são iguais
             *  @param alvo Resenha alvo de comparação
             *  @return PASSOU ou FALHOU
             */
            bool equals (const Resenha &alvo);

			/**
             *  Destrutor padrão
             */
            void deletar () const;
    };

    /*  Definição dos métodos 'Get' */
    inline Texto Resenha::getTexto() const {return this->texto;}
    inline Titulo Resenha::getTitulo() const {return this->titulo;}

    /*  Definição dos métodos 'Set' */
    inline void Resenha::setTexto (const Texto &txt) {this->texto = txt;}
    inline void Resenha::setTitulo (const Titulo &titulo) {this->titulo = titulo;}

	/*  Definição do destrutor padrão */
   inline void Resenha::deletar() const{delete this;}
#endif // RESENHA_H
