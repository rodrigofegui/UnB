#include "../../../Bibliotecas/Apresentacao/Aplicacao/Aplicacao.hpp"

void Aplicacao::menu (){
    Manipulacao::limparTela();

    cout << "****************************************************" << endl;
    cout << "*                 Bem-Vindo à Estante              *" << endl;
    cout << "*                                                  *" << endl;
    cout << "* São lhe oferecidas as opções:                    *" << endl;
    printf ("*    %d - Login: Caso já tenha cadastro;            *\n", Aplicacao::AUTENTICAR);
    printf ("*    %d - Cadastro: Caso seja a primeira vez na     *\n", Aplicacao::CADASTRAR);
    cout << "* plataforma;                                      *" << endl;
    printf ("*    %d - Sair.                                     *\n", Aplicacao::SAIR);
    cout << "****************************************************" << endl << endl;
}

Resultado Aplicacao::leitura(){
    int resp = 0;

    cout << "Digite a sua escolha: ";

    cin >> resp;
        getchar ();

    if (resp == Aplicacao::AUTENTICAR)
        return Resultado(Resultado::ESC_AUTENTICAR);

    if (resp == Aplicacao::CADASTRAR)
        return Resultado(Resultado::ESC_CADASTRAR);

    if (resp == Aplicacao::SAIR)
        return Resultado(Resultado::ESC_SAIR);

    cout << "Fora do intervalo desejável!" << endl << endl;
    return Resultado(Resultado::FALHA);
}

Resultado Aplicacao::direcionar (const Resultado &escolha){
    if (escolha.getCampo() == Resultado::ESC_AUTENTICAR)
        return autenticar();

    if (escolha.getCampo() == Resultado::ESC_CADASTRAR)
        return usuario();

    if (escolha.getCampo() == Resultado::ESC_SAIR)
        return escolha;
}

Resultado Aplicacao::autenticar(){
    cout << "Autenticar..." << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}

Resultado Aplicacao::usuario(){
    cout << "Usuário..." << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}

Resultado Aplicacao::estante(){
    cout << "Estante..." << endl;
    Manipulacao::pausar();

    return Resultado (Resultado::SUCESSO);
}

Resultado Aplicacao::tratarErro (){ return Resultado(Resultado::ESC_SAIR);}

Resultado Aplicacao::tratarErro (const Resultado &evento){
    if (evento.getCampo() == Resultado::FLH_LIM)
        cout << "Foi atingido o limite de tentativas" << endl;

    return Resultado(Resultado::ESC_SAIR);
}
