/*  Descritivo das funções para andamento do Projeto */

/*  Bibliotecas requisitada */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "Funcoes_P4.h"


/*  Lista das funcoes de manipulacao */

/*  Funcao 'inicio_geral', realiza a apresentacao do projeto e questiona sobre
**  o inicio ou nao do mesmo */
char inicio_geral (){
    limpa_tela ();

    /*  Apresentacao das caracteristicas do projeto */
    printf ("Bem-vindo ao processamento de documentos!\n");
    printf ("\nO processamento realizado por este projeto visa:");
    printf ("\n\t1. Ranquear as palavras, de uma certa quantidade de documentos,\n");
        printf ("a partir da frequencia das mesmas entre os documentos, ou seja, a quantidade de\n");
        printf ("documentos que contenha tais palavras;");
    printf ("\n\t2. O rank tera como tamanho maximo o minimo tamanho entre os documentos\n");
        printf ("fornecidos, onde o tamanho de um documento eh avaliado pela quantidade de palavras no\n");
        printf ("mesmo;");
    printf ("\n\t3. A quantidade de colisoes, devido a geracao do rank, tentara ser minimizado;");
    printf ("\n\t4. Sera gerado um arquivo resultado contendo:");
    printf ("\n\t\t4.1 As palavras, com suas respectivas chaves e indices;");
    printf ("\n\t\t4.2 As estatisticas do hashing:");
    printf ("\n\t\t\t4.2.1 Numero total de palavras encontradas;");
    printf ("\n\t\t\t4.2.2 Numero maximo do indice;");
    printf ("\n\t\t\t4.2.3 Total de colisoes;");
    printf ("\n\t\t\t4.2.4 Numero de elementos com numero maximo de colicoes.");
    printf ("\n\t5. Os dados existentes no documento resultado serao exibidos na tela;");
    printf ("\n\t6. Sera disponibilizado a procura de uma palavra durante todas.");

    /*  Questionamento sobre inicio do projeto */
    printf ("\n\nDadas as caracteristicas do projeto, deseja inicia-lo? S/N ou s/n\n");
        return ler_simounao ();
}

