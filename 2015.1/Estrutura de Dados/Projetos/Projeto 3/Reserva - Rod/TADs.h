/*  Cabecalho das funções relacionadas as TADs; definicoes de constantes globais;
**  assim como definicoes das estruturas a serem utilizadas na simulacao */

/* Definicao das TADs a serem usadas na simulacao:  */
/*  'Ponto' define e simplifica a utilizacao da 'struct ponto' durante a execucao
**  do jogo; 'linha' e 'coluna' armazenam as respectivas coordenadas para o ponto
**  especifico; 'valor' armazena o valor referente aquela posicao */
typedef struct ponto{
    char linha, coluna;
    int valor;
    struct ponto *prox;
} Ponto;

typedef struct pontos{
    Ponto *inicio;
} Seqpontos;

/*  'Primo' define e simplifica a utilizacao da 'struct primo' durante a execucao
**  do jogo; 'valor' armazena o numero primo em si; 'status' armazena o status de
**  manipulacao do numero no jogo */
typedef struct primo{
    int valor;
    char status;
} Primo;

/*  'Tabuleiro' define e simplifica a utilizacao da 'struct tabu' durante a execucao
**  do jogo; 'campo' armazena o tabuleiro em si; 'zeros' armazena a quantidade de
**  posicoes livres no tabuleiro */
typedef struct tabu{
    int **campo, tam;
    char zeros;
} Tabuleiro;

/*  'Elemento' define e simplifica a utilizacao da 'struct elemento' durante a execucao
**  do jogo; 'numero' armazena o numero primo em si; 'pcardeais' armazena o status para
**  cada vizinho na 4-vizinhaca; 'coord' armazena a coordenada do numero no tabuleiro;
**  'prox' e 'ante' armazenam, respectivamente, o proximo e o anterior elemento ao atual
**  no historico */
typedef struct elemento{
    int numero;
    char pcardeais[4], coord[2];
    struct elemento *prox, *ante;
} Elemento;

/*  'Historico' define e simplifica a utilizacao da 'struct pilha' durante a execucao
**  do jogo; 'topo' e 'base' armazenam, respectivamente, o topo e a base da pilha;
**  'quant' armazena a quantidade de elementos na pilha */
typedef struct pilha{
    Elemento *topo, *base;
    int quant;
} Historico;

/*  Lista de funcoes para manipulacao sobre as TADs: */

/*  Criacao do Historico de Jogadas */
Historico * cria_historico ();

/*  Criacao de um elemento do Historico */
Elemento * cria_elemento ();

/* Criacao de um Ponto no tabuleiro */
Ponto * cria_ponto ();

/*  Criacao do Tabuleiro a ser realizado o Jogo */
int ** cria_tabuleiro (int);

/*  Inicializacao dos Numeros Primos */
Primo * inicia_primos (int);

/*  Inicializacao do Tabuleiro */
void inicia_tabu (Primo *, Tabuleiro *);

void zera_tabu (Tabuleiro *, Primo *);

/*  Desalocacao dos Numeros Primos */
void libera_primos (Primo *);

/*  Desalocacao Completa do Tabuleiro */
void libera_tabuleiro (Tabuleiro *);

/*  Desalocacao de um Elemento do Historico */
void libera_elemento (Elemento *);

/*  Desaloca toda a sequencia gravada no Historico */
Historico * libera_elementos (Historico *hist);

/*  Desalocacao completa do Historico */
void libera_historico (Historico *);

/* Desalocacao completa de um ponto */
void libera_ponto (Ponto *);

void libera_point (Seqpontos *);

/*  Adiciona o movimento realizado no historico */
void constroi_historico (Historico *, Tabuleiro *, Primo *, int, char, char, char);

void insere_pontos (Seqpontos *, int, char, char);

/*  Localizacao de um numero primo dentre as opcoes */
int localiza_primo (Primo *, int, int, int);

/*  Determinacao do menor numero primo digitado pelo usuario */
char menor_tabu (Ponto *, Primo *, Tabuleiro *);

/*  Retira o ultimo movimento do historico */
Ponto * remove_historico (Historico *, Tabuleiro *, Primo *, int);

/*  Exibicao na tela do Tabuleiro */
void imprime_tabu (Tabuleiro *);

/*  Exibicao na tela dos numeros primos */
void imprime_primo (Primo *, int);

/*  Exibicao na tela o Historico de movimentos */
void imprime_historico (Historico *);
