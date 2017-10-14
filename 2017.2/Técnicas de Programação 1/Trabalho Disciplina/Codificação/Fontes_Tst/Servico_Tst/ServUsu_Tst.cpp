#include "../../Bibliotecas_Tst/Servico_Tst/ServUsu_Tst.hpp"

const string ServUsuTst::DIVISOR    (", ");
const string ServUsuTst::TERMINACAO ("]");

const string ServUsuTst::MSG_SUC        ("Sucesso ao cadastrar.");
const string ServUsuTst::MSG_INI        ("Tentativa de cadastro: [");
const string ServUsuTst::MSG_CADST_EXT  ("Cadastro de usuário já existente.");
const string ServUsuTst::MSG_CADST_EBD  ("Falha ao acessar a Base de Dados.");

const string ServUsuTst::CADST_EXT      ("leila");
const string ServUsuTst::CADST_EBD      ("zelma");

Resultado ServUsuTst::cadastrar(const Usuario &tentativa) throw (runtime_error){
    Log::escrever(msgInicio(tentativa));

    if(tentativa.getApelido().getCampo() == CADST_EXT){
        Log::escrever(MSG_CADST_EXT);
        return Resultado(Resultado::FLH_CAD);
    }

    if(tentativa.getApelido().getCampo() == CADST_EBD){
        Log::escrever(MSG_CADST_EBD);
        throw runtime_error (MSG_CADST_EBD);
    }

    Log::escrever(MSG_SUC);
    return Resultado (Resultado::SUCESSO);
}

string ServUsuTst::msgInicio(const Usuario &tentativa){
    return MSG_INI + tentativa.getApelido().getCampo()
                   + DIVISOR + tentativa.getNome().getCampo()
                   + DIVISOR + tentativa.getTelefone().getCampo()
                   + DIVISOR + tentativa.getSenha().getCampo() + TERMINACAO;
}
