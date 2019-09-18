/*****************************************************************
**      Inclusão das bibliotecas
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "../Bibliotecas/Arquivos.hpp"
#include "../Bibliotecas/Rede.hpp"

int main (){
    Rede* rede = rede_cria();
    rede = arq_ler(rede);

    printf("Tempo total da simulacao: Simulacao ainda nao iniciada\n");
    printf("Custo total da simulacao: %d\n", rede->in_ger->custo);
    printf("Total de geradores: %d\n", rede->in_ger->qnt);
    printf("Energia total gerada: %d\n", rede->in_ger->rec);
    printf("Total de cidades: %d\n", rede->in_city->qnt);
    printf("Tamanho total das interconexoes: %d km\n", rede->in_conex->tam_tot);


    /*adaptador_imprime(rede->in_adap->inicio);
    gerador_imprime(rede->in_ger->inicio);
    cidade_imprime(rede->in_city->inicio);
    interconex_imprime(rede->in_conex->inic);
    pos_imprime (rede->inicio);*/

    return 0;
}
