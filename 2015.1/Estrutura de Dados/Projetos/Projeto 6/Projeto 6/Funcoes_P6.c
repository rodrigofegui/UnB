/*  Descritivo das funções para andamento do Projeto */

/*  Bibliotecas requisitada */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes_P6.h"


/*  Lista das funcoes de manipulacao */

/*  Funcao 'hello', da as boas vindas */
void hello (){
	limpa_tela ();

	printf ("Hello World!\n");
    temporizador (1.5);

    printf ("Bem-vindo!\n");
    pausa();
}

/*  Funcao 'inicio_geral', realiza a apresentacao do projeto e questiona sobre
**  o inicio ou nao do mesmo */
char inicio_geral (){
    limpa_tela ();

    /*  Apresentacao das caracteristicas do projeto */
    printf ("Bem-vindo ao Roteiro de Viagem!\n");
    printf ("\nO(s) roteiro(s) a ser(em) criado(s) por este projeto visam:");
    printf ("\n\t1. Disponibilizar a melhor rota para visitar todas as cidades desejadas\n");
        printf ("a partir de uma cidades especifica;");
    printf ("\n\t2. O(s) roteiro(s) criado(s) sera(ao) disponibilizados na tela, assim\n");
        printf ("como sera(ao) registrados num arquivo resultado;");


    /*  Questionamento sobre inicio do projeto */
     printf ("\n\nDadas as caracteristicas do projeto, deseja inicia-lo? S/N ou s/n\n");
        return ler_simounao ();
}

/*  Função abre_arquivo, realiza a abertura e teste de alocacao de um arquivo */
FILE * abre_arquivo (char *nome, char modo, char extra){
    /*  'nome' armazena o nome do arquivo a ser manipulado; 'modo' armazena o modo
    **  de abertura do mesmo; 'extra' armazena a condicao extra, se for para
    **  leitura ou escrita; 'auxiliar' armazena o ponteiro para o documento a ser
    **  manipulado */
    FILE *auxiliar;

    /* Verificacao do status de abertura */
    /* 'r' significa somente leitura; 'w' somente escrita; 'a' caso especial de escrita,
    ** por ser a parir do final */
    if (modo == 'r')    auxiliar = fopen (nome, "r");
    else if (modo == 'w')    auxiliar = fopen (nome, "w");
    else auxiliar = fopen (nome, "a+");

    /* Teste de abertura do arquivo */
    if (auxiliar == NULL && extra == 'l')
        printf ("\nERRO ABERTURA ARQUIVO %s\n", nome);

    return auxiliar;
}

/*  Funcao 'limpa_tela', realiza a limpeza da tela durante a execucao */
void limpa_tela(){
    #ifdef LINUX
        printf ("\e[H\e[2J");
    #elif defined WIN32
        system ("cls");
    #else
        printf ("\e[H\e[2J");
    #endif
        return;
}

/*  Leitura do arquivo base */
void ler_fonte (Grafo *graph){
    /*  'graph' armazena o grafo a ser construido; 'city1' e 'city2' armazenam os nomes das cidades
    **  a serem adicionadas ao grafo; 'dist' armazena a distancia entre elas; 'hinweis' armazena uma
    **  string de referencia; 'reserva' armazena a palavra lida no arquivo a ser tratada; 'lido'
    **  armazena o caracter lido no arquivo fonte; 'ind' armazena o indice a ser manipulado; 'campo'
    **  armazena o status do campo de interesse lido; 'arq' armazena o arquivo a ser lido */
    char city1[MAX], city2[MAX];
    char hinweis[] = "para", reserva[MAX], lido;
    int ind, campo, dist;
    FILE *arq = abre_arquivo ("entradaProj6.txt", 'r', 'l');

    /*  Tendo exito ao abrir o arquivo */
    if (arq != NULL){
        /*  Enquanto houver arquivo a ser lido */
        do{
            /*  Inicializao das variaveis de controle primarias */
            campo = dist = 0;
            zera_string (city1, 0, MAX);
            zera_string (city2, 0, MAX);

            /*  Lendo uma linha de dados completa */
            do{
                /*  Inicializacao das variaveis de controle secundarias */
                ind = 0;
                zera_string (reserva, 0, MAX);

                /*  Lendo uma palavra por vez */
                do{
                    lido = fgetc (arq);
                    if (lido != -1 && lido != 10 && lido != 32 && lido != 58){
                        reserva[ind] = lido;
                        ind++;
                    }

                }while (lido != -1 && lido != 10 && lido != 32 && lido != 58  && !feof(arq));

                /*  Configuracao do campo lido */
                if ((strcmp (reserva, hinweis) == 0)
                    || (campo == 1 && (strcmp (reserva, hinweis) != 0))
                    || (lido == 10))
                    campo++;

                /*  Sendo um campo de interesse */
                switch (campo){
                    /*  Pertencendo ao nome da primeira cidade */
                    case 0:
                        if (strlen (city1) > 0)
                            strcat (city1, " ");
                        strcat (city1, reserva);
                        zera_string (city1, strlen(city1), MAX);
                        break;
                    /*  Pertencendo ao nome da segunda cidade */
                    case 2:
                        if (strlen (city2) > 0)
                            strcat (city2, " ");
                        strcat (city2, reserva);
                        zera_string (city2, strlen(city2), MAX);
                        break;
                    /*  Pertencendo a distancia */
                    case 3:
                        dist = atoi (reserva);
                        break;
                }

                /*  Configuracao extra do campo lido */
                if (lido == 58) campo++;

            }while (lido != 10 && !feof(arq));

            /*  Ultima validacao dos dados, para construcao do grafo */
            if (dist != 0)
                constroi_grafo (graph, city1, city2, dist);

        }while (!feof(arq));

        fclose (arq);
    }
}

