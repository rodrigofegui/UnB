#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void quickSort(int *, int, int);
int particao(int *, int, int);
void swap(int *, int *);
int getPivo (int *, int, int);

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
    if (ini < fim){
        int part = particao(vet, ini, fim);
        quickSort(vet, ini, part - 1);
        quickSort(vet, part + 1, fim);
    }
}

int particao (int *vet, int ini, int fim){
    int pivo = getPivo(vet, ini, fim);
    int indMenor = ini;
    int indMaior = fim;

    while(1){
        while(pivo > vet[indMenor]) indMenor++;
        while(pivo < vet[indMaior]) indMaior--;

        if (indMenor <= indMaior)
            swap(&vet[indMenor], &vet[indMaior]);

        return indMaior;
    }
}

void swap (int* ind1, int* ind2){
	int temp = *ind1;
	
	*ind1 = *ind2;
	*ind2 = temp;
}

int getPivo (int *vet, int ini, int fim){
    int indPivo = ini + (rand() % (fim - ini));
	swap (&vet[ini], &vet[indPivo]);

    return vet[ini];
}