#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Respons�vel / Turma: Rodrigo Guimar�es / E
// Implemente o algoritmo da bisse��o discutido em sala de aula e determine as ra�zes das seguintes fun��es, nos intervalos e com a precis�o indicados

int main (){
	
	int laco = 0, n = 0;
	float a3, a2, a1, a0, x0, x1, E, xm, fx0, fx1, fxm;
	
	printf("Ola! Vamos implementar um algoritmo que realize bissecao para determincacao de\nraiz:\n\nPara isso digite o coeficiente 'a3': ");
		scanf("%f", &a3);
	printf("\nAgora, digite o coeficiente 'a2': ");
		scanf("%f", &a2);
	printf("\nAgora, digite o coeficiente 'a1': ");
		scanf("%f", &a1);
	printf("\nAgora, digite o coeficiente 'a0': ");
		scanf("%f", &a0);
	printf("\nAgora, digite o ponto inicial, 'x0': ");
		scanf("%f", &x0);
	printf("\nAgora, digite o ponto final, 'x1': ");
		scanf("%f", &x1);
	printf("\nAgora, digite a precisao desejada, 'E': ");
		scanf("%f", &E);
	
	while (laco == 0){
		fx0 = ((a3 * (pow(x0,3.0))) + (a2 * (pow(x0,2.0)))  + (a1 * x0) + a0);
		fx1 = ((a3 * (pow(x1,3.0))) + (a2 * (pow(x1,2.0)))  + (a1 * x1) + a0);
//		printf("\n %d Voltas.\t xm: %f", n, xm);
//		printf("\nx0: %f; x1: %f; f(x0): %f ; f(x1): %f\n", x0, x1 , fx0, fx1);
						
		if (((fx0 || fx1) == 0) || (fabs(fx0 - fx1) < E)){
			if (fabs(fx0 - 0) > fabs(fx1 - 0)){
				printf("\nA raiz eh %.4f!\n\n", x1);
			
			}else{
				printf("\nA raiz eh %.4f!\n\n", x0);
			}
			
			laco = 1;
		
		}else if ((fx0 < 0) && (fx1 > 0)){
		xm = (x0 + x1)/2.0;
		fxm = ((a3 * (pow(xm,3.0))) + (a2 * (pow(xm,2.0)))  + (a1 * xm) + a0);
		
			if (fxm == 0){
				printf("\nA raiz eh %.4f!\n\n", xm);
				laco = 1;
			}else{
				if (fxm > 0){
					x1 = xm;
				}else{
					x0 = xm;
				}
			}
		
		}else{// if ((fx0 > 0) && (fx1 < 0)){
		xm = (x0 + x1)/2.0;
		fxm = ((a3 * (pow(xm,3.0))) + (a2 * (pow(xm,2.0)))  + (a1 * xm) + a0);
		
			if (fxm == 0){
				printf("\nA raiz eh %.4f!\n\n", xm);
				laco = 1;
			}else{
				if (fxm > 0){
					x1 = xm;
				}else{
					x0 = xm;
				}
			}
		
		}
		
		n++;
}

	getchar ();
	return 0;
}
