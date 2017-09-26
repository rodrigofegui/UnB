#include "../../Bibliotecas_Tst/Dominio_Tst/Codigo_Tst.hpp"

void CodigoTst::inicializar(){
    cout << "Testando Domínio/Codigo:" << endl;

    corpoTeste = new Codigo();
    this->status = TesteUnitario::PASSOU;
}

void CodigoTst::validar (){
    validarCampoNOk (INV_LETRA);
    validarCampoNOk (INV_LETRA);
    validarCampoNOk (INV_MENOS);
    validarCampoOk  (VAL_MAX);
}
