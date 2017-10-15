#include "../../../Bibliotecas_Tst/Apresentacao_Tst/CtrlUsu_Tst/AUsu_Tst.hpp"
#include "../../../Bibliotecas_Tst/Servico_Tst/ServUsu_Tst.hpp"

void AUsuTst::menu(){
    Manipulacao::limparTela();

    cout << "****************************************************" << endl;
    cout << "*              Teste de Cadastramento              *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* Gatilhos disponíveis:                            *" << endl;
    cout << "*     - Usuário já cadastrado:                     *" << endl;
    cout << "*         + Apelido: " +
            ServUsuTst::CADST_EXT + "                         *" << endl;
    cout << "*     - Erro conexão Base de Dados:                *" << endl;
    cout << "*         + Apelido: " +
            ServUsuTst::CADST_EBD + "                         *" << endl;
    cout << "****************************************************" << endl;

    Manipulacao::pausar();

    AUsu::menu();
}
