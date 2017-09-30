#include "../../Bibliotecas/Entidade/Livro.hpp"

Livro::Livro (const Data &dataPublicacao){
    setDataPublicacao(dataPublicacao);
}

Livro::Livro (const GeneroLiterario &genero){
    setGenero(genero);
}

Livro::Livro (const Nome &autor){
    setAutor (autor);
}

Livro::Livro (const Titulo &titulo){
    setTitulo(titulo);
}

Livro::Livro ( const Data &data,
               const GeneroLiterario &genero,
               const Nome &autor,
               const Titulo &titulo){
    setDataPublicacao(data);
    setGenero(genero);
    setAutor(autor);
    setTitulo(titulo);
}

Livro::Livro ( const Codigo &codigo,
               const Data &data,
               const GeneroLiterario &genero,
               const Nome &autor,
               const Titulo &titulo){
    Livro(data, genero, autor, titulo);
    setCodigo(codigo);
}