/*  Funcao 'ler_intervalo', verifica a validade de um numero inteiro dentre de um intervalo aceitavel */
int ler_intervalo (int min, int max){
    /*  'max' armazena o valor maximo para o intervalo de validade; 'num' armazena a coordenada
    **  a ser lida */
    int num;

    /*  Enquanto for invalido */
    do{
        scanf ("%d", &num);
        getchar ();

        /*  Sendo invalido, mensagem correspondente */
        if (num < min || num > max)
            printf ("\nO valor fornecido eh invalido! Digite novamente!\n");

    }while (num < min || num > max);

    return num;
}

/*  Funcao 'ler_nome_doc', realiza a leitura dos nomes dos documentos a serem analisados */
void ler_nome_doc (char *nome){
    /*  'alocacao' armazena o ponteiro do documento a ser avaliado como valido ou nao;
    **  nome' armazena o nome do arquivo a ser analisado; 'resp' armazena a resposta do usuario sobre
    **  a condicao de sobrescrita, no caso da previa existencia do arquivo para escrita; 'existe'
    **  informa se o arquivo ja existe ou nao */
    FILE *alocacao;
    char resp = 'S';

    /*  Enquanto existir arquivo, mas o usuario nao querendo sobrescrever */
    do{
        printf ("\nDigite o nome do documento a ser armazenados os dados, com a extensao .txt:\n");

        /*  Enquanto for diferente de ENTER, apenas */
        do{
            zera_string (nome, 0, MAXC * 2);
            scanf ("%[^\n]", nome);
            getchar ();

            if (nome[0] == 0)
                printf("\nNome invalido! Apenas ENTER foi recolhido! Digite novamente!\n");
        }while (nome[0] == 0);


        /*  Verificacao da validade do arquivo */
        alocacao = abre_arquivo (nome, 'r', 'e');

        /*  O arquivo nao deve existir, caso contrario pode ser sobrecrito,
        **  a vontade do usuario */
        if (alocacao != NULL){
            printf ("\nO arquivo ja existe! Deseja sobrescrever? S/N ou s/n\n");
            resp = ler_simounao ();
            if (resp == 'N' || resp == 'n')
                printf ("\nEntao digite um nome novamente!\n");
            else
                printf ("\nEntao, prosseguindo...\n");
            fclose (alocacao);
        }


    }while ((resp != 'S' && resp != 's'));

    /*  Se o arquivo existe, ele eh fechado, se nao, o seu ponteiro eh liberado */
    if (alocacao != NULL)
        fclose (alocacao);
    /*else
        free (alocacao);
        */
}

/*  Funcao 'ler_simounao', verifica a validade da resposta para uma pergunta de "sim ou nao"
**  ao longo do progresso do jogo */
char ler_simounao (){
    /*  'resp' armazena a resposta do usuario para a pergunta */
    char resp;

    /*  Enquanto for invalida */
    do{
        scanf ("%[^\n]", &resp);
        getchar ();

        /*  Sendo invalido, mensagem correspondente */
        if ((resp != 's') && (resp != 'S') && (resp != 'n') && (resp != 'N'))
            printf ("Resposta invalida, digite novamente!\n");

    }while ((resp != 's') && (resp != 'S') && (resp != 'n') && (resp != 'N'));

    return resp;
}

/*  Funcao 'pausa', realiza a pausa do programa ate pressionar o ENTER */
void pausa (){
    printf ("\nPressione ENTER para continuar.\n");
	getchar ();
}

