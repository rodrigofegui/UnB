/* Cabecalho das Funções relacionadas a manipulacao de arquivos e realizacao dos calculos
** necessarios para se obter o resultado da comparacao entre os arquivos .txt. */

#include "Lista.h"

struct arquivo{
    /* 'arquivo' armazena o nome do arquivo a ser feito a analise de plagio */
    char arquivo[TAMS];
};
/* Definicao da struct arquivo para simplificacao da manipulacao no programa */
typedef struct arquivo Arquivo;

/* 1 - Abertura de Arquivo */
FILE * abre_arquivo (char *, char);

/* 2 - Montagem do Nome do Arquivo a ser analisado */
void nome_arquivo (char *, int);

/* 3 - Montagem do Nome dos Arquivos Resumidos */
void nome_arquivo_resumo (char *, char *);

/* 4 - Leitura do Documento a ser analisado */
Lista * ler_arquivos (Lista *, char *);

/* 5 - Leitura dos Documentos Resumos */
void ler_arquivos_resumo (Resultado *, char *, char *);

/* 6 - Cálculo da Métrica da Projeção */
int metrica_projecao (Resultado *);

/* 7 - Cálculo da Magnitude de um Documento */
float magnitude_doc (Lista *);

/* 8 - Cálculo da Métrica para Ângulo */
float metrica_angulo (int, float, float);

/* 9 - Grau de Semelhança */
float grau_semelhanca (float);

/* 10 - Cria arquivo com resumo do documento lido */
void escreve_arq_lista (Lista *, char *);

/* 11 - Cria arquivo final a partir da comparacao */
void escreve_arq_resultado (Resultado *, char *, char *, float , float, float);
