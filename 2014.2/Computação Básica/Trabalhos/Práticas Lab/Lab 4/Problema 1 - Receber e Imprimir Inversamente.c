#include <stdio.h>
#include <stdlib.h>
#define tam 5

/* Respons�vel / Turma: Rodrigo Guimar�es / E
Escreva um programa que solicita ao usu�rio 5 n�meros inteiros e os exibe na tela do computador na ordem inversa em que foram digitados. */

int main(){
	int num [tam], i;
	
	printf("Ola! Valos treinar conhecimentos de vetores.\n");
	
	for(i = 0; i <= (tam-1); i++){
		printf("\nDigite um numero: ");
			scanf("%d", &num[i]);
	}
	
	for(i = (tam-1); i >= 0; i--){
		printf("O numero da %do posicao eh: %d.\n", i, num[i]);
	}
	
	getchar ();
	return 0;
}
