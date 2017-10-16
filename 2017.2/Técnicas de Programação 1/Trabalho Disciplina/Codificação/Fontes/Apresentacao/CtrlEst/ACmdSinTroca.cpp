#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdSinTroca.hpp"

const string ACmdSinTroca::MSG_INICIO       ("Iniciada o comando de sinalizar disponibilidade para troca de  Livro.");
const string ACmdSinTroca::MSG_FINALIZAR    ("Comando de sinalizar disponibilidade para troca Livro finalizado.");
const string ACmdSinTroca::MSG_LER_TIT      ("Aquisição do Título com êxito.");
const string ACmdSinTroca::MSG_LER_DIS      ("Aquisição da Disponibilidade com êxito.");
const string ACmdSinTroca::MSG_ERRO_D       ("Erro na entrada de login ou na Base de Dados.");

ACmdSinTroca::ACmdSinTroca(InterSEst *servico){
    this->servico = servico;
}

ACmdSinTroca::ACmdSinTroca(InterSEst *servico, Apelido *apelido){
    this->servico = servico;
    this->apelido = apelido;
}

Resultado ACmdSinTroca::executar(){
    Log::escrever(MSG_INICIO);

    TUI::executar();

    return Resultado (Resultado::SUCESSO);
}

void ACmdSinTroca::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*            Sinalizar Troca de Livro              *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar a sinalização da disponibilidade ou *" << endl;
    cout << "* não para troca de um livro é preciso fornecer    *" << endl;
    cout << "* algum título; lembrando que:                     *" << endl;
    cout << "*     - Título deve ter até 20 letras.             *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado ACmdSinTroca::leitura(){
    char buffer[Titulo::TAM_MAX];
    string transf;

    cout << "Digite o título: ";
        cin.getline(buffer, Titulo::TAM_MAX);
    Log::escrever(MSG_LER_TIT);
    transf = buffer;
    Titulo *novo = new Titulo ();
    novo->setCampo(transf);

    cout << "Há disponibilidade? S/N: ";
        cin >> transf; getchar ();
    Log::escrever(MSG_LER_DIS);

    if (transf == "S")
        return Resultado (novo, true);
    else
        return Resultado (novo, false);
}

Resultado ACmdSinTroca::direcionar(const Resultado &escolha){
    Resultado result = this->servico->sinTroca(*(this->apelido), *(escolha.getTitulo()), escolha.getDisponibilidade());

    if (escolha.getDisponibilidade()){
        cout << "Usuário(s) interessado(s): " << endl;
        cout << "Apelido: " + result.getUsuario()->getApelido().getCampo() << endl;
    }

    Manipulacao::pausar();

    return Resultado (Resultado::ESC_SAIR);
}

Resultado ACmdSinTroca::tratarErro (){
    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado ACmdSinTroca::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void ACmdSinTroca::finalizar(){
    Log::escrever(MSG_FINALIZAR);
}
