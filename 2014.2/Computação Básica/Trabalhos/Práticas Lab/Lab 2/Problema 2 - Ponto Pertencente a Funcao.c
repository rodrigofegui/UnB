#include <stdio.h>
#include <stdlib.h>

// Responável: Rodrigo F. Guimarães
// Turma: E
// Escreva um programa em C que solicita ao usuário coordenadas x e y do plano Cartesiano e
// verifica se esse ponto pertence à curva abaixo.

int main ()
{
	
	float x, y, r1, r2;
	
	printf("Olá\nVamos destrinchar o conhecimento sobre funcao, analise a funcao g(x):\n\t\t\tg(x) = 0, x <= 0;\n\t\t\tg(x) = x/3, 0 <= x <= 3;\n\t\t\tg(x) = -x/3 + 2, 3 <= x <= 6;\n\t\t\tg(x) = 0, x >= 6.\n\nAgora que sabe-se a g(x), digite a abscissa do seu par ordenado:\n");
		scanf("%f", &x);
	printf("\nMuito bem! Agora digite a ordenada do seu par ordenado:\n");
		scanf("%f", &y);

r1 = (x/3);
r2 = ((-x/3) + 2);

	if ((y < 0) ||(y > 1) || ((x < 0 || x > 6) && y != 0)){
		printf("\nA coordenada fornecida (%f,%f) nao pertence a funcao g(x).\nTente novamente!\n\n", x, y);
	}else{
		if (((x >= 0 && x <= 3) && y == r1) || ((x >= 3 && x <= 6) && y == r2) || ((x <= 0 || x >= 6) && y == 0))
			printf("\nA coordenada fornecida (%f,%f) pertence a funcao g(x).\n\n", x, y);
		else
			printf("\nA coordenada fornecida (%f,%f) nao pertence a funcao g(x).\nTente novamente!\n\n", x, y);
		}

	getchar();
	return 0;
}
