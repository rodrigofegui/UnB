/*  Biblioteca requisitadas para o projeto */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes_P5.h"

/*  Estrutura de Dados - Turma E - 116319;
**  Professor:  Díbio Leandro Borges;
**  Projeto 5:  PAGERANK DE PAGINAS WEB;
**  Autores:    Lucas Nascimento Santos Souza - 140151010;
                Rodrigo Ferreira Guimarães - 140170740;
**  Data de início: 08/05/2015;
**  Data da última modificação: --/06/2015;
**  Finalidade: o projeto visa realizar o ranqueamento de paginas web atraves do
**  PageRank desenvolvido pela Google para sua maquina de busca;
**  Fontes: slides disponibilizados no moodle da disciplina, notas de aula,
**  documentos explicando o processo de pagerank;
**  Projeto implementado usando o Code::Blocks IDE */

int main (){
    Grafo *grafo;
    Pagina *aux;
    char inicio;
    int contador = 1;
    float percent = 0.0;

    /*  Boas vindas */
    //hello();

    /*  Apresentacao da proposta do projeto e questionamento sobre o
    **  inicio do mesmo */
    inicio = inicio_geral();

    /*  Havendo retorno positivo */
    if (inicio == 'S' || inicio == 's'){
        /*  Criacao do grafo, base do projeto */
        grafo = cria_grafo ();

        /*  Questiona o diretorio base do projeto */
        questiona_diretorio (grafo->dirbase);
        printf ("O diretorio de trabalho eh: '%s'", grafo->dirbase);
        temporizador (1.5);

        /*  Inicializacao dos nos do grafo */
        ler_allpages (grafo);

        printf ("\nA ler os codigos-fonte...");
        temporizador (0.8);

        for (aux = grafo->inicio; aux != NULL; aux = aux->proximo){
            limpa_tela ();
            ler_codfontes (grafo, aux);
            percent += (100.0/grafo->quant);
            printf ("Leu o %dº de %d codigos-fonte, no caso:\n", contador, grafo->quant);
            printf ("'%s'\n", aux->dados.nome);
            printf ("%.2f%% concluidos\n", percent);
            contador++;
        }

        limpa_tela ();

        ranqueia_grafo (grafo);

        printf ("Ordenando... Aguarde...\n");
        ordena_grafo (grafo);

        exibe_grafo (grafo);

        exibe_top10 (grafo);

        printf("\nUm histograma baseado nos dados obtidos sera exibido a seguir!\n");
        histograma (grafo);

        escreve_grafo (grafo);

        libera_grafo (grafo);
        printf ("\nFim do processamento!");
    }

    printf ("\nVolte Sempre!!\n\n");

    return 0;
}
