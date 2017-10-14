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
#define CODEBLOCKS

#include "../Bibliotecas/Entidade/Login.hpp"

int main(){
    //*
    #ifdef TESTE
        //fullTeste ();
        AplicacaoTst aplicacao;
    #else
        Aplicacao aplicacao;
    #endif // TESTE

    aplicacao.executar();
    //*/

    cout << endl << "A execucao da aplicação finalizou!" << endl;
    cout << "Volte sempre!" << endl;

    return 0;
}
