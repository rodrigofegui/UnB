#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdIncluir.hpp"

const string ACmdIncluir::MSG_INICIO       ("Iniciada o comando de inserir Livro.");
const string ACmdIncluir::MSG_FINALIZAR    ("Comando de inserir Livro finalizado.");
const string ACmdIncluir::MSG_LER_TIT      ("Aquisição do Título com êxito.");
const string ACmdIncluir::MSG_LER_AUT      ("Aquisição do Autor com êxito.");
const string ACmdIncluir::MSG_LER_GEN      ("Aquisição do Gênero com êxito.");
const string ACmdIncluir::MSG_LER_DAT      ("Aquisição da Data com êxito.");
const string ACmdIncluir::MSG_ERRO_D       ("Erro na entrada de login ou na Base de Dados.");

ACmdIncluir::ACmdIncluir(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdIncluir::executar(){
    Log::escrever(MSG_INICIO);

    TUI::executar();

    return Resultado (Resultado::SUCESSO);
}

void ACmdIncluir::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*               Inserção de Livro                  *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar a inserção de um livro é preciso    *" << endl;
    cout << "* fornecer todos os dados; lembrando que:          *" << endl;
    cout << "*     - Título deve ter até 20 letras.             *" << endl;
    cout << "*     - Autor deve ter até letras (espaço e ponto) *" << endl;
    cout << "*     - Gênero deve ser:                           *" << endl;
    cout << "*          + EPOPEIA, NOVELA, CONTO, ENSAIO        *" << endl;
    cout << "*            ou ROMANCE                            *" << endl;
    cout << "*     - Data de publicação, deve estar na forma:   *" << endl;
    cout << "*          + dd/mm/aa                              *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado ACmdIncluir::leitura(){
    Titulo titulo;
    Nome autor;
    GeneroLiterario gen;
    Data data;

    char buffer[Titulo::TAM_MAX], buffer2[Nome::TAM_MAX];
    string transf;

    cout << "Digite o título: ";
        cin.getline(buffer, Titulo::TAM_MAX);
    transf = buffer;
    titulo.setCampo(transf);
    Log::escrever(MSG_LER_TIT);

    cout << "Digite o autor: ";
        cin.getline(buffer, Titulo::TAM_MAX);
    transf = buffer;
    autor.setCampo (transf);
    Log::escrever(MSG_LER_AUT);

    cout << "Digite o gênero: ";
        cin >> transf; getchar ();
    gen.setCampo (transf);
    Log::escrever(MSG_LER_GEN);

    cout << "Digite a data: ";
        cin >> transf; getchar ();
    data.setCampo (transf);
    Log::escrever(MSG_LER_DAT);

    Livro *novo = new Livro ();
    novo->setTitulo(titulo);
    novo->setAutor (autor);
    novo->setDataPublicacao (data);
    novo->setGenero (gen);

    return Resultado (novo);
}

Resultado ACmdIncluir::direcionar(const Resultado &escolha){
    this->servico->incluir(*(escolha.getLivro()));

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdIncluir::tratarErro (){
    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdIncluir::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdIncluir::finalizar(){
    Log::escrever(MSG_FINALIZAR);
}
