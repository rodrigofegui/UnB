#include "../../Bibliotecas/Apresentacao/TUI.hpp"

void TUI::executar (){
    do{
        menu ();
    }while (tentar ().getCampo() != Resultado::ESC_SAIR);
}

Resultado TUI::tentar (){
    int tentativas = LIM_TENT;
    Resultado result;

    try{
        for (tentativas = LIM_TENT; tentativas > 0; tentativas--){
            result = leitura();

            if (result.getCampo() != Resultado::FALHA)
                break;
        }

        if (!tentativas)
            throw Resultado(Resultado::FLH_LIM);

        return direcionar(result);
    }catch(Resultado evento){   return tratarErro(evento);
    }catch(...){                return tratarErro();
    }
}
