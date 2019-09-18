#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Arquivo.h"
#define PI 3.14159265359

/* O arquivo Arquivo.c contem a implementacao para as funcoes relacionadas
** com a manipulacao dos arquivos a serem comparados e a realizacao dos
** calculos relacionados a semelhanca de tais arquivos */

/* 1 - Função abre_arquivo, realiza a abertura e teste de alocacao de um arquivo */
FILE * abre_arquivo (char *nome, char modo){
    /* 'nome' armazena o nome do arquivo a ser manipulado; 'modo' armazena o modo
    ** de abertura do mesmo; 'auxiliar' armazena o ponteiro para o documento a ser
    ** manipulado */
    FILE *auxiliar;

    /* Verificacao do status de abertura */
    /* 'r' significa somente leitura; 'w' somente escrita; 'a' caso especial de escrita,
    ** por ser a parir do final */
    if (modo == 'r')    auxiliar = fopen (nome, "r");
    else if (modo == 'w')    auxiliar = fopen (nome, "w");
    else auxiliar = fopen (nome, "a+");

    /* Teste de abertura do arquivo */
    if (auxiliar == NULL && modo == 'r'){
        printf ("\nERRO ABERTURA ARQUIVO %s\n", nome);
        return auxiliar;
    }
}

/* 2 - Função nome_arquivo, cria o nome dos arquivos a serem lidos */
void nome_arquivo (char *nome, int numero){
    /* 'nome' armazena o nome do arquivo a ser feito a analise; 'numero' armazena
    ** a posicao da sequencia de documentos a serem analisados; 'alocacao' verifica
    ** a existencia do arquivo informado */
    FILE *alocacao;

    /* Formação da string */
    printf ("Digite o nome do %dº documento: ", numero);

    /* Aceita apenas nomes de arquivos existentes do diretorio do programa,
    ** ou diretorio informado */
    do{
        scanf ("%[^\n]", nome);
    getchar();
    alocacao = abre_arquivo (nome, 'r');
    if (alocacao == NULL) printf ("Digite o nome do documento novamente: ");
    }while (alocacao == NULL);

    nome[strlen(nome)]= '\0';
    fclose (alocacao);
}

/* 3 - Montagem do Nome dos Arquivos Resumidos */
void nome_arquivo_resumo (char *origem, char *destino){
    /* 'origem' armazena o nome do arquivo a ser feito o resumo;
    ** 'destino' armazena o nome do arquivo-resumo em si */

    /* Formação da string */
    zera_string (destino, TAMT);
    strcpy (destino, "RESUMO_");
    strcat (destino, origem);
}

/* 4 - Funcao ler_arquivos, realiza a leitura das informações do arquivo .txt */
Lista * ler_arquivos (Lista *lista, char *nome_arquivo){
	/* lista' armazena o cabecalho da lista propriamente dita;
	** 'nome_arquivo' armazena o nome do arquivo a ser feito o levantamento
	** de informacoes; 'caracter' recebe cada caracter do arquivo texto
    ** 'palavra_auxiliar' armazena cada palavra formada que
    ** será inserida na Elemento; 'indice' é indice de
    ** apoio; e 'arquivo' trabalha com o documento ser lido */
	char caracter, palavra_auxiliar[16];
	int indice;
	FILE *arquivo;

    /* Abertura do arquivo para leitura */
	arquivo = abre_arquivo (nome_arquivo, 'r');

    /* Leitura do Arquivo .txt */
	do{
		indice = 0;
        zera_string (palavra_auxiliar, 16);

        /* Formação das Palavras */
		do{
			caracter = fgetc (arquivo);

			/* Captura de caracteres alfanuméricos, apenas */
			if ((caracter >= 48 && caracter <= 57) || (caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122)){
				palavra_auxiliar[indice] = caracter;
				indice++;
			}

		}while (((caracter >= 48 && caracter <= 57) || (caracter >= 65 && caracter <= 90) ||
		(caracter >= 97 && caracter <= 122)) && !feof(arquivo));

        /* Garantia de que o último elemento válido da string seja NULL */
		palavra_auxiliar[indice] = 0;

        /* Verificar Status da Palavra em Relação ao arquivo corrente */
        if (strlen(palavra_auxiliar) >= 1) lista = add_info (lista, palavra_auxiliar);

	}while (!feof(arquivo));

	fclose(arquivo);

	return lista;
}

