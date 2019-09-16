#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arquivo.h"


/* O arquivo Lista.c contem a implementacao para as funcoes relacionadas
** com as listas, tanto as dos arquivos a serem lidos como a resultado da
** comparacao dois a dois */

/* Sequência de saidas por erros ocasionais:
    Exit (-1) = Erro alocação de uma Lista, tando do documento como do resultado
    Exit (-2) = Erro alocação de um Elemento ou Campo de uma lista */


/* 1 - Funcao cria_lista, aloca espaco para o cabecalho da lista e zera
** suas variaveis de controle */
Lista* cria_lista (){
    /* 'auxiliar' armazena o espaco alocado para o Cabecalho da Lista */
    Lista *auxiliar = (Lista *) malloc (sizeof(Lista));

    /* Teste de Alocação */
    if (auxiliar == NULL){
        printf("\nERRO ALOCACAO LISTA!\n");
        exit (-1);
    }

    /* Inicialição das Variáveis de Controle*/
    auxiliar->campos = 0;
    auxiliar->comeco = NULL;
    auxiliar->fim = NULL;

    return auxiliar;
}

/* 2 - Funcao cria_elemento, aloca espaco para um elemento da lista
** e zera suas variaveis de controle */
Elemento * cria_elemento (){
    /* 'auxiliar' armazena o espaco alocado para um elemento a ser
    ** inserido na Lista */
    Elemento *auxiliar = (Elemento *) malloc (sizeof(Elemento));

    /* Teste de Alocação*/
    if (auxiliar == NULL){
        printf("\nERRO ALOCACAO ELEMENTO!\n");
        exit (-2);
    }

    /* Inicialição das Variáveis de cotrole*/
    auxiliar->frequencia = 0;
    zera_string (auxiliar->palavra, TAMP);
    auxiliar->proximo = NULL;

    return auxiliar;
}

/* 3 - Funcao cria_resultado, aloca espaco para o cabecalho da lista resultado
** da comparacao de dois arquivos e zera suas variaveis de controle */
Resultado * cria_resultado (){
    /* 'auxiliar' armazena o espaco alocado para o Cabecalho da lista
    ** Resultado da Comparacao */
    Resultado *auxiliar = (Resultado *) malloc (sizeof(Resultado));

    /* Teste de Alocacao */
    if (auxiliar == NULL){
        printf ("\nERRO ALOCACAO LISTA RESULTADO\n");
        exit (-1);
    }

    /* Inicialição das Variáveis de cotrole*/
    auxiliar->campos = 0;
    auxiliar->comeco = auxiliar->fim = NULL;
    return auxiliar;
}

/* 4 - Funcao cria_campo, aloca espaco para um elemento da lista resultado
** da comparacao e zera suas variaveis de controle */
Campo * cria_campo (){
    /* 'auxiliar' armazena o espaco alocado para um campo a ser
    ** inserido na lista Resultado da Comparacao */
    Campo *auxiliar = (Campo *) malloc (sizeof(Campo));

    /* Teste de Alocação*/
    if (auxiliar == NULL){
        printf ("\nERRO ALOCACAO CAMPO RESULTADO\n");
        exit (-2);
    }

    /* Inicialição das Variáveis de cotrole*/
    zera_string (auxiliar->palavra, TAMP);
    auxiliar->freq1 = auxiliar->freq2 = 0;
    auxiliar->proximo = NULL;
    return auxiliar;
}

/* 5 - Funcao libera_elementos, desaloca o espaco alocado para cada elemento
** da Lista */
Lista * libera_elementos (Lista *lista){
    /* 'lista' armazena o cabecalho da lista propriamente dita; 'auxiliar' percorre
    ** a Lista, sem modificá-la diretamente */
    Elemento *auxiliar = lista->comeco;

    /* 'temp' armazena o endereco do proximo elemento da Lista
    ** para evitar quebra da mesma, apos a liberacao da posicao
    ** corrente */
    while (auxiliar != NULL){
        Elemento *temp = auxiliar->proximo;
        free (auxiliar);
        auxiliar = temp;
    }

    /* Reciclagem do inicio da lista propriamente dita */
    lista->comeco = auxiliar;

    return lista;
}

