#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quickSort(int *, int, int);
int particao(int *, int, int);
int particao_esquerda (int *, int, int);
int particao_direita(int *, int, int);
void swap (int *, int *);

int main (){
    int tam;
	scanf("%d", &tam);
	
	int val[tam], cnt = 0;
	srand(time(NULL));
	
	while (cnt < tam)
		scanf("%d", &val[cnt++]);
		
	quickSort(val, 0, tam - 1);
	
	for (cnt = 0; cnt < tam; cnt++)
		printf("%d\n", val[cnt]);

    return 0;
}

void quickSort (int *vet, int ini, int fim){
    if(ini < fim){
        int part = particao(vet, ini, fim);
        quickSort(vet, ini, part - 1);
        quickSort(vet, part + 1, fim);
    }
}

int particao (int *vet, int ini, int fim){
    int indPivo = ini + (rand()%(fim - ini));

    int part = particao_direita(vet, indPivo, fim);

    return particao_esquerda(vet, ini, part);
}

int particao_esquerda (int *vet, int ini, int fim){
    int pivo = vet[fim];

    int indMenor = fim;

    for(int indMaior = fim - 1; indMaior >= ini; indMaior--){
        if(vet[indMaior] > pivo)
            swap(&vet[--indMenor], &vet[indMaior]);
    }

    swap(&vet[fim], &vet[indMenor]);

    return indMenor;
}


int particao_direita(int *vet, int ini, int fim){
    int pivo = vet[ini];

    int indMenor = ini;
    for(int indMaior = ini + 1; indMaior <= fim; indMaior++){
        if(vet[indMaior] < pivo)
            swap(&vet[++indMenor], &vet[indMaior]);
    }

    swap(&vet[ini], &vet[indMenor]);

    return indMenor;
}

void swap (int *val1, int *val2){
	int temp = *val1;
	
	*val1 = *val2;
	*val2 = temp;
}






