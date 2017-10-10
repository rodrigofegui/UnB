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

int main(){
    #ifdef TESTE
        fullTeste ();
        cout << "aplicação test" << endl;
    #else
        cout << "aplicação real" << endl;
    #endif // TESTE


    cout << endl << "A execucao da aplicação finalizou!" << endl;
    cout << "Volte sempre!" << endl;

    return 0;
}
