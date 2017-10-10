#include "../../Bibliotecas_Tst/Servico_Tst/SAutenticacao_Tst.hpp"

const Login SAutenticacaoTst::VALIDO    (Apelido("jose"), Senha("abcd"));
const Login SAutenticacaoTst::INV_DADOS (Apelido("dado"), Senha("abcd"));
const Login SAutenticacaoTst::INV_BASE  (Apelido("base"), Senha("abcd"));

OpResult SAutenticacaoTst::autenticar (const Login &login){
    if(login.equals(VALIDO))
        return OpResult::SUCESSO;

    if(login.equals(INV_DADOS))
        return OpResult::ERR_ENTRADA;

    if(login.equals(INV_BASE))
        return OpResult::ERR_BASE_DADOS;
}
