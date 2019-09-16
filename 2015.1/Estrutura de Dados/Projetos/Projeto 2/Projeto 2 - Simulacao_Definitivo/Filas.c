/*  Descritivo das funcoes para manipulacao sobre as TADs */

/*  Biblioteca dinamica requisitada para este arquivo */
#include "Eventos.h"

/*  Lista de funcoes para manipulacao sobre as TADs: */

/*  1 - Funcao cria_aviao, aloca espaco para um novo voo a ser inserido na devida fila
**  e inicializa suas variaveis de controle */
Aviao * cria_aviao (){
    /*  'novo' armazera o espaco alocado para um novo voo a ser inserido na devida
    **  fila */
    Aviao *novo = (Aviao *) malloc (sizeof(Aviao));

    /* Teste de alocacao */
    if (novo == NULL){
        printf ("ERRO NA ALOCACAO DO ELEMENTO AVIAO\n");
        exit (-1);
    }

    /* Inicializacao das variaveis de controle */
    zera_string (novo->nome, TAMp);
    novo->status = '\0';
    novo->comb = 0;
    novo->proximo = NULL;

    return novo;
}

/*  2 - Funcao cria_aprox, aloca espaco para o cabecalho do que venha a ser a fila de
**  Aproximacoes e inicializa suas variaveis de controle */
 Aproximacao * cria_aprox (){
    /*  'novo' armazena o espaco alocado para o cabecalho da fila Aproximacao */
    Aproximacao *novo = (Aproximacao *) malloc (sizeof(Aproximacao));

    /*  Teste de alocacao */
    if (novo == NULL){
        printf ("ERRO NA ALOCACAO DO ELEMENTO APROXIMACAO\n");
        exit (-2);
    }

    /*  Inicializacao das variaveis de controle */
    novo->quant = 0;
    novo->inicio = novo->fim = NULL;

    return novo;
 }

/*  3 - Funcao cria_deco, aloca espaco para o cabecalho do que venha a ser a fila de
**  Decolagens e inicializa suas variaveis de controle */
Decolagem * cria_deco (){
    /*  'novo' armazena o espaco alocado para o cabecalho da fila Decolagem */
    Decolagem *novo = (Decolagem *) malloc (sizeof(Decolagem));

    /*  Teste de alocacao */
    if (novo == NULL){
        printf ("ERRO NA ALOCACAO DO ELEMENTO DECOLAGEM\n");
        exit (-3);
    }

    /*  Inicializacao das variaveis de controle */
    novo->quant = 0;
    novo->inicio = novo->fim = NULL;

    return novo;
}

/*  4 - Funcao cria_pista, aloca espaco para as pistas do Aeroporto, que serao manipuladas */
Pista * cria_pista (){
    /*  'novo' armazena o espaco alocado para as pistas do Aeroporto */
    Pista *novo = (Pista *) malloc (TAMs * sizeof(Pista));

    /*  Teste de alocacao */
    if (novo == NULL){
        printf ("ERRO ALOCACAO DE PISTAS!\n");
        exit (-4);
    }

    return novo;
}

/*  5 - Funcao cria_aero, aloca espaco para o Aeroporto e inicializa suas variaveis de controle */
Aeroporto * cria_aero (){
    /*  'novo' armazena o espaco alocado para o elemento Aeroporto */
    Aeroporto *novo = (Aeroporto *) malloc (sizeof(Aeroporto));

    /*  Teste de alocacao */
    if (novo == NULL){
        printf ("ERRO NA ALOCACAO DO ELEMENTO AEROPORTO\n");
        exit (-5);
    }

    /*  Inicializacao das variaveis de controle */
    novo->voos = novo->req = 0;
    novo->percente = 0.0;
    novo->ciclo = 0;
    novo->atual = hora_atual ();
    novo->filaap = NULL;
    novo->filade = NULL;
    novo->pista = cria_pista();

    return novo;
}

/*  6 - Funcao libera_aviao, desaloca o espaco alocado para o Aviao individualmente */
void libera_aviao (Aviao *voo){
    /*  'voo' armazena o elemento aviao a ser liberado */
    free (voo);
}

