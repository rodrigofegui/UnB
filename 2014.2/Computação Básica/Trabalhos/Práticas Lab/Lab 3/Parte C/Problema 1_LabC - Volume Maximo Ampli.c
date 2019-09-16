#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Responsável / Turma: Rodrigo Guimaraães / E
// qual tamanho devem ter os quadrados cortados (qual deve ser o valor de x) de maneira a se obter o volume máximo para a caixa.

int main ()
{
	int n = 0, calc = 0, t;
	float comp=0, larg=0, fx1=0, fx2=0, fxm=0;
	float a=0, b=0, E=0;
	float x1=0, x2=0, xm=0;
	
	printf("Ola! Vamos determinar o volume maximo de uma caixa.\n\nPara isso digite o comprimento inicial, em cm: ");
		scanf("%f", &comp);
	printf("\nAgora a largura inicial, em cm: ");
		scanf("%f", &larg);
	printf("\nDetermine a altura minima desejada da caixa, em cm: ");
		scanf("%f", &a);
	/*printf("\nDetermine a altura maxima desejada da caixa, em cm: ");
		scanf("%f", &b);*/
	printf("\nAgora, digite a precisao esperada: ");
		scanf("%f", &E);
		
	if(comp > larg)
		b = (larg/2.0)-0.1;
	else
		b = (comp/2.0)-0.1;
	
	t= clock();
	
	do{
		x1 = a + ((b - a)/3.0);
		x2 = b - ((b - a)/3.0);		
		fx1 = (comp - 2.0*x1) * (larg - 2.0*x1) * x1;
		fx2 = (comp - 2.0*x2) * (larg - 2.0*x2) * x2;

		if (fx2 > fx1)
			a = x1;
		else
			b = x2;
		
		n++;
	}while (fabs(b-a) > E);
	
	xm = (a + b)/2.0;
	fxm = (comp - 2.0*xm) * (larg - 2.0*xm) * xm;
	
	printf("\n\nO volume maximo, %f cm3, eh atingido com x = %.2f cm.\nForam necessarias %d interacoes.\n\n", fxm, xm, n);
	printf("\nDemorou %d clicks, ou %f seg, para calcular.\n\n", t,((float)t)/CLOCKS_PER_SEC);
	
	getchar();
	return 0;
}