/* 6 - Funcao libera_lista, desaloca o espaco alocado para o cabecalho da Lista */
void libera_lista (Lista *lista){
    /* 'lista' armazena o cabecalho da lista propriamente dita */
    free (lista);
}

/* 7 - Funcao libera_campos, desaloca o espaco alocado para cada campo
** da lista Resultado */
Resultado * libera_campos (Resultado *resultado){
    /* 'resultado' armazena o cabecalho da lista Resultado propriamente dita;
    ** 'auxiliar' percorre a lista Resultado, sem modificá-la diretamente */
    Campo *auxiliar = resultado->comeco;

    /* 'temp' armazena o endereco do proximo elemento da lista
    ** Resultado para evitar quebra da mesma, apos a liberacao
    ** da posicao corrente */
    while (auxiliar != NULL){
        Campo *temp = auxiliar->proximo;
        free (auxiliar);
        auxiliar = temp;
    }

    /* Reciclagem das variveis de controle */
    resultado->comeco = resultado->fim = auxiliar;
    resultado->campos = 0;

    return resultado;
}

/* 8 - Funcao libera_resultado, desaloca o espaco alocado para o cabecalho da lista Resultado*/
void libera_resultado (Resultado *resultado){
    /* 'resultado' armazena o cabecalho da lista Resultado propriamente dita */
    free (resultado);
}

/* 9 - Funcao add_info, insere uma nova informação a Lista */
Lista* add_info (Lista *lista, char *leitura){
    /* 'lista' armazena o cabecalho da lista Resultado propriamente dita; 'leitura' armazena
    ** a palavra formada a partir do documento analisado; 'auxiliar' manipula a Lista, sem
    ** modificá-la diretamente;  */
    Elemento *auxiliar = lista->comeco;

    /* Busca do elemento na Lista */
    while (auxiliar != NULL && auxiliar->palavra != NULL){
        if (strcmp(auxiliar->palavra, leitura) == 0) break;
            auxiliar = auxiliar->proximo;
    }

    /* Verificacao do status da busca */
    /* Caso especial para fim da Lista, "Lista vazia" */
    if (auxiliar == NULL && lista->campos == 0){
        add_lista_vazia (lista, leitura);

    /* Chegando ao fim da Lista */
    }else if (auxiliar == NULL && lista->campos != 0){
        add_elemento (lista, leitura);

    /* Encontrando a mesma palavra */
    }else if (strcmp (auxiliar->palavra, leitura) == 0){
        auxiliar->frequencia++;
    }

	return lista;
}

/* 10 - Funcao add_lista_vazia, insere um novo elemento na Lista, mas
** para o caso especial: Lista vazia */
void add_lista_vazia (Lista *lista, char *leitura){
    /* 'lista' armazena o cabecalho da lista Resultado propriamente dita; 'leitura' armazena
    ** a palavra formada a partir do documento analisado; 'novo' aloca o espaco para o novo
    ** elemento a ser inserido na Lista */
    Elemento *novo = cria_elemento ();

    /* Inicialização das Variáveis do novo elemento, a partir dos dados fornecidos */
    novo->frequencia = 1;
    strcpy (novo->palavra, leitura);

    /* Configuracao da armacao da Lista */
    novo->proximo = NULL;
    lista->comeco = novo;
    lista->fim = novo;
    lista->campos++;
}

/* 11 - Funcao add_elemento, insere um novo elemento no comeco da Lista */
void add_elemento (Lista *lista, char *leitura){
    /* 'lista' armazena o cabecalho da lista Resultado propriamente dita; 'leitura' armazena
    ** a palavra formada a partir do documento analisado; 'novo' aloca o espaco para o novo
    ** elemento a ser inserido na Lista */
    Elemento *novo = cria_elemento ();

    /* Inicialização das Variáveis do novo elemento, a partir dos dados fornecidos */
    novo->frequencia = 1;
    strcpy (novo->palavra, leitura);

    /* Configuracao da armacao da Lista */
    novo->proximo = lista->comeco;
    lista->comeco = novo;
    lista->campos++;
}

