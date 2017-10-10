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

bool Livro::equals(const Livro &alvo){
    if (this->codigo.equals(alvo.getCodigo())
        && this->dataPublicacao.equals(alvo.getDataPublicacao())
        && this->genero.equals(alvo.getGenero())
        && this->nomeAutor.equals(alvo.getAutor())
        && this->titulo.equals(alvo.getTitulo()))
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}
