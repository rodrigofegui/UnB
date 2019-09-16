#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void recebe_notas (float*, int, int*);
void conta_notas (int*, int, float*, float*);
int porcentagem_aprovados (float, float, float*, float*);

int main(){
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
	
	printf("Quantidade de aprovados: %.0f\n", numapro);
	printf("Quantidade de reprovados: %.0f\n", numrepro);
	printf("Percentual de aprovados: %.2f\n", porcapro);
	printf("Percentual de reprovados: %.2f\n", porcrepro);
	
	if(resultado == 1)
		printf("Mais da metade da turma foi APROVADA!\n\n");
	else
		printf("Menos da metade da turma foi aprovada\n\n");

	system("pause");
	return 0;
}

void recebe_notas (float*notas, int n, int *apr){
int i;

	for(i=0; i<n; i++){
		if (*(notas+i) >= 6.0)
			*(apr+i)=1;
		else
			*(apr+i)=0;	
	}
}

void conta_notas (int *apr , int n, float *apro, float *repro){
int i, qntapro=0, qntrepro=0;

	for(i=0; i<n; i++){
		if(*(apr+i)==1)
			qntapro++;
		else
			qntrepro++;
	}

	*apro = qntapro;
	*repro = qntrepro;
}

int porcentagem_aprovados (float numrepro, float numapro, float *papro, float *prepro){
	
	*papro = (numapro / (numapro+numrepro)) * 100.0;
	*prepro = (numrepro / (numapro+numrepro)) * 100.0;
	
	if(*papro > 50.0)
		return 1;
	return 0;
}
