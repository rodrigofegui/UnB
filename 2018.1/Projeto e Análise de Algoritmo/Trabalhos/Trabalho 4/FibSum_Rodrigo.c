#include <stdio.h>

#define LL long long
#define CTRL_MOD 1000000007

LL fibSum(int);
void mult(LL [2][2], LL [2][2]);
LL fib(int);

int main(){
	int limInf, limSup, qntPrbs;
	LL soma;
	
	scanf("%d", &qntPrbs);

	while(qntPrbs--){
  		scanf("%d %d", &limInf, &limSup);

  		soma = (fibSum(limSup) - fibSum(limInf-1)) % CTRL_MOD;

		if(soma < 0) soma += CTRL_MOD;

		soma %= CTRL_MOD;

  		printf("%lld\n", (soma % CTRL_MOD));
	}

	return 0;
}

LL fibSum (int num){
	return fib (num + 2) - 1;
}

LL fib (int num){
	int temp = 1;
	LL fibo[2][2] = {{1,0} , {0,1}};
	LL matriz[2][2] = {{0,1} , {1,1}};
	
	while(num > 0){
  		if(num & temp){
   			num -= temp;
   			mult(fibo, matriz);
		}

		temp <<= 1;
  		mult(matriz,matriz);
 	}

	return fibo[0][1] % CTRL_MOD;
}

void mult(LL fibo[2][2], LL matriz[2][2]){
	LL buffer[2][2];
	for(int lin = 0; lin < 2; lin++){
  		for(int col = 0; col < 2; col++){
			buffer[lin][col] = 0;
   			for(int ctrl = 0; ctrl < 2; ctrl++)
				buffer[lin][col] = (buffer[lin][col] + (fibo[lin][ctrl]) * (matriz[ctrl][col]) % CTRL_MOD) % CTRL_MOD;
		}
 	}

	for(int lin = 0; lin < 2; lin++)
		for(int col = 0; col < 2; col++)
			fibo[lin][col] = buffer[lin][col];
}



