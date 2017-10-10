#ifndef LIVRO_H
    #define LIVRO_H

    /**
     *  @file   Livro.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Dominio/Titulo.hpp"
    #include "../Dominio/Nome.hpp"
    #include "../Dominio/Data.hpp"
    #include "../Dominio/Codigo.hpp"
    #include "../Dominio/GeneroLiterario.hpp"

    /**
     *  @class Livro
     *  Livro padrão aceito na estante virtual, garantindo
     *  sua integridade
     */
    class Livro{
        private:
            /*  Domínios que compoem um Livro */
            Codigo          codigo;
            Data            dataPublicacao;
            GeneroLiterario genero;
            Nome            nomeAutor;
            Titulo          titulo;

        public:
            /**
             *  Construtor padrão
             */
            Livro (){};

            /**
             *  Construtor de um Livro, conhecendo-se sua data de
             *  publicação
             *  @param data Data de publicação
             */
            Livro (const Data &dataPublicacao);

            /**
             *  Construtor de um Livro, conhecendo-se seu gênero
             *  literário
             *  @param gen Gênero literário
             */
            Livro (const GeneroLiterario &genero);

            /**
             *  Construtor de um Livro, conhecendo-se seu autor
             *  @param autor Nome do autor
             */
            Livro (const Nome &autor);

            /**
             *  Construtor de um Livro, conhecendo-se seu título
             *  @param titulo Título do livro
             */
            Livro (const Titulo &titulo);

            /**
             *  Construtor de um Livro, conhecendo-se todos os
             *  dados públicos do mesmo
             *  @param data Data de publicação
             *  @param gen  Gênero Literário
             *  @param autor Nome do autor
             *  @param titulo Título do livro
             */
            Livro (const Data &data,
                   const GeneroLiterario &genero,
                   const Nome &autor,
                   const Titulo &titulo);

            /**
             *  Construtor de um Livro, conhecendo-se todos os
             *  dados do mesmo
             *  @param codigo Codigo
             *  @param data Data de publicação
             *  @param gen  Gênero Literário
             *  @param autor Nome do autor
             *  @param titulo Título do livro
             */
            Livro (const Codigo &codigo,
                   const Data &data,
                   const GeneroLiterario &genero,
                   const Nome &autor,
                   const Titulo &titulo);

            /**
             *  Atribuição do código do Livro
             *  @param codigo Código a ser atribuído
             */
            void setCodigo (const Codigo &codigo);

            /**
             *  Recuperar o valor atribuído ao código do Livro
             *  @return Código armazenado do Livro
             */
            Codigo getCodigo() const;

            /**
             *  Atribuição da data de publicação do Livro
             *  @param data Data de publicação a ser atribuída
             */
            void setDataPublicacao (const Data &data);

            /**
             *  Recuperar o valor atribuído à data de
             *  publicação do Livro
             *  @return Data de publicação armazenada do Livro
             */
            Data getDataPublicacao () const;

            /**
             *  Atribuição do gênero literário do Livro
             *  @param genero Gênero literário a ser atribuído
             */
            void setGenero (const GeneroLiterario &genero);

            /**
             *  Recuperar o valor atribuído ao gênero
             *  literário do Livro
             *  @return Gênero literário armazenado do Livro
             */
            GeneroLiterario getGenero () const;

            /**
             *  Atribuição do nome do autor do Livro
             *  @param autor Nome do autor a ser atribuído
             */
            void setAutor (const Nome &autor);

            /**
             *  Recuperar o valor atribuído ao autor do Livro
             *  @return Autor armazenado do Livro
             */
            Nome getAutor () const;

            /**
             *  Atribuição do título do Livro
             *  @param título Título a ser atribuído
             */
            void setTitulo (const Titulo &titulo);

            /**
             *  Recuperar o valor atribuído ao título do Livro
             *  @return Título armazenado do Livro
             */
            Titulo getTitulo () const;

            /**
             *  Verificar se dois livros são iguais
             *  @param alvo Livro alvo de comparação
             *  @return PASSOU ou FALHOU
             */
            bool equals (const Livro &alvo);

            /**
             *  Destrutor padrão
             */
            void deletar() const;
    };


    /*  Definição dos métodos 'Get' */
    inline Codigo Livro::getCodigo() const{return this->codigo;}
    inline Data Livro::getDataPublicacao() const{return this->dataPublicacao;}
    inline GeneroLiterario Livro::getGenero() const{return this->genero;}
    inline Nome Livro::getAutor() const{return this->nomeAutor;}
    inline Titulo Livro::getTitulo() const{return this->titulo;}

    /*  Definição dos métodos 'Set' */
    inline void Livro::setCodigo (const Codigo &codigo){this->codigo = codigo;}
    inline void Livro::setDataPublicacao (const Data &data){this->dataPublicacao = data;}
    inline void Livro::setGenero (const GeneroLiterario &genero){this->genero = genero;}
    inline void Livro::setAutor (const Nome &autor){this->nomeAutor = autor;}
    inline void Livro::setTitulo (const Titulo &titulo){this->titulo = titulo;}

    /*  Definição do destrutor padrão */
    inline void Livro::deletar() const{delete this;}
#endif // LIVRO_H
