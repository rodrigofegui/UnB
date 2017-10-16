#include "../../../Bibliotecas/Apresentacao/CtrlEst/AEst.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdConLivro.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdConUsuario.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdCriarResenha.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdIncluir.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdRemover.hpp"

const string AEst::MSG_INI          ("Iniciada a funcionalidade da Estante.");
const string AEst::MSG_FINALIZAR    ("Funcionalidade da Estante finalizada.");
const string AEst::MSG_LER          ("Leitura das opções do usuário na tela da Estante.");
const string AEst::MSG_ESC_INV      ("Leitura de um valor fora do intervalo.");

const string AEst::MSG_ERRO_D       ("Erro na entrada de login ou na Base de Dados.");


Resultado AEst::executar(const Resultado &apelido){
    Log::escrever(MSG_INI);

    setApelido(apelido.getApelido());

    TUI::executar();

    return Resultado (Resultado::SUCESSO);
}

void AEst::menu(){
    Manipulacao::limparTela();
    cout << "****************************************************" << endl;
    cout << "*                     Estante                      *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Olá " + this->apelido->getCampo() + ",                                       *" << endl;
    cout << "* São lhe oferecidas as opções:                    *" << endl;
    printf ("*     %d - Consulta de livro;                       *\n", CON_LIVRO);
    printf ("*     %d - Consulta de usuário;                     *\n", CON_USUARIO);
    printf ("*     %d - Criar resenha;                           *\n", CRIAR_RES);
    printf ("*     %d - Incluir exemplar de livro à estante;     *\n", INC_LIVRO);
    printf ("*     %d - Remover exemplar de livro da estante;    *\n", RMV_LIVRO);
    printf ("*     %d - Sair.                                    *\n", SAIR);
    cout << "****************************************************" << endl << endl;
}

Resultado AEst::leitura(){
    int resp = 0;

    Log::escrever(MSG_LER);
    cout << "Digite a sua escolha: ";
        cin >> resp; getchar ();

    switch(resp){
        case CON_LIVRO:
            return Resultado (Resultado::ESC_CONS_LIVRO);
        case CON_USUARIO:
            return Resultado (Resultado::ESC_CONS_USR);
        case CRIAR_RES:
            return Resultado (Resultado::ESC_CRI_RES);
        case INC_LIVRO:
            return Resultado (Resultado::ESC_INC_LIVRO);
        case RMV_LIVRO:
            return Resultado (Resultado::ESC_RMV_LIVRO);
        case SAIR:
            return Resultado (Resultado::ESC_SAIR);
        default:
            cout << MSG_ESC_INV << endl << endl;
            Log::escrever(MSG_ESC_INV);
		    return Resultado(Resultado::FALHA);
    }
}

Resultado AEst::direcionar(const Resultado &escolha){
    if (escolha.getCampo() == Resultado::ESC_SAIR)
        return escolha;

    if (escolha.getCampo() == Resultado::ESC_CONS_LIVRO)
        cmd = new ACmdConLivro (servico);

    else if (escolha.getCampo() == Resultado::ESC_CONS_USR)
        cmd = new ACmdConUsuario (servico);

    else if (escolha.getCampo() == Resultado::ESC_CRI_RES)
        cmd = new ACmdCriarResenha (servico);

    else if (escolha.getCampo() == Resultado::ESC_INC_LIVRO)
        cmd = new ACmdIncluir (servico);

    else if (escolha.getCampo() == Resultado::ESC_RMV_LIVRO)
        cmd = new ACmdRemover (servico);

    else
        return Resultado (Resultado::FALHA);

    return cmd->executar();
}

Resultado AEst::tratarErro (){
    this->apelido->clear();

    Log::escrever(MSG_ERRO_D);
    cout << MSG_ERRO_D << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado AEst::tratarErro (const Resultado &evento){
    return Resultado(Resultado::ESC_SAIR);
}

void AEst::finalizar(){
    /*if(this->servico)
        delete this->servico;

    if(this->cmd)
        delete this->cmd;
        //*/

    Log::escrever(MSG_FINALIZAR);
}
