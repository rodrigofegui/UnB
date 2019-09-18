/*  Cabecalho das funções relacionadas as TADs; definicoes de constantes globais;
**  assim como definicoes das estruturas a serem utilizadas na simulacao */

/*  Definicao das TADs a serem usadas na simulacao:  */

/*  'Letra' define e simplifica o uso da 'struct letra', fara o armazenamento de cada
**  letra da nova palavra a ser montada; 'letra' armazena a letra da palavra; 'prox'
**  aponta para a proxima letra da palavra */
typedef struct letra{
    char letra;
    struct letra *prox;
}
Letra;

/*  'Palavra' define e simplifica o uso da 'struct word', armazena a palavra montada de forma
**  dinamica e variante de acordo com a demanda de cada palavra; 'inicio' armazena o inicio da
**  palavra manipulada; 'quant' armazena o tamanho da palavra */
typedef struct word{
    Letra *inicio;
    int quant;
}
Palavra;

/*  'Arquivos' define e simplifica o uso da 'struct arq', armazena os documentos a serem manipulados
**  durante o processamento; 'nome' armazena o nome do documento que sera manipulado processamento;
**  'tamanho' armazena a quantidade de palavras existentes no mesmo */
typedef struct arq{
    char *nome;
    int tamanho;
}
Arquivos;

/*  'Documento' define e simplifica o uso da 'struct doc', armazenara a fila de documentos
**  que contem as palavras; 'nome' armazena o nome do documento que contem a palavra; 'prox'
**  aponta para o proximo elemento da lista de documentos */
typedef struct doc{
    char *nome;
    struct doc *prox;
}
Documento;

/*  'Registro' define e simplifica o uso da 'struct reg', armazenara todas as informacoes importantes
**  para as palavras tratadas no processamento; 'chave' armazena a chave para a palavra; 'docs' armazena
**  a quantidade de documentos que possuem a palavra; 'palavra' armazena a palavra em si a ser considerada
**  para o processamento; 'documentos' armazena a lista de documentos que possuem a palavra */
typedef struct reg{
    int chave, docs;
    char *palavra;
    struct reg *prox;
    Documento *documentos;
}
Registro;

/*  'Lista' define e simplifica o uso da 'struct lista', armazenara a lista de palavras, tanto para o
**  levantamento das informacoes como para a montagem da tabela hashing; 'inicio' armazena o inicio da
**  lista propriamente dita; 'quant' armazena a quantidade de palavras na lista */
typedef struct lista{
    Registro *inicio;
    int quant;
}
Lista;

/*  'Hashing' define e simplifica o uso da 'struct hashi', armazenara a tabela hashing, assim como suas
**  estatisticas gerais; 'totpalavras' e 'totpalavrasdistin' armazenam os totais de palavras, existentes
**  nos documentos e as distintas; 'tamtab' armazena o tamanho da tabela; 'totcolisoes' armazena o total
**  de colisoes, independente do indice; 'indice' e 'maiorcoli' armazenam as posicoes, havendo mais de uma,
**  e a quantidade de colisoes no pior caso, assim como 'quant' armazena a quantidade de indices com este
**  valor de colisoes; 'tabhash' armazena a tabela hash propriamente dita */
typedef struct hashi{
    int totpalavras, totpalavrasdistin;
    int tamtab, totcolisoes;
    int *indice, maiorcoli, quant;
    Lista *tabhash;
}
Hashing;


/*  Lista de funcoes para manipulacao sobre as TADs: */

/*  Criacao de uma letra */
Letra * cria_letra ();

/*  Criacao de uma nova palavra */
Palavra * cria_palavra ();

/*  Criacao de um novo documento */
Documento * cria_doc ();

/*  Criacao da lista de arquivos a serem manipulados */
Arquivos * cria_arq (int);

/*  Criacao de um novo elemento para a lista de palavras */
Registro * cria_reg ();

/*  Criacao da lista de palavras */
Lista * cria_lista (int);

/*  Criação da tabela hashing e suas estatisticas */
Hashing * cria_hash (int);



/*  Libera o espaco alocado para uma letra */
void libera_letra (Letra *);

/*  Libera o espaco alocado para uma palavra */
void libera_palavra (Palavra *);

/*  Libera o espaco alocado para um documento */
void libera_doc (Documento *);

/*  Libera o espaco alocado para a lista de documentos */
void libera_arq (Arquivos *);

/*  Libera o espaco alocado para um registro */
void libera_reg (Registro *);

/*  Libera o espaco alocado para a lista */
void libera_lista (Lista *, int);

/*  Libera o espaco alocado para a tabela */
void libera_hash (Hashing *);



/*  Construcao de uma palavra */
void constroi_palavra (Palavra *, char);

/*  Construcao da lista de palavras */
void constroi_lista (Lista *, char *, char *);

/*  Constroi a fila de documentos para a palavra */
void monta_doc (Registro *, char *);

/*  Transfere as palavras da lista para a tabela hashing */
int * monta_hash (Arquivos *, Hashing *, Lista *, int, int);



/*  Procura a palavra na tabela hashing */
void localiza_palavra (Hashing *, char *);



/*  Remove a primeira letra da palavra */
char remove_letra (Palavra *);

/*  Remove o primeiro registro da lista de palavras */
Registro * remove_lista (Lista *);



/*  Exibe na tela a lista de documentos */
void exibe_arq (Arquivos *, int);

/*  Exibe na tela os documentos */
void exibe_doc (Documento *);

/*  Exibe na tela a lista de palavras */
void exibe_lista (Lista *, float);

/*  Exibe na tela a tabela hashing */
void exibe_hash (Hashing *, int);

/*  Realiza a pausa escolhida pelo usuario */
void exibe_tempo (float);


/*  Escreve os arquivos num documento */
void escreve_arq (Arquivos *, FILE *, int);

/*  Escreve os documentos num documento */
void escreve_doc (Documento *, FILE *);

/*  Escreve a lista num documento */
void escreve_lista (FILE *, Lista *);

/*  Escreve o resultado do processamento num documento */
void escreve_result (Arquivos *, Hashing *, int);
