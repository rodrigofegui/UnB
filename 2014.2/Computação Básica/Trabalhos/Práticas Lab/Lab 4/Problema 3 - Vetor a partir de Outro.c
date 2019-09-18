#include <stdio.h>
#include <stdlib.h>
#define tam 10

/* Responsável / Turma: Rodrigo Guimarães / E
Escreva um programa que lê um conjunto VET1 de 20 elementos reais e constrói outro conjunto VET2 formado da seguinte maneira:
a) os elementos de ordem par são os correspondentes de VET1 divididos por 2;
b) os elementos de ordem impar são os correspondentes de VET1 multiplicados por 3. */

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
