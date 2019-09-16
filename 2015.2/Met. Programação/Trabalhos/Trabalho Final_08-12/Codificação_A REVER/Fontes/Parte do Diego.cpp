#include<stdio.h>
#include<stdlib.h>

int main(){

FILE* arquivo = fopen("teste.txt","r");
char texto[100],nome[50],aux[5];
int pos_x,pos_y,recurso,custo, pos_final_x,pos_final_y,tempo;
int i,j;
float chance_falha;

while(fgets(texto,100,arquivo) != NULL){// Enquanto não for o final do arquivo
    if(texto[0] == 'C'){// Se for uma linha de cidade
        printf("\n");
        for(i=2;texto[i]<47 || texto[i]>58;i++){// Copia o nome da cidade
            nome[i-2] = texto[i];
        }
        nome[i-3]='\0';
        printf("Nome da cidade: %s\n", nome);

        for(j=i;texto[j]!=' ';j++){
            aux[j-i] = texto[j];
        }
        aux[j-i]='\0';
        pos_x=atoi(aux);
        printf("pos_x: %d\n",pos_x);
        j++;

        for(i=j;texto[i]!=' ';i++){
            aux[i-j] = texto[i];
        }
        aux[i-j] = '\0';
        pos_y=atoi(aux);
        printf("pos_y: %d\n",pos_y);
        i++;

        for(j=i;texto[j]!='\n';j++){
            aux[j-i] = texto[j];
        }
        recurso=atoi(aux);
        printf("Recurso necessario: %d\n",recurso);
    }
    else if(texto[0] == 'G'){// Se for uma linha de gerador
        printf("\n");
        for(i=2;texto[i]<47 || texto[i]>58;i++){// Copia o nome da cidade
            nome[i-2] = texto[i];
        }
        nome[i-3]='\0';
        printf("Nome: %s\n", nome);

        for(j=i;texto[j]!=' ';j++){
            aux[j-i] = texto[j];
        }
        aux[j-i]='\0';
        pos_x=atoi(aux);
        printf("pos_x: %d\n",pos_x);
        j++;

        for(i=j;texto[i]!=' ';i++){
            aux[i-j] = texto[i];
        }
        aux[i-j] = '\0';
        pos_y=atoi(aux);
        printf("pos_y: %d\n",pos_y);
        i++;

        for(j=i;texto[j]!=' ';j++){
            aux[j-i] = texto[j];
        }
        recurso=atoi(aux);
        printf("Recurso produzido: %d\n",recurso);
        j++;

        for(i=j;texto[i]!='\n';i++){
            aux[i-j] = texto[i];
        }
        aux[i-j] = '\0';
        custo=atoi(aux);
        printf("Custo gerador: %d\n",custo);

    }
    else if(texto[0] == 'I'){// Se for uma linha de interconexão
        printf("\n");
        for(i=2;texto[i]!=' ';i++){// Copia o nome da cidade
            nome[i-2] = texto[i];
        }
        nome[i-2]='\0';
        printf("Nome: %s\n", nome);
        i++;

        for(j=i;texto[j]!=' ';j++){
            aux[j-i] = texto[j];
        }
        aux[j-i]='\0';
        pos_x=atoi(aux);
        printf("pos_x: %d\n",pos_x);
        j++;

        for(i=j;texto[i]!=' ';i++){
            aux[i-j] = texto[i];
        }
        aux[i-j] = '\0';
        pos_y=atoi(aux);
        printf("pos_y: %d\n",pos_y);
        i++;

        for(j=i;texto[j]!=' ';j++){
            aux[j-i] = texto[j];
        }
        aux[j-i]='\0';
        pos_final_x=atoi(aux);
        printf("pos_final_x: %d\n",pos_final_x);
        j++;

        for(i=j;texto[i]!=' ';i++){
            aux[i-j] = texto[i];
        }
        aux[i-j] = '\0';
        pos_final_y=atoi(aux);
        printf("pos_final_y: %d\n",pos_final_y);
        i++;

        for(j=i;texto[j]!=' ';j++){
            aux[j-i] = texto[j];
        }
        aux[j-i]='\0';
        recurso=atoi(aux);
        printf("Capacidade maxima: %d\n",recurso);
        j++;

        for(i=j;texto[i]!=' ';i++){
            aux[i-j] = texto[i];
        }
        aux[i-j] = '\0';
        chance_falha=(float)atof(aux);
        printf("Chance de falha: %f\n",chance_falha);
        i++;

        for(j=i;texto[j]!=' ';j++){
            aux[j-i] = texto[j];
        }
        aux[j-i]='\0';
        tempo=atoi(aux);
        printf("Tempo de conserto: %d\n",tempo);
        j++;

        for(i=j;texto[i]!='\n';i++){
            aux[i-j] = texto[i];
        }
        aux[i-j] = '\0';
        custo=atoi(aux);
        printf("Custo de conserto: %d\n",custo);
        i++;



    }
    else if(texto[0] == 'A'){// Se for uma linha de adaptador
        printf("\n");
        for(i=2;texto[i]!=' ';i++){// Copia o nome da cidade
            nome[i-2] = texto[i];
        }
        nome[i-2]='\0';
        printf("Nome: %s\n", nome);
        i++;

        for(j=i;texto[j]!=' ';j++){
            aux[j-i] = texto[j];
        }
        aux[j-i]='\0';
        pos_x=atoi(aux);
        printf("pos_x: %d\n",pos_x);
        j++;

        for(i=j;texto[i]!='\0';i++){
            aux[i-j] = texto[i];
        }
        aux[i-j] = '\0';
        pos_y=atoi(aux);
        printf("pos_y: %d\n",pos_y);
        i++;
    }
}


return 0;
}
