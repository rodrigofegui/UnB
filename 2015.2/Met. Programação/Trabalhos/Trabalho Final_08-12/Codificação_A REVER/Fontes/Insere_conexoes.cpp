#include "estruturas.hpp"
#include "Insere_conexoes.hpp"
#include<string.h>
/*struct intercon{//para interconexoes
    char tipo;// indica que e interconexao
    char *nome;// vai guardar o nome da conexao
    int linha_inicio,coluna_inicio;// linha = pos_x e coluna = pos_y
    int linha_fim, coluna_fim;
    int capacidade;
    float falha;
    int tempo_cons, custo_cons; // custo e tempo de conserto
    struct intercon *linha, *coluna;//vai ser uma matriz de interconexoes. Cada linha, representa interconexoes
    int ordem;
    // ligadas. A juncao de todas as ligacoes reulta na matriz

};
*/
/*
Conexao* insere_con(Conexao* inicio,FILE *arquivo,char* dado,int p_x,int p_y,int x_f,int y_f,int rec, int cust){
    char tipo, *nome=NULL;// aux_1 eh para fazer testes antes de comecar a elr de arquivos;
    int numero,i,tam_1=0,contador=0;
    Conexao *aux,*ant,*atual;/*possibilitam realizar insercoes no meio da lista*/
  /*  tipo = dado[0];


    for(i=1;i<=strlen(dado);i++){//vamos considerar que a string dado tenha somente o nome do elemento e o tipo
        if( (dado[i]!='Space') && (dado[i]!='\0') && (dado[i]!='\n') ){
                nome =(char*) realloc(nome,tam_1+1);
                nome[tam_1] = dado[i];
                tam_1++;
        }
    }
        if(inicio == NULL){/*nada foi criado*/
    /*        inicio = cria_con();
            inicio->tipo = tipo;
            inicio->nome = (char*) malloc(sizeof(char)*tam_1);
            strcpy(inicio->nome,nome);
            inicio->linha_inicio = p_x;
            inicio->coluna_inicio= p_y;
            inicio->linha_fim = x_f;
            inicio->coluna_fim= y_f;
        }else{
         //   atual = busca_elemento(inicio,&ant,p_x,p_y);
            if(ant==NULL && atual!=NULL){/*insercao no inicio da linha*/
  /*              ant = insere_con(ant,arquivo,dado,p_x,p_y,x_f,y_f,rec,cust);
                ant->proximo = atual->proximo;
                atual->proximo = ant;
            }else if(ant==NULL && atual ==NULL){// criacao de uma nova linha
                aux= NULL;
                aux = insere_con(aux,arquivo,dado,p_x,p_y,x_f,y_f,rec,cust);
                aux->ger = inicio;
                inicio = aux;
            }else {//insecao no meio da linha
                aux = NULL;//serah usado para criar um novo elemento para ser inserido no meio
                aux = insere_con(aux,arquivo,dado,p_x,p_y,x_f,y_f,rec,cust);
                ant->proximo = aux;
                aux->proximo = atual;
            }
        }
    }
    free(nome);
    return inicio;

}*/
Conexao* cria_con(void){
    return NULL;
}
