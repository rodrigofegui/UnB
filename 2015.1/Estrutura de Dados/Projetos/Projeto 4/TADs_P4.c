/*  Descritivo das funções para andamento do Projeto */

/*  Bibliotecas requisitada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Funcoes_P4.h"

/*  Lista das funcoes de manipulacao */

/*  Funcao 'cria_letra', realiza a criacao de uma letra */
Letra * cria_letra (){
    /*  'nova' armazena a nova letra a ser adicionada */
    Letra *nova;

    /*  Alocacao da letra */
    do{
        nova = (Letra *) malloc (sizeof(Letra));
    }while (nova == NULL);

    /*  Inicializacao das variaveis de controle */
    nova->letra = '\0';
    nova->prox = NULL;

    return nova;
}

/*  Funcao 'cria_palavra', realiza a criacao de uma nova palavra */
Palavra * cria_palavra (){
    /*  'nova' armazena a nova palavra a ser criada */
    Palavra *nova;

    /*  Alocacao da palavra */
    do{
        nova = (Palavra *) malloc (sizeof(Palavra));
    }while (nova == NULL);

    /*  Inicializacao das variaveis de controle */
    nova->inicio = NULL;
    nova->quant = 0;

    return nova;
}

/*  Funcao 'cria_doc', realiza a criacao de um novo documento a ser
**  manipulado no processamento */
Documento * cria_doc (){
    /*  'novo' armazena o novo documento a ser manipulado no
    **  processamento */
    Documento *novo;

    /*  Alocacao do documento */
    do{
        novo = (Documento *) malloc (sizeof(Documento));
    }while (novo == NULL);

    /*  Inicializacao das variaveis de controle */
    novo->nome = NULL;
    novo->prox = NULL;

    return novo;
}

/*  Funcao 'cria_arq', realiza a criacao da lista de arquivos a serem manipulados */
Arquivos * cria_arq (int tam){
    /*  'tam' armazena o tamanho do vetor a ser criado; 'novo' armazena a lista de
    **  documentos a ser manuseada no processamento; 'ind' armazena o indice do novo
    **  a ser feito a inicializacao */
    Arquivos *novo;
    int ind;

    /*  Alocacao do Arquivos */
    do{
        novo = (Arquivos *) malloc (tam * sizeof (Arquivos));
    }while (novo == NULL);

    /*  Inicializacao das variaveis de controle */
    for (ind = 0; ind < tam; ind++){
        novo[ind].nome = NULL;
        novo[ind].tamanho = 0;
    }

    return novo;
}

/*  Funcao 'cria_reg', realiza a criacao de um novo elemento para a lista de palavras */
Registro * cria_reg (){
    /*  'novo' armazena a nova palavra a ser manipulado no
    **  processamento */
    Registro *nova;

    /*  Alocacao da nova palavra */
    do{
        nova = (Registro *) malloc (sizeof(Registro));
    }while (nova == NULL);

    /*  Inicializacao das variaveis de controle */
    nova->palavra = NULL;
    nova->prox = NULL;
    nova->documentos = NULL;
    nova->chave = nova->docs = 0;

    return nova;
}

/*  Funcao 'cria_lista', realiza a criacao da lista de palavras */
Lista * cria_lista (int tam){
    /*  'tam' armazena o tamanho do vetor de lista a ser criado; 'nova' armazena o vetor
    **  de lista a ser criado; 'ind' armazena o indice do vetor a ser manipulado */
    Lista *nova;
    int ind;

    /*  Alocacao da Lista */
    do{
        nova = (Lista *) malloc (tam*sizeof(Lista));
    }while (nova == NULL);

    /*  Inicializacao das variaveis de controle */
    for (ind = 0; ind < tam; ind++){
        nova[ind].inicio = NULL;
        nova[ind].quant = 0;
    }

    return nova;
}

