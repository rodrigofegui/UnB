#include "../../Bibliotecas/Apresentacao/TUI.hpp"

bool TUI::iniciouLog = TesteUnitario::FALHOU;

void TUI::executar (){

    if (!this->iniciouLog){
        this->iniciouLog = !this->iniciouLog;
        Log::iniciar();
    }

    do{
        menu ();
    }while (tentar().getCampo() != Resultado::ESC_SAIR);

    finalizar ();
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

    	result = direcionar(result);

		if (result.getCampo() != Resultado::SUCESSO)
			throw result;

		return result;

    }catch(Resultado evento){   return tratarErro(evento);
    }catch(...){                return tratarErro();
    }
}
