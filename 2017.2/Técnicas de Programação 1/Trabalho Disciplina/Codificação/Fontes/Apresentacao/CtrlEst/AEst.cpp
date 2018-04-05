#include "../../../Bibliotecas/Apresentacao/CtrlEst/AEst.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdConLivro.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdConUsuario.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdCriarResenha.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdIncluir.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdRemover.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdProcurar.hpp"
#include "../../../Bibliotecas/Apresentacao/CtrlEst/ACmdSinTroca.hpp"

Resultado AEst::executar(const Resultado &apelido){
    Log::escrever(Mensagem::INI_EST);

    setApelido(apelido.getApelido());

    TUI::executar();

    apelido.clear();
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
    printf ("*     %d - Consulta de troca;                       *\n", CON_TROCA);
    printf ("*     %d - Criar resenha;                           *\n", CRIAR_RES);
    printf ("*     %d - Incluir exemplar de livro à estante;     *\n", INC_LIVRO);
    printf ("*     %d - Remover exemplar de livro da estante;    *\n", RMV_LIVRO);
    printf ("*     %d - Sinalizar disponibilidade de troca;      *\n", SIN_TROCA);
    printf ("*     %d - Sair.                                    *\n", SAIR);
    cout << "****************************************************" << endl << endl;
}

Resultado AEst::leitura(){
    int resp = 0;

    Log::escrever(Mensagem::LEITURA);
    cout << Mensagem::LER_ESC;
        cin >> resp; getchar ();

    switch(resp){
        case CON_LIVRO:
            return Resultado (Resultado::ESC_CONS_LIVRO);
        case CON_USUARIO:
            return Resultado (Resultado::ESC_CONS_USR);
        case CON_TROCA:
            return Resultado (Resultado::ESC_CONS_TRC);
        case CRIAR_RES:
            return Resultado (Resultado::ESC_CRI_RES);
        case INC_LIVRO:
            return Resultado (Resultado::ESC_INC_LIVRO);
        case RMV_LIVRO:
            return Resultado (Resultado::ESC_RMV_LIVRO);
        case SIN_TROCA:
            return Resultado (Resultado::ESC_SIN_TROCA);
        case SAIR:
            return Resultado (Resultado::ESC_SAIR);
        default:
            cout << Mensagem::FLH_ESC << endl << endl;
            Log::escrever(Mensagem::FLH_ESC);
		    return Resultado(Resultado::FALHA);
    }
}

Resultado AEst::direcionar(const Resultado &escolha){
    if (escolha.getCampo() == Resultado::ESC_SAIR)
        return escolha;

    if (escolha.getCampo() == Resultado::ESC_CONS_LIVRO){
		Log::escrever (Mensagem::RED_EST_CON_LVR);
        cmd = new ACmdConLivro (servico);

    }else if (escolha.getCampo() == Resultado::ESC_CONS_USR){
		Log::escrever (Mensagem::RED_EST_CON_USR);
        cmd = new ACmdConUsuario (servico);

    }else if (escolha.getCampo() == Resultado::ESC_CONS_TRC){
		Log::escrever (Mensagem::RED_EST_CON_TRC);
        cmd = new ACmdProcurar (servico);

    }else if (escolha.getCampo() == Resultado::ESC_CRI_RES){
		Log::escrever (Mensagem::RED_EST_CRS);
        cmd = new ACmdCriarResenha (servico);

    }else if (escolha.getCampo() == Resultado::ESC_INC_LIVRO){
		Log::escrever (Mensagem::RED_EST_INC_LVR);
        cmd = new ACmdIncluir (servico);

    }else if (escolha.getCampo() == Resultado::ESC_RMV_LIVRO){
		Log::escrever (Mensagem::RED_EST_RMV_LVR);
		cmd = new ACmdRemover (servico);

    }else if (escolha.getCampo() == Resultado::ESC_SIN_TROCA){
		Log::escrever (Mensagem::RED_EST_STR);
        cmd = new ACmdSinTroca (servico, this->apelido);

    }else{
        escolha.clear();
        return Resultado (Resultado::FALHA);
    }

    escolha.clear();
    return cmd->executar();
}

Resultado AEst::tratarErro (){
    this->apelido->clear();

    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);
}

Resultado AEst::tratarErro (const Resultado &evento){
    evento.clear();
    return Resultado(Resultado::ESC_SAIR);
}

void AEst::finalizar(){
    if(this->servico)
        delete this->servico;

    delete this;

    Log::escrever(Mensagem::FIM_EST);
}
