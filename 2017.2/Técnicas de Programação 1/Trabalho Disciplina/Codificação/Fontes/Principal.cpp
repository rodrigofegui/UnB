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

int main(){
    Aplicacao *aplicacao;

    #ifdef TESTE
        //fullTeste ();
        aplicacao = new AplicacaoTst ();
    #else
        aplicacao = Aplicacao ();
    #endif // TESTE

    aplicacao->executar();

    cout << Mensagem::FIM << endl;
    cout << Mensagem::SAUDACAO_FIM << endl;

    return 0;
}
