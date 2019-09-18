/*  Biblioteca dinamica e estaticas requisitadas para a simulacao */
#include <stdio.h>
#include <stdlib.h>
#include "Eventos.h"

/*  Estrutura de Dados - Turma E - 116319;
**  Professor:  Díbio Leandro Borges;
**  Projeto 2:  SIMULACAO DE CONTROLE DE AEROPORTO DE GRANDE PORTE;
**  Autores:    Lucas Nascimento Santos Souza - 140151010;
                Rodrigo Ferreira Guimarães - 140170740;
**  Data de início: 11/04/2015;
**  Data da última modificação: 18/04/2015;
**  Finalidade: Gerenciar o uso das 3 pistas, sendo uma reservada apenas a emergencia, de um aeroporto
**  de grande porte a partir do numero de aproximacoes e decolagens, escolhidos de forma randomica,
**  atendendo ao maximo de requisicoes, quando nao for possivel redirecionar a outro aeroporto, e gerar
**  um documento com os acontecimentos da simulacao para futuras consultas;
**  História da solução: a implementação do código foi realizada seguindo o roteiro do projeto, onde
**  funções foram sendo criadas com o objetivo de suprir as necessidades encontradas para obter o
**  resultado desejado na finalizacao da simulacao;
**  Fontes: slides disponibilizados no moodle da disciplina, notas de aula;
**  Projeto implementado usando o Code::Blocks IDE
**  Lista de saidas por erros ocasionais:
        * Exit (-1): Erro associado ao Aviao
        * Exit (-2): Erro associado a fila Aproximacao
        * Exit (-3): Erro associado a fila Decolagem
        * Exit (-4): Erro associado as Pistas
        * Exit (-5): Erro associado ao Aeroporto
        * Exit (-6): Erro associado a Strings
        * Exit (-7): Erro associado a Arquivo */


