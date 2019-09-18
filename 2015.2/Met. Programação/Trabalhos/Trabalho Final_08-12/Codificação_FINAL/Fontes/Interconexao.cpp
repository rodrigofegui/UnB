#include "../Bibliotecas/Estruturas.hpp"
#include "../Bibliotecas/Interconexao.hpp"
#include<stdio.h>
#include<stdlib.h>
/*! Funcao Monta_rede
Vai unir todas as structs para que a simulacao possa ser realizada
*/
/***********************************************************************************!
* Funcao: Montar a rede
* Descricao
*     Vai ligar todos os elementos da lista de interconexoes aos devidos elementos nas listas de
*     geradores, adaptadores ou cidades de acordo com as posicoes geograficas de cada um,
*     de acordo com o que foi fornecido no arquivo texto. Essas ligacoes serao feitas com o auxilio da
*     estrutura Posicao, que contem ponteiros para os elementos das listas de geradores, adaptadores e cidades,
*     a posicao geografica (x,y) e o tipo do elemento corrente. Para ver sua definicao, va para o arquivo
*     "Estruturas.hpp".
* Parametros
*     inicio - ponteiro para o primeiro elemento da lista de interconexoes
*     posi - ponteiro para o primeiro elemento da lista de posicoes
* Valor retornado
*     Funcao nao retorna valores
* Assertiva de entrada
*     inicio!=NULL
*     posi!=NULL

* Assertiva de saida
*     Se um desses elementos tem posicao (x,y) igual a posicao (x0,y0) igual a da interconexao,entao elemento
*     eh anterior.Se o elemento tem posicao (x,y) igual a posicao final da interconexao, entao elemento eh
*     conectado como proximo. Senao, interconexao esta isolada

 ***********************************************************************************/
void Monta_rede(Rede *rede, Conexao *inicio,Posicao* posi){
    char tipo;/*! < Tipo encontrado pela funcao que busca na Posicao * */
    Posicao *aux,*aux1;/*! < aux1 vai ajudar a ligar o anteior e proximo da interconexao de uma vez*/
    int local,local1,rep;/*!< rep vai permitir lincar o que esta conectado no incio e no fim da interconexao */
    while(inicio!=NULL){

        aux = busca_pos(inicio,posi,&local,&aux1,&local1);
        for(rep=1;rep<=2;rep++){
            if(aux!=NULL){/*!< se achou alguma equivalencia*/
                tipo = aux->tipo;
            }else if(rep==1 && aux1==NULL){/*!< Para nao repetir a informacao mostrada na tela*/
                printf("Interconexao %s isolada em (%d,%d)  \n",inicio->nome,inicio->lin_i,inicio->col_i);
                inicio->status =  isolada;/*! a interconexao nao faz nada mas foi visitada*/
                rede->in_conex->total_falhas +=1;
            }

            if(aux!=NULL){
                switch(tipo){
                    case 'G':
                        if(local==Anterior){
                            inicio->ant_g = aux->gera;
                            inicio->tipo_ant = tipo;

                        }else{
                            inicio->prox_g = aux->gera;
                            inicio->tipo_prox = tipo;
                        }
                        printf("Conexao %s ligada a gerador %s em (%d,%d)\n",inicio->nome,aux->gera->nome,aux->gera->lin_i,aux->gera->col_i);
                        break;
                    case 'A':
                    /*Tentar incluir tb as cidades. N estah incluindo geradores ou cids pq acha 1 o adapt e passa pra frente*/
                        if(local==Anterior){
                           inicio->ant_a = aux->adapt;
                           inicio->tipo_ant = tipo;
                            if(inicio->tipo_prox=='G'){/*!< Caso haja interconexao ligando geradores e adaptadores*/
                                aux->adapt->entrada = aux->adapt->entrada + menor(inicio->prox_g->rec,inicio->cpc);
                                inicio->status = n_verificada;//tem que ver se falhou na funcao de verificar
                                printf("Conexao %s ligada a gerador %s em (%d,%d)\n",inicio->nome,inicio->prox_g->nome,inicio->prox_g->lin_i,inicio->prox_g->col_i);
                            }
                        }else{
                           inicio->prox_a = aux->adapt;
                           inicio->tipo_prox = tipo;
                           if(inicio->tipo_ant=='G'){/*!< Caso haja interconexao ligando geradores e adaptadores*/
                                aux->adapt->entrada = aux->adapt->entrada + menor(inicio->ant_g->rec,inicio->cpc);
                                inicio->status = n_verificada;//tem que ver se falhou na funcao de verificar
                                printf("Conexao %s ligada a gerador %s em (%d,%d)\n",inicio->nome,inicio->ant_g->nome,inicio->ant_g->lin_i,inicio->ant_g->col_i);
                            }
                        }

                        printf("Conexao %s ligada a adaptador %s em (%d,%d)\n",inicio->nome,aux->adapt->nome,aux->adapt->lin_i,aux->adapt->col_i);

                        break;
                    case 'C':
                        if(local==Anterior){
                            inicio->ant_c = aux->cid;
                            inicio->tipo_ant = tipo;
                        }else{
                            inicio->prox_c = aux->cid;
                            inicio->tipo_prox = tipo;

                        }
                        printf("Conexao %s ligada a cidade %s em (%d,%d)\n",inicio->nome,aux->cid->nome,aux->cid->lin_i,aux->cid->col_i);

                }/*! <switch*/
            }/*!< if*/
            aux = aux1;
            local = local1;
        }/*!< for*/
        inicio = inicio->prox_i;
    }/*!<while*/
}/*!<Monta_rede */

