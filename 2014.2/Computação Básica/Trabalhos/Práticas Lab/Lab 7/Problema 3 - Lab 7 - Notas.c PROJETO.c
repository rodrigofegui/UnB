#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define MAX 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float notas[MAX];
	int apr[MAX];
	float porcapro, porcrepro, *papro, *prepro;
	float numapro, numrepro, *apro, *repro;
	int i, n=0, resultado;
	
	for(i=0; i<MAX; i++){
		printf("digite a nota[%d]:", i);
		scanf("%f", &notas[i]);
	 }
	 
	 apro = &numapro;
	 repro = &numrepro;
	 papro = &porcapro;
	 prepro = &porcrepro;
	
	recebe_notas (notas, i, apr);
	conta_notas (apr, i, apro, repro);
	resultado = porcentagem_aprovados (numrepro, numapro, papro, prepro);
	system ("pause");
	system ("cls");
	
	printf("Quantidade de aprovados: %.0f\n", numapro);
	printf("Quantidade de reprovados: %.0f\n", numrepro);
	printf("Percentual de aprovados: %.2f\n", porcapro);
	printf("Percentual de reprovados: %.2f\n", porcrepro);
	
	if (resultado == 1)
		printf("Mais da metade da turma foi APROVADA!\n\n");
	else
		printf("Menos da metade da turma foi aprovada\n\n");

	system("pause");
	return 0;
}