/* 5 - Funçao ler_arquivos_resumo, realiza a leitura dos documentos resumos */
void ler_arquivos_resumo (Resultado *resultado, char *documento1, char *documento2){
    /* 'resultado' armazena o cabecalho da lista Resultado propriamente dita;
    ** 'documento1' e 'documento2' armazenam os nomes dos arquivos a serem analisados
    ** ao par; 'arq1' e 'arq2' armazenam os nomes dos arquivos-resumo a serem lidos
    ** 'arquivo1' e 'arquivo2' apontam para estes arquivos, resp.; 'letra' armazena
    ** cada caracter lido nos arquivos-resumo; 'indice' e 'indice_reserva' são os indices
    ** para 'palavra' e 'reserva', resp., onde 'reserva' efetua o armazenamento previo das
    ** frequencias, que serao armazenadas em 'frequencia1' e 'frequencia2'; 'condicao' e
    ** 'condicao_parada' sao condicoes de controle dos lacos */
    char arq1[TAMT], arq2[TAMT];
    char letra, palavra[TAMP], palavra2[TAMP], reserva[2];
    int frequencia1, frequencia2, indice, indice_reserva;
    int condicao, condicao_parada;
    FILE *arquivo1, *arquivo2;

    /* Montagem dos nomes dos arquivos-resumo a serem lidos */
    zera_string (arq1, TAMT);
    nome_arquivo_resumo (documento1, arq1);


    /* Abertura e teste de Abertura dos arquivos-resumo */
    arquivo1 = abre_arquivo (arq1, 'r');//arq1, 'r');
    /* Leitura do arquivo-resumo 1 e 2, analogo ao processo da função ler_arquivos */
    /* Os arquivos-resumo estão organizador por "<palavra>;<frequência>\n" */
    do{

        indice = 0;
        indice_reserva = 0;
        condicao = 0;
        condicao_parada = 0;
        zera_string (palavra, TAMP);
        zera_string (reserva, 2);

        /* Captura da Palavra e sua frequencia no 1º documento */
        do{
            letra = fgetc (arquivo1);

            if (condicao == 0 && ((letra >= 48 && letra <= 57) || (letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122))){
                palavra[indice] = letra;
                indice++;

            }else if (letra == 59){
                condicao = 1;

            }else if (letra == 10){
                condicao_parada = 1;
            }
            if (condicao == 1 && ((letra >= 48 && letra <= 57) || (letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122))){
                reserva[indice_reserva] = letra;
                indice_reserva++;
            }

        }while (letra != 10 && condicao_parada != 1 && !feof(arquivo1));

        frequencia1 = atoi (reserva);
        zera_string (arq2, TAMT);
        nome_arquivo_resumo (documento2, arq2);
        arquivo2 = abre_arquivo (arq2, 'r');

        /* Captura da Palavra e sua frequencia no 2º documento */
        do{

            indice = 0;
            indice_reserva = 0;
            condicao = 0;
            condicao_parada = 0;
            zera_string (palavra2, TAMP);
            zera_string (reserva, 2);

            do{

                letra = fgetc (arquivo2);

                if (condicao == 0 && letra != 59 && letra != 10){
                    palavra2[indice] = letra;
                    indice++;

                }else if (letra == 59){
                    condicao = 1;

                }else if (letra == 10){
                    condicao_parada = 1;

                }
                if (condicao == 1 && letra != 59 && letra != 10){
                    reserva[indice_reserva] = letra;
                    indice_reserva++;
                }

            }while (letra != 10 && condicao_parada != 1 && !feof(arquivo2));

            /* Verificacao do status de semelhanca entre as palavras armazenadas */
            if (strcmp (palavra, palavra2) == 0 && frequencia1 > 0){
                frequencia2 = atoi (reserva);

                if (resultado->campos == 0){
                    resultado = add_result_vazia (resultado, palavra, frequencia1, frequencia2);

                }else{
                    resultado = add_campo (resultado, palavra, frequencia1, frequencia2);

                }
                break;
            }

        }while (!feof(arquivo2));

        fclose (arquivo2);

    }while (!feof(arquivo1));

    fclose (arquivo1);

}

/* 6 - Funcao metrica_projecao, calcula o produto interno dos vetores de frequencia das palavras em comum entre dois documentos */
int metrica_projecao (Resultado *resultado){
    /* 'resultado' armazena o cabecalho da lista Resultado propriamente dita;
    ** 'auxiliar' percorre a lista fornecida sem modifica-la, diretamente;
    ** 'metrica' armazena o valor da metrica de projecao */
    Campo *auxiliar = resultado->comeco;
    int metrica = 0;

    /* Calculo da metrica de projecao */
    while (auxiliar != NULL){
        metrica += (auxiliar->freq1) * (auxiliar->freq2);
        auxiliar = auxiliar->proximo;
    }

    return metrica;
}

/* 7 - Funcao magnitude_doc, calcula a magnitude do documento */
float magnitude_doc (Lista *lista){
    /* 'lista' armazena o cabecalho da lista propriamente dita;
    ** 'auxiliar' percorre a lista fornecida sem modifica-la diretamente;
    ** 'soma' armazena o somatorio dos quadrados da frequencia de cada
    ** palavra, a priori, passando a ser a magnitude em si, posteriormente */
    Elemento *auxiliar = lista->comeco;
    float soma = 0.0;

    /* Realizada o somatorio dos termos */
    while (auxiliar != NULL){
        soma += (float) pow(auxiliar->frequencia, 2);
        auxiliar = auxiliar->proximo;
    }

    /* Cálculo da Magnitude em si */
    soma = sqrt(soma);

    return soma;
}

