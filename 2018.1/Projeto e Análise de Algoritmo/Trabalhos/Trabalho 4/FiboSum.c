#include <stdio.h>
#include <stdlib.h>

#define TAM_MTZ 2
#define CTRL_MOD 1000000007

long long fiboSum(long long);
long long fiboMatriz(long long);
void multQuadMatriz(long long [2][2], long long [2][2], long long [2][2]);
void multQuadMatriz2(long long [2][2], long long [2][2], long long [2][2]);
long long ajuste (long long);

int main (){
	long long qntPrb;
	long long limInf, limSup, soma;

	scanf("%lld", &qntPrb);

	while (qntPrb--){
		scanf("%lld %lld", &limInf, &limSup);

		soma = ajuste(fiboSum(limSup) - fiboSum(limInf - 1));

		if (soma < 0) soma += CTRL_MOD;

		printf("%lld\n", (soma % CTRL_MOD));
	}
	
	return 0;
}

long long fiboSum(long long num){
	return fiboMatriz(num + 2) - 1;
}

long long fiboMatriz (long long num){
	switch(num){
		case 0: return 0;
		case 1: return 1;
		case 2: return 1;
	}

	long long matrizBase[TAM_MTZ][TAM_MTZ] = {{1, 1}, {1, 0}};
	long long matriz[TAM_MTZ][TAM_MTZ] = {{1, 1}, {1, 0}};
	num--;

	while(--num)
		//multQuadMatriz(matriz, matrizBase, matriz);
		multQuadMatriz2(matriz, matrizBase, matriz);

	return ajuste(matriz[0][0]);
}

void multQuadMatriz(long long matA[2][2], long long matB[2][2], long long matC[2][2]){
	long long a = matA[0][0], b = matA[0][1], c = matA[1][0], d = matA[1][1];
	long long e = matB[0][0], f = matB[0][1], g = matB[1][0], h = matB[1][1];
	long long fat1 = (a * (f - h));
	long long fat2 = ((a + b) * h);
	long long fat3 = ((c + d) * e);
	long long fat4 = (d * (g - e));
	long long fat5 = ((a + d) * (e + h));
	long long fat6 = ((b - d) * (g + h));
	long long fat7 = ((a - c) * (e + f));
	
	matC[0][0] = (fat5 + fat4 - fat2 + fat6);
	matC[0][1] = (fat1 + fat2);
	matC[1][0] = (fat3 + fat4);
	matC[1][1] = (fat5 + fat1 - fat3 - fat7);
}

void multQuadMatriz2(long long matA[2][2], long long matB[2][2], long long matC[2][2]){
	matC[0][0] = ((matA[0][0] * matB[0][0]) + (matA[0][1] * matB[1][0]));
	matC[0][1] = ((matA[0][0] * matB[0][1]) + (matA[0][1] * matB[1][1]));
	matC[1][0] = ((matA[1][0] * matB[0][0]) * (matA[1][1] * matB[1][0]));
	matC[1][1] = ((matA[1][0] * matB[0][1]) * (matA[1][1] * matB[1][1]));
}

long long ajuste (long long num){
	return num % CTRL_MOD;
}