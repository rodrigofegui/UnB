#include "../../Bibliotecas/Dominio_Tst/DominioBase_Tst.hpp"

void DominioBaseTst::finalizar(){
    this->corpoTeste->deletar();

    if(status)
        cout << "APROVADO!" << endl << endl;
    else cout << "REPROVADO!" << endl << endl;
}

void DominioBaseTst::validarCampoOk (const string &campo){
    try{
        this->corpoTeste->setCampo(campo);
        if(!TesteUnitario::expect_EQ(this->corpoTeste->getCampo(), campo))
            status = TesteUnitario::FALHOU;

    }catch (invalid_argument e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }catch (length_error e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }
}

void DominioBaseTst::validarCampoNOk (const string &campo){
    try{
        this->corpoTeste->setCampo(campo);
        status = TesteUnitario::FALHOU;

    }catch (invalid_argument InvArg){
    }catch (length_error LenErr){}
}