/*  Funcao 'cria_hash', realiza a criação da tabela hashing e suas estatisticas */
Hashing * cria_hash (int tam){
    /*  'tam' armazena o tamanho da tabela a ser criada; 'novo' armazena a tabela
    **  e suas estatisticas a serem criadas */
    Hashing *novo;

    /*  Alocacao do Ramo */
    do{
        novo = (Hashing *) malloc (sizeof(Hashing));
    }while (novo == NULL);

    /*  Inicializacao das variaveis de controle */
    novo->totpalavras = novo->totpalavrasdistin = 0;
    novo->totcolisoes = novo->maiorcoli = novo->quant = 0;
    novo->tamtab = tam;
    novo->indice = NULL;
    novo->tabhash = cria_lista (tam);

    return novo;
}



/*  Funcao 'libera_letra', desaloca o espaco reservado para uma letra */
void libera_letra (Letra *letra){
    /*  'letra' armazena a letra a ser liberada */
    free (letra);
}

/*  Funcao 'libera_palavra', desaloca o espaco para todas de uma palavra */
void libera_palavra (Palavra *palavra){
    /*  'palavra' armazena a palavra a ser liberada */

    /*  Havendo letras existentes */
    if (palavra->inicio != NULL){
        Letra *aux;

        /*  Percorre todas as letras e as libera */
        while(palavra->inicio != NULL){
            aux = palavra->inicio;
            palavra->inicio = aux->prox;
            libera_letra (aux);
        }
    }

    free (palavra);
}

/*  Funcao 'libera_doc', desaloca o espaco alocado para um documento */
void libera_doc (Documento *doc){
    /*  'doc' armazena o documento a ser liberado */
    free (doc);
}

/*  Funcao 'libera_arq', desaloca o espaco alocado para a lista de documentos */
void libera_arq (Arquivos *arq){
    /*  'arq' armazena o vetor de arquivos a ser liberado */
    free (arq);
}

/*  Funcao 'libera_reg', desaloca o espaco alocado para um registro */
void libera_reg (Registro *reg){
    /*  'reg' armazena o registro a ser liberado */
    free (reg);
}

/*  Funcao 'libera_lista', desaloca o espaco alocado para a lista */
void libera_lista (Lista *list, int tam){
    /*  'list' armazena a lista a ser liberada; 'tam' armazena o tamanho
    **  do vetor lista a ser liberado */

    /*  Havendo lista a ser liberada */
    if (list != NULL){
        /*  'aux' auxilia na remocao dos registro na lista; 'ind' armazena
        **  o indice do vetor lista a ser manipulado */
        Registro *aux;
        int ind;

        /*  Percorre todo o vetor lista */
        for (ind = 0; ind < tam; ind++){

            /*  Enquanto houver registro a ser liberado */
            while (list[ind].inicio != NULL){
                aux = list[ind].inicio;
                list[ind].inicio = aux->prox;
                libera_reg (aux);
                aux = NULL;
            }
        }
    }

    free (list);
}

/*  Funcao 'libera_hash', desaloca o espaco alocado para a tabela */
void libera_hash (Hashing *tabela){
    /*  'tabela' armazena a tabela hashing a ser liberada; */

    libera_lista (tabela->tabhash, tabela->tamtab);

    free (tabela);
}



/*  Funcao 'constroi_palavra', realiza a construcao de uma palavra */
void constroi_palavra (Palavra *palavra, char leitura){
    /*  'palavra' armazena a palavra que esta sendo montada; 'leitura'
    **  armazena o caracter lido e provavelmente a ser inserido na palavra */
    if (palavra == NULL) return;

    if (leitura != 10){
        /*  'nova' armazena uma nova letra valida a ser adicionada a palavra */
        Letra *nova = cria_letra();

        /*  Inicializacao da letra */
        nova->letra = leitura;

        /*  Montagem da palavra, caso não exista ainda */
        if (palavra->inicio == NULL)
            palavra->inicio = nova;

        /*  Ou já existente, inserir no final */
        else{
            Letra *aux = palavra->inicio;

            while (aux->prox != NULL)
                aux = aux->prox;

            aux->prox = nova;
        }

        /*  Incremento no numero de letra da palavra */
        palavra->quant++;
    }
}

