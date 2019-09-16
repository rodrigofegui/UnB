/*  Cabecalho das funções relacionadas as TADs; definicoes de constantes globais;
**  assim como definicoes das estruturas a serem utilizadas na simulacao */

/*  Bibliotecas estaticas requisitadas para .c dependentes deste arquivo */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/*  Definicoes globais:
**  'TAMp' traduz o tamanho para a identificacao do voo; 'TAMs' traduz a quantidade
**  de pistas disponiveis; 'TEMPO' traduz o tempo medio para cada operacao, como
**  o tempo de ciclo ocorre a cada 5min, os tempos para aproximacao, aterrissagem
**  e decolagem assumem um ciclo, bastando apenas uma definicao geral */
#define TAMp 6
#define TAMs 3
#define TEMPO 5


/* Definicao das TADs a serem usadas na simulacao:  */

/* 'Aviao' define e simplifica a utilizacao da 'struct aviao' durante a simulacao;
** 'nome' armazena a identificacao do voo do tipo AA0000; 'status' armazena o status
**  do voo em relacao ao aeroporto, sendo 'A' para aproximacao, 'P' para pouso e 'D'
**  para decolagem; 'comb' armazena o nivel de combustivel para a aeronave, exceto
**  para decolagem, variando de 1 a 13 niveis; 'proximo' armazena o endereco do proximo
**  voo para a fila que esteja relacionado */
typedef struct aviao {
    char nome[TAMp], status;
    int comb;
    struct aviao *proximo;
}
Aviao;

/*  'Aproximacao' define e simplifica a utilizacao da 'struct aprox', e armazena
**  a fila de aproximacao; 'quant' armazena a quantidade de voos na fila de aprox;
**  'inicio' e 'fim' armazenam o inicio e o fim da fila em si, respectivamente */
typedef struct aprox {
    int quant;
    Aviao *inicio;
	Aviao *fim;
}
Aproximacao;

/*  'Decolagem' define e simplifica a utilizacao da 'struct deco', e armazena
**  a fila de decolagem; 'quant' armazena a quantidade de voos na fila de aprox;
**  'inicio' e 'fim' armazenam o inicio e o fim da fila em si, respectivamente */
typedef struct deco {
    int quant;
    Aviao *inicio;
	Aviao *fim;
}
Decolagem;

/*  'Pista' define e simplifica a utilizacao da 'struct pista', e armazena as condicoes da
**  pista envolvendo o status e a existencia de voo na mesma, caso haja tem a descricao do
**  mesmo; 'status' armazena o estado da pista, estando livre 'L' ou ocupada 'O'; 'voo'
**  armazena o voo que faz uso da dada pista, estando ela ocupada, num dado momento */
typedef struct pista {
    char status;
    Aviao *voo;
}
Pista;

/*  'Aeroporto' define e simplifica a utilizacao da 'struct aero', e armazena
**  as informacoes da estatistica do aeroporto em si, assim como as filas
**  para aproximacao e decolagem; 'voos' armazena o numero de voos suportados,
**  teoricamente, pelo aeroporto; 'req' armazena a quantidade de trabalho requerido
**  para o aeroporto, ou seja, numero de aproximacoes somado aos de decolagens;
**  'ciclo' armazena o ciclo, variante de 1 a 12, corrente da simulacao; 'percente'
**  armazena a porcentagem do uso do aeroporto; 'atual' armazena os dados temporais
**  do Aeroporto; 'filaap' e 'filade' armazenam as filas de aproximacao e decolagem,
**  respectivamente; 'pista' armazena o conjunto de pistas disponiveis para o Aeroporto */
typedef struct aero {
    int voos, req, ciclo;
    float percente;
    struct tm *atual;
    Aproximacao *filaap;
    Decolagem *filade;
    Pista *pista;
}
Aeroporto;


/*  Lista de funcoes para manipulacao sobre as TADs: */

/*  1 - Criacao de novo voo para as filas */
Aviao * cria_aviao ();

/*  2 - Criacao da fila Aproximacao */
Aproximacao * cria_aprox ();

/*  3 - Criacao da fila Decolagem */
Decolagem * cria_deco ();

/*  4 - Criacao das Pistas */
Pista * cria_pista ();

/*  5 - Criacao do Aeroporto */
Aeroporto * cria_aero ();

/*  6 - Liberacao de um aviao */
void libera_aviao (Aviao *);

/*  7 - Liberacao da fila Aproximacao, em si */
void libera_aprox (Aproximacao *);

/*  8 - Liberacao da fila Decolagem, em si */
void libera_deco (Decolagem *);

/*  9 - Liberacao das Pistas */
void libera_pista (Pista *);

/*  10 - Liberacao do Aeroporto */
void libera_aero (Aeroporto *);

/*  11 - Disponibilizacao de uma dada Pista */
void inicia_pista (Aeroporto *, Pista *);

/*  12 - Inicializacao do Aeroporto */
void inicia_aero (Aeroporto *, int);

/*  13 - Insercao de um novo voo na fila Aproximacao */
void add_aprox (Aproximacao *, char *);

/*  14 - Insercao de um novo voo na fila Decolagem */
void add_deco (Decolagem *, char *);

/*  15 - Insercao de um voo existente na fila Decolagem */
void insere_deco (Decolagem *, Aviao *);

/*  16 - Ordenacao dos voos na fila Aproximacao */
void ordena_aprox (Aproximacao *);

/*  17 - Retirada do voo da fila Aproximacao */
Aviao * retira_aprox (Aproximacao *);

/*  18 - Retirada do voo da fila Decolagem */
Aviao * retira_deco (Decolagem *);

/*  19 - Exibicao do voo individual na tela */
void imprime_voo (Aviao *);

/*  20 - Escreve um voo individual num arquivo */
void imprime_voo_arq (FILE *, Aviao *);

/*  21 - Exibicao da fila Aproximacao na tela */
void imprime_aprox (Aproximacao *);

/*  22 - Escreve a fila Aproximano num arquivo */
void imprime_aprox_arq (FILE *, Aproximacao *);

/*  23 - Exibicao da fila de Decolagens na tela */
void imprime_deco (Decolagem *);

/*  24 - Escreva a fila Decolagem num arquivo */
void imprime_deco_arq (FILE *, Decolagem *);

/*  25 - Exibicao de uma dada Pista na tela */
void imprime_pista (Pista *);

/*  26 - Escreve uma dada Pista num arquivo */
void imprime_pista_arq (FILE *, Pista *);

/*  27 - Exibicao da configuracao do Aeroporto na tela */
void imprime_aero (Aeroporto *);

/*  28 - Escreve a configuracao do Aeroporto num arquivo */
void imprime_aero_arq (FILE *, Aeroporto *);

/*  29 - Montagem do nome para um novo voo */
char * monta_nome ();
