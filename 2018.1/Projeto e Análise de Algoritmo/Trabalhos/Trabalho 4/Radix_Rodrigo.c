#include <stdio.h>
#include <stdlib.h>

#define BASE_NUM 10

void radixSort(int *, int);
int maxVet(int *, int);

int main (){
    int tam;
	scanf("%d", &tam);
	
	int val[tam], cnt = 0;
	
	while (cnt < tam)
		scanf("%d", &val[cnt++]);
		
	radixSort(val, tam);
	
	for (cnt = 0; cnt < tam; cnt++)
		printf("%d\n", val[cnt]);

    return 0;
}

void radixSort(int *vet, int tam){
	int semiOrd[tam];
	int digitoSignificativo = 1;
	int max = maxVet(vet, tam);

	while (max / digitoSignificativo > 0){
		int buffer[BASE_NUM] = { 0 };

		for (int pos = 0; pos < tam; pos++)
			buffer[(vet[pos] / digitoSignificativo) % BASE_NUM]++;

		for (int pos = 1; pos < BASE_NUM; pos++)
			buffer[pos] += buffer[pos - 1];

		for (int pos = tam - 1; pos >= 0; pos--)
			semiOrd[--buffer[(vet[pos] / digitoSignificativo) % BASE_NUM]] = vet[pos];


		for (int pos = 0; pos < tam; pos++)
			vet[pos] = semiOrd[pos];

		digitoSignificativo *= BASE_NUM;
	}
}

int maxVet(int *vet, int tam){
  int i;
  int max = -1;
  
  for(int pos = 0; pos < tam; pos++)
    if(vet[pos] > max)
      max = vet[pos];
  
  return max;
}