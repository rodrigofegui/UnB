#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *vetA, *vetB, *vetC;
	int tam, soma = 0, i;
	
	printf("Digite o tamanho dos vetores A, B e C: ");
		scanf("%d", &tam);
	
	vetA = (int*) calloc (tam,sizeof(int));
	vetB = (int*) calloc (tam,sizeof(int));
	vetC = (int*) calloc (tam,sizeof(int));
	
	if(vetA == NULL || vetB == NULL|| vetC == NULL){
		printf("\nAlocacao falhou!\n\n");
		exit (1);
	}
	
	for(i = 0; i < tam; i++){
		printf("\nDigite o valor do vetor A [%d]: ", i);
			scanf("%d", &vetA[i]);
	}
	for(i = 0; i < tam; i++){
		printf("\nDigite o valor do vetor B [%d]: ", i);
			scanf("%d", &vetB[i]);
	}
	
	for(i = 0; i < tam; i++){
		*(vetC + i)=(*(vetA + i))+(*(vetB + i));
		soma += *(vetC + i);
	}

	for(i=0; i < tam; i++){
		printf("\nVetor C[%d]: %d\n", i, *(vetC + i));
	}
	
	printf("\nSoma acumulada do Vetor C: %d\n\n", soma);

	free (vetA);
	free (vetB);
	free (vetC);
	
	system ("pause");
	return 0;
}
