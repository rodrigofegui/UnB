#include "../../Bibliotecas/Dominio_Tst/Nome_Tst.hpp"


void NomeTst::inicializar(){
    corpoTeste = new Nome();
    this->status = TesteUnitario::PASSOU;
}

void NomeTst::validar(){
    validarCampoNOk(INV_TAM);
    validarCampoNOk(INV_NUM);
    validarCampoNOk(INV_SIMB);
    validarCampoOk(VAL[0]);
    validarCampoOk(VAL[1]);
    validarCampoOk(VAL[2]);
    validarCampoNOk(INV_2_PONTO);
    validarCampoNOk(INV_2_SPACE);
}
