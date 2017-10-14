#include "../../Bibliotecas/Entidade/Resultado.hpp"

const string Resultado::SUCESSO         ("Operou com sucesso.");
const string Resultado::FALHA           ("Operou com falha.");
const string Resultado::FLH_LIM         ("Operou com falha no limite.");
const string Resultado::FLH_AUT			("Operou com falha de autenticação.");
const string Resultado::FLH_BD			("Operou com falha na Base de Dados");

const string Resultado::ESC_AUTENTICAR  ("Escolheu autenticar.");
const string Resultado::ESC_CADASTRAR   ("Escolheu cadastrar.");
const string Resultado::ESC_SAIR        ("Escolheu sair.");

Resultado::Resultado(){ setCampo (Resultado::SUCESSO);}

Resultado::Resultado(const string &campo){setCampo(campo);}

Resultado::Resultado(Login *login){setCampo (Resultado::SUCESSO); setLogin(login);}

Resultado::Resultado(Apelido *apelido){setCampo (Resultado::SUCESSO); setApelido(apelido);}

void Resultado::validar (const string &campo) throw (invalid_argument){}

void Resultado::deletar(){
    this->login->deletar();

    delete this;
}
