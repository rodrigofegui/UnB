/*****************************************************************
**  Projeto e Analise de Algoritmos - Turma A - 117536
**  Professor:
**				- Jan Correia
**  Responsável:
**				- Rodrigo Ferreira Guimarães - 140170740
**  Finalidades:
**              - Pesquisa de valores num dado vetor ordenado,
**              retornando sua posição ou -1 caso não exista.
*****************************************************************/
#include <stdio.h>

using namespace std;

int buscaBinaria (int *, int, int, int);

int main () {
	int N, Q, chave, entradas[100000];

	scanf ("%d %d", &N, &Q);

    for (int i = 0; i < N; i++) scanf ("%d", &entradas[i]);

	for (int i = 0; i < Q; i++){
		scanf ("%d", &chave);
		printf ("%d\n", buscaBinaria(entradas, 0, N - 1, chave));
	}
}

int buscaBinaria (int *vetor, int ini, int fim, int chave){
    if (ini > fim)
    return -1;
    int meio = (ini + fim) / 2;
    if (vetor[meio] == chave){
        if (meio == 0 || vetor[meio - 1] != chave)
            return meio;
        return buscaBinaria (vetor, ini, meio - 1, chave);
    }
    if (vetor[meio] > chave)
        return buscaBinaria(vetor, ini, meio - 1, chave);
    return buscaBinaria(vetor, meio + 1, fim, chave);
}
