#include "Pilha.h"

struct pilha{
    int quant;
    Elemento *topo;
};

struct reg {
    int info;
};

struct elemento {
    Registro dado;
    Elemento *proximo;
};



Pilha * cria_pilha (){
    Pilha *nova = NULL;

    do{
        nova = (Pilha *) malloc (sizeof(Pilha));
    }while (nova == NULL);

    nova->quant = 0;
    nova->topo = NULL;

    return nova;
}

Elemento * cria_elemento (){
    Elemento *novo = NULL;

    do{
        novo = (Elemento *) malloc (sizeof(Elemento));
    }while (novo == NULL);

    novo->dado.info = 0;
    novo->proximo = NULL;

    return novo;
}

void insere_pilha (Pilha *pilha, int info){
    Elemento *novo = cria_elemento ();

    novo->dado.info = info;

    if (pilha->quant > 0)
        novo->proximo = pilha->topo;

    pilha->topo = novo;
    pilha->quant++;
}

Elemento * retira_pilha (Pilha *pilha){
    if (pilha->topo == NULL){
        printf ("A pilha está vazia!\n");

        return NULL;
    }
    else{
        Elemento *retirado = pilha->topo;

        pilha->topo = retirado->proximo;

        return retirado;
    }
}

int topo_pilha (Pilha *pilha){
    if (pilha->topo == NULL){
        printf ("A pilha está vazia!\n");

        return 0;
    }
    else{
        int visualizar = pilha->topo->dado.info;

        return visualizar;
    }
}

void libera_pilha (Pilha *pilha){
    while (pilha->topo != NULL){
        Elemento *aux = retira_pilha (pilha);

        libera_elemento (aux);
    }

    free (pilha);
}

void libera_elemento (Elemento *campo){
    free (campo);
}

void exibe_pilha (Pilha *pilha){
    Elemento *aux = pilha->topo;

    printf ("Exibição da Pilha até o momento...\n\n");

    printf ("Existem %d elemento(s) registrados, sendo ele(s):\n", pilha->quant);

    for (aux = pilha->topo; aux != NULL; aux = aux->proximo){
        exibe_elemento (aux);

        if (aux->proximo != NULL)
            printf (", ");
        else
            printf (".\n");
    }
}

void exibe_elemento (Elemento *campo){
    printf ("%d", campo->dado.info);
}