/***********************************************************************************!
* Funcao: buscar posicao de equivalencia entre interconexao e elemento em Posicao
* Descricao
*   Busca se ha algum gerador, adaptador ou cidade ligado ao inicio da interconexao (anterior a ela)
*   e se algum deles se conecta na posicao final da interconexao (roximo dela). Ela procura por essas duas
*   posicoes a cada chamada.
* Parametros
*   atual - ponteiro para o inicio da lista de interconexoes
*   posi - ponteiro para o inicio da lista de posicoes
*   local - endereco de memoria do inteiro que guarda a informacao se o elemento esta na posicao Anterior
*   a interconexao.
*   aux1 - endereco de memoria de um ponteiro do tipo Posicao para que seja indicado qual o ponteiro do
*   elemento que esta na posicao Proximo em relacao a interconexao
*   local1 -  endereco de memoria do inteiro que guarda a informacao se o elemento esta na posicao Proximo
*   a interconexao.
* Valor retornado
*   Ponteiro do tipo Posicao que contem a localizacao do elemento na posicao Anterior em relacao a interconexao
* Assertiva de entrada
*   atual!= NULL
*   posi !=NULL
*   local !=NULL
*   aux1!=NULL
*   local1!=NULL
* Assertiva de saida
*   SE posicao inicial (xi,yi) de algum elemento de interconexao pertencente a lista de interconexoes ==
* posicao (x,y) de algum elemento da lista de posicoes ENTAO
*       Ponteiro retornado nao nulo
*   SENAO
*       Ponteiro retornado sera nulo
*   FIMSE
***********************************************************************************/
Posicao* busca_pos(Conexao* atual,Posicao* posi,int* local,Posicao** aux1,int* local1){
    int x_con_i,y_con_i,x_con_f,y_con_f;
    int x_pos,y_pos;
    Posicao *aux=NULL;
    *aux1 = NULL;
   while(posi!=NULL){
        x_con_i = atual->lin_i;
        y_con_i =atual->col_i;
        x_con_f =atual->lin_f;
        y_con_f =atual->col_f;
        x_pos = posi->x;
        y_pos= posi->y;
        if( (x_pos ==x_con_i )&& (y_pos==y_con_i ) ){/*! < a conexao sai do elemento*/
            *local =Anterior;/*! <sao posicoes relativas de insercao*/
            aux= posi;
        }else if( (x_pos ==x_con_f )&& (y_pos==y_con_f ) ){/*! < a conexao entra no elemento*/

            *local1 = Proximo;/*! <sao posicoes relativas de insercao*/
            *aux1= posi;
        }
        posi = posi->prox;
    }
	return aux;/*! <se nao achou nada*/
}

