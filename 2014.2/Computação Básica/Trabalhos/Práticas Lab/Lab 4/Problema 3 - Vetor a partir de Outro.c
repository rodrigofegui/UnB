#include <stdio.h>
#include <stdlib.h>
#define tam 10

/* Respons�vel / Turma: Rodrigo Guimar�es / E
Escreva um programa que l� um conjunto VET1 de 20 elementos reais e constr�i outro conjunto VET2 formado da seguinte maneira:
a) os elementos de ordem par s�o os correspondentes de VET1 divididos por 2;
b) os elementos de ordem impar s�o os correspondentes de VET1 multiplicados por 3. */

int main (){
	float vet1[tam],vet2[tam];
	int i;
	
	printf("Ola! Valos treinar conhecimentos de vetores.\n");
	
	for(i = 0; i <= (tam-1) ; i++){
		printf("\nDigite um numero para o Vetor 1 posicao %d: ", i);
			scanf("%f", &vet1[i]);
			
	}
	
	for(i = 0; i <= (tam-1) ; i++){
		if ((i%2) == 0)
			vet2[i] = vet1[i]/2.0;
		else
			vet2[i] = vet1[i]*3.0;

	}
	
	printf("\nO Vetor 1:\n");
	
	for(i = 0; i <= (tam-1); i++){
		printf("%.2f\t", vet1[i]);
	}
	
	printf("\n\nO Vetor 2:\n");
	
	for(i = 0; i <= (tam-1); i++){
		printf("%.2f\t", vet2[i]);
	}
	
	printf("\n\n");
	getchar ();
	return 0;
}