/*  Funcao 'constroi_lista', realiza a construcao da lista de palavras */
void constroi_lista (Lista *list, char *palavra, char *nomearq){
    /*  'list' armazena a lista de palavras a ser construida; 'palavra' armazena a palavra
    **  a ser avaliada a insercao na 'list'; 'nomearq' armazena o nome do arquivo corrente
    **  ao qual a palavra pertence */

    /*  Nao havendo lista */
    if (list == NULL) return;

    /* Havendo lista, mas vazia */
    if (list->inicio == NULL){
        /*  'novo' armazena o novo registro a ser adicionado na lista */
        Registro *novo = cria_reg ();

        /*  Configuracao do novo registro */
        novo->palavra = (char *) calloc (strlen(palavra), sizeof (char));
        strcpy (novo->palavra, palavra);
        novo->chave = chaveamento (novo->palavra);
        monta_doc (novo, nomearq);

        /*  Armacaoda lista */
        list->inicio = novo;
        list->quant++;

    }else{
        /*  'aux' auxilia a procura na lista */
        Registro *aux = list->inicio;

        /*  Enquanto houver lista e nao encontrar a palavra na lista */
        while (aux->prox != NULL && strcmp (palavra, aux->palavra) != 0)
            aux = aux->prox;

        /*  Nao tem a palavra na lista, adiciona-se no final */
        if (aux->prox == NULL){
            /*  'novo' armazena o novo registro a ser adicionado na lista */
            Registro *novo = cria_reg ();

            /*  Configuracao do novo registro */
            novo->palavra = (char *) calloc (strlen(palavra), sizeof (char));
            strcpy (novo->palavra, palavra);
            novo->chave = chaveamento (novo->palavra);
            monta_doc (novo, nomearq);

            /*  Armacaoda lista */
            aux->prox = novo;
            list->quant++;

        /*  Tendo a palavra, analisa-se a condicao do documento, perante a palavra */
        }else if (strcmp (palavra, aux->palavra) == 0)
            monta_doc (aux, nomearq);
    }
}

/*  Funcao 'monta_doc', realiza a construcao da fila de documentos para a palavra */
void monta_doc (Registro *reg, char *nomearq){
    /*  'reg' armazena o registro a ser manipulado nesta etapa; 'nomearq' armazena o nome
    **  do arquivo a ser avaliado na insercao; 'aux' auxilia na procura do documento */
    Documento *aux = reg->documentos;

    /*  Nao havendo documentos */
    if (aux == NULL){
        /*  'novo' armazena o novo documento a ser inserido */
        Documento *novo = cria_doc ();

        /*  Configuracao do novo documento */
        novo->nome = (char *) calloc (strlen(nomearq), sizeof(char));
        strcpy (novo->nome, nomearq);

        /* Armacao da lista de documentos */
        reg->documentos = novo;
        reg->docs++;

    /*  Havendo lista de documentos */
    }else{
        /*  Enquanto tiver lista e nao houver o arquivo armazenado */
        while (aux->prox != NULL && strcmp (aux->nome, nomearq) != 0)
            aux = aux->prox;

        /*  Acabando a lista e nao sendo o arquivo */
        if (aux->prox == NULL && strcmp (aux->nome, nomearq) != 0){
            /*  'novo' armazena o novo documento a ser inserido */
            Documento *novo = cria_doc ();

            /*  Configuracao do novo documento */
            novo->nome = (char *) calloc (strlen(nomearq), sizeof(char));
            strcpy (novo->nome, nomearq);

            /* Armacao da lista de documentos */
            aux->prox = novo;
            reg->docs++;
        }
    }
}