/***********************************************************************************
* Funcao: verificar falhas na rede
* Descricao
*    Procura se alguma interconexao falhou em algum momento da simulacao. Se isso ocorrer, ela recebe um
*    indicador de falha. Todas as interconexoes que falharam tem sua contribuicao de energia retirada ate
*    que a falha seja corrigida. A funcao tambem calcula quando a interconexao que falhou foi consertada,
*    baseado nas informcaoes de tempo de conserto presentes no arquivo texto fornecido,reitegrando-a
*    na lista de interconexoes a serem avalidas.Por fim,calcula os tempos que a interconexoes falharam,o
*    custo total de conserto e o numero de falhas nas interconexoes. No final
*    de sua execucao, a funcao percorre a lista de cidades para calcular os
*    tempos e quantidades de cidades que ficaram com menos recurso que o necessario.
* Parametros
*    inicio - ponteiro para o inicio da lista de interconexoes
*    tempo - inteiro que indica o tempo corrente (em segundos) desde o momento que a simulacao foi iniciada
* Valor retornado
*    Funcao nao retorna nenhum valor (parametro de saida como void)
* Assertiva de entrada
*    inicio != NULL
*    tempo>= 0
* Assertiva de saida
*    SE inicio != NULL && tempo>=0 ENTAO
*       o status da lista de conexao vai ser falhou, verficada ou isolada.
*    SENAO SE inicio == NULL ENTAO
*       status da lista de interconexoes nao muda
*    SENAO SE tempo<0 ENTAO
*       funcao pode se comportar de forma imprevisivel
*    FIMSE
*
*
*
*
***********************************************************************************/


void verifica_rede(Rede *rede,int tempo,float *probs){
/*! <Todos os conexao->tipo_ant e conexao->tipo_prox tem q ser incializados com o cogio 'N' */
    Conexao *inicio;
    int repeticao=0;/*! indica se a funcao ja passou pelo laco uma vez*/
    Conexao *aux;
    int delta_t,ind; //vai registrar a variacao do tempo decorrido entre a conexao que falhou e o tempo atual
    int verificacao = verificada;
    City *aux_cid;/*! Ponteiro para auxiliar a percorrer toda lista de ciades*/
    ind = rede->in_conex->total -1; //os indices vao de 0 ateh tamanho-1
    inicio = rede->in_conex->inic;
    aux =inicio;
    verifica_gerador(rede,probs,tempo);
    *(rede->in_city->menos_30_recurso) =-1;
    rede->in_city->ct_insuf=0;
	if(aux==NULL){
		printf("NULO\n");
	}
    while(aux!=NULL){
        /*! Se a interconexao esta com falha, duas coisas tem que ser verificadas:
            1-> se passou tempo suficiente para ela ser consertada desde o tempo que ela falhou;
            2-> se ela nao falhou novamente no momento em que foi consertada
            Se 1 && 2 ocorrerem ao mesmo tempo, entao a conexao deixa de falhar
        */
        if(aux->status==falhou){
            delta_t = tempo - aux->comeco;
            if( ( delta_t>= aux->temp) && !( (aux->prob_falha > 0) && (aux->prob_falha  >=probs[ind]) )  ){
                aux->status = n_verificada;
                printf("Interconexao %s foi consertada!\n",aux->nome);
                rede->in_conex->total_falhas -=1;
                rede->in_conex->custo_tot+= aux->custo;
            }
        }
		printf("Status: %d\n",aux->status);
        if( aux->status==n_verificada){/*! se ela estiver isolada, nao podemos fazer nada*/
            if ( (aux->prob_falha > 0) && (aux->prob_falha  >=probs[ind]) ){
                aux->status = falhou;
                aux->comeco = tempo;
                printf("Interconexao %s falhou!\n",aux->nome);
                rede->in_conex->total_falhas +=1;
            }else {/*!serve para o caso de os paramentros terem sido incializados
               de forma incorreta na funcao de insercao*/
                aux->status = verificada;
            }
			printf("Ant.: %c\n",aux->tipo_ant);
			printf("Prox.: %c\n",aux->tipo_prox);
            if(aux->tipo_ant=='A'){
                busca_adapt(rede,aux->ant_a,delta_t);/*!< Vai sempre procurar adapatdores da posicao atual para frente*/
            }else if(aux->tipo_prox=='A'){/*!< Vai sempre procurar adapatdores da posicao atual para frente*/
                busca_adapt(rede,aux->prox_a,delta_t);
            }else if( aux->tipo_ant!='C' && aux->tipo_prox !='C'){/*!< se a interconexao estiver isolada*/
                printf("Interconexao %s isolada em (%d,%d)  \n",aux->nome,aux->lin_i,aux->col_i);
                aux->status =  isolada;/*! a interconexao nao faz nd mas foi visitada*/
                rede->in_conex->total_falhas +=1;

            }
        }
        aux = aux->prox_i;

	ind--;
    }/*while*/
    /*! Depois de verificar as interconexoes, contamos os tempos que as cidades*/
    for(aux_cid = rede->in_city->inicio;aux_cid!=NULL;aux_cid= aux_cid->prox){
        if(aux_cid->t_s_rec >0){// Uma ciadade descoberta que nao teve energia suficiente
            rede->in_city->ct_insuf += 1;
			printf ("Cidades insuf = %d\n", rede->in_city->ct_insuf);
			pausa ();
            rede->in_city->t_s_recurso += aux_cid->t_s_rec;
            if(aux_cid->t_30_rec){
                rede->in_city->menos_30_recurso+=1;
                rede->in_city->t_m_30_rec += aux_cid->t_30_rec;
            }
        }
    }
}

