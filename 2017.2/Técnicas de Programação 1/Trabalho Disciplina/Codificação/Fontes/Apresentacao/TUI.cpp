#include "../../Bibliotecas/Apresentacao/TUI.hpp"

void TUI::executar (){
    menu ();

    tentar ();
}

void TUI::tentar (){
    int tentativas = LIM_TENT;

    while (tentativas--){
        try{
            direcionar(leitura());
            break;
        }catch(...){ tratarErro();}
    }
}
