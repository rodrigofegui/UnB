#include "../../Bibliotecas/Entidade/Resenha.hpp"

Resenha::Resenha (const Texto &txt){setTexto(txt);}

Resenha::Resenha (const Titulo &titulo){setTitulo(titulo);}

Resenha::Resenha (const Texto &txt,
                     const Titulo &titulo){
    setTexto(txt);
    setTitulo(titulo);
}

bool Resenha::equals(const Resenha &alvo){
    if (this->texto.equals(alvo.getTexto())
        && this->titulo.equals(alvo.getTitulo()))
        return TesteUnitario::PASSOU;

    return TesteUnitario::FALHOU;
}
