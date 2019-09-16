#include <stdio.h>
#include <stdlib.h>
#include "../Bibliotecas/Pilha.h"

int main (){
	Pilha *pilha = pilha_cria_vet (4);

	printf ("Inicio do teste numa pilha como vetor\n\n");

	printf ("Tentando remover em pilha vazia e...\n");
	pilha_remove (pilha);

	printf ("Inserindo o 2\n");
    pilha_insere (pilha, 2);

	printf ("Inserindo o 5\n");
	pilha_insere (pilha, 5);

	printf ("Inserindo o 7\n");
	pilha_insere (pilha, 7);

	printf ("Inserindo o 8\n");
	pilha_insere (pilha, 8);

	printf ("Inserindo o 10\n");
	pilha_insere (pilha, 10);

    printf ("O elemento do topo e':\n");
	elemento_exibe (pilha_topo(pilha));

    pilha_exibe (pilha);

    pilha = pilha_libera (pilha);

	printf ("Tentando exibir o elemento do topo, com a pilha já liberada e...\n");
	elemento_exibe (pilha_remove(pilha));

	printf ("Fim do teste numa pilha como vetor\n");

    return 0;
}
