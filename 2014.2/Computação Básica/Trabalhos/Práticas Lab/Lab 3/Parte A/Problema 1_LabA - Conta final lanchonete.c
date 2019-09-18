#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Responsável / Turma: Rodrigo Guimarães / E
// Mostrar Menu de uma lanchonete,coletar o pedido e imprimir o valor final da compra.

int main()
{
	
	int p, t;
	float cont = 0;
	
	printf("Bem-vindo a  Lanch-EC! Acompanhe nosso menu:\n\n**********************\n");
	printf("\tMENU\n**********************\n\n");
	printf("1 - Fome-Zero:\n\tHamburguer e pao.\n\n2 - R.U.:\n\tQueijo, alface, tomate, hamburguer e pao.\n\n3 - E.Batista:\n\tBacon, ovo frito, 2 queijos, 2 hamburgueres,\n\talface, tomate e pao.\n");
	printf("\n**********************\n\nQual a opcao escolhida?\n");
	scanf("%d", &p);
	
	t = clock ();
	
		switch (p){
			
			case 3:
				cont = (0.6 + 0.7 + 0.25 + 1.5);
			
			case 2:
				cont += (0.5 + 0.5 + 0.5);
			
			case 1:
				cont += (1.5 + 0.5);
				break;
		
			default:
				printf("\n\nOperacao invalida!");
			
	}

	printf("\n\nO total a pagar eh RS %.2f .\n", cont);
	printf("\nDemorei %d clicks, ou %f seg, para calcular.\n\n", t,((float)t)/CLOCKS_PER_SEC);

	getchar();
	return 0;
}
