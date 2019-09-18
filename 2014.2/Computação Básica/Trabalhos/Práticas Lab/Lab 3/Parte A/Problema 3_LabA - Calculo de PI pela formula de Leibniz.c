#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Responsável / Turma: Rodrigo Guimarães / E
// Escreva um programa para calcular e escrever o valor de PI, com precisao de 0,001, usando a serie de soma.
// Calcule tambem quanto tempo o programa leva para chegar a solucao.

int main ()
{

	int n = 0, t, laco = 1;
	float pi, pi2, soma = 0, soma2 = 0, E;

	printf("Ola! Vamos realizar o calculo para PI, atraves da formula de Leibniz, com precisao de:  ");
		scanf("%f", &E);
	
	t = clock();
	
	while (laco == 1){
		n++;
		soma += ((pow(-1,n - 1))/(2*(n -1) +1));
		pi = 4.0 * soma;
		soma2 = soma + ((pow(-1,n))/(2*n +1));
		pi2 = 4.0 * soma2;
		
		if (fabs(pi - pi2) <= E){
			laco = 0;
		}else{
			pi = pi2;
		}
	}
	
	printf("\nPela formula de Leibniz, PI equivale a %f, em %d interacoes.\n", pi, n);
	printf("\nDemorou %d clicks, ou %f seg, para calcular.\n\n", t,((float)t)/CLOCKS_PER_SEC);
	
	getchar ();
	return 0;
}
