#include "../../Bibliotecas_Tst/Entidade_Tst/Livro_Tst.hpp"

void LivroTst::inicializar(){
    cout << "Testando Entidade/Livro:" << endl;

    this->livro = new Livro ();
    this->status = TesteUnitario::PASSOU;

    codigo.setCampo("00001");
    data.setCampo("12/10/79");
    genero.setCampo("NOVELA");
    autor.setCampo("Douglas Adams");
    titulo.setCampo("Guia do Mochileiro");
}

void LivroTst::finalizar (){
    if(this->status)
        cout << "APROVADO!" << endl << endl;
    else cout << "REPROVADO!" << endl << endl;

    this->livro->deletar();
    delete this;
}

void LivroTst::validar (){
    validarCodigo ();

    validarData();

    validarGenero();

    validarAutor();

    validarTitulo();
}

void LivroTst::validarCodigo (){
    this->livro->setCodigo(this->codigo);

    if(!this->codigo.equals(this->livro->getCodigo()))
        this->status = TesteUnitario::FALHOU;
}

void LivroTst::validarData (){
    this->livro->setDataPublicacao(this->data);

    if(!this->data.equals(this->livro->getDataPublicacao()))
        this->status = TesteUnitario::FALHOU;
}

void LivroTst::validarGenero (){
    this->livro->setGenero(this->genero);

    if(!this->genero.equals(this->livro->getGenero()))
        this->status = TesteUnitario::FALHOU;
}

void LivroTst::validarAutor (){
    this->livro->setAutor(this->autor);

    if(!this->autor.equals(this->livro->getAutor()))
        this->status = TesteUnitario::FALHOU;
}

void LivroTst::validarTitulo (){
    this->livro->setTitulo(this->titulo);

    if(!this->titulo.equals(this->livro->getTitulo()))
        this->status = TesteUnitario::FALHOU;
}