/*  7 - Funcao libera_aprox, desaloca o espaco alocado para a fila Aproximacao */
void libera_aprox (Aproximacao *aprox){
    /*  'aprox' armazena a fila Aproximacao a ser liberada */
    free (aprox);
}

/*  8 - Funcao libera_deco, desaloca o espaco alocado para a fila Decolagem */
void libera_deco (Decolagem *deco){
    /*  'deco' armazena a fila Decolagem a ser liberada */
    free (deco);
}

/*  9 - Funcao libera_pista, desaloca o espaco alocado para as pistas do Aeroporto */
void libera_pista (Pista *pista){
    /*  'pista' armazena as pistas do Aeroporto a serem liberadas */
    free (pista);
}

/*  10 - Funcao libera_aero, desaloca o espaco alocado para o Aeroporto */
void libera_aero (Aeroporto *aero){
    /*  'aero' armazena o Aeroporto a ser liberadi; 'ind' armazena indices a
    **  serem manipulados */
    int ind;

    /*  Havendo Aproximacao ao final da simulacao */
    if (aero->filaap != NULL && aero->filaap->quant != 0){
        /*  Havendo voos na fila, estes serao liberados */
        for (ind = aero->filaap->quant; ind > 0; ind--)
            libera_aviao (retira_aprox(aero->filaap));

        /*  Liberacao da Aproximacao em si */
        libera_aprox (aero->filaap);
    }

    /*  Havendo Decolagem ao final da simulacao*/
    if (aero->filade != NULL && aero->filade->quant != 0){
        /*  Havendo voos na fila, estes serao liberados */
        for (ind = aero->filade->quant; ind > 0; ind--)
            libera_aviao (retira_deco (aero->filade));

        /*  Liberacao da Decolagem em si*/
        libera_deco (aero->filade);
    }

    /*  Liberacao das Pistas */
    libera_pista (aero->pista);

    /*  Liberacao do Aeroporto */
    free (aero);
}

/*  11 - Funcao inicia_pista, inicializa a pista para uso posterior */
void inicia_pista (Aeroporto *aero, Pista *pista){
    /*  'pista' armazena a pista a ser liberada */

    /*  Inicializacao das Variaveis de Controle */
    pista->status = 'L';
    if (pista->voo != NULL){
        /*  Estando ocupada para decolagem, o Aeroporto nao se responsabiliza
        **  totalmente pelo voo */
        if (pista->voo->status == 'D')
            libera_aviao (pista->voo);

        /*  Estando ocupada para pouso, o voo e inserido na fila Decolagem */
        else if (pista->voo->status == 'P')
            insere_deco (aero->filade, pista->voo);
    }
    pista->voo = NULL;
}

/*  12 - Funcao inicia_aero, inicializa o trabalho do Aeroporto para a proxima hora de
**  simulacao */
void inicia_aero (Aeroporto *aero, int req){
    /*  'aero' armazena o Aeroporto; 'req' armazena o numero de voos requeridos;
    **  'ind' armazena indice a ser manipulado */
    int ind;

    /*  Criacao das filas de aproximacao e decolagem */
    /*  Nao havendo filas, as mesmas sao criadas, pois pode ser uma continuacao da simulacao */
    if (aero->filaap == NULL)   aero->filaap = cria_aprox();
    if (aero->filade == NULL)   aero->filade = cria_deco();

    /*  Inicializacao das pistas individualmente */
    for (ind = 0; ind < TAMs; ind++)
        inicia_pista (aero, aero->pista + ind);

    /*  Configuracao da porcentagem e requeridos */
    aero->req = req;
    if (req > 0)    aero->percente = (float) req/aero->voos;
}

/*  13 - Funcao add_aprox, insere um novo voo na fila Aproximacao */
void add_aprox (Aproximacao *aprox, char *nome){
    /*  'aprox' armazena a fila Aproximacao a ser manipulada; 'nome' armazena a identificacao
    **  do voo a ser inserido na fila Aproximacao; 'novo' armazena o espaco alocado para o novo
    **  voo a ser inserido na fila Aproximacao */
    Aviao *novo = cria_aviao();

    /* Configuracao da variaveis do novo elemento a ser inserido */
    *(nome+strlen(nome)) = '\0';
    strcpy (novo->nome, nome);
    novo->comb = gera_aleatorio (2, 13);
    novo->status = 'A';

    /* Configuracao para armacao da fila */
    /* Estando vazia */
    if (aprox->quant == 0){
        aprox->fim = novo;
        aprox->inicio = novo;
    }

    /* Nao estando vazia */
    else {
        aprox->fim->proximo = novo;
        aprox->fim = novo;
    }

    aprox->quant++;
}

