#include "../../Bibliotecas/Dominio_Tst/Texto_Tst.hpp"

void TextoTst::inicializar(){
    corpoTeste = new Texto();
    this->status = TesteUnitario::PASSOU;
}

void TextoTst::validar(){
    validarCampoNOk(INV_LIM);
    validarCampoOk(VAL_MENOS);
    validarCampoOk(VAL_LIM);
}
