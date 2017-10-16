#include "../../Bibliotecas/Entidade/Resultado.hpp"

const string Resultado::SUCESSO         ("Operou com sucesso.");
const string Resultado::FALHA           ("Operou com falha.");
const string Resultado::FLH_LIM         ("Operou com falha no limite.");
const string Resultado::FLH_AUT			("Operou com falha de autenticação.");
const string Resultado::FLH_BD			("Operou com falha na Base de Dados.");
const string Resultado::FLH_CAD			("Operou com falha de cadastramento.");
const string Resultado::FLH_CON			("Operou com falha de consulta.");
const string Resultado::FLH_CRI			("Operou com falha de criação.");
const string Resultado::FLH_INC			("Operou com falha de inserção.");
const string Resultado::FLH_RMV			("Operou com falha de remoção.");

const string Resultado::ESC_AUTENTICAR  ("Escolheu autenticar.");
const string Resultado::ESC_CADASTRAR   ("Escolheu cadastrar.");
const string Resultado::ESC_CONS_LIVRO  ("Escolheu consultar livro.");
const string Resultado::ESC_CONS_USR    ("Escolheu consultar usuário.");
const string Resultado::ESC_CRI_RES		("Escolheu criar resenha.");
const string Resultado::ESC_INC_LIVRO   ("Escolheu inserir livro.");
const string Resultado::ESC_RMV_LIVRO   ("Escolheu remover livro.");
const string Resultado::ESC_SAIR        ("Escolheu sair.");

Resultado::Resultado(){ setCampo (Resultado::SUCESSO);}

Resultado::Resultado(const string &campo){setCampo(campo);}

Resultado::Resultado(Apelido *apelido){setCampo (Resultado::SUCESSO); setApelido(apelido);}

Resultado::Resultado(Livro *livro){setCampo (Resultado::SUCESSO); setLivro(livro);}

Resultado::Resultado(Livro *livro, Resenha *resenha){
	setCampo (Resultado::SUCESSO); setLivro(livro); setResenha(resenha);
}

Resultado::Resultado(Login *login){setCampo (Resultado::SUCESSO); setLogin(login);}

Resultado::Resultado(Usuario *usuario){setCampo (Resultado::SUCESSO); setUsuario(usuario);}

Resultado::Resultado(Titulo *titulo){setCampo (Resultado::SUCESSO); setTitulo (titulo);}

bool Resultado::equals (const Resultado &alvo){
	if(DominioBase::equals(alvo)){
		if (this->apelido == alvo.getApelido()
			&& this->livro == alvo.getLivro()
			&& this->login == alvo.getLogin()
			&& this->resenha == alvo.getResenha()
			&& this->usuario == alvo.getUsuario())
			return TesteUnitario::PASSOU;
	}

	return TesteUnitario::FALHOU;
}

void Resultado::deletar(){
	if (this->apelido)
		this->apelido->deletar ();

	if (this->livro)
		this->livro->deletar();

	if (this->login)
		this->login->deletar();

	if (this->resenha)
		this->resenha->deletar();

	if (this->usuario)
		this->usuario->deletar();

    delete this;
}
