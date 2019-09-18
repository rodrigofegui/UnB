#include <stdlib.h>
#include <stdio.h>
#include "Arquivo.h"

/*  Estrutura de Dados - Turma E - 116319;
**  Professor:  Díbio Leandro Borges;
**  Projeto 1:  SEMELHANÇA ENTRE DOCUMENTOS;
**  Autores:    Lucas Nascimento Santos Souza - 140151010;
                Rodrigo Ferreira Guimarães - 140170740;
**  Data de início: 19/03/2015;
**  Data da última modificação: 29/03/2015;
**  Finalidade: Calcular a semelhança entre 10 arquivos .txt fornecidos, onde ocorre a comparação de
**  dois em dois arquivos, gerando um arquivo com as palavras em comum, frequências destas e o valor
**  de semelhança, concluindo assim, se o plágio ocorreu ou não;
**  História da solução: a implementação do código foi realizada seguindo o roteiro do projeto, onde
**  funções foram sendo criadas com o objetivo de suprir as necessidades encontradas para obter o
**  resultado desejado na finalizacao do projeto;
**  Fontes: slides disponibilizados no moodle da disciplina, notas de aula e o site com endereco:
**  <http://pt.kioskea.net/faq/10263-listas-simplesmente-encadeadas>;
**  Projeto implementado usando o Code::Blocks IDE.
 */


int main(){
    /* 'lista' armazena a lista de cada documento a ser analisado;
    ** 'result' armazena a lista resultado da comparacao de dois
    ** documentos; 'nome' armazena os nomes dos arquivos a serem
    ** analisados; 'indice' e 'indice2' realizam o controle dos
    ** arquivos a serem analizados; 'percent' armazena a porcentagem
    ** dos arquivos analisado; 'magnitude' armazena a magnitude de
    ** cada arquivo manipulado para analise */
    Lista *lista = cria_lista ();
    Resultado *resultado = cria_resultado ();
    Arquivo nome[QUANT];
    char num[2];
    int indice, indice2, m_projecao = 0;
    float percent, magnitude[QUANT], teta = 0.0;

    printf ("Comparacao entre %d documentos!\n", QUANT);

    /* Armazenar o nome dos arquivos */
    for (indice = 0; indice < QUANT; indice++){
        zera_string (nome[indice].arquivo, TAMT);
        nome_arquivo (nome[indice].arquivo, indice+1);
    }

    /* Levantamento das informacoes dos arquivos */
    for (indice = 0; indice < QUANT; indice++){

        lista = ler_arquivos (lista, nome[indice].arquivo);

        ordena_lista (lista);

        magnitude[indice] = magnitude_doc (lista);

        escreve_arq_lista (lista, nome[indice].arquivo);

        lista = libera_elementos (lista);

        percent = (float) ((indice + 1) * 100.0)/QUANT;
        system ("clear");
        printf ("%.2f%% Concluido de %d arquivos!\n", percent, QUANT);
        printf ("Aperte ENTER para continuar o levantamento de informacoes.\n");
        getchar ();

    }

    libera_lista (lista);

    /* Comparacao entre os Documentos */
    for (indice = 0; indice < QUANT; indice++){
        for (indice2 = indice+1; indice2 < QUANT; indice2++){
            teta = 0.0;

            m_projecao = 0;

            ler_arquivos_resumo (resultado, nome[indice].arquivo, nome[indice2].arquivo);

            if (resultado->comeco != NULL){
                m_projecao = metrica_projecao (resultado);

                teta = metrica_angulo (m_projecao, magnitude[indice], magnitude[indice2]);

            }

            escreve_arq_resultado (resultado, nome[indice].arquivo, nome[indice2].arquivo,
                                magnitude[indice], magnitude[indice2], teta);

            resultado = libera_campos(resultado);
        }

    }

    libera_resultado (resultado);

    return 0;
}
