#include "../../Bibliotecas/Dominio/OpResult.hpp"

void OpResult::deletar() {delete this;}

OpResult::OpResult(const string &campo){
    setCampo(campo);
}

const string OpResult::SUCESSO          ("Operação foi um sucesso.");
const string OpResult::FALHA            ("Operação falhou.");
const string OpResult::EXE_AUTENTICAR   ("Executar a função de Autenticar.");
const string OpResult::EXE_USUARIO      ("Executar a função de Usuario.");
const string OpResult::EXE_ESTANTE      ("Executar a função da Estante.");
const string OpResult::SAIR             ("Sair da execução atual.");

