/*  Cabecalho das funções independentes das TADs para andamento do Projeto */

/*  Biblioteca dinamica requisitada para este arquivo */
#include "TADs_P5.h"

/*  Lista das funcoes de manipulacao sobre os eventos e as passagens */

/*  Da as boas vindas */
void hello ();

/*  Apresentacao do Programa */
char inicio_geral ();

/*  Realiza a limpeza da tela durante a execucao */
void limpa_tela ();

/*  Leitura da resposta para uma pergunta de sim ou nao */
char ler_simounao ();

/*  Leitura de um numero inteiro dentre de um intervalo aceitavel */
int ler_intervalo (int, int);

/*  Leitura de uma palavra ate o ENTER */
char * ler_palavra ();

/*  Leitura do nome do documentos a manipulado */
char * ler_nome_doc ();

/*  Leitura do arquivo base para o grafo */
void ler_allpages (Grafo *);

/*  Leitura dos codigos fonte para construcao das ligacoes entre as
**  paginas web */
void ler_codfontes (Grafo *, Pagina *);

/*  Questiona sobre o diretorio a ser analisado */
void questiona_diretorio (char *);

/*  Questiona a forma de ranqueamento */
int questiona_rank ();

/*  Pausa por ENTER na execucao do jogo */
void pausa ();

/*  Pausa por TEMPO durante a execucao do jogo */
void temporizador (float);

/*  Abertura de Arquivo */
FILE * abre_arquivo (char *, char, char);

/*  Concatena strings, a partir de um ponto ate outro */
void concat_string (char *, char *, int, int);

/*  Compara duas strings, n bytes e a partir de m byte */
int compara_string_n (char *, char *, int, int, int);

/*  Anula os caracteres de uma string, de um ponto a outro */
void zera_string (char *, int, int);

/*  Descobrir a n-ultima ocorrencia de um caracter numa string */
int n_ultima_ocorrencia (char *, char, int);

/*  Ranqueamento dos sites */
void ranqueia_grafo (Grafo *);

/*  Calculo do PageRank pelo metodo iterativo */
void pr_iterativo (Grafo *);

/*  Calculo do PageRank pelo metodo da diferenca */
void pr_diferenca (Grafo *, float);

/*  Apresentacao grafica dos resultados */
void histograma (Grafo *);