/*  Funcao 'monta_hash', realiza a transferencia das palavras da lista para a tabela hashing*/
int * monta_hash (Arquivos *arq, Hashing *tabela, Lista *list, int tam, int quant){
    /*  'arq' armazena o vetor de documentos avaliados no processamento; 'tabela' armazena a tabela
    **  a ser criada; 'list' armazena a lista de palavras a manipulada; 'tam' armazena o tamanho
    **  da tabela; 'quant' armazena a quantidade de documentos avaliados; 'aux' e 'aux2' auxiliam
    **  nos processos; 'posicoes' armazena todas as posicoes da tabela que possuem o maior numero de
    **  colisoes; 'ind' e 'ind2' armazena indices a serem manipulados */
    Registro *aux, *aux2;
    int *posicoes, ind, ind2 = 0;

    /*  Contagem bruta do total de palavras */
    for (ind = 0; ind < quant; ind++)
        tabela->totpalavras += arq[ind].tamanho;

    /*  Configuracao do total liquido de palavras e do tamanho da tabela */
    tabela->totpalavrasdistin = list->quant;
    tabela->tamtab = tam;

    /*  Enquanto houver lista de palavras */
    while (list->inicio != NULL){
        aux = remove_lista (list);
        ind = calc_hashing (aux->chave, tam);
        aux2 = tabela->tabhash[ind].inicio;

        /*  Nao havendo lista para este indice */
        if (aux2 == NULL)

            /*  Armacao da lista */
            tabela->tabhash[ind].inicio = aux;

        /*  Havendo */
        else{
            /*  Enquanto houver lista e a chave referencia for maior que a proxima a ser avaliada */
            while (aux2->prox != NULL && aux->chave > aux2->prox->chave)
                aux2 = aux2->prox;

            /*  Armacao da lista */
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }

        /*  Incremento na quantidade de palavras para este indice */
        tabela->tabhash[ind].quant++;

    };

    /*  Avalia o maior numero de colisoes */
    for (ind = 0; ind < tam; ind++){
        /*  Contagem de colisoes */
        if (tabela->tabhash[ind].quant > 0)
            tabela->totcolisoes += (tabela->tabhash[ind].quant - 1);
        if (tabela->tabhash[ind].quant > tabela->maiorcoli)
            tabela->maiorcoli = tabela->tabhash[ind].quant;
    }

    /*  Contagem da quantidade de indices com o numero maximo de colisoes */
    for (ind = 0; ind < tam; ind++){
        if (tabela->tabhash[ind].quant == tabela->maiorcoli)
            tabela->quant++;
    }

    /*  Configuracao dos indices que possuem o numero maximo de colisoes */
    posicoes = (int *) calloc (tabela->quant, sizeof(int));
    ind2 = 0;
    for (ind = 0; ind < tam; ind++){
        if (tabela->tabhash[ind].quant == tabela->maiorcoli){
            posicoes[ind2] = ind;
            ind2++;
        }
    }

    /*  Correcao do numero de colisoes */
    tabela->maiorcoli--;

    return posicoes;
}



/*  Funcao 'localiza_palavra', realiza a procura a palavra na tabela hashing */
void localiza_palavra (Hashing *tabela, char *palavra){
    /*  'tabela' armazena a tabela hashing; 'palavra' armazena a palavra a ser procurada na tabela;
    **  'aux' auxilia na navegacao da lista; 'codigo' armazena o indice da tabela hashing */
    Registro *aux;
    int codigo;

    /*  Codificao da palavra numa chave, posteiormente no indice */
    codigo = chaveamento (palavra);
    codigo = calc_hashing (codigo, tabela->tamtab);

    /*  Configuracao de qual indice sera feita busca */
    aux = tabela->tabhash[codigo].inicio;

    /*  Enquanto houver lista e nao encontrar a palavra */
    while (aux != NULL && strcmp(palavra, aux->palavra) != 0)
        aux = aux->prox;

    /*  Nao encontrando */
    if (aux == NULL){
        printf ("\nA palavra '%s' nao pertence ao nosso banco de dados!\n\n", palavra);

    /*  Encontrando */
    }else if (strcmp(palavra, aux->palavra) == 0){
        printf ("\nA palavra '%s' foi encontrada!! Tendo tais atribuicoes:\n", palavra);
        printf ("\tChave = %d\n", aux->chave);
        printf ("\tIndice = %d\n", codigo);
        printf ("\tQuant. documentos relacionados = %d\n", aux->docs);
        printf ("\tLista de documentos relacionados:\n");
        exibe_doc (aux->documentos);
        printf ("\n");
    }
}



