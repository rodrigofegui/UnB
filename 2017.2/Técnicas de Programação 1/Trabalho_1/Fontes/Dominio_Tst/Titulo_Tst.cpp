#include "../../Bibliotecas/Dominio_Tst/Titulo_Tst.hpp"

void TituloTst::inicializar(){
    cout << "Testando Domínio/Título:" << endl;

    corpoTeste = new Titulo();
    this->status = TesteUnitario::PASSOU;
}

void TituloTst::validar(){
    validarCampoNOk(INV_LIM);
    validarCampoNOk(INV_2_SPACE);
    validarCampoOk(VAL_LIM);
    validarCampoOk(VAL_ACT);
    validarCampoOk(VAL_SIM);
}
