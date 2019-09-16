/*  Cabecalho das funções independentes das TADs para andamento do Projeto */

/*  Biblioteca dinamica requisitada para este arquivo */
#include "TADs_P4.h"

/*  Lista das funcoes de manipulacao sobre os eventos e as passagens */

/*  Apresentacao do Jogo */
char inicio_geral ();

/*  Da as boas vindas */
void hello ();

/*  Realiza a limpeza da tela durante a execucao */
void limpa_tela ();

/*  Questiona sobre a quantidade de documentos a serem analisados */
int questiona_tam ();

/*  Questiona a vontade de procurar uma palavra na tabela */
char questiona_procura ();

/*  Questiona sobre o procedimento de pausa do programa */
float questiona_tempo ();

/*  Leitura da resposta para uma pergunta de sim ou nao */
char ler_simounao ();

/*  Leitura dos nomes dos documentos a serem analisados */
char * ler_nome_doc (int, int, char);

/*  Leitura de um numero inteiro dentre de um intervalo aceitavel */
int ler_intervalo (int, int);

/*  Leitura de uma palavra ate o ENTER */
char * ler_palavra ();

/*  Leitura dos arquivos */
int le_arquivo (Lista *, char *);

/*  Abertura de Arquivo */
FILE * abre_arquivo (char *, char, char);

/*  Pausa por ENTER na execucao do jogo */
void pausa ();

/*  Pausa por TEMPO durante a execucao do jogo */
void temporizador (float);

/*  Codifica a palavra numa chave */
int chaveamento (char *);

/*  Calcula o hashing */
int calc_hashing (int, int);
