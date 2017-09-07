#include "../../Bibliotecas/Dominio_Tst/DominioBase_Tst.hpp"

void DominioBaseTst::finalizar(){
    if(this->status)
        cout << "APROVADO!" << endl << endl;
    else cout << "REPROVADO!" << endl << endl;

    this->corpoTeste->deletar();

    delete this;
}

void DominioBaseTst::validarCampoOk (const string &campo){
    try{
        this->corpoTeste->setCampo(campo);
        if(!TesteUnitario::expect_EQ(this->corpoTeste->getCampo(), campo))
            this->status = TesteUnitario::FALHOU;
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
        this->status = TesteUnitario::FALHOU;

    }catch (invalid_argument e){
        cout << e.what() << endl;
    }catch (length_error e){
        cout << e.what() << endl;
    }
}
