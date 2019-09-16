/*  Cabecalho das funções para andamento do Projeto */

/*  Biblioteca dinamica requisitada para este arquivo */
#include "TADs.h"

/*  Lista das funcoes de manipulacao sobre os eventos e as passagens */

/*  Apresentacao do Jogo */
char inicio_geral ();

/*  Apresentacao dos Modos de Inicio e questionamento sobre o mesmo */
char inicio_real ();

/*  Questionamento do tamanho do lado do tabuleiro */
int pergunta_tam ();

/*  Insercao dos Numeros primos em ordem decrescente */
char resolve_ant (Historico *, Tabuleiro *, Primo *, int, int, char, char, int *, char);

/*  Insercao dos Numeros primos em ordem crescente */
char resolve_post (Historico *, Tabuleiro *, Primo *, int, int, char, char, int *);

/*  Verificacao da condicao de numero primo */
char verifica_primo (int, int);

/* Calcula a distancia entre dois primos consecutivos */
char calcula_distancia (Seqpontos *, Primo *, int);

/*  Leitura da resposta para uma pergunta de sim ou nao */
char ler_resposta ();

/*  Leitura da coordenada */
int ler_intervalo (int, int);

/*  Leitura do numero fornecido */
int ler_primo (int);

/* Escolha o tipo de impressao da resolucao */
float questiona_impressao (int *, int *);

/* Imprime o tabuleiro pausadamente */
void imprime_pausa (Tabuleiro *, Historico *, float);

/* Imprime o tabuleiro pausada por ENTER */
void imprime_enter (Tabuleiro *, Historico *, float);

/*  Pausa por ENTER na execucao do jogo */
void pausa ();

/*  Pausa por TEMPO durante a execucao do jogo */
void temporizador (float);

/* Leitura do arquivo entrada */
Tabuleiro leitura_arquivo ();
