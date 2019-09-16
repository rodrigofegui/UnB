#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Responsável / Turma: Rodrigo Guimarães / E
// Escreva um programa que calcule e escreva o número de anos necessários para que a população do país A
// ultrapasse ou iguale a população do país B, mantidas essas taxas de crescimento.

int main ()
{
	
	int t;
	float ano = 1.0, popA = 90000000.0, popB = 200000000.0;
	
	printf("Ola! Vamos explorar nosso conhecimento sobre progressao geometrica.\n");
	printf("\nA populacao do pais A equivale a 90.000.000 hab., com uma taxa anual de\ncrescimento de 3%%; e que a pop. do pais B seja equivalente a 200.000.000 hab.,\ncom uma taxa anual de crescimento de 1,5%%.\n");
	printf("\nEm quantos anos a pop. do pais A ultrapassa ou se iguala a do pais B?\nPensem nisso...\n");
	
	while (popA < popB){
		ano ++;
		popA = 90000000 * pow(1.03,ano -1);
		popB = 200000000 * pow(1.015,ano - 1);
	}
	
	t = clock ();
	
	printf("\nCom taxa de crescimento cte, pode-se afirmar que sao necessarios %.0f anos,\npara que a pop. do pais A iguale ou ultrapasse a pop. do pais B.\n", ano);
	printf("\nOnde a pop. do pais A equivale a %.0f hab.;\na pop. do pais B equivale a %.0f hab.\n", popA, popB);
	printf("\nDemorei %d clicks, ou %f seg, para calcular.\n\n", t,((float)t)/CLOCKS_PER_SEC);
	
	getchar();
	return 0;
}
