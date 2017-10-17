#include "../../../Bibliotecas_Tst/Apresentacao_Tst/Aplicacao_Tst/Aplicacao_Tst.hpp"
#include "../../../Bibliotecas_Tst/Apresentacao_Tst/CtrlAut_Tst/AAut_tst.hpp"
#include "../../../Bibliotecas_Tst/Apresentacao_Tst/CtrlUsu_Tst/AUsu_Tst.hpp"
#include "../../../Bibliotecas_Tst/Apresentacao_Tst/CtrlEst_Tst/AEst_Tst.hpp"
#include "../../../Bibliotecas_Tst/Servico_Tst/ServAut_Tst.hpp"
#include "../../../Bibliotecas_Tst/Servico_Tst/ServUsu_Tst.hpp"
#include "../../../Bibliotecas_Tst/Servico_Tst/ServEst_Tst.hpp"

bool AplicacaoTst::apresentou = false;

void AplicacaoTst::menu(){
    if (!this->apresentou){
        this->apresentou = !this->apresentou;
        Manipulacao::limparTela();

        Log::escrever(Mensagem::INI_APP_TST);

        cout << "****************************************************" << endl;
        cout << "*          Bem-vindo ao teste da Aplicação         *" << endl;
        cout << "*                                                  *" << endl;
        cout << "* Nesse teste, a aplicação será executada normal-  *" << endl;
        cout << "* mente, mas para cada possibilidade de comando    *" << endl;
        cout << "* será mostrado os gatilhos disponíveis para cada  *" << endl;
        cout << "* tarefa (através de uma tela anterior à execução  *" << endl;
        cout << "* em si). Dessa forma, aconselhamos que armazene   *" << endl;
        cout << "* em algum lugar os gatilhos: os mesmos serão apa- *" << endl;
        cout << "* gados da tela para a execução de fato; e só      *" << endl;
		cout << "* aparecerão uma vez.                              *" << endl;
        cout << "*                                                  *" << endl;
        cout << "* Obrigado por testar nossa plataforma! E desculpe *" << endl;
        cout << "* por possíveis transtornos.                       *" << endl;
        cout << "****************************************************" << endl;

        Manipulacao::pausar();
    }

    Aplicacao::menu();
}

Resultado AplicacaoTst::autenticar(){
    Log::escrever(Mensagem::RED_AUT);

	this->func = new AAutTst ();
	this->func->setServico(new ServAutTst());
	return this->func->executar();
}

Resultado AplicacaoTst::usuario(){
    Log::escrever(Mensagem::RED_USU);

    this->func = new AUsuTst ();
	this->func->setServico(new ServUsuTst());
	return this->func->executar();
}

Resultado AplicacaoTst::estante(const Resultado &apelido){
    Log::escrever(Mensagem::RED_EST);

	this->func = new AEstTst ();
	this->func->setServico(new ServEstTst());
	return this->func->executar(apelido);
}
