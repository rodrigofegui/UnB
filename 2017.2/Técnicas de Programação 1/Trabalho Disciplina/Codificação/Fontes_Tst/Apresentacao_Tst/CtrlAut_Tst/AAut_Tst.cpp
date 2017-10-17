#include "../../../Bibliotecas_Tst/Apresentacao_Tst/CtrlAut_Tst/AAut_tst.hpp"
#include "../../../Bibliotecas_Tst/Servico_Tst/ServAut_Tst.hpp"

bool AAutTst::apresentou = false;

void AAutTst::menu(){
	if (!this->apresentou){
        this->apresentou = !this->apresentou;
        Manipulacao::limparTela();

	    cout << "****************************************************" << endl;
	    cout << "*              Teste de Autenticação               *" << endl;
	    cout << "*                                                  *" << endl;
	    cout << "* Gatilhos disponíveis:                            *" << endl;
	    cout << "*     - Usuário cadastrado:                    *" << endl;
	    cout << "*         + Apelido: " +
	            ServAutTst::LOGIN_EXI + "                         *" << endl;
	    cout << "*     - Usuário não cadastrado:                    *" << endl;
	    cout << "*         + Apelido: " +
	            ServAutTst::LOGIN_INE + "                         *" << endl;
	    cout << "*     - Erro conexão Base de Dados:                *" << endl;
	    cout << "*         + Apelido: " +
	            ServAutTst::LOGIN_EBD + "                         *" << endl;
	    cout << "****************************************************" << endl;

	    Manipulacao::pausar();
	}

    AAut::menu();
}
