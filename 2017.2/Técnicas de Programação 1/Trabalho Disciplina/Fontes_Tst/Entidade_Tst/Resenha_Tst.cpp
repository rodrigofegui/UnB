#include "../../Bibliotecas_Tst/Entidade_Tst/Resenha_Tst.hpp"

void ResenhaTst::inicializar(){
    cout << "Testando Entidade/Resenha:" << endl;

    this->resenha = new Resenha ();
    this->status = TesteUnitario::PASSOU;

    texto.setCampo("Lorem ipsum dolor sit amet, consectetur");
    titulo.setCampo("Péssimo Livro");
}

void ResenhaTst::finalizar(){
    if(this->status)
        cout << "APROVADO!" << endl << endl;
    else cout << "REPROVADO!" << endl << endl;

    delete this->resenha;
    delete this;
}

void ResenhaTst::validar(){
    validarTexto();

    validarTitulo();
}

void ResenhaTst::validarTexto(){
    this->resenha->setTexto(this->texto);

    if(!this->texto.equals(this->resenha->getTexto()))
        this->status = TesteUnitario::FALHOU;
}

void ResenhaTst::validarTitulo(){
    this->resenha->setTitulo(this->titulo);

    if(!this->titulo.equals(this->resenha->getTitulo()))
        this->status = TesteUnitario::FALHOU;
}
