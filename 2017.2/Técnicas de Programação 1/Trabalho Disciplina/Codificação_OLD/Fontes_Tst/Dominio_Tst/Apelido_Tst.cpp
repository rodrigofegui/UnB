#include "../../Bibliotecas_Tst/Dominio_Tst/Apelido_Tst.hpp"

void ApelidoTst::inicializar(){
    cout << "Testando Domínio/Apelido:" << endl;

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




