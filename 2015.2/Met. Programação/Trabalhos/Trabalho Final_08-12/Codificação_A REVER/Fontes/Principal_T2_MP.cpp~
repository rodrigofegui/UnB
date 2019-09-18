/*****************************************************************
**  Métodos de Programação - Turma  - 
**  Professor:
**              Jan Correia
**  Responsável:
**              Pedro Aurélio Coelho Almeida - 140158103
**              Rodrigo Ferreira Guimarães - 140170740
**  Finalidades:
**              
*****************************************************************/

/*****************************************************************
**      Inclusão das bibliotecas auxiliares
*****************************************************************/
	#include <stdio.h>
    #include <stdlib.h>
	#include "../Bibliotecas/Basica.hpp"
	#include "../Bibliotecas/Estruturas.hpp"


/*****************************************************************
**      Namespaces utilizados
*****************************************************************/
    using namespace std;


/*****************************************************************
**      Cabeçalho da Exclusiva
*****************************************************************/
    bool inicio ();

/*****************************************************************
**      Programa principal
*****************************************************************/
int main (){
	Elem* inicial=NULL;
 	/*   Conexao *conex=NULL;
    Rede *r;
    r = obtem_dados();
    r = obtem_dados();
    r=obtem_dados();
    r=obtem_dados();
    r=obtem_dados();
    inicial = r->comeco;
    conex=r->inic;
  	*/

    inicial = insere_elemento(inicial,NULL, "G Usina",10,42,100,1000);

    inicial = insere_elemento(inicial,NULL, "A adapta_1",2,3,0,0);

    inicial = insere_elemento(inicial,NULL, "C Brasília",15,47,143,0);

    inicial = insere_elemento(inicial,NULL, "G Foda-se ",10,42,100,1000);

    imprime_El(inicial);

    libera_elementos(inicial);

	getchar();

    return 0;
}

/*****************************************************************
**      Definição da Função
*****************************************************************/
bool inicio (){
    /*  Questionamento sobre inicio do projeto */
    limpa_tela ();
    printf ("Bem-vindo ao gerenciamento de redes de distribuição de recursos!\n");
    
    printf ("\n\nDadas as caracteristicas do projeto, deseja inicia-lo? S/N ou s/n\n");
        return ler_simounao ();
}
