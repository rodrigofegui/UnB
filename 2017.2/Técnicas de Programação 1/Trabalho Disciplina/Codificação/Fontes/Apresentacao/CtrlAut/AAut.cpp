#include "../../../Bibliotecas/Apresentacao/CtrlAut/AAut.hpp"

Resultado AAut::executar (){
    Log::escrever(Mensagem::INI_AUT);

    TUI::executar();

	return avaliarCond();
}

void AAut::menu(){
    Manipulacao::limparTela();

    cout << "****************************************************" << endl;
    cout << "*                   Autenticação                   *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Para efetuar o login na aplicação é preciso for- *" << endl;
    cout << "* necer o apelido e a senha; lembrando que:        *" << endl;
    cout << "*     - Apelido deve ter até 5 letras;             *" << endl;
    cout << "*     - Senha deve ter 4 letras.                   *" << endl;
    cout << "****************************************************" << endl << endl;
}

Resultado AAut::leitura(){
    string resp;
    Senha respSenha;

	Log::escrever(Mensagem::LEITURA);

    cout << Mensagem::LER_APE;
        cin >> resp; getchar();
    		this->apelido.setCampo(resp);
    	Log::escrever(Mensagem::AQS_APE);

    cout << Mensagem::LER_SEN;
        cin >> resp; getchar();
    		respSenha.setCampo(resp);
    	Log::escrever(Mensagem::AQS_SEN);

    if (!this->login)
        this->login = new Login (this->apelido, respSenha);
    else{
        this->login->setApelido(this->apelido);
        this->login->setSenha(respSenha);
    }
	Log::escrever (Mensagem::CRI_LGN);

    return Resultado (this->login);
}

Resultado AAut::direcionar(const Resultado &entrada){
    Resultado result = servico->autenticar(*(entrada.getLogin()));

    if(result.getCampo() != Resultado::SUCESSO)
        this->apelido.clear();
    else
        result.setCampo(Resultado::ESC_SAIR);

    entrada.clear();

    return result;
}

Resultado AAut::tratarErro (){
    this->apelido.clear();

    Log::escrever(Mensagem::ERR_DUB);
    cout << Mensagem::ERR_DUB << endl;
    Manipulacao::pausar();

    return Resultado(Resultado::ESC_SAIR);

}

Resultado AAut::tratarErro (const Resultado &evento){
    if (evento.getCampo() == Resultado::FLH_AUT){
        cout << Mensagem::FLH_LGN << endl;
        Manipulacao::pausar();
    }

    evento.clear();
    return Resultado(Resultado::ESC_SAIR);
}

Resultado AAut::avaliarCond (){
	if(!this->apelido.getCampo().empty()){
		Log::escrever(Mensagem::SUC_AUT + this->apelido.getCampo());
		Resultado res (&this->apelido);
		return res;
	}

	Log::escrever(Resultado::FALHA);
	return Resultado (Resultado::FALHA);
}

void AAut::finalizar(){
    if (this->servico)
        delete this->servico;

    if (this->login)
        this->login->deletar();

    delete this;

    Log::escrever(Mensagem::FIM_AUT);
}
