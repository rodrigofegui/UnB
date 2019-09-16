#include <stdio.h>
#include <stdlib.h>
#define VAZIA 'V'
#define CHEIA 'C'

typedef struct pilha Pilha;

typedef struct elemento Elemento;

typedef struct reg Registro;

Pilha * cria_pilha_enc ();

Pilha * cria_pilha_vec (int);

Elemento * cria_elemento ();

void insere_pilha_enc (Pilha *, int);

void insere_pilha_vec (Pilha *, int);

Elemento * retira_pilha_enc (Pilha *);

Registro * retira_pilha_vec (Pilha *);

int topo_pilha (Pilha *);

char vazia_enc (Pilha *);

char vazia_vec (Pilha *);

char lotada (Pilha *);

void libera_pilha (Pilha *);

void libera_elemento (Elemento *);

void exibe_pilha (Pilha *);

void exibe_elemento (Elemento *);


