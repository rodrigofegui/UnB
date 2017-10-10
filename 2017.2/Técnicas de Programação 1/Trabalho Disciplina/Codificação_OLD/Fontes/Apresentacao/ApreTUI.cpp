#include "../../Bibliotecas/Apresentacao/ApreTUI.hpp"

OpResult ApreTUI::executar (){
    menu ();

    criar ();

    tentativas();

    return OpResult(OpResult::SAIR);
}

void ApreTUI::tentativas(){
    int tentativas = MAX_TENTATIVAS;

    while (tentativas--){
        try{
            servico(configurar());
        }catch (invalid_argument e){
            erroOp(OpResult::ERR_ENTRADA);
        }
    }

    if (!tentativas)
        erroOp(OpResult::LIM_TENTA);
}

