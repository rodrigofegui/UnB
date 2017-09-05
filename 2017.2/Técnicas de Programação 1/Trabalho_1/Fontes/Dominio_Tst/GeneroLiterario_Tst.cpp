#include "../../Bibliotecas/Dominio_Tst/GeneroLiterario_Tst.hpp"

void GeneroLiterarioTst::inicializar(){
    corpoTeste = new GeneroLiterario();
    this->status = TesteUnitario::PASSOU;
}

void GeneroLiterarioTst::validar(){
    validarCampoNOk (INV[0]);
    validarCampoNOk (INV[1]);
    validarCampoNOk (INV[2]);
    validarCampoNOk (INV[3]);
    validarCampoOk (VAL_REG[0]);
    validarCampoOk (VAL_REG[1]);
    validarCampoOk (VAL_REG[2]);
    validarCampoOk (VAL_REG[3]);
    validarCampoOk (VAL_REG[4]);
}
