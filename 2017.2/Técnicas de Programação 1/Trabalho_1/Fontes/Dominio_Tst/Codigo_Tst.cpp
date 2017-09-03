#include "../../Bibliotecas/Dominio_Tst/Codigo_Tst.hpp"

void CodigoTst::inicializar(){
    this->codigo = new Codigo();
    this->status = TesteUnitario::PASSOU;
}

void CodigoTst::validar (){
    validarCampoNOk (invalido_Limite);
    validarCampoNOk (invalido_Menos);
    validarCampoNOk (invalido_Letra);
    validarCampoOk  (valido_Max);
}

void CodigoTst::validarCampoOk (string campo){
    try{
        this->codigo->setCampo(campo);
        if(!TesteUnitario::expect_EQ(this->codigo->getCampo(), campo))
            status = TesteUnitario::FALHOU;

    }catch (invalid_argument e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }catch (length_error e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }
}

void CodigoTst::validarCampoNOk (string campo){
    try{
        this->codigo->setCampo(campo);
        status = TesteUnitario::FALHOU;

    }catch (invalid_argument InvArg){
    }catch (length_error LenErr){}
}

void CodigoTst::finalizar(){
    delete this->codigo;
}
