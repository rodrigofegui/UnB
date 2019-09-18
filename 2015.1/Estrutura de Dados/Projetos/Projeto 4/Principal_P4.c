/*  Biblioteca dinamica e estaticas requisitadas para o projeto */
#include <stdio.h>
#include <stdlib.h>
#include "Funcoes_P4.h"

/*  Estrutura de Dados - Turma E - 116319;
**  Professor:  Díbio Leandro Borges;
**  Projeto 4:  OTIMIZACAO DE HASHING;
**  Autores:    Lucas Nascimento Santos Souza - 140151010;
                Rodrigo Ferreira Guimarães - 140170740;
**  Data de início: 16/05/2015;
**  Data da última modificação: 23/05/2015;
**  Finalidade: o projeto visa realizar a otimizacao no numero de colisoes através do
**  desenvolvimento de uma funcao hashing;
**  Fontes: slides disponibilizados no moodle da disciplina, notas de aula;
**  Projeto implementado usando o Code::Blocks IDE */

int main (){
    /*  'arq' armazena o vetor de documento a serem avaliados no processamento; 'tabela' armazena a
    **  tabela hashing e suas respectivas estatisticas; 'lista' armazena a lista de palavras distintas
    **  lidas nos documentos requisitados; 'projeto' armazena o status para progresso do mesmo; 'indice'
    **  armazena o indice a a ser manipulado; 'tamanho' armazena o quantidade de documentos a serem avaliados
    **  'minimo' armazena o menor tamanho de documento registrados dentre os fornecidos */
    Arquivos *arq;
    Hashing *tabela;
    Lista *lista;
    char projeto, procura;
    int indice, tamanho, minimo = 99999999;

    /*  Da as boas vindas ao projeto */
    hello();

    /*  Apresentacao do projeto e questionamento sobre o progresso do mesmo */
    projeto = inicio_geral();

    /*  Tendo retorno positivo */
    while (projeto == 's' || projeto == 'S'){
        /*	Alocacao da lista de palavras para o processamento */
		lista = cria_lista (1);

		/*  Questionamento da quantidade de documentos a serem avaliados */
        tamanho = questiona_tam ();

        /*  Criacao do vetor de documentos */
        arq = cria_arq (tamanho);

        /*  Leitura do nome dos documentos a serem avaliados, assim como a avaliacao dos mesmos e a determinacao
        **  do menor tamanho de documento */
        for (indice = 0; indice < tamanho; indice++){
            arq[indice].nome = ler_nome_doc (indice+1, tamanho, 'l');
            arq[indice].tamanho = le_arquivo (lista, arq[indice].nome);
            if (arq[indice].tamanho < minimo)
                minimo = arq[indice].tamanho;
        }

        /*  Exibicao dos dados importatantes dos documentos */
        exibe_arq (arq, tamanho);

        /*  Criacao e configuracao da tabela hashing */
        tabela = cria_hash (minimo);
        tabela->indice = monta_hash (arq, tabela, lista, minimo, tamanho);

        /*  Exibicao na tela e escrita num documento a tabela hashing e suas estatisticas */
        exibe_hash (tabela, tamanho);
        escreve_result (arq, tabela, tamanho);

        pausa ();

        /*  Questionamento da vontade de procura */
        procura = questiona_procura ();

        /*  Enquanto houver interesse pela procura de uma palavra */
        while (procura == 'S' || procura == 's'){
            printf ("\nEntao, digite a palavra que deseja procurar:\n");
            localiza_palavra (tabela, ler_palavra());

            printf ("\nDeseja procurar outra palavra? S/N ou s/n\n");
            procura = ler_simounao ();

        };

        /*  Questionamento sobre o progresso do projeto */
        printf ("\n\nDeseja reiniciar o processamento, com novos documentos? S/N ou s/n\n");
        projeto = ler_simounao();

        /*  Liberacao das variaveis */
        libera_arq (arq);
        libera_hash (tabela);
        libera_lista (lista, 1);
    };

    printf ("Fim do processamento! Volte sempre!\n");
    printf ("Pressione Ctrl+C para sair!\n");

    return 0;
}

