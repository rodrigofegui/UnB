#include <stdio.h>
#include <stdlib.h>

int bemvindo (void);
int mopera (int);
int moperabank (void);
void deposito (float *, int);
void saque (float *, int);
void transf (float *, int);

int main ()
{
	FILE *banco;
	int conta, ope, i;
	float saldo[4] = {0,0,0,0}, *s;
	
	s = saldo;
	
	banco = fopen ("banco.bin", "a+b");
	if (banco == NULL){
		printf("FALHA 2!!\n\n");
		exit(1);
	}
	
	for (i = 0; i < 4; i++){
		fread((s+i),sizeof(float), 1, banco);
	}

	fclose(banco);
	do{
		conta = bemvindo();

		while((conta < 0) || (conta > 4)){
			printf("\nConta Invalida! Tente Novamente!\nDigite sua conta ou 0-Sair:\n");
				scanf("%d", &conta);
		}

		if (conta == 0){
			printf("\nOperacao Finalizada!\n\n");
		}else{
			while((conta >= 1) && (conta <= 4)){	
				if ((conta >= 1) && (conta <= 3)){
					ope = mopera(conta);
					
					while ((ope < 0) || (ope > 4)){
						printf("\nOperacao Invalida! Tente Novamente!\n");
						printf("Digite a operacao:\n");
							scanf("%d", &ope);
					}

					switch (ope){
						case 0:{
							printf("\nOperacao Finalizada!\n\n");
							system("pause");
							system ("clear");
							conta = bemvindo ();
							break;
						}
						case 1:{
							deposito(s, conta);
							break;
						}
						case 2:{
							saque(s, conta);
							break;
						}
						case 3:{
							transf (s, conta);
							break;
						}
						case 4:{
							printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", saldo[conta-1]);		
							getchar();
						break;
						}
					}
				}else{
					ope = moperabank();
					
					while ((ope < 0) || (ope > 4)){
						printf("\nOperacao Invalida! Tente Novamente!\n");
						printf("Digite a operacao:\n");
							scanf("%d", &ope);
					}

					switch (ope){
						case 0:
							printf("\nOperacao Finalizada!\n\n");
							getchar();
							system ("clear");
							conta = bemvindo();
							break;
						case 1:
							printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", saldo[4]);
							system("pause");
							break;
					}
				}
			}
		}
	}while (conta > 0);
	
	banco = fopen("banco.bin", "wb");
	for (i = 0; i < 4; i++){
		fwrite((s+i),sizeof(float), 1, banco);
	}
	
	fclose(banco);
	
	getchar();
	return 0;
}

int bemvindo (){
	int conta;
	
	printf("\t***********************************\n");
	printf("\t\tPORTAL R.G.'s BANK\n");
	printf("\t***********************************\n");
	printf("\nDigite sua conta ou 0-Sair:\n");
		scanf("%d", &conta);
		
	return conta;
}

int mopera (int conta){
	int ope;
	
	getchar();
	system ("clear");
	printf("\n\t\tBEM-VINDO A CONTA %d!\n", conta);
	printf("\n\t***********************************\n");
	printf("\t\t     OPERACOES\n");
	printf("\t***********************************\n");
	printf("\n\t1 - Deposito\n");
	printf("\t2 - Saque\n");
	printf("\t3 - Transferencia\n");
	printf("\t4 - Saldo\n");
	printf("\t0 - Sair\n");
	printf("\n\t***********************************\n");
	printf("\nDigite a operacao: ");
		scanf("%d", &ope);
		
	return ope;
}

int moperabank (void){
	int ope;
	
	getchar();
	system ("clear");
	printf("\n\t    BEM-VINDO A CONTA DO BANCO!\n");
	printf("\n\t***********************************\n");
	printf("\t\t     OPERACOES\n");
	printf("\t***********************************\n");
	printf("\n\t1 - Saldo\n");
	printf("\t0 - Sair\n");
	printf("\n\t***********************************\n");
	printf("\nDigite a operacao: ");
		scanf("%d", &ope);
	
	return ope;
}

void deposito (float *s, int conta){
	float valor;
	
	printf("\nValor a ser depositado (RS): ");
		scanf("%f", &valor);
	*(s+(conta-1)) += valor;
	printf("\nDeposito realizado com sucesso!\n\n");
	
	getchar();
}

void saque (float *s, int conta){
	float valor;
		printf("\n Valor a ser sacado (RS):");
			scanf("%f", &valor);

		if (valor > *(s+(conta-1))){
			printf("\nSaldo insuficiente!\n\n");
		}else{
			*(s+(conta-1)) -= (valor * 1.0038);
			*(s+4) += (valor * 0.0038);
			printf("\nSaque realizado com sucesso!\n\n");
		}

	system("pause");
}

void transf (float *s, int conta){
	int contat;
	float valor;
	
	do{
		printf("\nConta receptora da transferencia: Conta ");
			scanf("%d", &contat);
	}while (contat < 1 || contat > 3);
	
	printf("\nValor a ser transferido (RS): ");
			scanf("%f", &valor);

	if(valor > *(s+(conta-1))){
		printf("\nSaldo insuficiente!\n\n");
	}else{
		*(s+4) += (valor * 0.0038);
		*(s+(contat-1)) += valor;
		*(s+(conta-1)) -= (valor * 1.0038);
		printf("\nTransferencia realizada com sucesso!\n\n");
	}

	getchar();
}
