#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Responsável / Turma: Rodrigo Guimarães / E
// Implementar o algoritmo da bisseção na funcao: (5*sin(x))-(5-x) = 0

int main (){
	
	int laco = 0, n = 0;
	float fx0s, fx1s, fxms, x0s, x1s, xms, E;
	
	printf("Ola! Vamos implementar um algoritmo que realize bissecao para determincacao de\nraiz para a equacao (5*sin(x))-(5-x) = 0:\n\nPara isso digite o  ponto inicial, 'x0': ");
		scanf("%f", &x0s);
	printf("\nAgora, digite o ponto final, 'x1': ");
		scanf("%f", &x1s);
	printf("\nAgora, digite a precisao desejada, 'E': ");
		scanf("%f", &E);

	while (laco == 0){
		fx0s = (5*sin(x0s))-(5-x0s);
		fx1s = (5*sin(x1s))-(5-x1s);
		xms = (x0s + x1s)/2.0;
		fxms = (5*sin(xms))-(5-xms);
		/*printf("\n %d Voltas.", n);
		printf("\nx0: %f; f(x0): %f ; x1: %f; f(x1): %f;\nxm: %f; f(xm): %f\n", x0s, fx0s, x1s, fx1s, xms, fxms);*/
						
		if (((fx0s || fx1s) == 0) || (fabs(fx0s - fx1s) < E)){
			if (fabs(fx0s) > fabs(fx1s)){
				printf("\nA raiz eh %.4f!\n", x1s);
			
			}else{
				printf("\nA raiz eh %.4f!\n", x0s);
			}
			
			laco = 1;
		
		}else if ((fx0s < 0) && (fx1s > 0)){
			if (fxms == 0){
				printf("\nA raiz eh %.4f!\n", xms);
				laco = 1;
			}else{
				if (fxms > 0){
					x1s = xms;
				}else{
					x0s = xms;
				}
			}
		
		}else{
			if (fxms == 0){
				printf("\nA raiz eh %.4f!\n", xms);
				laco = 1;
			}else{
				if (fxms > 0){
					x0s = xms;
				}else{
					x1s = xms;
				}
			}
		
		}
		
		n++;
	}

	getchar ();
	return 0;
}