/*! Funcao verifica se houve falha entre conexao que liga gerador a adaptador*/
/***********************************************************************************
* Funcao: verificar se conexoes que ligam geradores a adaptadores funcionam
* Descricao
*    Obtem e percorre a lista de interconexoes que saem de um gerador indicado pela conexao dele com
*    a lista de interconexoes e redistribui a enrgia contida em cada um para os adaptadores ligadas a ele
*    Verifica se ha geradores ligados diretamente a cidades (caso em que ha
*    falha) e verifica tambem se a interconexao falhou no dado momento de
*    execucao da simulacao
* Parametros
*   rede - ponteiro para todos os cabecalhos das estrutuas usadas
*   prob - vetor de floats com as probabilidades utilizadas no momento
*   tempo_atual - inteiro indicando qual o tempo corrente da execucao (em segundos)
* Valor retornado
*    Funcao nao retorna nenhum valor (parametro de saida como void)
* Assertivas de entrada
*    rede != NULL
*    prob != NULL
*    tempo_atual>=0
* Assertivas de saida
*    SE rede != NULL && prob != NULL ENTAO
*       SE tempo_atual>=0
*
*           os geradores e os adaptadores ligados terao a energia total que passa por eles computada e as interco-
*           nexoes ligadas ao adaptador analisado serao marcadas como verificadas se nao houve falha.
*           Para qualquer falha for detectada, a interconexao fica marcada como falhou e a energia
*           que vai dela para o adaptador se torna 0, atualizando o numero de interconexoes que falharam
*       SENAO
*           Todas as interconexoes sao tratadas como se foram consertadas naquele momento se a
*           o criterio de falha nao tiver sido detectado.
*       FIMSE
*    SENAO
*       Nada sera alterado
*    FIMSE
*
***********************************************************************************/

