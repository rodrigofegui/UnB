#include<stdio.h>
#include<stdlib.h>

void hanoi (int, int, int, int);

int main(){
	int numdiscos=0;
	printf("digite a quantidade de discos:");
	scanf("%d", &numdiscos);
	hanoi(numdiscos, 1, 3, 2 );
	printf("\n");
	system("pause");
	return 0;
	
}

void hanoi(int n, int origem, int destino, int intermediario ){
	if(n==1)
		printf("mover disco %d da torre %d para torre %d\n", n, origem, destino);

	else{
		hanoi(n-1, origem, intermediario, destino);
		printf("mover disco %d da torre %d para a torre %d\n", n, origem, destino);
		hanoi(n-1, intermediario, destino, origem);
	}

}

