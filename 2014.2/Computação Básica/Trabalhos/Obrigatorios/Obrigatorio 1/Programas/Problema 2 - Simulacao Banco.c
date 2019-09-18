#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Responsável / Turma: Rodrigo Guimarães / E
// Escreva um programa em linguagem C que gerencia algumas transações bancárias:
// a) Criar 03 contas bancárias; b) Simular operações de depósito nestas contas.

int main ()
{
	
	int conta, contat, ope = 0;
	float sldc1 = 0, sldc2 = 0, sldc3 = 0, sldcb = 0, dep, sac, transf;
	
// Página Inicial
	printf("\t***********************************\n\t\tPORTAL R.G.'s BANK\n\t***********************************\n");
	printf("\nDigite sua conta ou 0-Sair:\n");
		scanf("%d", &conta);
		
// Conta Inválida
	while((conta < 0) || (conta > 4)){
		printf("\nConta Invalida! Tente Novamente!\nDigite sua conta ou 0-Sair:\n");
			scanf("%d", &conta);
	}
	
// Saída Menu Principal, pela Conta 0
	if (conta == 0){
		printf("\nOperacao Finalizada!\n\n");
	}
	
// Operação Banco
	while((conta >=1) && (conta <= 4)){
		
// Escolha da Conta
	switch (conta){
	
	// Controle Conta 1
		case 1:{
			printf("\n\n\t\tBEM-VINDO A CONTA 1!\n");
			printf("\n\t***********************************\n\t\t     OPERACOES\n\t***********************************\n");
			printf("\n\t1 - Deposito\n\t2 - Saque\n\t3 - Transferencia\n\t4 - Saldo\n\t0 - Sair\n");
			printf("\n\t***********************************\n\nDigite a operacao: ");
				scanf("%d", &ope);
				
			while ((ope < 0) || (ope > 4)){
				printf("\nOperacao Invalida! Tente Novamente!\n");
				printf("Digite a operacao:\n");
					scanf("%d", &ope);
			}
			
			switch (ope){
				case 0:{
					printf("\nOperacao Finalizada!\n\n");
					printf("\n\n\t***********************************\n\t\tPORTAL R.G.'s BANK\n\t***********************************\n");
					printf("\nDigite sua conta ou 0-Sair:\n");
						scanf("%d", &conta);
					break;
				}
					
				case 1:{
					printf("\nValor a ser depositado (RS): ");
						scanf("%f", &dep);
					sldc1 += dep;
					printf("\nDeposito realizado com sucesso!\n\n");
					break;
				}
				
				case 2:{
					printf("\n Valor a ser sacado (RS):");
						scanf("%f", &sac);
						
					if (sac > sldc1){
						printf("\nSaldo insuficiente!\n\n");
					}else{
						sldcb += (0.38 * sac);
						sldc1 -= sac;
						printf("\nSaque realizado com sucesso!\n\n");
					}
					break;
				}
				
				case 3:{
					printf("\nConta receptora da transferencia: Conta ");
						scanf("%d", &contat);
					printf("\nValor a ser transferido (RS): ");
						scanf("%f", &transf);
						
					if(transf > sldc1){
						printf("\nSaldo insuficiente!\n\n");
					}else{
						sldcb += (0.38 * transf);
						sldc1 -= (1.38 * transf);
						
						switch (contat){
							case 2:
								sldc2 += transf;
								break;
								
							case 3:
								sldc3 += transf;
								break;
						}
						printf("\nTransferencia realizada com sucesso!\n\n");
					}
					break;
				}
				
				case 4:
					printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", sldc1);
					break;
			}
			
			break;
		}
		
	// Controle Conta 2	
		case 2:{
			printf("\n\n\t\tBEM-VINDO A CONTA 2!\n");
			printf("\n\t***********************************\n\t\t     OPERACOES\n\t***********************************\n");
			printf("\n\t1 - Deposito\n\t2 - Saque\n\t3 - Transferencia\n\t4 - Saldo\n\t0 - Sair\n");
			printf("\n\t***********************************\n\nDigite a operacao: ");
				scanf("%d", &ope);
				
			while ((ope < 0) || (ope > 4)){
				printf("\nOperacao Invalida! Tente Novamente!\n");
				printf("Digite a operacao:\n");
					scanf("%d", &ope);
			}
			
			switch (ope){
				case 0:{
					printf("\nOperacao Finalizada!\n\n");
					printf("\n\n\t***********************************\n\t\tPORTAL R.G.'s BANK\n\t***********************************\n");
					printf("\nDigite sua conta ou 0-Sair:\n");
						scanf("%d", &conta);
					break;
				}
					
				case 1:{
					printf("\nValor a ser depositado (RS): ");
						scanf("%f", &dep);
					sldc2 += dep;
					printf("\nDeposito realizado com sucesso!\n\n");
					break;
				}
				
				case 2:{
					printf("\n Valor a ser sacado (RS):");
						scanf("%f", &sac);
						
					if (sac > sldc2){
						printf("\nSaldo insuficiente!\n\n");
					}else{
						sldcb += (0.38 * sac);
						sldc2 -= sac;
						printf("\nSaque realizado com sucesso!\n\n");
					}
					break;
				}
				
				case 3:{
					printf("\nConta receptora da transferencia: Conta ");
						scanf("%d", &contat);
					printf("\nValor a ser transferido (RS): ");
						scanf("%f", &transf);
						
					if(transf > sldc2){
						printf("\nSaldo insuficiente!\n\n");
					}else{
						sldcb += (0.38 * transf);
						sldc2 -= (1.38 * transf);
						
						switch (contat){
							case 1:
								sldc1 += transf;
								break;
								
							case 3:
								sldc3 += transf;
								break;
						}
						printf("\nTransferencia realizada com sucesso!\n\n");
					}
					break;
				}
				
				case 4:
					printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", sldc2);
					break;
			}
			
			break;
		}
		
	// Controle Conta 3	
		case 3:{
			printf("\n\n\t\tBEM-VINDO A CONTA 3!\n");
			printf("\n\t***********************************\n\t\t     OPERACOES\n\t***********************************\n");
			printf("\n\t1 - Deposito\n\t2 - Saque\n\t3 - Transferencia\n\t4 - Saldo\n\t0 - Sair\n");
			printf("\n\t***********************************\n\nDigite a operacao: ");
				scanf("%d", &ope);
				
			while ((ope < 0) || (ope > 4)){
				printf("\nOperacao Invalida! Tente Novamente!\n");
				printf("Digite a operacao:\n");
					scanf("%d", &ope);
			}
			
			switch (ope){
				case 0:{
					printf("\nOperacao Finalizada!\n\n");
					printf("\n\n\t***********************************\n\t\tPORTAL R.G.'s BANK\n\t***********************************\n");
					printf("\nDigite sua conta ou 0-Sair:\n");
						scanf("%d", &conta);
					break;
				}
					
				case 1:{
					printf("\nValor a ser depositado (RS): ");
						scanf("%f", &dep);
					sldc3 += dep;
					printf("\nDeposito realizado com sucesso!\n\n");
					break;
				}
				
				case 2:{
					printf("\n Valor a ser sacado (RS):");
						scanf("%f", &sac);
						
					if (sac > sldc2){
						printf("\nSaldo insuficiente!\n\n");
					}else{
						sldcb += (0.38 * sac);
						sldc2 -= sac;
						printf("\nSaque realizado com sucesso!\n\n");
					}
					break;
				}
				
				case 3:{
					printf("\nConta receptora da transferencia: Conta ");
						scanf("%d", &contat);
					printf("\nValor a ser transferido (RS): ");
						scanf("%f", &transf);
						
					if(transf > sldc3){
						printf("\nSaldo insuficiente!\n\n");
					}else{
						sldcb += (0.38 * transf);
						sldc3 -= (1.38 * transf);
						
						switch (contat){
							case 1:
								sldc1 += transf;
								break;
								
							case 2:
								sldc2 += transf;
								break;
						}
						printf("\nTransferencia realizada com sucesso!\n\n");
					}
					break;
				}
				
				case 4:
					printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", sldc3);
					break;
			}
			
			break;
		}
		
	// Exposição Conta R.G.'s Bank	
		case 4:{
			printf("\n\n\t    BEM-VINDO A CONTA DO BANCO!\n");
			printf("\n\t***********************************\n\t\t     OPERACOES\n\t***********************************\n");
			printf("\n\t1 - Saldo\n\t0 - Sair\n");
			printf("\n\t***********************************\n\nDigite a operacao: ");
				scanf("%d", &ope);
				
			while ((ope < 0) || (ope > 4)){
				printf("\nOperacao Invalida! Tente Novamente!\n");
				printf("Digite a operacao:\n");
					scanf("%d", &ope);
			}
			
			switch (ope){
				case 0:
					printf("\nOperacao Finalizada!\n\n");
					printf("\n\n\t***********************************\n\t\tPORTAL R.G.'s BANK\n\t***********************************\n");
					printf("\nDigite sua conta ou 0-Sair:\n");
						scanf("%d", &conta);
					break;
				
				case 1:
					printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", sldcb);
					break;
			}
			
			break;
		}
		
			}
}
	
	getchar ();
	return 0;
}