/*  Funcao 'remove_letra', realiza a remocao da primeira letra da
**  palavra */
char remove_letra (Palavra *palavra){
    /*  'palavra' armazena a palavra a ser manipulada */

    /*  Nao existindo palavra */
    if (palavra == NULL || palavra->inicio == NULL)
        return '\0';

    /*  'aux' auxilia na remocao de uma letra da palavra; 'leitura'
    **  armazena a letra em si */
    Letra *aux = palavra->inicio;
    char leitura = aux->letra;

    /*  Decrementa o tamanho da palavra e mantem a arrumacao da
    **  palavra */
    palavra->quant--;

    if (palavra->quant == 0)
        palavra->inicio = NULL;

    else
        palavra->inicio = aux->prox;

    /*  Liberacao da letra nao mais util */
    libera_letra (aux);

    return leitura;
}

/*  Funcao 'remove_lista', realiza a remocao do primeiro registro da lista de palavras */
Registro * remove_lista (Lista *list){
    /*  'list' armazena a lista de palavra a ser manipulada */

    /*  Havendo lista */
    if (list == NULL || list->inicio == NULL)
        return NULL;

    /*  'aux' auxilia na remocao do primeiro registro */
    Registro *aux = list->inicio;

    /*  Configuracao da lista e manutencao da estrutura */
    list->quant--;

    if (list->quant == 0)
        list->inicio = NULL;
    else
        list->inicio = aux->prox;

    aux->prox = NULL;

    return aux;
}



/*  Funcao 'exibe_arq', exibe na tela a lista de documentos */
void exibe_arq (Arquivos *arq, int tam){
    /*  'arq' armazena o vetor de documentos a ser exibido na tela; 'tam' armazena o tamanho
    **  do vetor; 'tempo' armazena o tempo de pausa entre as exibicoes; 'ind' armazena o indice
    **  a ser manipulado */
    float tempo;
    int ind;

    /*  Questionamento sobre o modo de exibicao */
    limpa_tela ();
    printf ("Para a exibicao dos documentos processados\n");
    tempo = questiona_tempo ();
    temporizador(1.0);
    limpa_tela ();

    /*  Exibicao da lista de documentos */
    printf ("Lista de documentos processados:\n");

    /*  Percorre todo o vetor, exibindo-o */
    for (ind = 0; ind < tam; ind++){
        printf ("\n%dº Documento:", ind + 1);
        printf ("\n\tNome = %s", arq[ind].nome);
        printf ("\n\tTotal de palavras = %d\n", arq[ind].tamanho);

        if (tempo >= 0)
            exibe_tempo (tempo);
    }

    if (tempo < 0)
        pausa();
}

/*  Funcao 'exibe_doc', exibe na tela os documentos */
void exibe_doc (Documento *doc){
    /*  'doc' armazena a fila de documentos a ser exibida na tela */

    /*  Havendo lista de documentos */
    if (doc != NULL){
        /*  'aux' auxilia na navegacao da lista de documentos */
        Documento *aux = doc;

        /*  Exibicao da lista */
        printf ("\t\tNome(s) = ");
        while (aux != NULL){
            printf ("%s", aux->nome);
            if (aux->prox != NULL)
                printf(", ");
            else
                printf ("\n\n");
            aux = aux->prox;
        }
    }
}

