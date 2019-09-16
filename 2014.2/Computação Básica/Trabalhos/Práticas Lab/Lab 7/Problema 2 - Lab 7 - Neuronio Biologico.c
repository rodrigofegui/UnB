#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int neuronio (float*, float*, float, int);

int main(){
	float entrada[MAX], peso[MAX], T, *e, *p;
	int i, status;

	for(i=0; i<MAX; i++){
		printf("Digite o valor do vetor entrada[%d]: ", i);
		scanf("%f", &entrada[i]);
		printf("\nDigite o valor do vetor peso[%d]: ", i);
		scanf("%f", &peso[i]);
		system("pause");
		system("cls");
	}
	printf("Digite o valor do limiar T: ");
		scanf("%f", &T);
	printf("\nDigite a quantidade a ser lida: ");
		scanf("%d", &i);

	status=neuronio(entrada, peso, T, i);

		if (status == 1)
			printf("\nNeuronio excitado\n");
		else
			printf("\nNeuronio inibido\n");

	system("pause");
	return 0;
}

int neuronio (float *s, float *r, float t, int n){
	float somap=0;
	int i;
	
	for(i=0; i<n; i++){
		somap += (*(s+i))*(*(r+i));
	}
	
	if (somap > t)
		return 1;
	else
		return 0;
}


