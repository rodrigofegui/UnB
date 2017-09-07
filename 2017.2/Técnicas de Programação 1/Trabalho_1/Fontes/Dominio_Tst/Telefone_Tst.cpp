#include "../../Bibliotecas/Dominio_Tst/Telefone_Tst.hpp"

void TelefoneTst::inicializar(){
    cout << "Testando Domínio/Telefone:" << endl;

    corpoTeste = new Telefone();
    this->status = TesteUnitario::PASSOU;
}

void TelefoneTst::validar(){
    validarCampoNOk(INV_TAM);
    validarCampoNOk(INV_NUM);
    validarCampoNOk(INV_FRMT[0]);
    validarCampoNOk(INV_FRMT[1]);
    validarCampoNOk(INV_FRMT[2]);

    validarCampoOk(VAL);
}
