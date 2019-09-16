/*  Descritivo das funções para andamento do Projeto */

/*  Bibliotecas requisitada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes_P5.h"

/*  Lista das funcoes de manipulacao */

/*  1 - Secao de Criacao de Estruturas */
/*  1.1 - Funcao 'cria_letra', realiza a criacao de uma letra */
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

/*  1.2 - Funcao 'cria_palavra', realiza a criacao de uma nova palavra */
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

/*  1.3 - Funcao 'cria_referencia', realiza a criacao de uma nova referencia */
Referencia * cria_referencia (){
    /*  'nova' armazena a nova referencia a ser criada */
    Referencia *nova;

    /*  Alocacao da referencia */
    do{
        nova = (Referencia *) malloc (sizeof(Referencia));
    }while (nova == NULL);

    /*  Inicializacao das variaveis de controle */
    nova->pag = NULL;
    nova->proximo = NULL;

    return nova;
}

/*  1.4 - Funcao 'cria_pagina', realiza a criacao de uma nova pagina web */
Pagina * cria_pagina (){
    /*  'nova' armazena a nova pagina a ser criada */
    Pagina *nova;
    int ind;

    /*  Alocacao da pagina */
    do{
        nova = (Pagina *) malloc (sizeof(Pagina));
    }while (nova == NULL);

    /*  Inicializacao das variaveis de controle */
    nova->dados.entradas = nova->dados.saidas = 0;
    nova->dados.pr = 1.0;
    for (ind = 0; ind < MAX; ind++) nova->dados.nome[ind] = '\0';
    nova->dados.inicio = NULL;
    nova->anterior = nova->proximo = NULL;

    return nova;
}

/*  1.5 - Funcao 'cria_grafo', realiza a criacao de um novo grafo */
Grafo * cria_grafo (){
    /*  'novo' armazena o novo grafo a ser criada */
    Grafo *novo;
    int ind;

    /*  Alocacao do grafo */
    do{
        novo = (Grafo *) malloc (sizeof(Grafo));
    }while (novo == NULL);

    /*  Inicializacao das variaveis de controle */
    novo->quant = 0;
    for (ind = 0; ind < (2 * MAX2); ind++) novo->dirbase[ind] = '\0';
    novo->inicio = novo->fim = NULL;

    return novo;
}



/*  2 - Secao de Liberacao */
/*  2.1 - Funcao 'libera_letra', desaloca o espaco reservado para uma letra */
void libera_letra (Letra *letra){
    /*  'letra' armazena a letra a ser liberada */
    free (letra);
}

/*  2.2 - Funcao 'libera_palavra', desaloca o espaco para todas as letras de uma palavra
**  assim como ela em si */
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

/*  2.3 - Funcao 'libera_referencia', desaloca o espaco reservado para uma referencia */
void libera_referencia (Referencia *ref){
    /* 'ref' armazena a referencia a ser liberada */
    free (ref);
}

/*  2.4 - Funcao 'libera_pagina', desaloca o espaco reservado para uma pagina */
void libera_pagina (Pagina *page){
    /*  'page' armazena a pagina a ser liberada */

    /*  Tendo lista de referencia */
    if (page->dados.inicio != NULL){
        /*  'aux' auxilia a percorrer a lista de referencias */
        Referencia *aux;

        /*  Enquanto houver lista */
        while (page->dados.inicio != NULL){
            aux = page->dados.inicio;
            page->dados.inicio = aux->proximo;
            libera_referencia (aux);
        }
    }

    free (page);
}

/*  2.5 - Funcao 'libera_grafo', desaloca o espaco reservado para o grafo */
void libera_grafo (Grafo *grafo){
    /*  'grafo' armazena o grafo a ser liberado */

    /*  Tendo lista de paginas web */
    if (grafo->inicio != NULL){
        /*  'aux' auxilia a percorrer a lista de paginas web */
        Pagina *aux;

        /*  Enquanto houver lista */
        while (grafo->inicio != NULL){
            aux = grafo->inicio;
            grafo->inicio = aux->proximo;
            libera_pagina (aux);
        }
    }
    free (grafo);
}



/*  3 - Secao de Construcao e Organizacao */
/*  3.1 - Funcao 'constroi_palavra', realiza a construcao de uma palavra */
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

