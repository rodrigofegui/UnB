#include "../../Bibliotecas/Entidade/Resultado.hpp"

const string Resultado::SUCESSO         ("Operou com sucesso.");
const string Resultado::FALHA           ("Operou com falha.");
const string Resultado::FLH_LIM         ("Operou com falha no limite.");
const string Resultado::FLH_AUT			("Operou com falha de autenticação.");
const string Resultado::FLH_BD			("Operou com falha na Base de Dados.");
const string Resultado::FLH_CAD			("Operou com falha de cadastramento.");

const string Resultado::ESC_AUTENTICAR  ("Escolheu autenticar.");
const string Resultado::ESC_CADASTRAR   ("Escolheu cadastrar.");
const string Resultado::ESC_SAIR        ("Escolheu sair.");

Resultado::Resultado(){ setCampo (Resultado::SUCESSO);}

Resultado::Resultado(const string &campo){setCampo(campo);}

Resultado::Resultado(Login *login){setCampo (Resultado::SUCESSO); setLogin(login);}

Resultado::Resultado(Apelido *apelido){setCampo (Resultado::SUCESSO); setApelido(apelido);}

Resultado::Resultado(Usuario *usuario){setCampo (Resultado::SUCESSO); setUsuario(usuario);}

bool Resultado::equals (const Resultado &alvo){
	if(DominioBase::equals(alvo)){
		if (this->apelido == alvo.getApelido()
			&& this->login == alvo.getLogin()
			&& this->usuario == alvo.getUsuario())
			return TesteUnitario::PASSOU;
	}

	return TesteUnitario::FALHOU;
}

void Resultado::deletar(){
	if (this->apelido)
		this->apelido->deletar ();

	if (this->login)
		this->login->deletar();

	if (this->usuario)
		this->usuario->deletar();

    delete this;
}