/* 12 - Funcao add_result_vazia, insere um novo campo na lista Resultado, mas
** para o caso especial: lista Resultado vazia */
Resultado * add_result_vazia (Resultado *resultado, char *palavra, int freq1, int freq2){
    /* 'resultado' armazena o cabecalho da lista Resultado propriamente dita;
    ** 'novo' aloca o espaco para o novo campo a ser inserido na Lista;
    ** 'palavra' armazena a palavra em comum entre os documentos analisados;
    ** 'freq1' e 'freq2' armazenam as respectivas frequencias dos documentos
    ** analisados */
    Campo *novo = cria_campo ();

    /* Inicialização das Variáveis do novo campo, a partir dos dados fornecidos */
    novo->freq1 = freq1; novo->freq2 = freq2;
    strcpy (novo->palavra, palavra);

    /* Configuracao da armacao da lista Resultado */
    resultado->comeco = novo;
    resultado->fim = novo;
    resultado->campos++;

    return resultado;
}

/* 13 - Funcao add_campo, insere um novo campo na lista Resultado */
Resultado * add_campo (Resultado *resultado, char *palavra, int freq1, int freq2){
    /* 'resultado' armazena o cabecalho da lista Resultado propriamente dita;
    ** 'novo' aloca o espaco para o novo campo a ser inserido na Lista;
    ** 'palavra' armazena a palavra em comum entre os documentos analisados;
    ** 'freq1' e 'freq2' armazenam as respectivas frequencias dos documentos
    ** analisados */
    Campo *novo = cria_campo ();

    /* Inicialização das Variáveis do novo campo, a partir dos dados fornecidos */
    novo->freq1 = freq1; novo->freq2 = freq2;
    strcpy (novo->palavra, palavra);

    /* Configuracao da armacao da lista Resultado */
    novo->proximo = resultado->comeco;
    resultado->comeco = novo;
    resultado->campos++;

    return resultado;
}

/* 14 - Função ordena_lista, ordena a Lista de forma decrescente em relacao a frequencia */
void ordena_lista (Lista *lista){
    /* 'lista' armazena o cabecalho da lista Resultado propriamente dita;
    ** 'auxiliar' e 'auxiliar2' manipulam a lista, de forma a
    ** armazenar o atual e o proximo elemento da Lista;
    ** 'troca' guarda o status da troca ou não de elementos */
    Elemento *auxiliar = lista->comeco, *auxiliar2 = auxiliar->proximo;
    int troca = 0;

    /* Enquanto houver lista para percorrer */
    while (auxiliar2 != NULL){
        if (auxiliar->frequencia < auxiliar2->frequencia){
            /* 'temp' armazena as informacoes da posicao corrente */
            /* Fazer backup das informacoes */
            Elemento *temp = cria_elemento ();
            temp->frequencia = auxiliar->frequencia;
            strcpy(temp->palavra, auxiliar->palavra);

            /* Realizando a troca de informacoes */
            auxiliar->frequencia = auxiliar2->frequencia;
            zera_string (auxiliar->palavra, TAMP);
            strcpy(auxiliar->palavra, auxiliar2->palavra);

            /* Copiar do backup para o posterior */
            auxiliar2->frequencia = temp->frequencia;
            zera_string (auxiliar2->palavra, TAMP);
            strcpy(auxiliar2->palavra, temp->palavra);

            /* Guardar a realização da troca */
            troca = 1;
        }

        /* Atribuicoes para percorrer a Lista */
        auxiliar = auxiliar->proximo;
        auxiliar2 = auxiliar->proximo;
    }

    /* Havendo troca, chama a função de novo, até que não haja mais troca de informações */
    if (troca == 1){
        ordena_lista(lista);
    }
}

/* 15 - Função zera_string, inicializa a string com '\0' em todos os elementos */
void zera_string (char *palavra, int tamanho){
    /* 'indice' armazena o indice do vetor */
    int indice;

    /* Inicializar a string como NULL */
	for(indice = 0 ; indice < tamanho; indice++)
		*(palavra+indice) = '\0';
}
