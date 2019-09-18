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

	do{
		getchar();
		system("cls");
		printf("\t***********************************\n\t\tPORTAL R.G.'s BANK\n\t***********************************\n");
		printf("\nDigite sua conta ou 0-Sair:\n");
			scanf("%d", &conta);

		if ((conta < 0) || (conta > 4)){
			printf("\nConta Invalida!");
			
		}else if (conta == 0){
			printf("\nOperacao Finalizada!\n\n");
			
		}else if ((conta >= 1) && (conta <=3)){
			getchar ();
			system ("cls");
 			printf("\t\tBEM-VINDO A CONTA %d!\n", conta);
 			
			do{
			printf("\n\t***********************************\n\t\t     OPERACOES\n\t***********************************\n");
			printf("\n\t1 - Deposito\n\t2 - Saque\n\t3 - Transferencia\n\t4 - Saldo\n\t0 - Sair\n");
			printf("\n\t***********************************\n\nDigite a operacao: ");
				scanf("%d", &ope);

			if ((ope < 0) || (ope > 4))
				printf("\nOperacao Invalida! Tente Novamente!\n");

			}while ((ope < 0) || (ope > 4));

			switch (ope){
				case 0:
					printf("\nOperacao Finalizada!\n\n");
					break;

				case 1:{
					printf("\nValor a ser depositado (RS): ");
						scanf("%f", &dep);

					switch (conta){
						case 1:
							sldc1 += dep;			
							break;

						case 2:
							sldc2 += dep;
							break;

						case 3:
							sldc3 += dep;
							break;
						}

					printf("\nDeposito realizado com sucesso!\n\n");
					getchar();
					break;
				}

				case 2:{
					printf("\n Valor a ser sacado (RS):");
						scanf("%f", &sac);

					if (sac > sldc1){
						printf("\nSaldo insuficiente!\n\n");
					}else{

						switch (conta){
						case 1:
							sldc1 -= (sac * 1.038);
							break;

						case 2:
							sldc2 -= (sac * 1.038);
							break;

						case 3:
							sldc3 -= (sac * 1.038);
							break;
					}

						sldcb += (0.038 * sac);
						printf("\nSaque realizado com sucesso!\n\n");
					}
					getchar();
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
						sldcb += (0.038 * transf);

						switch (contat){
							case 1:
								sldc1 += transf;
								break;

							case 2:
								sldc2 += transf;
								break;

							case 3:
								sldc3 += transf;
								break;
						}

						switch (conta){
						case 1:
							sldc1 -= (1.038 * transf);
							break;

						case 2:
							sldc2 -= (1.038 * transf);
							break;

						case 3:
							sldc3 -= (1.038 * transf);
							break;
					}

						printf("\nTransferencia realizada com sucesso!\n\n");
					}

					getchar();
					break;
				}

				case 4:
					switch (conta){
						case 1:
							printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", sldc1);
							break;

						case 2:
							printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", sldc2);
							break;

						case 3:
							printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", sldc3);
							break;
					}
					
					getchar();
					break;
			}
		}else{
			printf("\n\n\t    BEM-VINDO A CONTA DO BANCO!\n");
			
			do{
			printf("\n\t***********************************\n\t\t     OPERACOES\n\t***********************************\n");
			printf("\n\t1 - Saldo\n\t0 - Sair\n");
			printf("\n\t***********************************\n\nDigite a operacao: ");
				scanf("%d", &ope);

			if ((ope < 0) || (ope > 1))
				printf("\nOperacao Invalida! Tente Novamente!\n");
				
			}while ((ope < 0) || (ope > 1));

			switch (ope){
				case 0:
					printf("\nOperacao Finalizada!\n\n");
					break;

				case 1:
					printf("\nO saldo disponivel (RS) eh: %.2f.\n\n", sldcb);
					break;
			}
		}

	}while(conta != 0);

	getchar();
	return 0;
}
