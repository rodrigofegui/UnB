#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Responsável / Turma: Rodrigo Guimarães / E
// Implementar o algoritmo da bisseção na funcao: x + ln(x) = 0

int main (){
	
	int laco = 0, n = 0;
	float fx0l, fx1l, fxml, x0l, x1l, xml, E;
	
	printf("Ola! Vamos implementar um algoritmo que realize bissecao para determincacao de\nraiz para a equacao x + ln(x) = 0:\n\nPara isso digite o  ponto inicial, 'x0': ");
		scanf("%f", &x0l);
	printf("\nAgora, digite o ponto final, 'x1': ");
		scanf("%f", &x1l);
	printf("\nAgora, digite a precisao desejada, 'E': ");
		scanf("%f", &E);

	/*printf("\nPara ratificar a efiencia do método de calculo,\npara a equacao: x + ln(x) = 0, entre 0.1 e 1.0,tem-se que:\n");
	x0l = 0.1;
	x1l = 1.0;*/
	
	while (laco == 0){
		fx0l = (x0l + (log(x0l)));
		fx1l = (x1l + (log(x1l)));
		xml = (x0l + x1l)/2.0;
		fxml = (xml + (log(xml)));
//		printf("\n %d Voltas.\t xm: %f", n, xm);
//		printf("\nx0: %f; x1: %f; f(x0): %f ; f(x1): %f\n", x0, x1 , fx0, fx1);
						
		if (((fx0l || fx1l) == 0) || (fabs(fx0l - fx1l) < E)){
			if (fabs(fx0l) > fabs(fx1l)){
				printf("\nA raiz eh %.4f!\n", x1l);
			
			}else{
				printf("\nA raiz eh %.4f!\n", x0l);
			}
			
			laco = 1;
		
		}else if ((fx0l < 0) && (fx1l > 0)){
			if (fxml == 0){
				printf("\nA raiz eh %.4f!\n", xml);
				laco = 1;
			}else{
				if (fxml > 0){
					x1l = xml;
				}else{
					x0l = xml;
				}
			}
		
		}else{
			if (fxml == 0){
				printf("\nA raiz eh %.4f!\n", xml);
				laco = 1;
			}else{
				if (fxml > 0){
					x0l = xml;
				}else{
					x1l = xml;
				}
			}
		
		}
		
		n++;
	}

	getchar ();
	return 0;
}
