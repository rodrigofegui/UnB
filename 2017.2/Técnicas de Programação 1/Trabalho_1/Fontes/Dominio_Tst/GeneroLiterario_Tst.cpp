#include "../../Bibliotecas/Dominio_Tst/GeneroLiterario_Tst.hpp"

void GeneroLiterarioTst::inicializar(){
    this->genLit = new GeneroLiterario();
    this->status = TesteUnitario::PASSOU;
}

void GeneroLiterarioTst::validar(){
    validarCampoNOk (INVALIDO[0]);
    validarCampoNOk (INVALIDO[1]);
    validarCampoNOk (INVALIDO[2]);
    validarCampoNOk (INVALIDO[3]);
    validarCampoOk (VALIDO_REG[0]);
    validarCampoOk (VALIDO_REG[1]);
    validarCampoOk (VALIDO_REG[2]);
    validarCampoOk (VALIDO_REG[3]);
    validarCampoOk (VALIDO_REG[4]);
}

void GeneroLiterarioTst::validarCampoOk (string campo){
    try{
        this->genLit->setCampo(campo);
        if(!TesteUnitario::expect_EQ(this->genLit->getCampo(), campo))
            status = TesteUnitario::FALHOU;

    }catch (invalid_argument e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }catch (length_error e){
        cout << e.what() << endl;
        status = TesteUnitario::FALHOU;
    }
}

void GeneroLiterarioTst::validarCampoNOk (string campo){
    try{
        this->genLit->setCampo(campo);
        status = TesteUnitario::FALHOU;

    }catch (invalid_argument e){
    }catch (length_error e){}
}

void GeneroLiterarioTst::finalizar(){
    delete this->genLit;
}