/*  Funcao 'exibe_lista', exibe na tela a lista de palavras */
void exibe_lista (Lista *list, float tempo){
    /*  'list' armazena a lista de palavras a ser exibida; 'tempo' armazena o tempo de espera
    **  entre as atualizacoes na tela */

    /*  Havendo lista */
    if (list->inicio != NULL){
        /*  'aux' auxilia na navegacao da lista */
        Registro *aux = list->inicio;

        /*  Exibicao da lista de palavras na tela */
        printf ("%d palavras associadas\n", list->quant);
        while (aux != NULL){
            printf ("\tPalavra = %s\n", aux->palavra);
            printf ("\tChave = %d\n", aux->chave);
            printf ("\tQuant. documentos relacionados = %d\n", aux->docs);
            printf ("\tLista de documentos relacionados:\n");
            exibe_doc (aux->documentos);

            if (tempo >= 0)
                exibe_tempo (tempo);

            aux = aux->prox;
        }

    }else
        printf ("0 palavras associadas\n");
}

/*  Funcao 'exibe_hash', exibe na tela a tabela hashing */
void exibe_hash (Hashing *tabela, int quant){
    /*  'tabela' armazena a tabela hashing e suas estatisticas; 'quant' armazena a quantidade
    **  de documentos avaliados; 'tempo' armazena o tempo de espera entre as atualizacaoes
    **  na tela; 'ind' armazena o indice a ser manipulado */
    float tempo;
    int ind;

    /*  Questionamento sobre o modo de exibicao */
    limpa_tela ();
    printf ("Para a exibicao dos dados da Tabela Hashing\n");
    tempo = questiona_tempo ();
    temporizador(0.8);
    limpa_tela ();

    if (tempo >= 0)
        exibe_tempo (tempo);

    /*  Exibicao da tabela hashing, propriamente dita */
    for (ind = 0; ind < tabela->tamtab; ind++){
        printf ("O indice %d tem ", ind);
        exibe_lista (&(tabela->tabhash[ind]), tempo);

        if (tempo >= 0)
            exibe_tempo (tempo);
    }

    /*  Exibicao das estatisticas da tabela hashing */
    printf ("Dados da Tabela Hashing\n");

    printf ("Total de palavras no(s) %d documento(s) = %d\n", quant, tabela->totpalavras);
    printf ("Total de palavras, sem repeticoes = %d\n", tabela->totpalavrasdistin);
    printf ("Tamanho da tabela hashing = %d\n", tabela->tamtab);
    printf ("Total de colisoes = %d\n", tabela->totcolisoes);
    printf ("Numero maximo de colisoes = %d\n", tabela->maiorcoli);
    printf ("Indice(s) com este valor de colisoes = ");
    for (ind = 0; ind < tabela->quant; ind++){
        printf("%d", tabela->indice[ind]);
        if (tabela->quant > 1 && ind < (tabela->quant - 1))
            printf (", ");
        else
            printf ("\n\n");
    }
}

/*  Funcao 'exibe_tempo', realiza a pausa escolhida pelo usuario */
void exibe_tempo (float tempo){
    /*  'tempo' armazena o tempo de espera entre as atualizacao das informacoes */

    /*  Sendo por ENTER */
    if (tempo == 0.0)
        pausa ();

    /*  Sendo por tempo */
    else
        temporizador (tempo);
}


/*  Funcao 'escreve_arq', escreve os arquivos num documento */
void escreve_arq (Arquivos *arquivos, FILE *arq, int tam){
    /*  'arquivos' armazena o vetor de documentos a ser exibido na tela; 'arq' armazena o ponteiro
    **  do arquivo a ser escrito; 'tam' armazena o tamanho do vetor; 'ind' armazena o indice a ser
    **  manipulado */
    int ind;

    /*  Escrita da lista de documentos */
    fprintf (arq, "Lista de documentos processados:\n");

    /*  Percorre todo o vetor, escrevendo-o */
    for (ind = 0; ind < tam; ind++){
        fprintf (arq, "\n%dº Documento :", ind + 1);
        fprintf (arq, "\n\tNome = %s", arquivos[ind].nome);
        fprintf (arq, "\n\tTotal de palavras = %d\n", arquivos[ind].tamanho);
    }
}

