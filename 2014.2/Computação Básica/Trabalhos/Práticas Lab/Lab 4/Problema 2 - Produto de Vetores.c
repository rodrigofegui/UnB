#include <stdio.h>
#include <stdlib.h>
#define tam 10

/* Responsável / Turma: Rodrigo Guimarães / E
Escreva um programa para fazer a multiplicação, elemento a elemento, de 2 vetores reais de comprimento 10. Os elementos dos vetores devem ser fornecidos pelo usuário. O resultado deve ser guardado
em um terceiro vetor e apresentado na tela do computador */

int main (){
	float A [tam], B [tam], C [tam];
	int i;
	
	printf("Ola! Valos treinar conhecimentos de vetores.\n");
	
	for(i = 0; i <= (tam-1) ; i++){
		printf("\nDigite um numero para o Vetor A posicao %d: ", i);
			scanf("%f", &A [i]);
	}
	
	for(i = 0; i <= (tam-1) ; i++){
		printf("\nDigite um numero para o Vetor B posicao %d: ", i);
			scanf("%f", &B [i]);
	}

	for(i = 0; i <= (tam-1) ; i++){
		C[i] = A[i] * B[i];
		printf("\n\nPara a posicao %d, do Vetor C, tem-se o produto: %f.\n", i, C[i]);
	}
	
	getchar ();
	return 0;
}
