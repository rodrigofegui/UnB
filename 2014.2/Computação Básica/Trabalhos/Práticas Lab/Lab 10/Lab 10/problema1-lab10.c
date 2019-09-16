#include<stdio.h>
#include<stdlib.h>
int potencia(int, int);

int main(){
	int x, n, resultado;
		printf("digite o valor de x:");
		scanf("%d", &x);
		printf("digite o valor de n:");
		scanf("%d", &n);
		resultado=potencia(x,n);
		printf("resultado %d\n", resultado);
		system("pause");
		return 0;
		
}
int potencia(int x, int n){
	if(n==1)
		return x;
	else 
		return x*potencia(x, (n-1));
}
