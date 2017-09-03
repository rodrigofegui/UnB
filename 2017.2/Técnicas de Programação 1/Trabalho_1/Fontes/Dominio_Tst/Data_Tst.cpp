#include "../../Bibliotecas/Dominio_Tst/Data_Tst.hpp"

void DataTst::inicializar(){
    this->data = new Data();
    this->status = TesteUnitario::PASSOU;
}

void DataTst::validar (){
    validarCampoNOk (INVALIDO_FORM_0);
    validarCampoNOk (INVALIDO_FORM_1);
    validarCampoNOk (INVALIDO_FORM_2);
    validarCampoNOk (INVALIDO_FORM_3);
    validarCampoNOk (INVALIDO_DIA_0);
    validarCampoNOk (INVALIDO_DIA_1);
    validarCampoNOk (INVALIDO_MES_0);
    validarCampoNOk (INVALIDO_MES_1);
    validarCampoNOk (INVALIDO_ANO_0);
    validarCampoOk  (VALIDO_0);
    validarCampoNOk (INVALIDO_DATA_0);
    validarCampoNOk (INVALIDO_DATA_1);
    validarCampoOk  (VALIDO_1);
    validarCampoOk  (VALIDO_2);
    validarCampoNOk (INVALIDO_DATA_2);
}

void DataTst::validarCampoOk (string campo){
    try{
        this->data->setCampo(campo);
        if(!TesteUnitario::expect_EQ(this->data->getCampo(), campo))
            status = TesteUnitario::FALHOU;

    }catch (invalid_argument e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }catch (length_error e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }
}

void DataTst::validarCampoNOk (string campo){
    try{
        this->data->setCampo(campo);
        status = TesteUnitario::FALHOU;

    }catch (invalid_argument e){
    }catch (length_error e){}
}

void DataTst::finalizar(){
    delete this->data;
}