/*  14 - Funcao add_deco, insere um novo voo na fila Decolagem */
void add_deco (Decolagem *deco, char *nome){
    /*  'deco' armazena a fila Decolagem a ser manipulada; 'nome' armazena a identificacao
    **  do voo a ser inserido na fila Decolagem; 'novo' armazena o espaco alocado para o novo
    **  voo a ser inserido na fila Decolagem */
    Aviao *novo = cria_aviao ();

    /* Configuracao das variaveis do novo elemento a ser inserido */
    *(nome+strlen(nome)) = '\0';
    strcpy (novo->nome, nome);
    novo->comb = 13;
    novo->status = 'D';

    /* Configuracao  para armacao da fila */
    /* Estando vazia */
    if (deco->quant == 0){
        deco->fim = novo;
        deco->inicio = novo;
    }

    /* Nao estando vazia */
    else {
        deco->fim->proximo = novo;
        deco->fim = novo;
    }

    deco->quant++;
}

/*  15 - Funcao insere_deco, insere um voo existente na fila Decolagem */
void insere_deco (Decolagem *deco, Aviao *voo){
    /*  'deco' armazena a fila Decolagem a ser manipulada; 'voo' armazena o voo a ser inserido
    **  na fila */

    /*  Configuracao do voo para fila Decolagem */
    voo->comb = 13;
    voo->status = 'D';

    /*  Configuracao  para armacao da fila */
    /*  Estando vazia */
    if (deco->quant == 0){
        deco->fim = voo;
        deco->inicio = voo;
    }
    /*  Nao estando vazia */
    else {
        deco->fim->proximo = voo;
        deco->fim = voo;
    }

    deco->quant++;
}

/*  16 - Funcao ordena_aprox, ordena a fila Aproximacao, tendo como prioridade o nivel
**  de combustivel */
void ordena_aprox (Aproximacao *aprox){
    /*  'aprox' armazena a fila Aproximacao a ser ordenada; 'auxiliar' e 'auxiliar2' armazenam
    **  voos da fila Aproximacao a serem manipulados na ordenação; 'troca' armazena o status
    **  das trocas */
    Aviao *auxiliar, *auxiliar2;
    int troca = 0;

    /*  Havendo fila a ser ordenada */
    if (aprox != NULL && aprox->quant > 0){
        /*  Configuracao dos auxiliares */
        auxiliar = aprox->inicio;
        auxiliar2 = auxiliar->proximo;

        /*  Enquanto houver lista para percorrer */
        while (auxiliar2 != NULL){
            if (auxiliar->comb > auxiliar2->comb){
                /*  'temp' armazena as informacoes da posicao corrente, fazendo backup das
                **  informacoes */
                Aviao *temp = cria_aviao ();
                temp->comb = auxiliar->comb;
                strcpy (temp->nome, auxiliar->nome);

                /*  Realizando a troca de informacoes */
                auxiliar->comb = auxiliar2->comb;
                strcpy (auxiliar->nome, auxiliar2->nome);

                /*  Copiar do backup para o posterior */
                auxiliar2->comb = temp->comb;
                strcpy (auxiliar2->nome, temp->nome);

                /*  Guardar a realização da troca */
                troca = 1;
            }

            /*  Atribuicoes para percorrer a lista */
            auxiliar = auxiliar->proximo;
            auxiliar2 = auxiliar->proximo;
        }
    }

    /*  Havendo troca, chama a função de novo, até que não haja mais troca de informações */
    if (troca == 1) ordena_aprox (aprox);
}