/*  3.2 - Funcao 'inicializa_grafo', realiza a inicializacao do Grafo em si, atraves
**  da construcao dos nos */
void inicializa_grafo (Grafo *grafo, char *pag){
    /*  'grafo' armazena o grafo a ser construido; 'pag' armazena o nome da pagina
    **  lida */

    /*  Nao existindo grafo */
    if (grafo == NULL) return;


	//pausa ();

    /*  Tendo Palavra significativa */
    if (strlen(pag) > 2){

        /*  Nao existindo paginas */
        if (grafo->inicio == NULL){
            /*  'novo' armazena a nova pagina a ser adicionada ao grafo */
            Pagina *novo = cria_pagina ();

            /*  Configuracao da pagina */
            strcpy (novo->dados.nome, pag);
			//printf ("gravou isso: %s\n", pag);

            /*  Configurando o grafo */
            grafo->inicio = novo;
            grafo->fim = novo;
            grafo->quant++;


        /*  Existindo */
        }else{
            /*  'aux' auxilia a percorrer o grafo */
            Pagina *aux = grafo->inicio;

            /*  Enquanto houver lista ou nao haver a pagina */
            while ((aux->proximo != NULL) && (strcmp (aux->dados.nome, pag) != 0))
                aux = aux->proximo;

            /*  Nao existindo previamente no grafo */
            if ((aux->proximo == NULL) && (strcmp (aux->dados.nome, pag) != 0)){
                /*  'novo' armazena a nova pagina a ser adicionada ao grafo */
                Pagina *novo = cria_pagina ();
                /*  Configuracao da pagina */
                strcpy (novo->dados.nome, pag);
				//printf ("gravou isso: %s\n", pag);

                if (strlen(novo->dados.nome) > strlen(pag)){
                    zera_string (novo->dados.nome, strlen(pag), MAX);
                }

                /*  Configurando o grafo */
                novo->anterior = aux;
                aux->proximo = novo;
                grafo->fim = novo;
                grafo->quant++;
            }
        }
    }
}

