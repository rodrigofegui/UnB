#include "../../Bibliotecas/Dominio_Tst/Codigo_Tst.hpp"

void CodigoTst::inicializar(){
    corpoTeste = new Codigo();
    this->status = TesteUnitario::PASSOU;
}

void CodigoTst::validar (){
    validarCampoNOk (INV_LETRA);
    validarCampoNOk (INV_LETRA);
    validarCampoNOk (INV_MENOS);
    validarCampoOk  (VAL_MAX);
}
