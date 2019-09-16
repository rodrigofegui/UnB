#include "estruturas_.hpp"
#include "busca.hpp"
#include "Insere_conexoes.hpp"
#include <string.h>

Elem* insere_elemento(Elem* inicio,FILE *arquivo,char* dado,int p_x,int p_y,int rec, int cust){
    char tipo, *nome=NULL;// aux_1 eh para fazer testes antes de comecar a elr de arquivos;
    int numero,i,tam_1=0,contador=0;
    Elem *aux,*ant,*atual;/*possibilitam realizar insercoes no meio da lista*/
    tipo = dado[0];


    for(i=1;i<=strlen(dado);i++){//vamos considerar que a string dado tenha somente o nome do elemento e o tipo
        if( (dado[i]!='Space') && (dado[i]!='\0') && (dado[i]!='\n') ){
                nome =(char*) realloc(nome,tam_1+1);
                nome[tam_1] = dado[i];
                tam_1++;
        }
    }
        if(inicio == NULL){/*nada foi criado*/
            inicio = cria_elemento();
            inicio->tipo_el = tipo;
            inicio->nome_el = (char*) malloc(sizeof(char)*tam_1);
            strcpy(inicio->nome_el,nome);
            inicio->lin = p_x;
            inicio->col= p_y;
            if(tipo!='A'){
                inicio->recurso = rec;
                if(tipo== 'G')
                    inicio->custo = cust;
            }

        }else{
            atual = busca_elemento(inicio,&ant,p_x,p_y);
            if(ant==NULL && atual!=NULL){/*insercao no inicio da linha*/
                ant = insere_elemento(ant,arquivo,dado,p_x,p_y,rec,cust);
                ant->proximo = atual->proximo;
                atual->proximo = ant;
            }else if(ant==NULL && atual ==NULL){// criacao de uma nova linha
                aux= NULL;
                aux = insere_elemento(aux,arquivo,dado,p_x,p_y,rec,cust);
                aux->ger = inicio;
                inicio = aux;
            }else {//insecao no meio da linha
                aux = NULL;//serah usado para criar um novo elemento para ser inserido no meio
                aux = insere_elemento(aux,arquivo,dado,p_x,p_y,rec,cust);
                ant->proximo = aux;
                aux->proximo = atual;
            }
        }

    free(nome);
    return inicio;

}
Elem* cria_elemento(void){
    Elem* novo;
    novo = (Elem*) malloc(sizeof(Elem));
    novo->conex_adapt = NULL;
    novo->ger = NULL;
    novo->conex = NULL;
    novo->proximo= NULL;
    novo->nome_el = NULL;
    return novo;
}



