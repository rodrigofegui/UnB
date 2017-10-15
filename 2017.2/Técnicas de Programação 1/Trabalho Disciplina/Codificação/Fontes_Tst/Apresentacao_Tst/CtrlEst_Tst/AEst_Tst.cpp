#include "../../../Bibliotecas_Tst/Apresentacao_Tst/CtrlEst_Tst/AEst_Tst.hpp"
#include "../../../Bibliotecas_Tst/Servico_Tst/ServEst_Tst.hpp"

void AEstTst::menu(){
    Manipulacao::limparTela();

    cout << "****************************************************" << endl;
    cout << "*                  Teste da Estante                *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Gatilhos disponíveis:                            *" << endl;
    cout << "*     - Livro existente:                           *" << endl;
    cout << "*         + Título: " +
            ServEstTst::LIVRO_EXI + "             *"   << endl;
    cout << "*     - Livro para erro de Base de Dados:          *" << endl;
    cout << "*         + Título: " +
            ServEstTst::LIVRO_EBD + "               *"   << endl;
    cout << "*     - Usuário existente:                         *" << endl;
    cout << "*         + Apelido: " +
            ServEstTst::USUARIO_EXI + "                         *"   << endl;
    cout << "*     - Usuário para erro de Base de Dados:        *" << endl;
    cout << "*         + Apelido: " +
            ServEstTst::USUARIO_EBD + "                         *"   << endl;
    cout << "****************************************************" << endl;

    Manipulacao::pausar();

    AEst::menu();
}
