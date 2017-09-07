#include "../../Bibliotecas/Entidade_Tst/Livro_Tst.hpp"

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

    delete this->livro;
    delete this;
}

void LivroTst::validar (){
    validarCodigo (codigo);

    validarData(data);

    validarGenero(genero);

    validarAutor(autor);

    validarTitulo(titulo);
}

void LivroTst::validarCodigo (const Codigo &codigo){
    this->livro->setCodigo(codigo);

    if(!codigo.equals(this->livro->getCodigo()))
        this->status = TesteUnitario::FALHOU;
}

void LivroTst::validarData (const Data &data){
    this->livro->setDataPublicacao(data);

    if(!data.equals(this->livro->getDataPublicacao()))
        this->status = TesteUnitario::FALHOU;
}

void LivroTst::validarGenero (const GeneroLiterario &genero){
    this->livro->setGenero(genero);

    if(!genero.equals(this->livro->getGenero()))
        this->status = TesteUnitario::FALHOU;
}

void LivroTst::validarAutor (const Nome &autor){
    this->livro->setAutor(autor);

    if(!autor.equals(this->livro->getAutor()))
        this->status = TesteUnitario::FALHOU;
}

void LivroTst::validarTitulo (const Titulo &titulo){
    this->livro->setTitulo(titulo);

    if(!titulo.equals(this->livro->getTitulo()))
        this->status = TesteUnitario::FALHOU;
}
