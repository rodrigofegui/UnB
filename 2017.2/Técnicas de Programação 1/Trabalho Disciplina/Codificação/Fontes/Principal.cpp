/**
 *  @file   Principal.cpp
 *  @author Rodrigo F. Guimarães
 *  @brief  Responsável por implementar a aplicação
 */


/**
 *  Biblioteca necessária
 */

#include "../Bibliotecas_Tst/AtivaTeste.hpp"
#include "../Bibliotecas/Principal.hpp"
#include "../Bibliotecas/Dominio/Log.hpp"


using namespace std;

int main(){
    //*
    #ifndef TESTE
        fullTeste ();
    #endif // TESTE
    //*/

    /*
    AControle aplicacao;

    aplicacao.executar();
    //*/
    FILE *arq = Log::criarArq();


    cout << endl << "A execucao da aplicação finalizou!" << endl;
    cout << "Volte sempre!" << endl;

    return 0;
}
