/* Cabecalho das Funções relacionadas as Listas, tanto dos documentos como do resultado
** das comparacoes; assim como definicoes das estruturas a serem utilizadas no Programa
** Principal */
/* 'TAMP' e o tamanho maximo primario: tamanho maximo de uma palavra entre os 12 arquivos
** teste; 'TAMS' e o tamanho maximo secundario: tamanho maximo dos nomes dos 12 arquivos
** teste; 'TAMT' e o tamanho maximo terciario: tamanho maximo dos nomes dos arquivos resumos
** dos 12 arquivos teste */
#define TAMP 20
#define TAMS 9
#define TAMT 16
#define QUANT 10

struct elemento{
    /* 'palavra' armazena a palavra contida no documento analisado;
    ** 'frequência' armazena a freq. absoluta da dita palavra no
    ** documento; 'proximo' aponta para o elemento posterior na Lista */
	char palavra [TAMP];
    int frequencia;
	struct elemento *proximo;
};
/* Definicao da struct elemento para simplificacao da manipulacao no programa */
typedef struct elemento Elemento;

struct lista{
    /* 'campos' armazena a quantidade de elementos na lista;
    ** 'comeco' e 'fim' armazenam os enderecos de seus respectivos
    ** elementos da Lista */
    int campos;
    Elemento *comeco;
    Elemento *fim;
};
/* Definicao da struct lista para simplificacao da manipulacao no programa */
typedef struct lista Lista;

struct camporesult{
    /* 'palavra' armazena a palavra em comum entre os documentos analisados;
    ** 'freq1' e 'freq2' armazenam as respectivas frequencias dos documentos
    ** analisados; 'proximo' aponta para o proximo campo da lista */
    char palavra[TAMP];
    int freq1;
    int freq2;
    struct camporesult *proximo;
};
/* Definicao da struct camporesult para simplificacao da manipulacao no programa */
typedef struct camporesult Campo;

struct listaresult{
    /* 'campos' armazena a quantidade de elementos na lista Resultados;
    ** 'comeco' e 'fim' armazenam os enderecos de seus respectivos
    ** elementos da lista Resultado */
    int campos;
    Campo *comeco;
    Campo *fim;
};
/* Definicao da struct listaresult para simplificacao da manipulacao no programa */
typedef struct listaresult Resultado;


/* 1 - Criacao de uma nova Lista */
Lista* cria_lista ();

/* 2 - Criacao de um novo Elemento para a Lista */
Elemento * cria_elemento ();

/* 3 - Criacao de uma nova lista Resultado */
Resultado * cria_resultado ();

/* 4 - Criacao de um novo Campo para a lista Resultado */
Campo * cria_campo ();

/* 5 - Liberacao Completa da Sequencia de Elementos da Lista*/
Lista * libera_elementos (Lista *);

/* 6 - Liberacao da Lista em si */
void libera_lista (Lista *);

/* 7 - Liberacao Completa da Sequencia de Campos da lista Resultado*/
Resultado * libera_campos (Resultado *);

/* 8 - Liberacao da lista Resultado em si*/
void libera_resultado (Resultado *);

/* 9 - Insercao de Informação na Lista */
Lista* add_info (Lista *, char *);

/* 10 - Inserção de Elemento na Lista, no caso especia: Lista vazia */
void add_lista_vazia (Lista *, char *);

/* 11-  Insercao de Elemento na Lista */
void add_elemento (Lista *, char *);

/* 12 - Insercao de Campo na lista Resultado, no caso especia: lista
** Resultado vazia */
Resultado * add_result_vazia (Resultado *, char *, int, int);

/* 13 - Inserção de Campo na lista Resultado */
Resultado * add_campo (Resultado *, char *, int, int);

/* 14 - Ordenação dos Elementos carregados na Lista,
** de forma decrescente */
void ordena_lista (Lista *);

/* Funcao para Manipulacao Avulsa Importante */
/* 15 - Inicialização de uma String */
void zera_string (char *, int );
