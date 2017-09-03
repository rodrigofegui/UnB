#include "../../Bibliotecas/Dominio_Tst/Apelido_Tst.hpp"

void ApelidoTst::inicializar(){
    this->apelido = new Apelido();
    this->status = TesteUnitario::PASSOU;
}

void ApelidoTst::validar(){
    validarCampo(CORRETO_LIM_LETRAS, TesteUnitario::CORRETO);

    validarCampo(ERRADO_LIM_NUM, TesteUnitario::ERRADO);

    validarCampo(ERRADO_ALFANUM, TesteUnitario::ERRADO);

    validarCampo(CORRETO_MENOS_LETRAS, TesteUnitario::CORRETO);

    validarCampo(ERRADO_ALFA_SIMB, TesteUnitario::ERRADO);
}

void ApelidoTst::validarCampo (string campo, bool cond){
    #ifdef ECHO_MSG_TST
        cout << "\nCampo A: " + this->apelido->getCampo() << endl;
        cout << "Tentando: " + campo << endl;
    #endif // ECHO_MSG_TST

    if (cond == TesteUnitario::ERRADO)
        validarCampoNOk (campo);
    else
        validarCampoOk (campo);

    #ifdef ECHO_MSG_TST
        cout << "Campo D: " + this->apelido->getCampo() << endl;
    #endif // ECHO_MSG_TST
}

void ApelidoTst::validarCampoOk (string campo){
    try{
        this->apelido->setCampo(campo);
        if(!TesteUnitario::expect_EQ(this->apelido->getCampo(), campo))
            status = TesteUnitario::FALHOU;

    }catch (invalid_argument e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }catch (length_error e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }
}

void ApelidoTst::validarCampoNOk (string campo){
    try{
        this->apelido->setCampo(campo);
        status = TesteUnitario::FALHOU;

    }catch (invalid_argument InvArg){
    }catch (length_error LenErr){}
}

void ApelidoTst::finalizar(){
    this->apelido->deletar();
}
