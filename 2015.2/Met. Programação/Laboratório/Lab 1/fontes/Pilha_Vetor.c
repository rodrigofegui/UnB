#include "../include/Pilha.h"

struct pilha {
    int quant;
    int topo;
    Elemento *conjunto;
};

struct reg {
    int info;
};

struct elemento{
    Registro dado;
};

Pilha * cria_pilha_vec (int tamanho){
    Pilha *nova = NULL;
    int indice;

    do{
        nova = (Pilha *) malloc (sizeof(Pilha));
    }while (nova == NULL);

    nova->conjunto = NULL;
    nova->quant = tamanho;
    nova->topo = 0;

    do{
        nova->conjunto = (Elemento *) malloc (tamanho * sizeof(Elemento));
    }while (nova->conjunto == NULL);

    for (indice = 0; indice < tamanho; indice++){
        nova->conjunto[indice].dado.info = 0;
    }

    return nova;
}

void insere_pilha_vec (Pilha *pilha, int info){
    if (lotada(pilha) == CHEIA){
        printf ("Pilha esta lotada!! Nao tem mais espaco!!!");
        return;
    }

    pilha->conjunto[pilha->quant].dado.info = info;
    pilha->quant++;

    return;
}

char lotada (Pilha *pilha){
    if (pilha->quant == pilha->topo){
        return CHEIA;
    }
    return VAZIA;
}

Registro * retira_pilha_vec (Pilha *pilha){
    Registro retirado = pilha->conjunto[pilha->quant].dado;


}