/*  17 - Funcao retira_aprox, retira o primeiro elemento da fila Aproximacao para manuseio
**  na simulacao */
Aviao * retira_aprox (Aproximacao *aprox){
    /*  'aprox' armazena a fila Aproximacao a ser manipulada; 'auxiliar' armazena o elemento
    **  retirado da fila */
    Aviao *auxiliar;

    /*  Teste de fila vazia */
    if (aprox->quant == 0){
        printf ("FILA DE APROXIMACOES VAZIA\n");
        return NULL;
    }

    /*  Remocao do elemento da fila e Configuracao para sustentacao da fila */
    auxiliar = aprox->inicio;
    aprox->inicio = aprox->inicio->proximo;
    aprox->quant--;

    return auxiliar;
}

/*  18 - Funcao retira_deco, retira o primeiro elemento da fila Decolagem para manuseio
**  na simulacao */
Aviao * retira_deco (Decolagem *deco){
    /*  'deco' armazena a fila Decolagems a ser manipulada; 'auxiliar' armazena o elemento
    **  retirado da fila */
    Aviao *auxiliar;

    /*  Teste de fila vazia */
    if (deco->quant == 0){
        printf ("FILA DE DECOLAGEM VAZIA\n");
        return NULL;
    }

    /*  Remocao do elemento da fila e Configuracao para sustentacao da fila */
    auxiliar = deco->inicio;
    deco->inicio = deco->inicio->proximo;
    deco->quant--;

    return auxiliar;
}

/*  19 - Funcao imprime_voo, exibe na tela o voo desejado */
void imprime_voo (Aviao *voo){
    /*  'voo' armazena o voo a ser exibido na tela; 'ind' armazena o indice da string
    **  a ser manipulada */
    int ind;

    printf ("\tIdentificacao do Voo = ");
    for (ind = 0; ind < TAMp; ind++) printf ("%c", voo->nome[ind]);
    printf ("\n\tStatus do Voo = %c\n", voo->status);
    printf ("\tCombustivel do Voo = %d\n\n", voo->comb);
}

/*  20 - Funcao imprime_voo_arq, escreve o voo desejado num arquivo */
void imprime_voo_arq (FILE *arq, Aviao *voo){
    /*  'voo' armazena o voo a ser escrito no arquivo; 'arq' armazena o arquivo a
    **  escrito; 'ind' armazena o indice da identificacao a ser manipulada */
    int ind;

    fprintf (arq, "\tIdentificacao do Voo = ");
    for (ind = 0; ind < TAMp; ind++) fprintf (arq, "%c", voo->nome[ind]);
    fprintf (arq, "\n\tStatus do Voo = %c\n", voo->status);
    fprintf (arq, "\tCombustivel do Voo = %d\n\n", voo->comb);
}

/*  21 - Funcao imprime_aprox, exibe na tela a fila de Aproximacoes */
void imprime_aprox (Aproximacao *aprox){
    /*  'aprox' armazena a fila Aproximacao a ser exibida; 'auxiliar' armazena o elemento
    **  corrente, e percorre toda a fila, sem modifica-la; 'num' armazena a ordem na fila;
    **  'ind' armazena o indice do voo na fila */
    Aviao *auxiliar;
    int num = 1, ind;

    printf ("\nFila de Aproximacao\n");

    /*  Havendo fila de Aproximacao */
    if (aprox != NULL && aprox->quant > 0){
        auxiliar = aprox->inicio;

        /*  Percorrer toda a fila */
        for (ind = aprox->quant; ind > 0; ind--){
            printf ("Voo %d\n", num);
            imprime_voo (auxiliar);
            num++;
            auxiliar = auxiliar->proximo;
        }
    }

    /*  Nao havendo */
    else if (aprox == NULL || aprox->quant == 0)
        printf ("\tSem Voos\n");

    printf ("\n");
}

