#include "../../../Bibliotecas_Tst/Apresentacao_Tst/CtrlAut_Tst/AAut_tst.hpp"

void AAutTst::menu(){
    if (!this->apresentou){
        this->apresentou = !this->apresentou;
        Manipulacao::limparTela();

        cout << "****************************************************" << endl;
        cout << "*              Teste de Autenticação               *" << endl;
        cout << "*                                                  *" << endl;
        cout << "* Gatilhos disponíveis:                            *" << endl;
        cout << "*     - Usuário não cadastrado:                    *" << endl;
        cout << "*         + Apelido: jose                          *" << endl;
        cout << "*     - Erro conexão Base de Dados:                *" << endl;
        cout << "*         + Apelido: mart                          *" << endl;
        cout << "****************************************************" << endl;

        Manipulacao::pausar();
    }

    AAut::menu();
}
