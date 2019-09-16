/*****************************************************************
**      Inclusão das bibliotecas
*****************************************************************/

#include "../Bibliotecas/Rede.hpp"

/*****************************************************************
**      Definição das Funções
*****************************************************************/

/* Cria uma estrutura de rede */
Rede * rede_cria (){
    Rede *novo = NULL;

    do{
        novo = (Rede *) malloc (sizeof(Rede));
    }while (novo == NULL);
    /* Inicia todos os cabeçalhos das listas */
    novo->in_ger = (Header_ger*) malloc(sizeof(Header_ger));
    novo->in_city = (Header_city*) malloc(sizeof(Header_city));
    novo->in_adap = (Header_adap*) malloc(sizeof(Header_adap));
    novo->in_conex = (Cabecalho_conex*) malloc(sizeof(Cabecalho_conex));

    /* Inicia todas as variávies necessárias */
    novo->in_adap = adaptador_inicio (novo->in_adap);
    novo->in_city = cidade_inicio (novo->in_city);
    novo->in_conex = interconex_inicio(novo->in_conex);
    novo->in_ger = gerador_inicio(novo->in_ger);

    novo->in_conex->tam_tot = 0;


    return novo;
}

/* Desaloca o espaço de memoria de uma estrutura de rede */
void rede_libera (Rede *rede){
    if (rede != NULL){
        //ger_
    }
}

/* Inicializa a estrutura de cabeçalho da lista de adaptadores */
Header_adap* adaptador_inicio (Header_adap* estrutura){
    estrutura->inicio = NULL;
    estrutura->qnt = 0;

    return estrutura;
}

/* Inicializa a estrutura de cabeçalho da lista de cidades */
Header_city* cidade_inicio (Header_city* estrutura){
    estrutura->inicio = NULL;
    estrutura->ct_insuf = 0;
    estrutura->menos_30_recurso = 0;
    estrutura->qnt = 0;
    estrutura->rec = 0;
    estrutura->t_m_30_rec = 0;
    estrutura->t_s_recurso = 0;

    return estrutura;
}

/* Inicializa a estrutura de cabeçalho da lista de geradores */
Header_ger* gerador_inicio (Header_ger* estrutura){
    estrutura->inicio = NULL;
    estrutura->custo = 0;
    estrutura->qnt = 0;
    estrutura->rec = 0;

    return estrutura;
}

/* Inicializa a estrutura de cabeçalho da lista de interconexoes */
Cabecalho_conex* interconex_inicio (Cabecalho_conex* estrutura){
    estrutura->inic = NULL;
    estrutura->tam_tot = 0;
    estrutura->temp_tot_falha = 0;

    return estrutura;
}