/*  22 - Funcao imprime_aprox_arq, escreve a fila Aproximacao num arquivo */
void imprime_aprox_arq (FILE *arq, Aproximacao *aprox){
    /*  'aprox' armazena a fila Aproximacao a escrita no arquivo; 'arq' armazena o arquivo a
    **  escrito; 'auxiliar' armazena o elemento corrente, e percorre toda a fila, sem modifica-la;
    **  'num' armazena a ordem na fila; 'ind' armazena o indice do voo na fila */
    Aviao *auxiliar;
    int num = 1, ind;

    fprintf (arq, "\nFila de Aproximacao\n");

    /*  Havendo fila de Aproximacao */
    if (aprox != NULL && aprox->quant > 0){
        auxiliar = aprox->inicio;

        /*  Percorrer toda a fila */
        for (ind = aprox->quant; ind > 0; ind--){
            fprintf (arq, "Voo %d\n", num);
            imprime_voo_arq (arq, auxiliar);
            num++;
            auxiliar = auxiliar->proximo;
        }
    }

    /*  Nao havendo */
    else if (aprox == NULL || aprox->quant == 0)
        fprintf (arq, "\tSem Voos\n");

    fprintf (arq, "\n");
}

/*  23 - Funcao imprime_deco, exibe na tela a fila de Decolagens */
void imprime_deco (Decolagem *deco){
    /*  'deco' armazena a fila Decolagem a ser exibida; 'auxiliar' armazena o elemento
    **  corrente, e percorre toda a fila, sem modifica-la; 'num' armazena a ordem na fila;
    **  'ind' armazena o indice do voo na fila */
    Aviao *auxiliar;
    int num = 1, ind;

    printf ("\nFila de Decolagem\n");

    /*  Havendo fila de Decolagem */
    if (deco != NULL && deco->quant > 0){
        auxiliar = deco->inicio;

        /*  Percorrer toda a fila */
        for (ind = deco->quant; ind > 0; ind--){
            printf ("Voo %d\n", num);
            imprime_voo (auxiliar);
            num++;
            auxiliar = auxiliar->proximo;
        }
    }

    /*  Nao havendo */
    else if (deco == NULL || deco->quant == 0)
        printf ("\tSem Voos\n");

    printf ("\n");
}

/*  24 - Funcao imprime_decp_arq, escreve a fila Decolagem num arquivo */
void imprime_deco_arq (FILE *arq, Decolagem *deco){
    /*  'deco' armazena a fila Decolagem a ser escrita no arquivo; 'arq' armazena o arquivo a
    **  escrito; 'auxiliar' armazena o elemento corrente, e percorre toda a fila, sem modifica-la;
    **  'num' armazena a ordem da fila; 'ind' armazena o indice do voo na fila */
    Aviao *auxiliar;
    int num = 1, ind;

    fprintf (arq, "\nFila de Decolagem\n");

    /*  Havendo fila de Decolagem */
    if (deco != NULL && deco->quant > 0){
        auxiliar = deco->inicio;

        /*  Percorrer toda a fila */
        for (ind = deco->quant; ind > 0; ind--){
            fprintf (arq, "Voo %d\n", num);
            imprime_voo_arq (arq, auxiliar);
            num++;
            auxiliar = auxiliar->proximo;
        }
    }

    /*  Nao havendo */
    else if (deco == NULL || deco->quant == 0)
        fprintf (arq, "\tSem Voos\n");

    fprintf (arq, "\n");
}

/*  25 - Funcao imprime_pista, exibe na tela a configuracao da pista em questao */
void imprime_pista (Pista *pista){
    /*  'pista' armazena uma determinada pista a ser exibida */

    /*  Exibicao do Status da pista: Livre ou Ocupada */
    printf ("\tStatus da Pista = %c\n", pista->status);

    /*  Havendo voo na pista */
    if (pista->voo != NULL)
        imprime_voo (pista->voo);

    /*  Nao havendo */
    else
        printf ("\tSem Voos\n");
}

/*  26 - Funcao imprime_pista_arq, escre a Pista em questao num arquivo */
void imprime_pista_arq (FILE *arq, Pista *pista){
    /*  'pista' armazena a pista a ser escrita no arquivo; 'arq' armazena o arquivo a
    **  escrito */

    /*  Escrita do Status da pista: Livre ou Ocupada */
    fprintf (arq, "\tStatus da Pista = %c\n", pista->status);

    /*  Havendo voo na pista */
    if (pista->voo != NULL)
        imprime_voo_arq (arq, pista->voo);

    /*  Nao havendo */
    else
        fprintf (arq, "\tSem Voos\n");
}

