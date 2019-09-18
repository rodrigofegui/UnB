/*  Cabecalho das funções relacionadas aos eventos e as passagens */

/*  Biblioteca dinamica requisitada para este arquivo */
#include "Filas.h"

/*  Lista das funcoes de manipulacao sobre os eventos e as passagens */

/*  1 - Inicio da simulação */
void inicia_simu (Aeroporto *);

/*  2 - Evento de Aproximacao */
void aproxima_aero (Aeroporto *);

/*  3 - Evento de Aterrissagem */
void aterrissa_aero (Aeroporto *, int);

/*  4 - Evento de Decolagem */
void decola_aero (Aeroporto *, int);

/*  5 - Abortando um voo que nao pode ser atendido */
void aborta_voo (Aeroporto *);

/*  6 - Verifica o status da Pista */
int verifica_pista (Pista *);

/*  7 - Configura o tempo de simulacao para ser coerente ao horario normal */
struct tm* hora_atual ();

/*  8 - Incrementa o tempo para a passagem dos ciclos */
void incre_tempo (struct tm *);

/*  9 - Exibicao da hora depois de um turno de 5 minutos */
void imprime_hora (struct tm *);

/*  10 - Escreve num documento a hora corrente da simulacao */
void imprime_hora_arq (FILE *, struct tm *);

/*  11 - Geracao de um numero inteiro aleatorio num dado intervalo */
int gera_aleatorio (int, int);

/*  12 - Iniciacao de uma string */
void zera_string (char *, int);

/*  13 - Verificacao da resposta do usuario so sistema */
char ler_resposta ();
