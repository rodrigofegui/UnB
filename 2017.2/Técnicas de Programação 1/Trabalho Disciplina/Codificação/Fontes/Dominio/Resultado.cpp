#include "../../Bibliotecas/Dominio/Resultado.hpp"

const string Resultado::SUCESSO         ("Operou com sucesso.");
const string Resultado::FALHA           ("Operou com falha.");
const string Resultado::FLH_LIM         ("Operou com falha no limite.");

const string Resultado::ESC_AUTENTICAR  ("Escolheu autenticar.");
const string Resultado::ESC_CADASTRAR   ("Escolheu cadastrar.");
const string Resultado::ESC_SAIR        ("Escolheu sair.");

Resultado::Resultado(const string &campo){ setCampo(campo);}

void Resultado::validar (const string &campo) throw (invalid_argument){}

void Resultado::deletar() {delete this;}
