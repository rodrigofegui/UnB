#include "../../Bibliotecas_Tst/Servico_Tst/ServAut_Tst.hpp"

const string ServAutTst::DIVISOR    (", ");
const string ServAutTst::TERMINACAO ("]");

const string ServAutTst::MSG_INI    ("Tentativa de autenticação: [");
const string ServAutTst::MSG_SUC    ("Sucesso ao autenticar.");
const string ServAutTst::MSG_EBD    ("Falha ao acessar a Base de Dados.");
const string ServAutTst::MSG_L_INE  ("Login falhou: registro inexistente.");

const string ServAutTst::LOGIN_INE ("inara");
const string ServAutTst::LOGIN_EBD ("dayse");

Resultado ServAutTst::autenticar (const Login &tentativa) throw (runtime_error){
    Log::escrever(msgInicio(tentativa));

    if(tentativa.getApelido().getCampo() == LOGIN_INE){
        Log::escrever(MSG_L_INE);
        return Resultado(Resultado::FLH_AUT);
    }

    if(tentativa.getApelido().getCampo() == LOGIN_EBD){
        Log::escrever(MSG_EBD);
        throw runtime_error (MSG_EBD);
    }

    Log::escrever(MSG_SUC);
    return Resultado(Resultado::SUCESSO);
}

string ServAutTst::msgInicio(const Login &tentativa){
    return MSG_INI + tentativa.getApelido().getCampo()
            + DIVISOR + tentativa.getSenha().getCampo() + TERMINACAO;
}
