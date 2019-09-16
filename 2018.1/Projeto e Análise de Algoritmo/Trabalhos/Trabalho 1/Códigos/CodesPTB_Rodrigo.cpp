/*****************************************************************
**  Projeto e Analise de Algoritmos - Turma A - 117536
**  Professor:
**				- Jan Correia
**  Responsável:
**				- Rodrigo Ferreira Guimarães - 140170740
**  Finalidades:
**              - Computar as mudanças de posição realizadas num
**				Insertion Sort não otimizado
*****************************************************************/
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long int mergesort(int[], int[], int, int);
unsigned long long merge(int[], int[], int, int, int);
unsigned long long int merge(int[], int);

int main(){
    int T, N;
    int entrada[200001];

    scanf("%d", &T);

    while(T--){
        scanf("%d", &N);

        for(int pos = 0; pos < N; pos++)
            scanf("%d", &entrada[pos]);

        printf("%llu\n", merge(entrada, N - 1));
    }

    return 0;
}

unsigned long long int merge(int orig[], int tam){
    int temp[200001];

    return mergesort(orig, temp, 0, tam);
}

unsigned long long int mergesort(int orig[], int temp[], int ini, int fim){
    unsigned long long int cont = 0;

    if(fim > ini){
        int meio = (ini + fim)/2;
        cont = mergesort(orig, temp, ini, meio);
        cont += mergesort(orig, temp, meio + 1, fim);
        cont += merge(orig, temp, ini, meio + 1, fim);
    }

    return cont;
}

unsigned long long merge(int orig[], int temp[], int ini, int meio, int fim){
    int pos = ini, pos2 = meio, posTmp = ini;
    unsigned long long int cont = 0;

    while((pos <= meio - 1) && (pos2 <= fim)){
        if(orig[pos] <= orig[pos2])
            temp[posTmp++] = orig[pos++];

        else{
            temp[posTmp++] = orig[pos2++];
            cont += (meio - pos);
        }
    }

    while(pos <= meio - 1)
        temp[posTmp++] = orig[pos++];

    while(pos2 <= fim)
        temp[posTmp++] = orig[pos2++];

    for(int ind = ini; ind <= fim; ind++)
        orig[ind] = temp[ind];

    return cont;
}
