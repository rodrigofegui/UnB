#include <stdio.h>
#include <stdlib.h>

// Responsável / Turma: Rodrigo Guimaraães / E
// qual tamanho devem ter os quadrados cortados (qual deve ser o valor de x) de maneira a se obter o volume máximo para a caixa.

int main ()
{
	int n = 0;
	float comp, larg, vol, volm = 0;
	float x = 0.01, xm = 0, calc = 0;
	
	printf("Ola! Vamos determinar o volume maximo de uma caixa.\n\nPara isso digite o comprimento inicial, em cm: ");
		scanf("%f", &comp);
	printf("\nAgora a largura inicial, em cm: ");
		scanf("%f", &larg);
	
	while (calc == 0 ){
		vol = (comp - 2.0*x) * (larg - 2.0*x) * x;

		if (vol > volm){
			volm = vol;
			xm = x;
			calc = 0;
		}else{
			calc = 1;
		}
		
		x += 0.01;
		n++;
	}
	
	printf("\n\nO volume maximo, %f cm3, eh atingido com x = %.2f cm.\nForam necessarias %d interacoes.\n\n", volm, xm, n);
	
	getchar();
	return 0;
}
