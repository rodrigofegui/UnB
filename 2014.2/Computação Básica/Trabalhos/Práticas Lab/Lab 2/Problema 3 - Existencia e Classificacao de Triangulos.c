#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Responável: Rodrigo F. Guimarães
// Turma: E
// Escreva um programa em C que solicita três valores A, B e C ao usuário, e verifica se esses valores satisfazem a
// condição de existência do triângulo. Caso essa condição seja satisfeita, classifique o triângulo em eqüilátero,
// isósceles ou escaleno.

int main ()
{
	
	float a, b, c;
	
	printf("Ola!\nVamos destrinchar o conhecimento sobre formacao de um triangulo...\n\nPara isso, digite um valor para um, possivel, lado do triangulo,\no 'A', em u.c. (unidade de comprimento):\n");
		scanf("%f", &a);
	printf("\nMuito bem! Agora, digite um valor para outro, possivel, lado do triangulo,\no 'B', tambem em u.c.:\n");
		scanf("%f", &b);
	printf("\nMuito bem! Agora, digite um valor para outro, possivel, lado do triangulo,\no 'C', tambem em u.c.:\n");
		scanf("%f", &c);

		
	if(!(a > fabs(b - c) && a < (b + c)) && !(b > fabs(a - c) && b < (a + c)) && !(c > fabs(a - b) && c < (a + b))){
		printf("\n\nCom as medidas fornecidas (%.2f, %.2f, %.2f) nao eh possivel construir\nnenhum triangulo.\nTente outros valores! Boa sorte!\n\n", a, b, c);
	}else{
		if ((a == b) && (a == c)){
			printf("\n\nCom as medidas fornecidas (%.2f, %.2f, %.2f) eh possivel construir um\ntriangulo EQUILATERO.\n\n", a, b, c);
		}else{
			if (((a == b) && (a != c)) || ((a == c) && (a != b)) || ((a == c) && (a != b))){
				printf("\n\nCom as medidas fornecidas (%.2f, %.2f, %.2f) eh possivel construir um\ntriangulo ISOSCELES.\n\n", a, b, c);
			}else{
				printf("\n\nCom as medidas fornecidas (%.2f, %.2f, %.2f) eh possivel construir um\ntriangulo ESCALENO.\n\n", a, b, c);
			}
			}
}
		
	getchar();
	return 0;
}
