#include "../../Bibliotecas_Tst/Servico_Tst/ServAut_Tst.hpp"

const string ServAutTst::DIVISOR    (Mensagem::FMT_DVS);
const string ServAutTst::TERMINACAO (Mensagem::FMT_TRM_GLB);

const string ServAutTst::MSG_INI    (Mensagem::INI_TST);

const string ServAutTst::LOGIN_EXI  ("rodfg");
const string ServAutTst::LOGIN_INE  ("inara");
const string ServAutTst::LOGIN_EBD  ("dayse");

Resultado ServAutTst::autenticar (const Login &tentativa) throw (runtime_error){
    Log::escrever(msgInicio(tentativa));

    if(tentativa.getApelido().getCampo() == LOGIN_INE){
        Log::escrever(Mensagem::FLH_LGN);
        return Resultado(Resultado::FLH_AUT);
    }

    if(tentativa.getApelido().getCampo() == LOGIN_EBD){
        Log::escrever(Mensagem::ERR_ABD);
        throw runtime_error (Mensagem::ERR_ABD);
    }

    Log::escrever(Mensagem::SUC_AUT);
    return Resultado(Resultado::SUCESSO);
}

string ServAutTst::msgInicio(const Login &tentativa){
    return MSG_INI + tentativa.getApelido().getCampo()
            + DIVISOR + tentativa.getSenha().getCampo() + TERMINACAO;
}
