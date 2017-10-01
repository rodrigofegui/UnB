#include "../../Bibliotecas_Tst/Dominio_Tst/Versao_Tst.hpp"

void VersaoTst::inicializar (){
    cout << "Testando Domínio/Versão:" << endl;

    corpoTeste = new Versao();
    this->status = TesteUnitario::PASSOU;
}

void VersaoTst::validar(){
    validarCampoNOk (INV[0]);
    validarCampoNOk (INV[1]);
    validarCampoNOk (INV[2]);
    validarCampoOk (VAL_REG[0]);
    validarCampoOk (VAL_REG[1]);
}