/*  3.3 - Funcao 'constroi_adjacencia', realiza a construcao da lista de adjacencias */
void constroi_adjacencia (Grafo *grafo, Pagina *page, char *valido, int codigo){
    /*  'grafo' armazena o grafo a ser manipulado; 'page' armazena a pagina dona do codigo-fonte;
    **  'valido' armazena uma leitura valida a ser minerada; 'codigo' armazena o codigo para a
    **  a validacao de 'valido' na mineracao; 'procura' armazena o nome da pagina a ser validada;
    **  'ind' e 'ind1' armazenam indices a serem manipulados; 'dirteste' armazena o diretorio de
    **  teste do arquivo a ser adicionado ou nao na lista de referencia; 'arqteste' armazena a
    **  condicao de abertura do arquivo */
    char dirteste[2 * MAX2], procura[MAX];
    FILE *arqteste = NULL;

    /*  Limpezas das strings e Pre-montagem do 'dirteste' */
    zera_string (procura, 0, MAX);
    zera_string (dirteste, 0, 2 * MAX2);
    strcpy(dirteste, grafo->dirbase);


    /*  Caso o ultimo caracter de 'valido' seja '"', entao sera convertido num ponto
    **  delimitador do tamanho de 'valido' */
    if (valido[strlen(valido) - 1] == 34)   valido[strlen(valido) - 1] = '\0';

    /*  Sendo validado por "href=" ou "HREF=" */
    if (codigo < 2){

        /*  Sendo um diretorio derivado direto do inicial, 6º caracter '/' */
        if (valido[6] == 47){
            /*  'chave' armazena o inicio comum as paginas
            **  que entram nesse trecho */
            char chave[] = "http://www.cs.sunysb.edu";

            /*  Configuracao da pagina a ser procurada */
            memcpy (procura, chave, strlen(chave));
            concat_string (procura, valido, 6, strlen(valido));

            /*  Montagem do diretorio de teste para o arquivo, validacao final */
            concat_string (dirteste, procura, strlen(chave), strlen(procura));
        }

        /*  Sendo a descrico completa da pagina web, ou seja, com 'http:/' */
        else if (compara_string_n(valido, "http:/", 6, 0, strlen("http:/")) == 0){
            /*  Configuracao da pagina a ser procurada */
            concat_string (procura, valido, 6, strlen(valido));

            /*  Montagem do diretorio de teste para o arquivo, validacao final */
            concat_string (dirteste, valido, 30, strlen(valido));
        }

        /*  Tendo apenas o nome, repoe o ultimo caminho */
        else if ((valido[6] >= 65 && valido[6] <= 90)
                 || (valido[6] >= 97 && valido[6] <= 122)){
            int posicao = n_ultima_ocorrencia (page->dados.nome, 47, 1);

            /*  Configuracao da pagina a ser procurada */
            concat_string (procura, page->dados.nome, 0, posicao + 1);
            concat_string (procura, valido, 6, strlen(valido));

            /*  Montagem do diretorio de teste para o arquivo, validacao final */
            concat_string (dirteste, procura, 24, strlen(procura));
        }

        /*  Tendo '../' ou '../../', volta dois caminhos */
        else if ((compara_string_n(valido, "../", 6, 0, strlen("../")) == 0)
                 || (compara_string_n(valido, "../../", 6, 0, strlen("../../")) == 0)){
            int quant = 0, posicao = -1;

            if (compara_string_n(valido, "../", 6, 0, strlen("../")) == 0)  quant = 2;
            if (compara_string_n(valido, "../../", 6, 0, strlen("../../")) == 0)  quant = 3;

            posicao = n_ultima_ocorrencia (page->dados.nome, 47, quant);

            /*  Configuracao da pagina a ser procurada */
            concat_string (procura, page->dados.nome, 0, posicao + 1);
            if (quant == 2) concat_string (procura, valido, 9, strlen(valido));
            if (quant == 3) concat_string (procura, valido, 12, strlen(valido));

        }

    /*  Sendo validado por "http:/" */
    }
    else{
        /*  Configuracao da pagina a ser procurada */
        concat_string (procura, valido, 0, strlen(valido));

        /*  Montagem do diretorio de teste para o arquivo, validacao final */
        concat_string (dirteste, valido, 24, strlen(valido));
    }

    /*  Validacao final */
    arqteste = abre_arquivo (dirteste, 'r', 'e');
    if (arqteste != NULL){
        /*  'aux' auxilia na manipulacao */
        Pagina *aux;

        /*  Caso o primeiro caracter intriseco da pagina seja alterior a 'g',
        **  comecar a pesquisa pelo inicio */
        if (procura[25] > 103){
            aux = grafo->inicio;

            while (aux != NULL){
                if (strcmp(aux->dados.nome, procura) == 0)
                    break;
                aux = aux->proximo;
            }

        /*  Caso o primeiro caracter intriseco da pagina seja posterior a 'g',
        **  comecar a pesquisa pelo fim */
        }
        else{
            aux = grafo->fim;

            while (aux != NULL){
                if (strcmp(aux->dados.nome, procura) == 0)
                    break;
                aux = aux->anterior;
            }
        }

        /*  Encontrando uma pagina valida */
        if (aux != NULL && (strcmp(aux->dados.nome, procura) == 0)){
            constroi_referencia (aux, page);
        }

        fclose (arqteste);
    }


}

/*  3.4 - Funcao 'constroi_referencia', realiza a construcao da lista de referencias */
void constroi_referencia (Pagina *referenciada, Pagina *origem){
    /*  'referenciada' armazena a pagina que eh citada pela 'origem'; 'origem' armazena
    **  a pagina que cita a 'referenciada' */

    /*  Nao havendo 'referenciada' */
    if (referenciada == NULL) return;

    /*  Sendo a primeira insercao */
    if (referenciada->dados.inicio == NULL){
        /*  'nova' armazena a nova referencia a ser adicionada a 'referenciada' */
        Referencia *nova = cria_referencia ();

        /* Configuracao de 'nova' */
        nova->pag = origem;

        /*  Montagem da lista de referencias e configuracao de 'referenciada' e 'origem' */
        referenciada->dados.inicio = nova;
        referenciada->dados.entradas++;
        origem->dados.saidas++;

        return;
    }

    /*  'aux' auxilia a percorrer a lista de referencias para 'referenciada' */
    Referencia *aux = referenciada->dados.inicio;

    /*  Enquanto houver lista valida, verificando se a 'origem' jah nao existe na lista de
    **  referencias */
    while (aux->proximo != NULL && (strcmp (aux->pag->dados.nome, origem->dados.nome) != 0))
        aux = aux->proximo;

    /*  Sendo uma referencia valida */
    if (aux->proximo == NULL && (strcmp (aux->pag->dados.nome, origem->dados.nome) != 0)){
        /*  'nova' armazena a nova referencia a ser adicionada a 'referenciada' */
        Referencia *nova = cria_referencia ();

        /* Configuracao de 'nova' */
        nova->pag = origem;

        /*  Montagem da lista de referencias e configuracao de 'referenciada' e 'origem' */
        aux->proximo = nova;
        referenciada->dados.entradas++;
        origem->dados.saidas++;

        return;
    }
}

