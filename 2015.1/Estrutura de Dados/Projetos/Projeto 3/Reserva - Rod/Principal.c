/*  Biblioteca dinamica e estaticas requisitadas para a simulacao */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes.h"
#define T 70000

/*  Estrutura de Dados - Turma E - 116319;
**  Professor:  Díbio Leandro Borges;
**  Projeto 3:  Jogo Caminho com Numeros Primos;
**  Autores:    Lucas Nascimento Santos Souza - 140151010;
                Rodrigo Ferreira Guimarães - 140170740;
**  Data de início: 30/04/2015;
**  Data da última modificação: 10/05/2015;
**  Finalidade: Desenvolver um algoritmo capaz de resolver um jogo de tabuleiro,
    que visa preencher em tabuleiro quadrado, com lado de tamanho N, apenas com
    numeros primos, sendo do 1º a (N^2)º;
**  Fontes: slides disponibilizados no moodle da disciplina, notas de aula,
    http://www.ime.usp.br/~pf/algoritmos/aulas/bubi.html,
    http://iris.sel.eesc.usp.br/sel886/Aula_1.pdf;
**  Projeto implementado usando o Code::Blocks IDE */

int main (){
    /*  'ponto' armazena as coordenadas e o valor do menor numero primo fornecido
    **  pelo usuario; 'primos' armazena os (tam^2) numeros primos que deverao ser
    **  utilizados para exito do jogo, e seus status em relacao a 4-vizinhaca;
    **  'tabu' armazena o tabuleiro a ser realizado o jogo, assim como as informacoes
    **  importantes sobre o mesmo; 'hist' armazena o historico de jogadas; 'tempo'
    **  armazena o tempo entre exibicoes da resolucao do jogo, caso exista; 'posiprimo'
    **  armazena a posicao do menor numero primo inicalizado em relacao a 'primos'; 'jogo'
    **  armazena o status para a realizacao ou nao do jogo em si; 'comeco' armazena
    **  a preferencia pelo tipo de inicio do jogo */
    Ponto ponto;
    Primo *primos;
    Tabuleiro tabu;
    Historico *hist = cria_historico ();
    float tempo;
    int posiprimo, contador = 0, escolha, opcao;
    char jogo, comeco, ant = 'S', post = 'S';

    /*  Apresentacao das Regras e Questionamento sobre Comeco do Jogo */
    jogo = inicio_geral ();

    /*  Havendo retorno positivo */
    if (jogo == 's' || jogo == 'S'){

        comeco = inicio_real;

        switch (comeco){
            case 1:
                /*  Leitura do arquivo e obtencao das informacaoes */
                tabu = leitura_arquivo ();

                /*  Inicializacao automatica de 'primos' */
                primos = inicia_primos (tabu.tam);

                /*  Impressao do tabuleiro inicial */
                imprime_tabu(&tabu);
                break;

            case 2:
                /*  Questionamento sobre o tamanho do lado do tabuleiro */
                tabu.tam = pergunta_tam ();

                /*  Inicializacao automatica de 'primos' */
                primos = inicia_primos (tabu.tam);

                /*  Inicializacao "manual" do tabuleiro */
                inicia_tabu (primos, &tabu);
                break;

        }

        /*  Determinacao do menor numero primo informado pelo usuario */
        jogo = menor_tabu (&ponto, primos, &tabu);

        if (jogo == 'S'){
            /*  Determinacao da posicao do menor numero primo informado pelo
            **  em relacao a 'primos' */
            posiprimo = localiza_primo (primos, -1, pow(tabu.tam,2), ponto.valor);

            /*  Preenchimento do tabuleiro */
            do{
                /* Ate o primeiro numero primo valido: 2 */
                ant = resolve_ant (hist, &tabu, primos, posiprimo, posiprimo, ponto.linha, ponto.coluna, &contador, post);

                /* Ate o (tam^2)-esimo primo valido */
                post = resolve_post (hist, &tabu, primos, posiprimo, posiprimo, ponto.linha, ponto.coluna, &contador);

                if(contador > T){
                    printf ("\nENTRADA FORNECIDA NAO POSSUI SOLUCAO\n");
                    printf ("\tPor exceder o numero de tentativas %d\n\tde se obter uma solucao\n", T);
                }

            }while (ant != 'S' || post != 'S');


            if (contador < T){
                tempo = questiona_impressao(&contador, &opcao);

                if (opcao == 1){
                    zera_tabu (&tabu, primos);
                    imprime_pausa (&tabu, hist, tempo);

                }else if (opcao == 2){
                    system("clear");
                    imprime_tabu(&tabu);

                }else if (opcao == 3){
                    zera_tabu (&tabu, primos);
                    imprime_enter (&tabu, hist, tempo);
                }
                pausa ();
            }

        }else{
            printf ("\nENTRADA FORNECIDA NAO POSSUI SOLUCAO\n");
            printf ("\tPor distancia entre numeros primos incompativel com a\n\treal distancia entre eles\n");
        }

        /* Liberacao do espaco alocado para 'primos' e o tabuleiro */
        libera_primos (primos);
        libera_tabuleiro (&tabu);
        hist = libera_elementos (hist);
    }

    /*  Mensagem de Fim de Jogo */
    printf ("\nFinal do jogo! Volte novamente\n");

    libera_historico (hist);
	return 0;
}
