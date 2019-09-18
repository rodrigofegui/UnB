/*  Biblioteca requisitadas para o projeto */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes_P6.h"

/*  Estrutura de Dados - Turma E - 116319;
**  Professor:  Díbio Leandro Borges;
**  Projeto 6:  ROTEIRO DE VIAGEM;
**  Autores:    Lucas Nascimento Santos Souza - 140151010;
                Rodrigo Ferreira Guimarães - 140170740;
**  Data de início: 25/06/2015;
**  Data da última modificação: 28/06/2015;
**  Finalidade: o projeto visa realizar a construcao de rotas a serem seguidas
	pelos viajantes, a fim de realizar a visita a todos os amigos nas cidades
	fornecidas, uma vez que as rotas formadas devem ser as que possuem menor
	distancia total de viagem;
**  Fontes: slides disponibilizados no moodle da disciplina, notas de aula,
	documentos explicando conceitos sobre manuseios para determinacao de
	caminhos sob grafos;
**  Projeto implementado usando o Code::Blocks IDE */

int main (){
    /*  'graph' armazena o grafo a ser montado com as ligacoes entre as cidades;
    **  'travel' armazena os roteiros de viagem formados sob o grafo; 'processo'
    **  armazena o status para realizacao do projeto */
    Grafo *graph = NULL;
    Roteiro travel[MAXC];
    char processo;

    /*  Boas-vindas */
    hello ();

    /*  Questionamento sobre o status para realizacao do projeto */
    processo = inicio_geral ();

    /*  Tendo retorno positivo */
    if ((processo == 's') || (processo == 'S')){
        /*  Criacao do grafo */
        graph = cria_grafo ();

        /*  Construcao do grafo com a leitura do documento-fonte */
        ler_fonte (graph);

        /*  Inicializacao dos roteiros */
        inicia_roteiro (graph, travel);

        /*  Construcao dos roteiros de viagem */
        for (processo = 65; processo < MAXC + 65; processo++){
            graph->livres = graph->quant;
            monta_roteiros (graph, &travel[processo - 65], travel[processo - 65].inicio->nome);
            zera_grafo (graph);
        }

        /*  Exibicao do grafo na tela */
        exibe_grafo (graph);

        /*  Exibicao do(s) roteiro(s) na tela */
        exibe_roteiro (travel);

        /*  Escrita dos dados no arquivo resultado */
        escreve_grafo (graph, travel);

        /*  Liberacao do espaco alocado para os roteiros e para o grafo */
        libera_roteiro (travel);
        libera_grafo (graph);

        printf ("\nFim do processamento!");
    }

    printf ("\nVolte Sempre!!\n\n");
    return 0;
}
