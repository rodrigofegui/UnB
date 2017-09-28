#include "../../Bibliotecas_Tst/Dominio_Tst/Data_Tst.hpp"

void DataTst::inicializar(){
    cout << "Testando Domínio/Data:" << endl;

    corpoTeste = new Data();
    this->status = TesteUnitario::PASSOU;
}

void DataTst::validar (){
    validarCampoNOk (INV_FORM_0);
    validarCampoNOk (INV_FORM_1);
    validarCampoNOk (INV_FORM_2);
    validarCampoNOk (INV_FORM_3);
    validarCampoNOk (INV_DIA_0);
    validarCampoNOk (INV_DIA_1);
    validarCampoNOk (INV_MES_0);
    validarCampoNOk (INV_MES_1);
    validarCampoNOk (INV_ANO_0);
    validarCampoOk  (VAL_0);
    validarCampoNOk (INV_DATA_0);
    validarCampoNOk (INV_DATA_1);
    validarCampoOk  (VAL_1);
    validarCampoOk  (VAL_2);
    validarCampoNOk (INV_DATA_2);
    validarCampoNOk (INV_DATA_3);
}
