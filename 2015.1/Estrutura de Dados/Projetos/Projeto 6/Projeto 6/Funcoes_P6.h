/*  Cabecalho das funções independentes das TADs para andamento do Projeto */

/*  Biblioteca dinamica requisitada para este arquivo */
#include "TADs_P6.h"

/*  Lista das funcoes de manipulacao sobre os eventos e as passagens */

/*  Da as boas vindas */
void hello ();

/*  Apresentacao do Programa */
char inicio_geral ();

/*  Abertura de Arquivo */
FILE * abre_arquivo (char *, char, char);

/*  Realiza a limpeza da tela durante a execucao */
void limpa_tela ();

/*  Leitura do arquivo base */
void ler_fonte (Grafo *);

/*  Leitura de um numero inteiro dentre de um intervalo aceitavel */
int ler_intervalo (int, int);

/*  Leitura do nome do documentos a manipulado */
void ler_nome_doc (char *);

/*  Leitura da resposta para uma pergunta de sim ou nao */
char ler_simounao ();

/*  Pausa por ENTER na execucao do jogo */
void pausa ();

/*  Questiona sobre o procedimento para exibicao do roteiro */
void questiona_roteiro ();

/*  Questiona sobre o procedimento de pausa do programa */
float questiona_tempo ();

/*  Pausa por TEMPO durante a execucao do jogo */
void temporizador (float);

/*  Anula os caracteres de uma string, de um ponto a outro */
void zera_string (char *, int, int);

/*  Compara duas strings, n bytes e a partir de m-esimo byte */
int compara_string_n (char *, char *, int, int, int);

/*  Concatena strings, a partir de um ponto ate outro */
void concat_string_n (char *, char *, int, int);
