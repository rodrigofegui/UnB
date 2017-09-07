/**
 *  @file   Principal.cpp
 *  @author Rodrigo F. Guimarães
 *  @brief  Responsável por implementar a aplicação
 */


/**
 *  Biblioteca necessária
 */
#include "Bibliotecas/AtivaTeste.hpp"
#include "Principal.hpp"

using namespace std;

int main(){
    #ifdef TESTE
        fullTeste ();
    #endif // TESTE

    cout << endl << "A execucao da aplicação finalizou!" << endl;
    cout << "Volte sempre!" << endl;

    return 0;
}