/* 8 - Funcao metrica_angulo, calcula o angulo de diferenca entre dois documentos */
float metrica_angulo (int metrica, float mag1, float mag2){
    /* 'metrica' armazena o valor da metrica de projecao entre os documentos correntes;
    ** 'mag1' e 'mag2' armazenam as frequencias da palavras dos documentos respectivos;
    ** 'angulo' armazena o valor do calculo da metrica do angulo */
    float angulo = 0.0;

    angulo = acos(metrica / (mag1 * mag2));
    angulo = (angulo * 180.0) / PI;

    return angulo;
}

/* 9 - Funcao grau_semelhanca, calcula o grau de semelhanca entre os documentos */
float grau_semelhanca (float angulo){
    /* 'angulo' armazena o angulo de semelhanca entre os documentos correntes;
    ** 'percentual' armazena o valor obtido no calculo da percentagem de semelhanca */
    float percentual;

    if (angulo == 0.0){
        percentual = 100.0;

    }else if (angulo == 90.0){
        percentual = 0.0;

    }else{
        percentual = 100.0 - (angulo * (10.0 / 9.0));
    }

    return percentual;
}

/* 10 - Função escreve_arq_lista, cria um arquivo auxiliar com resumo do documento lido,
** com as palavras e suas respectivas frequencias */
void escreve_arq_lista (Lista *lista, char *arquivo){
    /* 'lista' armazena o cabecalho da lista Resultado propriamente dita;
    ** 'arquivo' armazena o nome do arquivo a ser gerado o resumo; 'nome_arquivo'
    ** armazena o nome do arquivo a ser gravado a lista; 'auxiliar' percorre a
    ** Lista, sem modificá-la diretamente; 'documento' aponta para o documento a
    ** ser criado */
    char nome_arquivo[TAMT];
    Elemento *auxiliar = lista->comeco;
    FILE *documento;

    /* Construção do nome do arquivo a ser criado */
    zera_string (nome_arquivo, TAMT);
    strcpy (nome_arquivo, "RESUMO_");
    strcat (nome_arquivo, arquivo);

    /* Abertura do documento para escrita */
    documento = abre_arquivo (nome_arquivo, 'w');

    /* Escrita dos dados no documento criado */
    while (auxiliar != NULL){
        fprintf (documento, "%s;%d\n", auxiliar->palavra, auxiliar->frequencia);
        auxiliar = auxiliar->proximo;
    }

    /* Liberação do ponteiro arquivo*/
    fclose (documento);
}

/* 11 - Funcao escreve_arq_resultado, cria o arquivo final com as comparacoes realizadas sobre
** os documentos fornecidos */
void escreve_arq_resultado (Resultado *resultado, char *nome1, char *nome2, float mag1, float mag2, float angulo){
    /* 'resultado' armazena o cabecalho da lista Resultado propriamente dita;
    ** 'nome1' e 'nome2' armazenam os nomes dos arquivos comparados; 'mag1' e
    ** 'mag2' armazenam as magnitudes dos documentos avaliados; 'angulo' armazena
    ** o angulo, em graus, da semelhanca entre os documentos avaliados;
    ** 'auxiliar' percorre a lista Resultado, sem modifica-la diretamente;
    ** 'arquivo' aponta para o documento a ser manipulado; 'porcento' armazena
    ** a porcentagem de semelhanca entre os documentos fornecidos */
    Campo *auxiliar = resultado->comeco;
    FILE *arquivo = abre_arquivo ("comparaDoc_Lucas&Rodrigo.txt", 'a');
    float porcento;

    /* Verificacao do status da lista Resultado*/
    /* Não havendo palavra em comum entre os documentos analisados */
    if (auxiliar == NULL){
        fprintf (arquivo, "Nao ha palavra em comum entre %s e %s\n", nome1, nome2);

    /* Havendo palavra(as) em comum */
    }else{
        /* Cabecalho da Analise dos documentos */
        fprintf (arquivo, "Analise de Semelhanca entre %s(1) e %s(2)\n", nome1, nome2);
        fprintf (arquivo, "\nAs magnitudes:\n\tEm 1 = %.2f\tEm 2 = %.2f\n", mag1, mag2);

        /* Calculo da Porcentagem de semelhanca */
        porcento = grau_semelhanca (angulo);

        /* Verificacao do status de semelhanca */
        if (porcento < 50.0){
            fprintf (arquivo, "Com %.2f%% de semelhança, angulo de %.2f graus, conclui-se que:\nNÃO HOUVE PLAGIO\n\n",
                     porcento, angulo);

        }else{
            fprintf (arquivo, "Com %.2f%% de semelhança, angulo de %.2f graus, conclui-se que:\nHOUVE PLAGIO\n\n",
                     porcento, angulo);
        }

        /* Palavra(as) em comum com suas respectivas frequencias */
        fprintf (arquivo, "Segue Lista das palavras semelhantes entre os documentos e suas respectivas frequencias:\n");
        for (auxiliar; auxiliar != NULL; auxiliar = auxiliar->proximo){
            fprintf (arquivo, "\nPalavra = %s\n", auxiliar->palavra);
            fprintf (arquivo, "\tFreq. em 1 = %d\tFreq. em 2 = %d\n", auxiliar->freq1, auxiliar->freq2);
        }
    }

    fprintf (arquivo,"\n\n");

    fclose (arquivo);
}
