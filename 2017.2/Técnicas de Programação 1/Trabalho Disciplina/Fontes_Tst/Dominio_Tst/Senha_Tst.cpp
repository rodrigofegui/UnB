#include "../../Bibliotecas_Tst/Dominio_Tst/Senha_Tst.hpp"

void SenhaTst::inicializar(){
    cout << "Testando Domínio/Senha:" << endl;

    corpoTeste = new Senha ();
    this->status = TesteUnitario::PASSOU;
}

void SenhaTst::validar(){
    validarCampoNOk(INV_TAM);
    validarCampoNOk(INV_NUM);
    validarCampoNOk(INV_SIM);
    validarCampoNOk(INV_REP[0]);
    validarCampoNOk(INV_REP[1]);
    validarCampoOk(VAL[0]);
    validarCampoOk(VAL[1]);
    validarCampoOk(VAL[2]);
}
