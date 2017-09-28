#include "../../Bibliotecas/Entidade/Resenha.hpp"

Resenha::Resenha (const Texto &txt){setTexto(txt);}

Resenha::Resenha (const Titulo &titulo){setTitulo(titulo);}

Resenha::Resenha (const Texto &txt,
                     const Titulo &titulo){
    setTexto(txt);
    setTitulo(titulo);
}
