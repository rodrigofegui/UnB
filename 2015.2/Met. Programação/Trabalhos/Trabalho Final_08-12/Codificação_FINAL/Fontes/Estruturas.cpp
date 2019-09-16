/*****************************************************************
**      Inclusão das bibliotecas
*****************************************************************/
    #include "../Bibliotecas/Estruturas.hpp"
    #include <stdio.h>
    #include <stdlib.h>

/*****************************************************************
**      Definição das Funções
*****************************************************************/

void adaptador_imprime (Adaptador* lista){
    Adaptador* p;
    printf("\n Lista de adaptadores: \n");
    for(p = lista; p != NULL; p= p->prox){
        printf("Nome: %s\n", p->nome);
        printf("pos_x: %d\n",p->lin_i);
        printf("pos_y: %d\n",p->col_i);
    }
}

void gerador_imprime (Gerador* lista){
    Gerador *p;
    printf("\n Lista de geradores: \n");
    for(p = lista; p != NULL; p= p->prox){
        printf("Nome: %s\n", p->nome);
        printf("pos_x: %d\n",p->lin_i);
        printf("pos_y: %d\n",p->col_i);
        printf("Recurso produzido: %d\n",p->rec);
        printf("Custo de producao: %d\n",p->custo);
    }
}

void cidade_imprime (City* lista){
    City* p;
    printf("\n Lista de cidades: \n");
    for(p = lista; p != NULL; p= p->prox){
        printf("Nome: %s\n", p->nome);
        printf("pos_x: %d\n",p->lin_i);
        printf("pos_y: %d\n",p->col_i);
        printf("Recurso necessário: %d\n",p->rec);
    }
}

void interconex_imprime (Conexao* lista){
    Conexao* p;
    printf("\n Lista de interconexoes: \n");
    for(p = lista; p != NULL; p= p->prox_i){
        printf("Nome: %s\n", p->nome);
        printf("pos_inic_x: %d\n",p->lin_i);
        printf("pos_inic_y: %d\n",p->col_i);
        printf("pos_final_x: %d\n",p->lin_f);
        printf("pos_final_y: %d\n",p->col_f);
        printf("Capacidade maxima: %d\n",p->cpc);
        printf("Custo de manutencao: %d\n",p->custo);
        printf("Chance de falha: %f\n",p->prob_falha);
    }
}

void pos_imprime (Posicoes* lista){
    Posicoes* p;
    printf("\n Lista de posicoes: \n");
    for(p = lista; p != NULL; p= p->prox){
        printf("Tipo: %c\n", p->tipo);
        printf("pos_x: %d\n", p->x);
        printf("pos_y: %d\n", p->y);
        if (p->tipo == 'G')
            printf("Nome: %s\n", p->gera->nome);
        else if (p->tipo == 'C')
            printf("Nome: %s\n", p->cid->nome);
        else if (p->tipo == 'A')
            printf("Nome: %s\n", p->adapt->nome);
    }
}

int pitagoras (Info info){
    return sqrt( pow( (info.lin_f-info.lin_i) ,2) + pow( (info.col_f-info.col_i) ,2) );
}