void verifica_gerador(Rede *rede,float* prob,int tempo_atual){/*requer todas as probabilidades de falha
previamente calculadas*/
    Conexao *inicio = rede->in_conex->inic;
    int tam = 1,ind,delta_t,rec_disp,menor_cor;
    Conexao **aux=NULL;
    ind = rede->in_conex->total -1; //os indices vao de 0 ateh tamanho-1
    while(inicio!=NULL){
		printf("Status_ger: %d\n",inicio->status);
        if( (inicio->status==n_verificada || inicio->status==falhou ) && (inicio->tipo_ant=='G' || inicio->tipo_prox == 'G') ){
            aux = (Conexao**)realloc(aux,tam*(sizeof( Conexao*) ) );
            if(aux!=NULL){//testa se a alocacao falhou
                aux[tam-1] = inicio;
                if (inicio->status==n_verificada && ( (inicio->prob_falha > 0) && (inicio->prob_falha >= prob[ind] ) ) ){
                    //falhou
					printf ("Interconexao %s falhou huhu\n",inicio->nome);
                    inicio->status == falhou;
                    rede->in_conex->total_falhas +=1;
                }else {//ja estava classificada como falha
                    delta_t = tempo_atual - inicio->temp;
                    if( ( delta_t>= inicio->temp) && !( (inicio->prob_falha > 0) && (inicio->prob_falha  >=prob[ind]) )  ){
                        inicio->status = verificada;
                        printf("Interconexao %s foi consertada!\n",inicio->nome);
                        rede->in_conex->total_falhas -=1;
                        rede->in_conex->custo_tot+= inicio->custo;
                    }
                }

                tam++;
            }
        }
        inicio = inicio->prox_i;
        ind--;
    }
    tam--;
    for(ind = 0;ind<tam-1 && aux!=NULL;ind++){

        /*!< Estas condicionais abaixo vao porcurar o elemento ao qual o gerador esta ligado */
        /*3 sao os casos que podem ocorrer?
             1- Se o status do elemento eh igual a n_verificada, entao a interconexao nao estava quebrada e
             nada necessita ser feito
             2- Se o status do elemento eh igual a verificada, entao a interconexao foi reparada e devemos
             readicionar seu percentual de energia ao gerador
             3- Se o status do elemento eh igual a falhou, entao devemos retirar sua contribuicao ao adaptador
           */

        if(aux[ind]->tipo_ant=='G'){/*!< Se o gerador esta ligado ao inicio da interconexao*/
            menor_cor = menor(aux[ind]->ant_g->rec,aux[ind]->cpc);
            if(aux[ind]->tipo_prox=='C'){//gerador ligado diretamente a cidade nao pode
                printf("Interconexao %s liga diretamente gerador a cidade!\n",inicio->nome);
                aux[ind]->status = isolada; //codigo de erro geral
                rede->in_conex->total_falhas +=1;
            }else{
                if(aux[ind]->status==falhou)
                    menor_cor = -menor_cor;
                else if(aux[ind]->status==n_verificada){
                    menor_cor = 0;
                    aux[ind]->status = verificada;
                }
                if(menor_cor>=0 || (menor_cor<0 && aux[ind]->prox_a->entrada>=menor_cor)) /*! se tem que retorar corrente ou se ela for positiva*/
                    aux[ind]->prox_a->entrada = aux[ind]->prox_a->entrada + menor_cor;
            }
        }else{
            menor_cor = menor(aux[ind]->prox_g->rec,aux[ind]->cpc);
            if(aux[ind]->tipo_ant=='C'){
                printf("Interconexao %s liga diretamente gerador a cidade!\n",inicio->nome);
                aux[ind]->status = isolada; //codigo de erro geral
                rede->in_conex->total_falhas +=1;
            }else{
                if(aux[ind]->status==falhou)
                    menor_cor = -menor_cor;
                else if(aux[ind]->status==n_verificada){
                    menor_cor = 0;
                    aux[ind]->status = verificada;
                }
                if(menor_cor>=0 || (menor_cor<0 && aux[ind]->ant_a->entrada>=menor_cor)) /*! se tem que retorar corrente ou se ela for positiva*/
                    aux[ind]->ant_a->entrada = aux[ind]->ant_a->entrada + menor_cor;
            }
        }
    }/*!for*/

}
/***********************************************************************************
* Funcao: buscar interconexoes que saem do adaptador
* Descricao
*    Percorre a lista de interconexoes que saem de um adaptador indicado
*    pela posicao dele atraves da estrutura Posicao e redistribui a energia
*    contida nele para as interconexoes ligadas a ele. Decide o quanto de
*    energia vai distribuir por meio de duas regras de decisao:
*       1-> SE a probabilidade de falha for maior que a gerada para o tempo
*              atual de execucao ENTAO
*               interconexao marcada como falha e sua energia transmitida e retirada
*           SENAO SE interconexao foi consertada ENTAO
*               interconexao marcada como visiata e sua energia distribuida
*           SENAO
*               interconexao marcada como visiata e sua energia distribuida
*           FIMSE
*       2-> SE interconexao nao falhou ENTAO
*               energia de distribuida e calculada como o minimo entre a
*               capacidade maxima e a proporcao da energia que esta no
*               adaptador com relacao a capacidade total de todos os
*               geradores
*           FIMSE
*   Ao redistribuir energia para uma cidade, verifica-se se a energia que
*   chegou a ela foi menor que o total de recursos e se foi menor que 30%
*   desse valor. Caso um dos dois tenha ocorrido, as variaveis t_30_rec e
*   t_s_rec da estrutua da cidade sao atualizadas com o maior tempo de con-
*   serto de todas as conexoes que chegam a ela.
* Parametros
*    atual - ponteiro para a primeira interconexao ligada ao adaptador
*    procurado
*    posicao - ponteiro para o endereco de memoria do adaptador a ser
*    analisado
* Valor retornado
*    Funcao nao retorna nenhum valor (parametro de saida como void)
* Assertivas de entrada
*    atual != NULL
*    posicao != NULL
* Assertivas de saida
*    SE atual != NULL && posicao != NULL ENTAO
*       as cidades e os adaptadores ligados terao a energia total que passa
*       por eles computada e as interconexoes ligadas ao adaptador
*       analisado serao marcadas como verificadas
*    SENAO
*       Nada sera alterado
*    FIMSE
*
***********************************************************************************/

