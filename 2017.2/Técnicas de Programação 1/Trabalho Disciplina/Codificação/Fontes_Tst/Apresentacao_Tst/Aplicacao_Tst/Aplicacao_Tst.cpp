#include "../../../Bibliotecas_Tst/Apresentacao_Tst/Aplicacao_Tst/Aplicacao_Tst.hpp"
#include "../../../Bibliotecas_Tst/Apresentacao_Tst/CtrlAut_Tst/AAut_tst.hpp"

void AplicacaoTst::menu(){
    if (!this->apresentou){
        this->apresentou = !this->apresentou;
        Manipulacao::limparTela();

        cout << "****************************************************" << endl;
        cout << "*          Bem-vindo ao teste da Aplicação         *" << endl;
        cout << "*                                                  *" << endl;
        cout << "* Nesse teste, a aplicação será executada normal-   *" << endl;
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
	return this->func->executar();

    return Resultado (Resultado::SUCESSO);
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
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}