/*  Funcao 'hello', da as boas vindas */
void hello(){
	limpa_tela ();
	printf ("Hello World!\n");
    temporizador (1.5);
    printf ("Bem-vindo!\n");
    pausa();
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

/*  Funcao 'questiona_tam', questiona sobre a quantidade de documentos a serem analisados */
int questiona_tam (){
    limpa_tela ();
    printf ("Visto que desejou comecar o processamento, ");
    printf ("determine a quantidade de documentos\na serem analisados, recomendado que seja entre 1 e 999 apenas:\n");
        return ler_intervalo (1, 999);
}

/*  Funcao 'questiona_procura', questiona a vontade de procurar uma palavra na tabela */
char questiona_procura (){
    limpa_tela ();
    printf ("Tem a vontade de procurar uma palavra no nosso banco de dados? S/N ou s/n\n");
    return ler_simounao ();
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

/*  Funcao 'ler_simounao', verifica a validade da resposta para uma pergunta de "sim ou nao"
**  ao longo do progresso do jogo */
char ler_simounao (){
    /*  'resp' armazena a resposta do usuario para a pergunta */
    char resp;

    /*  Enquanto for invalida */
    do{
        scanf ("%c", &resp);
        getchar ();

        /*  Sendo invalido, mensagem correspondente */
        if ((resp != 's') && (resp != 'S') && (resp != 'n') && (resp != 'N'))
            printf ("Resposta invalida, digite novamente!\n");

    }while ((resp != 's') && (resp != 'S') && (resp != 'n') && (resp != 'N'));

    return resp;
}

/*  Funcao 'ler_nome_doc', realiza a leitura dos nomes dos documentos a serem analisados */
char * ler_nome_doc (int doc, int tot, char cond){
    /*  'doc' armazena o numero do documento a ser lido, no caso da inicializacao; 'tot' armazena o total de
    **  documentos a serem analisados; 'cond' armazena a condicao para realizacao da leitura, sendo 'l' para
    **  leitura e 'e' para a escrita; 'alocacao' armazena o ponteiro do documento a ser avaliado como valido
    **  ou nao; 'nome' armazena o nome do arquivo a ser analisado; 'resp' armazena a resposta do usuario sobre
    **  a condicao de sobrescrita, no caso da previa existencia do arquivo para escrita */
    FILE *alocacao;
    char *nome, resp = 'S';

    /*  Enquanto nao existir arquivo para leitura ou existindo para a escrita, mas o usuario nao querendo sobrescrever */
    do{
        /*  Querendo ler o arquivo */
        if (cond == 'l')
            printf ("\nDigite o nome do %dº documento, dentre o(s) %d,\na ser analisado, com a extensao .txt:\n", doc, tot);

        /*  Querendo escrever */
        else
            printf ("\nDigite o nome do documento a ser armazenados os dados, com a extensao .txt:\n");

        nome = ler_palavra();

        /*  Se o nome for ENTER, o nome padrao eh selecionado "nome.txt" */
        while (nome[0] == 0){
            printf("\nNome invalido! Digite novamente!\n");
            nome = ler_palavra();
        }

        /*  Verificacao da validade do arquivo */
        alocacao = abre_arquivo (nome, 'r', cond);

        /*  Sendo para leitura, o arquivo deve existir */
        if (cond == 'l'){
            if (alocacao == NULL)
                printf ("\nO arquivo fornecido nao existe neste diretorio! Digite o nome novamente!\n");

        /*  Sendo para escrita, o arquivo nao deve existir, caso contrario pode ser sobrecrito,
        **  a vontade do usuario */
        }else{
            if (alocacao != NULL){
                printf ("\nO arquivo ja existe! Deseja sobrescrever? S/N ou s/n\n");
                resp = ler_simounao ();
                if (resp == 'N' || resp == 'n')
                    printf ("\nEntao digite um nome novamente!\n");
                else
                    printf ("\nEntao, prosseguindo...\n");
            }
        }

    }while ((cond == 'l' && alocacao == NULL) || (cond == 'e' && (resp != 'S' && resp != 's')));


    free (alocacao);

    return nome;
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

/*  Funcao 'le_arquivo', realiza a leitura dos arquivos */
int le_arquivo (Lista *lista, char *nomearq){
	/*  'lista' armazena a lista de palavras a ser manipulada na leitura dos documentos; 'nomearq' armazena
	**  o nome do arquivo a ser lido; 'palavra' armazena a palavra lida no documento de forma dinamica;
	**  'caracter' armazena o caracter lido no documento; 'palavraauxiliar' armazena a palavra lida no modo
	**  estatico; 'indice' armazena o indice da palavra a ser manipulado; 'tam' armazena o tamanho da palavra
	**  lida; 'tamanho' armazena a quantidade de palavras lidas; 'arquivo' armazena o ponteiro do arquivo
	**  a ser lido */
	Palavra *palavra = cria_palavra ();
	char caracter, *palavraauxiliar = NULL;
	int indice, tam, tamanho = 0;
	FILE *arquivo;

    /* Abertura do arquivo para leitura */
	arquivo = abre_arquivo (nomearq, 'r', 'l');

    /* Leitura do Arquivo .txt */
	do{
		indice = 0;
		tam = 0;

        /* Formação das Palavras */
		do{
			caracter = fgetc (arquivo);

			/* Captura de caracteres alfanuméricos, apenas */
			if ((caracter >= 48 && caracter <= 57) || (caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122))
				constroi_palavra (palavra, caracter);

		}while (((caracter >= 48 && caracter <= 57) || (caracter >= 65 && caracter <= 90) ||
           (caracter >= 97 && caracter <= 122)) && !feof(arquivo));

        /*  Montagem da palavra na forma estatica, para ser inserida na lista de palavras */
        if (palavra->quant != 0){
            tam = palavra->quant;
            palavraauxiliar = (char *) calloc (tam, sizeof(char));
            for (indice = 0; indice < tam; indice++)
                palavraauxiliar[indice] = remove_letra (palavra);
            palavraauxiliar[indice] = 0;

            constroi_lista (lista, palavraauxiliar, nomearq);
            tamanho++;
        }

        /*  Tendo sido utilizada a 'palavraauxiliar' eh limpa para uma nova leitura */
        if (palavraauxiliar != NULL){
            free (palavraauxiliar);
            palavraauxiliar = NULL;
        }

	}while (!feof(arquivo));

    libera_palavra (palavra);
	fclose(arquivo);

	return tamanho;
}

/*  Funcao 'le_palavra', realiza a leitura de uma palavra ate o ENTER */
char * ler_palavra (){
    /* 'palavra' armazena o nome do documento a ser lido dinamicamente; 'int' armazena o indice do
    **  a ser manipulado; 'tam' armazena o tamanho da palavra para a alocacao do necessario; 'ler'
    **  armazena a leitura do teclado; 'nome' armazena a palavra digitada na forma estatica */
    Palavra *palavra = cria_palavra ();
    int ind, tam;
    char *nome, ler;

    /*  Enquanto nao for ENTER */
    do{
        scanf ("%c", &ler);
        constroi_palavra (palavra, ler);
    }while (ler != 10);

    /*  Configuracao estatica da palavra lida */
    tam = palavra->quant;
    nome = (char *) calloc (tam,sizeof(char));
    for (ind = 0; ind < tam; ind++)
        nome[ind] = remove_letra(palavra);
    nome[ind] = '\0';

    libera_palavra (palavra);

    return nome;
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

/*  Funcao 'pausa', realiza a pausa do programa ate pressionar o ENTER */
void pausa (){

    printf ("\nPressione ENTER para continuar.\n");
	getchar ();
}

/*  Funcao 'temporizador', realiza a pausa do programa por um periodo de tempo
**  definido pelo usuario */
void temporizador (float pausa){
    /*  'pausa' armazena o tempo de espera escolhido pelo usuario */
    if (pausa < 0.0) return;

    float tempoin = 0.0, tempofim = 0.0;

    tempoin = ((float) clock()) / ((float) CLOCKS_PER_SEC);

    /*  Enquanto nao der o tempo desejado */
    while ((tempofim - tempoin) < pausa){
        tempofim = ((float) clock()) / ((float) CLOCKS_PER_SEC);
    };

   return;
}

/*  Funcao 'chaveamento', realizaca a codificacao da palavra numa chave */
int chaveamento (char *palavra){
    /*  'palavra' armazena a palavra a ser gerada a chave; 'ind' armazena o indice da palavra
    **  a ser manipulado; 'chave' armazena o resultado da codificacao */
    int ind, chave = 0;

    for (ind = 0; ind < strlen (palavra); ind++){
        /*  Sendo entre 0 e 9, recebe o codigo entre 0 e 9 */
        if (palavra[ind] >= 48 && palavra[ind] <= 57)
            chave += palavra[ind] - 48;

        /*  Sendo entre A e Z, recebe o codigo entre 10 e 35 */
        else if (palavra[ind] >= 65 && palavra[ind] <= 90)
            chave += palavra[ind] - 55;

        /*  Sendo entre a e z, recebe o codigo entre 36 e 61 */
        else if (palavra[ind] >= 97 && palavra[ind] <= 122)
            chave += palavra[ind] - 61;
    }

    return chave;
}

/*  Funcao 'calc_hashing', realiza a codificacao final da palavra atraves de uma funcao, dado um valor limite */
int calc_hashing (int chave, int max){
    /*  'chave' armazena a chave da palavra a ser utilizada como base na conta, 'max' armazena o valor limite
    **  acrescido de 1; 'indhash' armazena a codificacao final da palavra; 'mult' armazena o fator multiplicador
    **  na funcao de hashing; 'expo' armazena o expoente da funcao de hashing */
    float indhash, mult = 1.702765, expo = 1/1.158878;

    /*  Funcao de hashing */
    indhash = pow(chave * mult, expo);

    /*  Limitacao do indice pelo valor maximo */
    indhash = ((int)indhash)%max;

    return indhash;
}