void busca_adapt(Rede *rede, Adaptador *posicao,int delta_t){/*! Ve se as linhas estao ligadas a adaptadores ou cidades*/
    Conexao *atual = rede->in_conex->inic;
    int rec_disp;/*! <recurso disponivel no adaptador*/
    int tam=1,ind,menor_cor;/*!< menor_cor e a menor corrente */
    int rec_tot_intercon=0;//vai calcular o total que as interconexoes sao capazes de suportar
    char tipo;
    Conexao **aux=NULL;
    if(posicao!=NULL)
        rec_disp = posicao->entrada;
    while(atual!=NULL){
        if( (atual->status==n_verificada || atual->status==falhou ) && (atual->ant_a==posicao || atual->prox_a == posicao) ){
            aux = (Conexao**)realloc(aux,tam*(sizeof( Conexao*) ) );
            if(aux!=NULL){//testa se a alocacao falhou
                aux[tam-1] = atual;
                rec_tot_intercon+= aux[tam-1]->cpc;
                tam++;
            }
        }
        atual = atual->prox_i;
    }
    tam--;/*!< Retorna a variavel "tam" para o tamanho correto apos alocar todas as informacoes de gerador*/

    for(ind = 0;ind<tam-1 && aux!=NULL;ind++){
        if(aux[ind]->status==falhou){
            rec_disp =-(aux[ind]->cpc);/*! Se a interconexao falhar, devmos tirar a contribuicao dela para a rede*/
        }else{
            aux[ind]->status = verificada;
            rec_disp = posicao->entrada;
        }
        /*! menor_cor eh o resultado do menor entre o maximo que a interconexao aguenta e a proporcao
        de corrente que o adaptador tem que fornecer para as interconexoes
        */
        menor_cor = menor(aux[ind]->cpc,(rec_disp*aux[ind]->cpc)/rec_tot_intercon);

        /*!< Estas condicionais abaixo vao porcurar o elemento ao qual o adaptor esta ligado */

        if(aux[ind]->ant_a==posicao){/*!< Se o adaptador esta ligado ao inicio da interconexao*/
            tipo =aux[ind]->tipo_prox;
            switch(tipo){
                case 'C':
                    if(menor_cor>=0 || (menor_cor<0 && aux[ind]->prox_c->recebida>=menor_cor)){ /*! se tem que retorar corrente ou se ela for positiva*/
                        aux[ind]->prox_c->recebida = aux[ind]->prox_c->recebida + menor_cor;
						printf("Corrente total em %s: %d\n",aux[ind]->prox_c->nome,aux[ind]->prox_c->recebida);                        
						if(aux[ind]->prox_c->recebida < aux[ind]->prox_c->rec){//cidade com menos recurso que o necessario
                            if(aux[ind]->prox_c->t_s_rec<delta_t)
                             aux[ind]->prox_c->t_s_rec=delta_t;

                            if(aux[ind]->prox_c->recebida < aux[ind]->prox_c->rec*0.3){
                                if(aux[ind]->prox_c->t_30_rec<delta_t)
                                    aux[ind]->prox_c->t_30_rec=delta_t;
                            }else{
                                aux[ind]->prox_c->t_30_rec=0;
                            }
                        }else{
                             aux[ind]->prox_c->t_s_rec=0;
                        }
                    }
                    break;
                case 'A':
                    if( menor_cor>=0 || (menor_cor<0 && aux[ind]->prox_a->entrada>=menor_cor) )
                        aux[ind]->prox_a->entrada = aux[ind]->prox_a->entrada + menor_cor;


            }
        }else{
            tipo =aux[ind]->tipo_ant;
            switch(tipo){
                case 'C':
                    if(menor_cor>=0 || (menor_cor<0 && aux[ind]->ant_c->recebida>=menor_cor)){
                        aux[ind]->ant_c->recebida = aux[ind]->ant_c->recebida + menor_cor;
						printf("Corrente total em %s: %d\n",aux[ind]->prox_c->nome,aux[ind]->prox_c->recebida);
                        if(aux[ind]->ant_c->recebida < aux[ind]->ant_c->rec){
                            if(aux[ind]->ant_c->t_s_rec<delta_t)
                                aux[ind]->ant_c->t_s_rec=delta_t;

                            if(aux[ind]->ant_c->recebida < aux[ind]->ant_c->rec*0.3){
                                if( aux[ind]->ant_c->t_30_rec<delta_t)//vai falhar ate que o que demore mais seja consertada
                                    aux[ind]->ant_c->t_30_rec=delta_t;
                            }else{
                                aux[ind]->ant_c->t_30_rec=0;
                            }
                        }else{
                            aux[ind]->ant_c->t_s_rec=0;
                        }
                    }
                    break;
                case 'A':
                    if(menor_cor>=0 || (menor_cor<0 && aux[ind]->ant_a->entrada>=menor_cor))
                        aux[ind]->ant_a->entrada = aux[ind]->ant_a->entrada + menor_cor;

            }
        }
    }/*!for*/

    free(aux);

}
/***********************************************************************************
* Funcao: calcular o menor entre dois numeros inteiros
* Descricao
*   Dado dois numeros inteiros, retorna o menor entre eles
* Parametros
*   num1 - inteiro a ser analisado
*   num2 - inteiro a ser analisado
* Valor retornado
*   Inteiro contendo o menor entre num1 e num2
* Assertivas de entrada
*   Funcaoa aceita quaisquer valores inteiros para os paramentros de entrada
* Assertiva de saida
*   SE num1<= num2 ENTAO
*    num1 retornado
*   SENAO
*    num2 retornado
*   FIMSE
*
*
*
*
*
*
*
*
*
***********************************************************************************/

