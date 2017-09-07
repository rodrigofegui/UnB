#include "../../Bibliotecas/Dominio_Tst/Texto_Tst.hpp"

void TextoTst::inicializar(){
    cout << "Testando Domínio/Texto:" << endl;

    corpoTeste = new Texto();
    this->status = TesteUnitario::PASSOU;
}

void TextoTst::validar(){
    validarCampoNOk(INV_LIM);
    validarCampoOk(VAL_MENOS);
    validarCampoOk(VAL_LIM);
}
