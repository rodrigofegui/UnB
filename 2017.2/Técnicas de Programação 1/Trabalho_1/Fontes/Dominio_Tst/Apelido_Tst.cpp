#include "../../Bibliotecas/Dominio_Tst/Apelido_Tst.hpp"

void ApelidoTst::inicializar(){
    corpoTeste = new Apelido();
    this->status = TesteUnitario::PASSOU;
}

void ApelidoTst::validar(){
    validarCampoOk(VAL_LIM_LETRAS);

    validarCampoNOk(INV_LIM_NUM);

    validarCampoNOk(INV_ALFANUM);

    validarCampoOk(VAL_MENOS_LETRAS);

    validarCampoNOk(INV_ALFA_SIMB);
}