/*  Funcao 'escreve_doc', escreve os documentos num documento */
void escreve_doc (Documento *doc, FILE *arq){
    /*  'doc' armazena a fila de documentos a ser exibida na tela; 'arq' armazena o ponteiro
    **  do arquivo a ser escrito */

    /*  Havendo lista de documentos */
    if (doc != NULL){
        /*  'aux' auxilia na navegacao da lista de documentos */
        Documento *aux = doc;

        /*  Escrita da lista */
        fprintf (arq, "\t\tNome(s) = ");
        while (aux != NULL){
            fprintf (arq, "%s", aux->nome);
            if (aux->prox != NULL)
                fprintf(arq, ", ");
            else
                fprintf (arq, "\n\n");
            aux = aux->prox;
        }
    }
}

/*  Funcao 'escreve_lista', escreve a lista num documento */
void escreve_lista (FILE *arq, Lista *list){
    /*  'arq' armazena o ponteiro do arquivo a ser escrito; 'list' armazena a lista de palavras a ser exibida */

    /*  Havendo lista */
    if (list->inicio != NULL){
        /*  'aux' auxilia na navegacao da lista */
        Registro *aux = list->inicio;

        /*  Escrita da lista de palavras no documento */
        fprintf (arq, "%d palavras associadas\n", list->quant);
        while (aux != NULL){
            fprintf (arq, "\tPalavra = %s\n", aux->palavra);
            fprintf (arq, "\tChave = %d\n", aux->chave);
            fprintf (arq, "\tQuant. documentos relacionados = %d\n", aux->docs);
            fprintf (arq, "\tLista de documentos relacionados:\n");
            escreve_doc (aux->documentos, arq);

            aux = aux->prox;
        }

    }else
        fprintf (arq, "0 palavras associadas\n");
}

/*  Escreve o resultado do processamento num documento */
void escreve_result (Arquivos *documentos, Hashing *tabela, int quant){
    /*  'documentos' armazena o vetor de documentos a ser escrito no documento; a'tabela' armazena
    **  a tabela hashing e suas estatisticas; 'quant' armazena a quantidade de documentos avaliados;
    **  'arq' armazena o ponteiro do arquivo a ser escrito; 'nomearq' armazena o nome do arquivo a ser
    **  escrito as informacoes; 'ind' armazena o indice a ser manipulado */
    FILE *arq = NULL;
    char *nomearq;
    int ind;

    /*  Leitura dinaminca do documento para escrita e configuraca de 'arq' */
    nomearq = ler_nome_doc (0, 0, 'e');
    arq = abre_arquivo (nomearq, 'w', 'l');


    /*  Escreve os arquivos num documento */
    escreve_arq (documentos, arq, quant);

    /*  Escrita das estatisticas da tabela hashing */
    fprintf (arq, "\n\nDados da Tabela Hashing\n");

    fprintf (arq, "Total de palavras no(s) %d documento(s) = %d\n", quant, tabela->totpalavras);
    fprintf (arq, "Total de palavras, sem repeticoes = %d\n", tabela->totpalavrasdistin);
    fprintf (arq, "Tamanho da tabela hashing = %d\n", tabela->tamtab);
    fprintf (arq, "Total de colisoes = %d\n", tabela->totcolisoes);
    fprintf (arq, "Numero maximo de colisoes = %d\n", tabela->maiorcoli);
    fprintf (arq, "Indice(s) com este valor de colisoes = ");
    for (ind = 0; ind < tabela->quant; ind++){
        fprintf(arq, "%d", tabela->indice[ind]);
        if (tabela->quant > 1 && ind < (tabela->quant - 1))
            fprintf (arq, ", ");
        else
            fprintf (arq, "\n\n");
    }

    /*  Escrita da tabela hashing, propriamente dita */
    for (ind = 0; ind < tabela->tamtab; ind++){
        fprintf (arq, "O indice %d tem ", ind);
        escreve_lista (arq, &(tabela->tabhash[ind]));
    }

}