int main () {
    /* 'aero' armazena o Aeroporto e, consequentemente, todas as informacoes
    ** uteis para o mesmo; 'resposta' armazena a resposta sobre o progresso
    ** da simulacao; 'condpara' armazena o status para continuar ciclo de
    ** simulacao, 83 = 'S' ou 78 = 'N'; 'ind' armazena o indice da pista a ser
    ** manipulada na ciclo; 'arq' armazena o ponteiro do documento a ser
    ** manipulado para a simulacao */
    Aeroporto *aero = cria_aero ();
    char resposta, condpara = 83;
    int ind;
    FILE *arq = fopen ("Simulacao Aeroporto_Lucas e Rodrigo.txt", "a");

    /* Teste de Alocacao */
    if (arq == NULL){
        printf ("FALHA AO ABRIR ARQUIVO");
        exit (-8);
    }

    /* Semente para geracao aleatoria de dados */
    srand(time(NULL));

    /* Confirmacao para inicio da simulacao */
    printf ("Deseja iniciar a simulacao? s/n ou S/N\n");
    resposta = ler_resposta ();

    /* Tendo retorno positivo, comeca simulacao */
    if (resposta == 'S' || resposta == 's'){
        /* Geracao do numero teorico de voos suportados pelo Aeroporto,
        ** independente da hora de simulacao em questao */
        aero->voos = gera_aleatorio (0, 42);

        /* Tendo retorno positivo, continua simulacao */
        while (resposta == 'S' || resposta == 's'){
            /* Inicializa as variaveis do aeroporto para a proxima hora
            ** de simulacao, assim como as exibi na tela */
            inicia_simu (aero);
            system("clear");
            imprime_aero (aero);
            imprime_aero_arq (arq, aero);
            aero->ciclo = 0;
            printf ("\nPressione ENTER para continuar\n");
            getchar (); getchar ();

            /* Simulacao do Aeroporto para a proxima 1 hora, ou seja, 12 ciclos de 5 minutos
            ** cada ou enquanto houver fila de aproximacao e/ou decolagem, caso alguma ou
            ** ambas forem criadas */
            while (aero->ciclo < 12 && ((aero->filaap->inicio != NULL && aero->filaap->quant != 0)
                    || (aero->filade->inicio != NULL && aero->filade->quant != 0))){
                /* Ocupacao de todas as pistas disponiveis e talvez a de emergencia,
                ** quando algum voo for caracterizado como tal, alem disso redicionar
                ** os voos com emergencia em caso de todas as pistas possiveis ocupadas,
                ** para os proximos 5 minutos, ou seja, 1 ciclo */
                printf ("Inicio do ciclo %d\n", aero->ciclo + 1);
                fprintf (arq, "Inicio do ciclo %d\n", aero->ciclo + 1);
                do{

                    /* Verificacao de pista vazia */
                    for (ind = 0; ind < TAMs; ind++){
                        if(verifica_pista(aero->pista + ind) == 0) break;
                    }

                    /* Controle de acoes do Aeroporto: aterrisa, decola ou rediciona voo */
                    /* Tendo as pistas 0 ou 1 livres */
                    if (ind < (TAMs - 1)){
                        /* Nao havendo fila de aproximacao ou havendo, mas com o nivel de combustivel
                        ** acima do desejavel e tendo pedido de decolagem: decola voo */
                        if ((aero->filaap->inicio == NULL) ||
                            (aero->filaap->inicio->comb > 2 && aero->filade->quant != 0 && aero->filade->inicio != NULL))
                            decola_aero (aero, ind);

                        /* Nao havendo fila de decolagem ou havendo, mas tendo situacao de emergencia
                        ** para pouso: aterrissa voo */
                        else if ((((aero->filade->inicio == NULL) || (aero->filade->quant == 0)) && (aero->filaap->quant > 0))
                                 || (aero->filaap->inicio != NULL && aero->filaap->inicio->comb <= 2))
                            aterrissa_aero (aero, ind);

                    }

                    /* Teste a pista 2, para emergencias, livre */
                    else if (ind == (TAMs - 1)){
                        /* Verificar existencia de emergencia para pouso */
                        if ((aero->filaap->inicio != NULL) && (aero->filaap->inicio->comb <= 2))
                            aterrissa_aero (aero, ind);

                    }

                    /* Nao havendo pista, verificar condicao de emergencia */
                    else if (ind == TAMs){
                        /* Havendo emergencia de aproximacao, redirecionar para outro aeroporto */
                        if (aero->filaap->inicio->comb <= 2)
                            aborta_voo (aero);
                    }

                    /* Nao existindo nem fila de decolagem nem de aproximacao ou havendo, mas tendo as pistas
                    ** regulamentares ocupadas e sem condicao de emergencia de aproximacao:
                    ** encerra ciclo */
                    if (((ind >= (TAMs - 1)) && (aero->filaap->inicio != NULL && aero->filaap->inicio->comb > 2))
                        || (ind >= (TAMs - 1) && aero->filaap->inicio == NULL)
                        || (aero->filaap->inicio == NULL && aero->filade->inicio == NULL)
                        || (aero->filaap->quant == 0 && aero->filade->quant == 0))
                        condpara = 78;

                }while (condpara == 83);

                /* Passagem do tempo */
                incre_tempo (aero->atual);

                /* Exibicao do que ocorreu */
                imprime_aero_arq (arq, aero);
                imprime_aero (aero);
                printf ("Fim do ciclo %d\n", aero->ciclo + 1);
                fprintf (arq, "Fim do ciclo %d\n", aero->ciclo + 1);
                printf ("\nPressione ENTER para continuar\n");
                getchar ();

                /* Libera os voos armazenados as pistas, liberando da responsabilidade do Aeroporto os que foram
                ** decolagem ou acrescentando na fila de decolagem os que foram pouso */
                for (ind = 0; ind < TAMs; ind++){
                    inicia_pista (aero, aero->pista + ind);
                }

                /* Contagem dos ciclos */
                aero->ciclo++;

                /* Consumo do combustivel das aeronaves */
                aproxima_aero (aero);

                /* Restart 'condpara' */
                condpara = 83;

            };

            /* Verificacao de existencia de condicao adversa para parada do laco */
            /* Por nao haver nenhuma pista */
            if (aero->filaap->quant == 0 && aero->filade->quant == 0){
                printf ("\nAcabaram os pedidos de aproximacao e decolagem\n");
                fprintf (arq, "\nAcabaram os pedidos de aproximacao e decolagem\n");
            }
            else if (aero->ciclo >= 12){
                printf ("\nAcabou hora de simulacao\n");
                fprintf (arq, "\nAcabou hora de simulacao\n");
            }

        /* Ao final da simulacao, questiona sobre a continuacao da mesma */
        printf ("\nDeseja continuar a simulacao? s/n ou S/N\n");
        resposta = ler_resposta ();

        };

    }

    /* Liberacao do Aeroporto e Mensagem de encerramento da simulacao */
    libera_aero (aero);
    printf ("\nFim da Simulacao! Volte Sempre!\n");
    fprintf (arq, "\nFim da Simulacao! Volte Sempre!\n");
    fclose (arq);

    return 0;
}
