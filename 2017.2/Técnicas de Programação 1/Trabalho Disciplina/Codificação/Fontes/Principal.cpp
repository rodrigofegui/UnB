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
    #ifdef TESTE
        //fullTeste ();
        AplicacaoTst aplicacao;
    #else
        Aplicacao aplicacao;
    #endif // TESTE

    aplicacao.executar();

    cout << Mensagem::FIM << endl;
    cout << Mensagem::SAUDACAO_FIM << endl;

    return 0;
}
