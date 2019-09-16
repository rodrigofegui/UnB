#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Responsável / Turma: Rodrigo Guimarães / E
// Determinar primaridade de um número inteiro positivo

int main (){	
	int n, div, resto, t;

	printf("\t***********************************\n\t\tTESTE DE PRIMARIDADE\n\t***********************************\n");

	do{
		printf("\nDigite um numero interio positivo ou (-1) para sair: ");
		scanf("%d", &n);
	
		if (n < -1){
			printf("Numero invalido, apenas numeros inteiros POSITIVOS sao aceitos!\n\n");
		}else if (n >= 0){
			
			div = 2;
			resto = n%div;
			
			while (div <= sqrt(n) && (resto != 0)){
				resto = n%div;
				div ++;			
			}
	
			if ((resto == 0) && (n != 2)){			
				printf("O numero NAO eh primo.\n");
			}else{
				printf("O numero eh primo.\n");
			}
	
		}
	
	}while(n != -1);		

	printf("\n\t***********************************\n\t      FIM TESTE DE PRIMARIDADE\n\t***********************************\n");
	
	getchar ();
	return 0;
}
