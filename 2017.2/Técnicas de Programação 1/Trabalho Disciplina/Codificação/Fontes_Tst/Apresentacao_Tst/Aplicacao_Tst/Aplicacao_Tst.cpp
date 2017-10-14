#include "../../../Bibliotecas_Tst/Apresentacao_Tst/Aplicacao_Tst/Aplicacao_Tst.hpp"
#include "../../../Bibliotecas_Tst/Apresentacao_Tst/CtrlAut_Tst/AAut_tst.hpp"
#include "../../../Bibliotecas_Tst/Servico_Tst/ServAut_Tst.hpp"

const string AplicacaoTst::MSG_TELA        ("Apresentação da Tela Inicial de Teste.");

void AplicacaoTst::menu(){
    if (!this->apresentou){
        this->apresentou = !this->apresentou;
        Manipulacao::limparTela();

        Log::escrever(MSG_TELA);

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
    Log::escrever(MSG_ESC_AUT);

	this->func = new AAutTst ();
	this->func->setServico(new ServAutTst());
	return this->func->executar();
}

Resultado AplicacaoTst::usuario(){
    Log::escrever(MSG_ESC_USU);
    cout << "Usuário de teste..." << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}

Resultado AplicacaoTst::estante(const Resultado &apelido){
    Log::escrever(MSG_ESC_EST);
    cout << "Estante de teste..." << endl;
    cout << "Chegou com: ";
    cout << apelido.getApelido()->getCampo() << endl;

    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}
