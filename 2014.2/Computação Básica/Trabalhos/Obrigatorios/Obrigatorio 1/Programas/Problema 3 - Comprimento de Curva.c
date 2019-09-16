#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Responsável / Turma: Rodrigo Guimaães / E
// Escreva um programa que calcula o comprimento C de uma curva definida por uma função polinomial


int main (){
	
	float a5, a4, a3, a2, a1, a0, x0, x1, E;
	float x0h, funx0, funx, h, funx0h, comp, comp2, compf;
	int n = 0, calc = 1, cont, t;
	
	printf("Ola! Vamos determinar o comprimento de uma curva de uma funcao de,\npossivel, quinto grau.\n");
	printf("\nPara isso, digite o coeficiente 'a5': ");
		scanf("%f", &a5);
	printf("\nAgora, digite o coeficiente 'a4': ");
		scanf("%f", &a4);
	printf("\nAgora, digite o coeficiente 'a3': ");
		scanf("%f", &a3);
	printf("\nAgora, digite o coeficiente 'a2': ");
		scanf("%f", &a2);
	printf("\nAgora, digite o coeficiente 'a1': ");
		scanf("%f", &a1);
	printf("\nAgora, digite o coeficiente 'a0': ");
		scanf("%f", &a0);
	printf("\nAgora, digite o ponto inicial, x0, da curva a ser considerada: ");
		scanf("%f", &x0);
	printf("\nAgora, digite o ponto final, x1, da curva a ser considerada: ");
		scanf("%f", &x1);
	printf("\nAgora, eh preciso determinar a precisao desejada: ");
		scanf("%f", &E);

	t = clock ();
	funx0 = ((a5 * (pow(x0,5.0))) + (a4 * (pow(x0,4.0))) + (a3 * (pow(x0,3.0))) + (a2 * (pow(x0,2.0))) + (a1 * (x0)) + (a0));
	funx = funx0;
	
	while (calc == 1){
		funx = funx0;
		h = (fabs(x1 - x0))/(n + 1);
		x0h = x0 + h;
		cont = 0;
		comp = 0;
		comp2 = 0;
		
		while (cont < (n + 1)){
			funx0h = ((a5 * (pow(x0h,5.0))) + (a4 * (pow(x0h,4.0))) + (a3 * (pow(x0h,3.0))) + (a2 * (pow(x0h,2.0))) + (a1 * (x0h)) + (a0));
			comp += sqrt(pow((fabs(funx0h - funx)),2) + pow(h,2));
			funx = funx0h;
			x0h += h;
			//printf("n: %d; x0: %f; fx0: %f; fx0h: %f; comp: %f\n\n", n, x0h, funx, funx0h, comp);
			cont++;
		
		}
		
		cont = 0;
		funx = funx0;
		h = (fabs(x1 - x0))/(n + 2);
		x0h = x0 + h;
		
		while (cont < (n + 2)){
			funx0h = ((a5 * (pow(x0h,5.0))) + (a4 * (pow(x0h,4.0))) + (a3 * (pow(x0h,3.0))) + (a2 * (pow(x0h,2.0))) + (a1 * (x0h)) + (a0));
			comp2 += sqrt(pow((fabs(funx0h - funx)),2) + pow(h,2));
			funx = funx0h;
			x0h += h;
			//printf("n: %d; x0: %f; fx0: %f; fx0h: %f; comp2: %f\n\n", n, x0h, funx, funx0h, comp2);
			cont++;
		
		}
				
		if (fabs(comp2 - comp) < E){
			calc = 0;	
		}else{
			n++;
		}
	}
	
	compf = (comp + comp2)/2.0;
	
	printf("\nSatisfazendo a precisao, foram realizadas %d interacoes,\nchegando ao comprimento: %f.\n\n", n, compf);
	printf("\nDemorou %d clicks, ou %f seg, para calcular.\n\n", t,((float)t)/CLOCKS_PER_SEC);
	
	system ("pause");
	return 0;
}