/*  Questiona sobre o procedimento para exibicao do roteiro */
void questiona_roteiro (Roteiro *roteiro, char *leitura){
    char ind = 65;

    /*  Apresentacao das possibilidades */
    printf ("Ha dois tipos de exibicao do(s) roteiro(s):\n");
    printf ("\t1 - Todos os roteiros gerados;\n");
    printf ("\t2 - Partindo de uma cidade especifica.\n");
    printf ("\nSabendo das opcoes, digite a sua escolha:\n");

    switch (ler_intervalo (1, 2)){
        case 1:
            printf ("\nA opcao de todos foi selecionada\n");
            leitura[0] = 33;
            break;
        case 2:
            printf ("\nEntao, agora digite o nome da cidade de partida:\n");
                /*  Enquanto for invalido */
                do{
                    /*  Inicializacao da string */
                    zera_string (leitura, 0, MAX);

                    scanf ("%[^\n]", leitura);
                    getchar();

                    for (ind = 65; ind < MAXC + 65; ind++)
                        if (strcmp (roteiro[ind -65].inicio->nome, leitura) == 0) break;

                    if (ind >= MAXC + 65)
                        printf ("Esta cidade nao existe no registro!\nDigite novamente:\n");
                }while (ind >= MAXC + 65);
            break;
    }
}

/*  Funcao 'questiona_tempo', questiona sobre o procedimento de pausa do programa */
float questiona_tempo (){
    float tempo;

    /*  Apresentacao das possibilidades */
    printf ("Ha tres modos para a exibicao:\n");
    printf ("\t1 - Exibicao direta;\n");
    printf ("\t2 - Exibicao pausada por ENTER;\n");
    printf ("\t3 - Exibicao pausada por tempo.\n");
    printf ("\nSabendo das opcoes, digite a sua escolha:\n");

    switch (ler_intervalo (1, 3)){
        case 1:
            printf ("\nA exibicao direta foi selecionada\n");
            return -1;
        case 2:
            printf ("\nA exibicao pausada por ENTER foi selecionada\n");
            return 0.0;

        case 3:
            printf ("\nEntao, agora digite o tempo digitado ");
            printf ("(lembrando que pode ser decimal\nseparado por ponto (.), recomendando valores acima de 1.0):\n");
                scanf ("%f", &tempo);
                getchar();
    }

    return tempo;
}

/*  Funcao 'temporizador', realiza a pausa do programa por um periodo de tempo
**  definido pelo usuario */
void temporizador (float pausa){
    /*  'pausa' armazena o tempo de espera escolhido pelo usuario; 'tempoin' e
    **  'tempofim' armazenam os tempos inicial e final do temporizador, respec. */
    if (pausa < 0.0) return;

    float tempoin = 0.0, tempofim = 0.0;

    tempoin = ((float) clock()) / ((float) CLOCKS_PER_SEC);

    /*  Enquanto nao der o tempo desejado */
    while ((tempofim - tempoin) < pausa){
        tempofim = ((float) clock()) / ((float) CLOCKS_PER_SEC);
    };

   return;
}

/*  Funcao 'zera_string', anula os caracteres da string */
void zera_string (char *alvo, int inicio, int fim){
    /*  'alvo' armazena a string a ser zerada; 'maximo' armazena o limite da operacao;
    **  'ind' armazena o indice a ser manipulado */
    int ind;

    /*  Inicializacao dos caracteres */
    for (ind = inicio; ind < fim; ind++)  alvo[ind] = '\0';
}

/*  Compara duas strings, n bytes e a partir de m-esimo byte */
int compara_string_n (char *primeiro, char *segundo, int iniciop, int inicios, int quant){
    /*  'primeiro' e 'segundo' armazenam as strings a serem comparadas; 'iniciop' e 'inicios'
    **  armazenam os inicios de cada string a ser iniciada a comparacao; 'quant' armazena a
    **  quantidade de caracteres a serem comparados; 'ind' e 'ind1' armazenam indices a serem
    **  manipulados */
    int ind, ind1 = iniciop;

    /*  Comparação das strings */
    for (ind = inicios; ind < (inicios + quant); ind++, ind1++){
        if (primeiro[ind1] != segundo[ind])  return (primeiro[ind1] - segundo[ind]);
    }

    return 0;
}

/*  Funcao 'concat_string_n', realiza a juncao de duas strings */
void concat_string_n (char *destino, char *fonte, int iniciof, int fimf){
    /*  'destino' armazena a string resultado da juncao; 'fonte' armazena o trecho a ser juntado;
    **  'ind' e 'ind2' armazenam indices a serem manipulados */
    int ind = strlen (destino), ind2 = 0;

    /*  Juncao das strings */
    for (ind2 = iniciof; ind2 < fimf; ind2++, ind++){
        destino[ind] = fonte[ind2];
        if (fonte[ind2] == '\0')    break;
    }

    destino[ind] = '\0';
}

