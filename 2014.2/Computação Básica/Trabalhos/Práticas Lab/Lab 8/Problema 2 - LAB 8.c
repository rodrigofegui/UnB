#include <stdio.h>
#include <stdlib.h>

int main(){
	int **matriz1, **matriz2, **matriz3;
	int i, j, fat, linha, lincol, col, soma=0;
	
	printf("Digite o numero de linhas da matriz A: ");
		scanf("%d", &linha);
	printf("\nDigite o numero de colunas da matriz A e linhas da matriz B: ");
		scanf("%d", &lincol);
	printf("\nDigite o numero de colunas da matriz B: ");
		scanf("%d", &col);
	
	matriz1 = (int**) calloc (linha, sizeof(int*));
	matriz2 = (int**) calloc (lincol, sizeof(int*));
	matriz3 = (int**) calloc (linha, sizeof(int*));
	
	if(matriz1==NULL||matriz2==NULL||matriz3==NULL){
		printf("FALHA!!!\n\n");
		exit (1);
		}	

	for(i = 0; i < linha; i++){
		*(matriz1 + i) = (int*) calloc (lincol, sizeof(int));
		if (*(matriz1 + i) == NULL){
			printf("FALHA 1!!!\n\n");
			exit (2);
		}	
	}

	for(i = 0; i < lincol; i++){
		*(matriz2 + i) = (int*) calloc (col, sizeof(int));
		if(*(matriz2 + i) == NULL){
			printf("FALHA 2!!!\n\n");
			exit (3);
		}	
	}

	for(i = 0; i < linha; i++){
		*(matriz3 + i) = (int*) calloc (col, sizeof(int));
		if(*(matriz3 + i) == NULL){
			printf("FALHA 3!!!\n\n");
			exit (4);
		}	
	}
	
	for(i = 0; i < linha; i++){
		for(j = 0; j < lincol; j++){
			printf("\nDigite o valor da matriz A[%d][%d]: ", i, j);
				scanf("%d", &matriz1[i][j]);
		}
	}
	
	for(i = 0; i < lincol; i++){
		for(j = 0; j < col; j++){
			printf("\nDigite o valor da matriz B[%d][%d]: ", i, j);
				scanf("%d", &matriz2[i][j]);
		}
	}
	
	printf("\n");
	
	for(i = 0; i < linha; i++){
		for(j = 0; j < col; j++){
			soma=0;
			for(fat = 0 ; fat < lincol; fat++){
				soma += matriz1[i][fat] * matriz2[fat][j];
			}
			matriz3[i][j] = soma;
		}
	}
	
	
	printf("Matriz A:\n\n");
	for(i = 0; i < linha; i++){
		for(j = 0; j < lincol; j++){
			printf("%d\t", matriz1[i][j]);
		}
		printf("\n\n");
	}
	
	printf("Matriz B:\n\n");
	for(i = 0; i < lincol; i++){
		for(j = 0; j < col; j++){
			printf("%d\t", matriz2[i][j]);
		}
		printf("\n\n");
	}
	
	printf("Matriz C:\n\n");
	for(i = 0; i < linha; i++){
		for(j = 0; j < col; j++){
			printf("%d\t", matriz3[i][j]);
		}
		printf("\n\n");
	}
	
	for(i = 0; i < linha; i++){
		free(*(matriz1 + i));
	}
	
	for(i = 0; i < lincol; i++){
		free(*(matriz2 + i));
	}
	
	for(i = 0; i < linha; i++){
		free(*(matriz3 + i));
	}
	
	free(matriz1);
	free(matriz2);
	free(matriz3);
	
	
	system("pause");
	return 0;	
}
	