/*  3.5 - Ordenacao do Grafo */
void ordena_grafo (Grafo *grafo){
    Pagina *aux = grafo->inicio, *aux1 = aux->proximo;
    char troca = 'n';

    while (aux1 != NULL){
        if ((aux->dados.pr < aux1->dados.pr)
            || ((aux->dados.pr == aux1->dados.pr)
                && (aux->dados.entradas > aux1->dados.entradas))){
            Pagina *aux2 = aux->anterior, *aux3 = aux1->proximo;

            if (aux2 != NULL)   aux2->proximo = aux1;
            else    grafo->inicio = aux1;

            if (aux3 != NULL)   aux3->anterior = aux;
            else    grafo->fim = aux;

            aux1->anterior = aux2;
            aux->proximo = aux3;

            aux1->proximo = aux;
            aux->anterior = aux1;

            troca = 's';
        }

        aux = aux->proximo;
        aux1 = aux->proximo;
    }

    if (troca != 'n') ordena_grafo (grafo);
}



/*  4 - Secao de Remocoes */
/*  4.1 - Funcao 'remove_letra', realiza a remocao da primeira letra da
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



/*  5 - Secao de Exibicao na Tela e Escrita em Documentos */
/*  5.1 - Funcao 'exibe_referencias', exibe na tela uma Referencia */
void exibe_referencias (Referencia *ref){
    /*  'ref' armazena lista de referencias a ser exibida; 'aux' auxilia a percorrer
    **  a lista */
    Referencia *aux = ref;

    /*  Enquanto houver lista */
    while (aux != NULL){
        printf ("'%s'", aux->pag->dados.nome);

        if (aux->proximo != NULL)
            printf (", ");
        else
            printf (";\n\n");

        aux = aux->proximo;
    }
}

/*  5.2 - Funcao 'exibe_pagina', exibe na tela uma Pagina */
void exibe_pagina (Pagina *pag){
    /*  'pag' armazena a pagina a ser exibida */

    /*  Havendo pagina */
    if (pag != NULL){
        printf ("A pagina\n'%s', tem:", pag->dados.nome);
        printf ("\n\tPageRank: %.6f;", pag->dados.pr);
        printf ("\n\tNº Saidas: %d;", pag->dados.saidas);
        printf ("\n\tNº Entradas: %d", pag->dados.entradas);
            if (pag->dados.entradas > 0){
                printf (", sendo ela(s):\n");
                exibe_referencias (pag->dados.inicio);

            }else printf (";\n");

        printf ("\n\n");
    }
}

/*  5.3 - Funcao 'exibe_top10', exibe na tela o top 10 */
void exibe_top10 (Grafo *grafo){
    /*  'grafo' armazena o grafo
    **  a ser escrito em 'arq'; 'quant' armazena a quantidade a ser manipulada no TOP10; 'aux'
    **  auxilia a percorrer as paginas */
    int quant;
    Pagina *aux = grafo->inicio;

    printf ("O TOP10, no PageRank, sao esses:\n");

    for (quant = 0; quant < 10; quant++, aux = aux->proximo){
        printf ("%dº Pagina, com PR = %.6f:\n", quant + 1, aux->dados.pr);
        printf ("%s\n\n", aux->dados.nome);

    }

    return;
}

