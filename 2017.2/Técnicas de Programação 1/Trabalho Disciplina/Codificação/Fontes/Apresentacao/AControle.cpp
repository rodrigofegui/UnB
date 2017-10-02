#include "../../Bibliotecas/Apresentacao/AControle.hpp"


void AControle::executar(){
    construir();

    aplicacao();

    finalizar();
}

OpResult AControle::construir(){
    OpResult resultado(OpResult::SUCESSO);
    cout << "Construindo" << endl;

    return resultado;
}

void AControle::aplicacao(){
    OpResult resultado;
    do{
        resultado = apresentarTUI();

        avaliar(resultado);

        Manipulacao::pausar();
    }while(resultado.getCampo() != OpResult::SAIR);
}

OpResult AControle::apresentarTUI(){
    OpResult resultado;

    Manipulacao::limparTela();

    cout << "********************************" << endl;
    cout << "   Página Inicial da Estante"     << endl << endl;
    cout << " Menu:"                           << endl;
    cout << "   1 - Login"                     << endl;
    cout << "   2 - Cadastro"                  << endl;
    cout << "   0 - Sair"                      << endl;
    cout << "********************************" << endl << endl;

    switch (Manipulacao::aguardarResp(2)){
        case 1: resultado.setCampo(OpResult::EXE_AUTENTICAR); break;
        case 2: resultado.setCampo(OpResult::EXE_USUARIO); break;
        case 0: resultado.setCampo(OpResult::SAIR); break;
    }

    return resultado;
}

void AControle::avaliar(const OpResult &result){
    if (result.getCampo() == OpResult::EXE_AUTENTICAR)
        autenticar();
    else if (result.getCampo() == OpResult::EXE_USUARIO)
        usuario();
    else if (result.getCampo() == OpResult::EXE_ESTANTE)
        estante();
}

OpResult AControle::autenticar(){
    OpResult resultado(OpResult::SUCESSO);
    cout << endl << "Entrou na autenticação!" << endl;

    //funcAut->executar();
    return resultado;
}

OpResult AControle::usuario(){
    OpResult resultado(OpResult::SUCESSO);
    cout << endl << "Entrou no usuário!" << endl;

    //funcUsu->executar();
    return resultado;
}

OpResult AControle::estante(){
    OpResult resultado(OpResult::SUCESSO);
    cout << endl << "Entrou na estante!" << endl;

    //funcEst->executar();
    return resultado;
}

void AControle::finalizar(){
    /*
    funcAut->deletar();
    funcUsu->deletar();
    funcEst->deletar();
    */
}
