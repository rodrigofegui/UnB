#include "estruturas.hpp"
#include "busca.hpp"
//retorna atual e modifica atualiza o conteudo do anterior por referencia ("eu entendi a referencia")
Elem* busca_elemento(Elem *inicio, Elem **anterior,int p_x,int p_y){//retorna o elemento anterior e o proximo da lista para a funca que chamou a busca
    Elem *ant, *atual,*aux;
    for(aux = inicio;aux!=NULL;aux=aux->ger){
        ant = NULL;
        atual = aux;
        while(atual!=NULL && ( (p_x != atual->lin) && (p_y != atual->col) ) ){/*procura a localizacao do elemento ou o fim da lista*/
            ant = atual;
            atual = atual->proximo;
        }
        if(atual!=NULL){// achou o elemento
            *(anterior) = ant;
            return atual;
        }
    }
    //se nao achou em nenhum elemento na matriz toda
    *(anterior) = NULL;
    return NULL;
}