/*  5.4 - Funcao 'exibe_grafo', exibe na tela o Grafo Completo */
void exibe_grafo (Grafo *grafo){
    /*  'grafo' armazena o grafo a ser exibido */

    /*  Havendo nos */
    printf ("Imprimir Grafo\n");
    if (grafo->inicio != NULL){
        /*  'aux' auxilia a percorrer a lista dos nos */
        Pagina *aux = grafo->inicio;
        int contador = 1;

    //    limpa_tela ();

        /*  Enquanto houver nos */
        while (aux != NULL){

            printf ("%dº de %d Paginas\n", contador,  grafo->quant);
            exibe_pagina (aux);
            aux = aux->proximo;
            contador++;
            //temporizador (0.2);
        }
    }
}

/*  5.5 - Funao 'escreve_referencias', escreve num arquivo uma Referencia */
void escreve_referencias (FILE *arq, Referencia *ref){
    /*  'ref' armazena lista de referencias a ser exibida; 'aux' auxilia a percorrer
    **  a lista */
    Referencia *aux = ref;

    /*  Enquanto houver lista */
    while (aux != NULL){
        fprintf (arq, "'%s'", aux->pag->dados.nome);

        if (aux->proximo != NULL)
            fprintf (arq, ", ");
        else
            fprintf (arq, ";\n\n");

        aux = aux->proximo;
    }
    return;
}

/*  5.6 - Funcao 'escreve_pagina', escreve num arquivo uma Pagina */
void escreve_pagina (FILE *arq, Pagina *pag){
    /*  'arq' armazena o arquivo em que sera armazenada as informacoes; 'pag' armazena a pagina
    **  a ser escrita em 'arq' */

    /*  Escrita das informacoes, havendo pagina */
    if (pag != NULL){
        fprintf (arq, "Pagina\n'%s', tem:", pag->dados.nome);
        fprintf (arq, "\n\tPageRank: %.6f;", pag->dados.pr);
        fprintf (arq, "\n\tNº Saidas: %d;", pag->dados.saidas);
        fprintf (arq, "\n\tNº Entradas: %d", pag->dados.entradas);
            if (pag->dados.entradas > 0){
                fprintf (arq, ", sendo ela(s):\n");
                escreve_referencias (arq, pag->dados.inicio);

            }else fprintf (arq, ";\n");

        fprintf (arq, "\n\n");
    }
    return;
}

/*  5.7 - Funcao 'escreve_top10', escreve num arquivo o top 10 */
void escreve_top10 (FILE *arq, Grafo *grafo){
    /*  'arq' armazena o arquivo em que sera armazenada as informacoes; 'grafo' armazena o grafo
    **  a ser escrito em 'arq'; 'quant' armazena a quantidade a ser manipulada no TOP10; 'aux'
    **  auxilia a percorrer as paginas */
    int quant;
    Pagina *aux = grafo->inicio;

    fprintf (arq, "O TOP10, no PageRank, sao esses:\n");

    for (quant = 0; quant < 10; quant++, aux = aux->proximo){
        fprintf (arq, "%dº Pagina, com PR = %.6f:\n", quant + 1, aux->dados.pr);
        fprintf (arq, "%s\n\n", aux->dados.nome);

    }
    return;
}

/*  5.8 - Funcao 'escreve_grafo', escreve num arquivo o Grafo Completo */
void escreve_grafo (Grafo *grafo){
    /*  'grafo' armazena o grafo a ser escrito num documento; 'nomearq' armazena o nome
    **  do arquivo ao qual o grafo sera gravado; 'quant' armazena a quantidade a ser
    **  manipulada durante a escrita; 'aux' auxiliar a percorrer as paginas na escrita;
    **  'arq' armazena o arquivo a ser escrito as informacoes */
    char *nomearq = NULL;
    int quant = 1, ind;
    Pagina *aux;
    FILE *arq = NULL;

    /*  Leitura dinaminca do documento para escrita e configuraca de 'arq' */
    nomearq = ler_nome_doc();
    arq = abre_arquivo (nomearq, 'w', 'l');

    /*  Inicio do arquivo, com o TOP10 */
    fprintf (arq, "Foram analisadas %d paginas web\n\n", grafo->quant);
    escreve_top10 (arq, grafo);

    /*  Escrita do grafo, em si */
    fprintf (arq, "\nContinuando, segue todas as paginas e seus respectivos dados...\n\n");

    for (aux = grafo->inicio; aux != grafo->fim->proximo; aux = aux->proximo){
        fprintf (arq, "%dº ", quant);
        escreve_pagina (arq, aux);
        quant++;
    }

    free (arq);
    return;
}