/*  27 - Funcao imprime_aero, exibe na tela toda a configuracao do Aeroporto */
void imprime_aero (Aeroporto *aero){
    /*  'aero' armazena o Aeroporto; 'quant' armazena a ordem das pistas a ser exibida */
    int quant;

    /*  Apresentacao do Aeroporto, assim como data e hora de inicio da simulacao
    **  e exibicao das variaveis de controle do Aeroporto, para a proxima hora */
    printf("\n-----------------------------------------------------------\n");
    printf ("Aeroporto Internacional Stairway to Heaven \\m/ \n");
    imprime_hora (aero->atual);
    printf ("Numero de Voos, aconselhado = %.2d\n", aero->voos);
    printf ("Numero de Voos, aproximacoes = %.2d\n", aero->filaap->quant);
    printf ("Numero de Voos, decolagens = %.2d\n", aero->filade->quant);
    if (aero->voos > 0)
        printf ("Porcentagem de lotacao, para proxima hora = %.2f%%\n", aero->percente * 100);

    /*  Exibicao das pistas individualmente */
    printf ("\nFila das Pistas\n");
    for (quant = 0; quant < TAMs; quant++){
        printf ("Pista %d:\n", quant);
        imprime_pista (aero->pista + quant);
    }
    printf ("\n");

    /*  Exibicao da fila Aproximacao */
    imprime_aprox (aero->filaap);

    /*  Exibicao da fila Decolagem */
    imprime_deco (aero->filade);
}

/*  28 - Funcao imprime_aero_arq, escreve num arquivo a configuracao do Aeroporto */
void imprime_aero_arq (FILE *arq, Aeroporto *aero){
    /*  'aero' armazena o Aeroporto; 'arq' armazena o arquivo a escrito; 'quant' armazena
    **  a ordem das pistas a ser exibida */
    int quant;

    /* Apresentacao do Aeroporto, assim como data e hora de inicio da simulacao
    ** e escrita das variaveis de controle do Aeroporto, para a proxima hora */
    fprintf (arq, "Aeroporto Internacional Stairway to Heaven \\m/ \n");
    imprime_hora_arq (arq, aero->atual);
    fprintf (arq, "Numero de Voos, aconselhado = %.2d\n", aero->voos);
    fprintf (arq, "Numero de Voos, aproximacoes = %.2d\n", aero->filaap->quant);
    fprintf (arq, "Numero de Voos, decolagens = %.2d\n", aero->filade->quant);
    if (aero->voos > 0)
        fprintf (arq, "Porcentagem de lotacao, para proxima hora = %.2f%%\n", aero->percente * 100);

    /*  Escrita das pistas individualmente */
    fprintf (arq, "\nFila das Pistas\n");
    for (quant = 0; quant < TAMs; quant++){
        fprintf (arq, "Pista %d:\n", quant);
        imprime_pista_arq (arq, aero->pista + quant);
    }
    fprintf (arq, "\n");

    /*  Escrita da fila Aproximacao */
    imprime_aprox_arq (arq, aero->filaap);

    /*  Escrita da fila Decolagem */
    imprime_deco_arq (arq, aero->filade);
}

/*  29 - Funcao monta_nome, realiza a geracao de uma identificacao para cada voo */
char * monta_nome (){
    /*  'auxiliar' armazena a identificacao gerada; 'ind' armazena o indice da posicao da
    **  string manipulada */
    char *auxiliar = (char *) malloc (TAMp * sizeof(char));
    int ind;

    /*  Teste de alocacao */
    if (auxiliar == NULL){
        printf ("\nERRO ALOCACAO DE STRING\n");
        exit (-6);
    }

    /*  Inicializacao das Variaveis de Controle */
    ind = 0;
    zera_string (auxiliar, TAMp);

    /*  Montagem da identificacao do Voo */
    for (ind = 0; ind < TAMp; ind++){
        if(ind < 2)
            /*  Somente Letra Maiuscula */
            auxiliar[ind] = gera_aleatorio (65, 90);
        else
            /*  Somente Numero */
            auxiliar[ind] = gera_aleatorio (48, 57);
    }

    /*  Garantia de final da string */
    auxiliar[ind] = '\0';

    return auxiliar;
}
