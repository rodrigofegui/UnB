#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdIncluir.hpp"

ACmdIncluir::ACmdIncluir(InterSEst *servico){
    this->servico = servico;
}

Resultado ACmdIncluir::executar(){
    Log::escrever(Mensagem::INI_EST_INC_LVR);

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

	Log::escrever (Mensagem::LEITURA);

    cout << Mensagem::LER_TIT;
        cin.getline(buffer, Titulo::TAM_MAX);
    	transf = buffer;
    		titulo.setCampo(transf);
    Log::escrever(Mensagem::AQS_TIT);

    cout << Mensagem::LER_ATR;
        cin.getline(buffer, Titulo::TAM_MAX);
    	transf = buffer;
    		autor.setCampo (transf);
    Log::escrever(Mensagem::AQS_ATR);

    cout << Mensagem::LER_GEN;
        cin >> transf; getchar ();
    		gen.setCampo (transf);
    Log::escrever(Mensagem::AQS_GEN);

    cout << Mensagem::LER_DAT;
        cin >> transf; getchar ();
    		data.setCampo (transf);
    Log::escrever(Mensagem::AQS_DAT);

    Livro *novo = new Livro ();
    novo->setTitulo(titulo);
    novo->setAutor (autor);
    novo->setDataPublicacao (data);
    novo->setGenero (gen);

	Log::escrever(Mensagem::CRI_LVR);

    return Resultado (novo);
}

Resultado ACmdIncluir::direcionar(const Resultado &escolha){
    this->servico->incluir(*(escolha.getLivro()));

    Manipulacao::pausar();

    escolha.clear();
    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdIncluir::tratarErro (){
    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdIncluir::tratarErro (const Resultado &evento){
    evento.clear();
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdIncluir::finalizar(){
    delete this;

    Log::escrever(Mensagem::FIM_EST_INC_LVR);
}
