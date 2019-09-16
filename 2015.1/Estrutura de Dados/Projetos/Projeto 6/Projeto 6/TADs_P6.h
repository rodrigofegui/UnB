/*  Cabecalho das funções relacionadas as TADs; definicoes de constantes globais;
**  assim como definicoes das estruturas a serem utilizadas na simulacao */


/*  Definicoes de constantes utilizadas */
/*  'MAX' armazena o tamanho maximo para o nome de uma cidade;
**  'MAXC' armazena o tamanho de cidades registradas no grafo */
#define MAX 17
#define MAXC 15


/*  Definicao das TADs a serem usadas no projeto:  */
/*  'Referencia' define e simplifica o uso da 'struct referencia', armazena as cidades que
**  possuem ligacao direta com a cidade corrente */
typedef struct referencia Referencia;

/*  'Cidade' define e simplifica o uso da 'struct city', armazena a cidade em si */
typedef struct city Cidade;

/*  'Grafo' define e simplifica o uso da 'struct grafo', armazena o grafo gerado a partir
**  das cidades utilizadas, sendo montado como uma lista de adjacencia */
typedef struct grafo Grafo;

/*  'Elemento' define e simplifica o uso da 'struct node', armazena o elemento a ser constituente
**  do roteiro de viagem */
typedef struct elem Elemento;

/*  'Roteiro' define e simplifica o uso da 'struct roteiro', armazena o roteiro realizado
**  pelo viajante para cada cidade de origem */
typedef struct script Roteiro;



/*  Implementacao das TADs a serem usadas no projeto */

/*  'city' armazena a cidade em si; 'distancia' armazena a distancia entre as cidades de interesse;
**  'proximo' armazena o proximo elemento da lista */
struct referencia{
    Cidade *city;
    int distancia;
    Referencia *proximo;
};

/*  'nome' armazena o nome da cidade em si; 'inicio' armazena o inicio da lista de cidades que possuem
**  ligacao direta com a cidade corrente; 'proximo' armazena a proxima cidade na lista do grafo */
struct city{
    char nome[MAX], status;
    int quantref;
    Referencia *inicio;
    Cidade *proximo;
};

/*  'quant' armazena a quantidade de cidades registradas no grafo; 'inicio' aponta para o inicio da lista
**  de cidade no grafo */
struct grafo{
    int quant, livres;
    Cidade *inicio;
};

/*  'distancia' armazena a distancia da cidade atual para a anterior a ele; 'nome' armazena o nome da cidade
**  corrente; 'proximo' armazena o endereco do proximo elemento da lista */
struct elem{
    int distancia;
    char nome[MAX];
    Elemento *proximo;
};

/*  'kilometragem' armazena o total de quilometros necessarios para a realizacao do roteiro sugerido;
**  'inicio' armazena o inicio do roteiro */
struct script{
    int kilometragem;

    Elemento *inicio, *fim;
};

/*  Lista de funcoes para manipulacao sobre as TADs: */

/*  1 - Secao de Criacao das Estruturas */
/*  1.1 - Criacao de uma nova referencia */
Referencia * cria_ref ();

/*  1.2 - Criacao de uma nova Cidade */
Cidade * cria_city ();

/*  1.3 - Criacao de um novo Grafo */
Grafo * cria_grafo ();

/*  1.4 - Criacao de um novo Elemento */
Elemento * cria_elemento ();

/*  1.4 - Inicializa as variaveis de controle de um Roteiro */
void inicia_roteiro (Grafo *, Roteiro *);




/*  2 - Secao de Liberacao */
/*  2.1 - Libera o espaco alocado para uma referencia */
void libera_ref (Referencia *);

/*  2.2 - Libera o espaco alocado para uma cidade */
void libera_city (Cidade *);

/*  2.3 - Libera o espaco alocado para um grafo */
void libera_grafo (Grafo *);

/*  2.4 - Libera o espaco alocado para um elemento */
void libera_elemento (Elemento *);

/*  2.4 - Libera o espaco alocado para o roteiro  */
void libera_roteiro (Roteiro *);




/*  3 - Secao de Construcao e Organizacao */
/*  3.1 - Construcao do Grafo nao direcionado */
void constroi_grafo (Grafo *, char *, char *, int);

/*  3.2 - Construcao da lista de referencias */
void constroi_ref (Grafo *, Cidade *, char *, int);

/*  3.3 - Insercao nos Registros */
void insere_roteiro (Roteiro *, char *, int);

/*  3.5 - Contrucao dos roteiros de viagem */
void monta_roteiros (Grafo *, Roteiro *, char *);

/*  3.5 - Reinicializa o status das cidades do grafo */
void zera_grafo (Grafo *);

/* 3.6 - Busca por um elemento ainda nao visitado */
void busca_ref (Referencia *, char *);




/*  4 - Secao de Exibicao na Tela e Escrita em Documentos */
/*  4.1 - Exibicao das referencias na tela */
void exibe_ref (Referencia *);

/*  4.2 - Exibicao da cidade na tela */
void exibe_city (Cidade *);

/*  4.3 - Exibicao do grafo na tela */
void exibe_grafo (Grafo *);

/*  4.4 - Exibicao da lista de elementos do roteiro
**  na tela */
void exibe_elemento (Elemento *);

/*  4.5 - Exibicao de um roteiro */
void exibe_roteiro (Roteiro *);

/*  4.6 - Escreve as referencias no arquivo */
void escreve_ref (FILE *, Referencia *);

/*  4.7 - Escreve a cidade no arquivo */
void escreve_city (FILE *, Cidade *);

/*  4.8 - Escreve o grafo no arquivo */
void escreve_grafo (Grafo *, Roteiro *);

/*  4.9 - Escreve a lista de elementos do roteiro
**  no arquivo */
void escreve_elemento (FILE *, Elemento *);

/*  4.10 - Escreve os roteiros de viagem no arquivo */
void escreve_roteiro (FILE *, Roteiro *);

/*  4.11 - Realiza a pausa escolhida pelo usuario */
void exibe_tempo (float);
