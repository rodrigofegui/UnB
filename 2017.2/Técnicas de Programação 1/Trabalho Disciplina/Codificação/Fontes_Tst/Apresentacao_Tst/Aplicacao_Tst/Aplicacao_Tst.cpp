#include "../../../Bibliotecas_Tst/Apresentacao_Tst/Aplicacao_Tst/Aplicacao_Tst.hpp"

void AplicacaoTst::menu(){

    if (!this->apresentou){
        this->apresentou = !this->apresentou;
        Manipulacao::limparTela();

        cout << "****************************************************" << endl;
        cout << "*     Bem-vindo à seção de teste da Aplicação      *" << endl;
        cout << "*                                                  *" << endl;
        cout << "* Nesse teste, a aplcação será executada normal-   *" << endl;
        cout << "* mente, mas para cada possibilidade de comando    *" << endl;
        cout << "* será mostrado os gatilhos disponíveis para cada  *" << endl;
        cout << "* tarefa (através de uma tela anterior à execução  *" << endl;
        cout << "* em si). Dessa forma, aconselhamos que armazene   *" << endl;
        cout << "* em algum lugar os gatilhos, pois os mesmos serão *" << endl;
        cout << "* apagados da tela para a execução de fato.        *" << endl;
        cout << "*                                                  *" << endl;
        cout << "* Obrigado por testar nossa plataforma! E desculpe *" << endl;
        cout << "* por possíveis transtornos.                       *" << endl;
        cout << "****************************************************" << endl;

        Manipulacao::pausar();
    }

    Aplicacao::menu();
}

Resultado AplicacaoTst::autenticar(){
    cout << "Autenticar de teste..." << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}

Resultado AplicacaoTst::usuario(){
    cout << "Usuário de teste..." << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}

Resultado AplicacaoTst::estante(){
    cout << "Estante de teste..." << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}
