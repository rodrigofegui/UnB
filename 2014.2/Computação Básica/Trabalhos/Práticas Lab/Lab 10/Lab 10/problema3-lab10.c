#include <stdio.h>
#include <stdlib.h>
void quicksort (int* , int, int );
int buscabinaria( int*, int, int, int );
int main(){
	int *vetor, n, i, inicio=0, fim, final, valor, resultado; 
		printf("digite o tamanho do vetor:");
		scanf("%d", &n);
		
	vetor=(int*)calloc(n, sizeof(int));
	for(i=0; i<n; i++){
		printf("digite o valor da posicao[%d]:", i);
		scanf("%d", &vetor[i]);
	}
	fim=n-1;
	quicksort(vetor, inicio, fim);
	
	printf("digite o valor a ser procurado:");
	scanf("%d", &valor);

	resultado=buscabinaria(vetor, inicio, fim, valor);
	if(resultado==-1)
	printf("O Valor Nao Esta no Vetor\n");
	else
		printf("A Posicao do vetor e: %d\n", resultado);
	 
	for(i=0; i<n; i++){
		printf("vetor[%d]:%d\n", i, vetor[i]);
	}
	
	
	free(vetor);
	system("pause");
	return 0;
}
void quicksort (int*vetor , int inicio, int fim ){
	int pivo=*(vetor+(inicio+fim)/2);
	int i=inicio, j=fim, temp;
	
		while(pivo> *(vetor+i))i++;
		
		while(pivo< *(vetor+j))j--;
		
		if(i<=j){
			temp=*(vetor+i);
			*(vetor+i)=*(vetor+j);
			*(vetor+j)= temp;
			i++;
			j--;
		}
	
		if(j>inicio)
			quicksort(vetor, inicio, j);
		if(i<fim)
			quicksort(vetor, i, fim);
}
int buscabinaria( int*vetor, int inicio, int fim, int valor ){
	int i;
	i=(fim+inicio)/2;
	if(inicio>fim) 
		return -1;
	
	if(*(vetor+i)==valor)
		return i;
	else if(*(vetor+i)<valor)
		return buscabinaria(vetor, (i+1), fim, valor);
	else 
		return buscabinaria(vetor, inicio, (i-1), valor);
	
}
