#include <stdio.h>
#include <stdlib.h>
#include "../include/Pilha.h"

int main (){
    Pilha *pilha = cria_pilha_enc ();

    insere_pilha_enc (pilha, 2);

    insere_pilha_enc (pilha, 5);

    insere_pilha_enc (pilha, 7);

    insere_pilha_enc (pilha, 8);

    printf ("O elemento do topo e': %d\n", topo_pilha(pilha));

    exibe_pilha (pilha);

    libera_pilha (pilha);

    return 0;
}
