/*****************************************************************
**      Inclusão das bibliotecas
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include "../Bibliotecas/Arquivos.hpp"
#include "../Bibliotecas/Rede.hpp"
#include "../Bibliotecas/Interconexao.hpp"

int main (){
	time_t t_inic, t_fim;
    float num;

    int tempo = 0, tempomax;/*! Pode ser mudado para float. Esta como int para faciliatr a simulacao inicial*/
    int tam_con,ind;

    float *probs;

    Rede* rede = rede_cria();
    rede = arq_ler(rede);

   // pos_imprime (rede->inicio);
    tam_con = rede->in_conex->total;
    probs = (float *)calloc(tam_con,sizeof(float));
    if(rede!=NULL){
        rede->in_conex->total_falhas =0;
    }
    Monta_rede(rede,rede->in_conex->inic,rede->inicio);
    srand(1); //so é executado uma vez na simulacao
    printf("Digite o tempo que deseja que a simulacao dure: ");
    scanf("%d",&tempomax);
    printf("\n");
    printf("Simulacao iniciada!\n");
    printf("**********************************\n");
    printf("Maximize sua janela!!!!!\n");
    printf("**********************************\n");

    getchar();


    while(tempo < tempomax){
		time (&t_inic);        
		for(ind=0;ind<tam_con;ind++){
            num =  ((float)rand()/RAND_MAX);
            probs[ind]= num;
        }
        printf("\nMomento da execucao: %d\n\n", tempo);
        verifica_rede(rede,tempo,probs);
        interface_cria(rede);
        reinicia_status(rede->in_conex->inic);
		do{
			time (&t_fim);
		}while (difftime(t_fim, t_inic) < 1.0);
		
		tempo++;
    }





    printf("Tempo total da simulacao: %d segundos\n", tempo);
    printf("Custo total da simulacao: %d\n", rede->in_ger->custo);
    printf("Total de geradores: %d\n", rede->in_ger->qnt);
    printf("Energia total gerada: %d\n", (int)((rede->in_ger->rec)*tempo));
    printf("Total de cidades: %d\n", rede->in_city->qnt);
    printf("Tamanho total das interconexoes: %d km\n", rede->in_conex->tam_tot);
    getchar();
    /*adaptador_imprime(rede->in_adap->inicio);
    gerador_imprime(rede->in_ger->inicio);
    cidade_imprime(rede->in_city->inicio);
    interconex_imprime(rede->in_conex->inic);
    pos_imprime (rede->inicio);*/

    return 0;
}
