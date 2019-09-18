/*	Declaração das constantes a serem utilizadas no projeto */
#define VERDADE 0
#define MENTIRA 1

/*	Declaração das Estruturas: */
/*	O cabeçalho da pilha */
typedef struct pilha Pilha;

/*	O elemento da pilha em si */
typedef struct elemento Elemento;

/*	Os registros intrínsecos dos elementos */
typedef struct reg Registro;


/*	Declaração das Funções: */
/*	Criação da pilha como uma lista encadeada */
Pilha * pilha_cria ();

/*	Criação da pilha como um vetor */
Pilha * pilha_cria_vet (int);

/*	Criação de um elemento da pilha */
Elemento * elemento_cria ();

/*	Inserção de um elemento na pilha */
void pilha_insere (Pilha *, int);

/*	Remoção de um elemento da pilha */
Elemento * pilha_remove (Pilha *);

/*	Retorna o elemento do topo */
Elemento * pilha_topo (Pilha *);

/*	Verifica se a pilha está vazia */
char pilha_vazia (Pilha *);

/*	Verifica se a pilha está cheia */
char pilha_cheia (Pilha *);

/*	Liberação da pilha */
Pilha * pilha_libera (Pilha *);

/*	Liberação de um elemento da pilha */
void elemento_libera (Elemento *);

/*	Exibição da pilha na tela */
void pilha_exibe (Pilha *);

/*	Exibição de um elemento na tela */
void elemento_exibe (Elemento *);