int menor(int num1,int num2){
    if(num1<=num2){
        return num1;
    }else{
        return num2;
    }

}

/***********************************************************************************
* Funcao: reiniciar status dos elementos da lista de interconexoes
* Descricao
*    Percorre a lista de inetrconexoes e muda todos os status classificados como verificada para
*    n_verificada a fim de que a funcao verifica rede possa percorrer a lista de interconexoes para
*    verificar a existencia de possiveis problemas decorrentes da ocorrencia da simulacao
* Parametros
*    inicio - ponteiro para o inicio da lista de interconexoes
* Valor retornado
*    Funcao nao retorna nenhum valor (parametro de saida como void)
* Assertivas de entrada
*    inicio != NULL
* Assertivas de saida
*    SE inicio!= NULL ENTAO
*       o status de todos os elementos sao diferentes n_verificada, falhou ou isolada
*    SENAO
*       nenhuma modificacao feita
*    FIMSE
*
*
*
*
*
*
*
*
*
*
*
*
***********************************************************************************/

void reinicia_status(Conexao* inicio){
    while(inicio!=NULL){
        if(inicio->status==verificada){
            inicio->status=n_verificada;
        }
        inicio =inicio->prox_i;
    }

}

// Padrao de comentarios sobre as funcoes
/***********************************************************************************
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
***********************************************************************************/
