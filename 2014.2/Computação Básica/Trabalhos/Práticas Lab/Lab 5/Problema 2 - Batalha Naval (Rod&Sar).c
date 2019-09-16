#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lin 20
#define col 20
#define img 240
#define navio 78
#define agua 65

int main (){
	int batnav[lin][col];
	int l, c, i, j;
	int posil, posic, n, laco;
	
	system ("color 0b");
	printf("****************************************\n\t    BATALHA NAVAL\n****************************************\n\n");
	printf("O campo possui %d linhas e %d colunas.\nO barco eh um quadrado 3x5. Diverta-se!!\n\n\n\t", lin, col);
	
	for (c = 0; c < col; c++)
		printf("%d\t", c);
	printf("\n");
		
	for (l = 0; l < lin; l++){
		printf("%d\t", l);
		for (c = 0; c < col; c++){
			batnav[l][c] = img;
			printf("%c\t", batnav[l][c]);
		}
		printf("\n\n");
	}
	
	srand(time(NULL));
	l=rand()%(lin-3);
	c=rand()%(col-5);
	posil = l;
	posic = c;
//	printf("%d,%d\n", l,c);
	n=0;
	printf("\nNavio posicionado! Que o jogo comece...\n");


	do{	
		printf("\nDigite o valor coordenada da linha (0-%d): ", lin-1);
			scanf("%d", &i);
		printf("\nDigite o valor coordenada da coluna (0-%d): ", col-1);
			scanf("%d", &j);
		printf("\n");

		if ((i >= posil && i <= posil+2) && (j >= posic && j <= posic+4)){
			if (batnav[i][j] != navio)
				n++;
			batnav[i][j] = navio;
		}else{
			if (batnav[i][j] != agua)
				batnav[i][j] = agua;
		}

		printf("\t");
		for (c = 0; c < col; c++)
			printf("%d\t", c);
		printf("\n");
		
		for (l = 0; l < lin; l++){
			printf("%d\t", l);
			for (c = 0; c < col; c++){
				printf("%c\t", batnav[l][c]);
			}
			printf("\n\n");
		}

		if (n < 15)
			laco = 0;
		else{
			laco = 1;
			printf("\nParabens, Voce Venceu!! O navio afundou!!!\n\n\n");
		}

		printf ("Ja acertou %d tiros, falta %d!\n\n", n, 15-n);
		system ("pause");
		system ("cls");

	}while(laco != 1);
	
	system ("pause");
	return 0;
}
