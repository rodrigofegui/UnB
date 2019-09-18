#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 35
#define COL 28
#define IMG 240
#define NAVIO 78
#define AGUA 65

void regras (void);
void atribuicao (int *, int, int);
void imprimir (int *, int, int);
int maquina (int *, int*, int *, int *, int, int);
int homem (int *, int, int);

int main (){
	int campoh [LIN][COL], campom [LIN][COL], navio[3][5], *ph, *pm, *pn;
	int l, c;
	int posilm, posicm, posilh, posich;
	int sith = 0, sitm = 0, jogo = 0;
	
	system ("color 0c");
	printf ("****************************************\n\t    BATALHA NAVAL\n****************************************\n\n");
	
	pm = &campom [0][0];
	ph = &campoh [0][0];
	pn = &navio[0][0];
	regras ();
	atribuicao (pm, LIN, COL);
	atribuicao (ph, LIN, COL);
	atribuicao (pn, LIN, COL);
	imprimir (pm, LIN, COL);
	
	srand (time (NULL));
	l = rand() % (LIN-3);
	c = rand() % (COL-5);
	printf("linha: %d, coluna: %d\n", l,c);
	posilm = l;
	posicm = c;
	
	printf ("\nA maquina ja posicionou o navio.\n");
	printf ("\nSua vez de posicinar o navio:\nDigite o valor da coordenada da linha (0-%d): ", LIN-1);
		scanf ("%d", &l);
	printf ("Digite o valor da coordenada da coluna (0-%d): ", COL-1);
		scanf ("%d", &c);
	printf ("\n");
	
	posilh = l;
	posich = c;
	
	srand (time (NULL));
	l = rand() % (LIN-3);
	c = rand() % (COL-5);
	
	do{
		sith += homem (pm, posilm, posicm);
		sitm += maquina (ph, pn, &l, &c, posilh, posich);

		if ((sith >= 15) || (sitm >= 15)){
			jogo = 1;
		}else {
			jogo = 0;
		}

		printf ("\n\nPontuacao Acumulada:\nVoce: %d\tMaquina: %d\nJogo: %d\n\n", sith, sitm, jogo);
	
	
	
	}while (jogo == 0);
	
	if (sith >= 15) {
		printf ("\nParabens, VOCE Venceu!! O navio da maquina afundou!!!\n\n\n");
	}else if (sitm >= 15){
		printf ("\nA MAQUINA Venceu o.o !! O seu navio afundou!!!\n\n\n");
	}
	
	system ("pause");
	return 0;
}

void regras (void){
	printf ("Bem-Vindo ao Jogo Batalha Naval!\nVamos as Regras:\n");
	printf ("\n1. O jogo consiste de um tabuleiro com %d linhas e %d colunas;\n", LIN, COL);
	printf ("\n2. O barco ocupa 3x5 posicoes;\n");
	printf ("\n3. Sera uma partida de voce contra a maquina, quem afundar\no navio do oponente primeiro eh consagrado VENCEDOR;\n");
	printf ("\n4. A maquina posicionara o navio primeiro, e depois de permitido\nvoce podera posicionar o seu;\n");
	printf ("\n5. Quem inicia a rodada eh voce, seguido pela maquina, ficando nesse\nrevezamento ateh haver um vencedor;\n");
	printf ("\n6. Feito a apresentacao das regras, diverta-se e um bom jogo, e\nque venca o melhor kkkkkkkkkk!\n\n");
	system ("pause");
	system ("cls");	
}

void atribuicao (int *p, int linha, int coluna){
	int i, j;
	
	for (i = 0; i < linha; i++){
		for (j = 0; j < coluna; j++){
			*(p+i*COL+j) = IMG;
		}
	}
}

void imprimir (int *p, int linha, int coluna){	
	int i, j;
	
	printf ("****************************************\n\t    BATALHA NAVAL\n****************************************\n\nL%c C%c\t", 25, 26);
	for (j = 0; j < coluna; j++)
		printf ("%d\t", j);
	printf ("\n");
		
	for (i = 0; i < linha; i++){
		printf ("%d\t", i);
		for (j = 0; j < coluna; j++){
			printf ("%c\t", *(p+i*coluna+j));
		}
		printf ("\n\n");
	}
	
}

int homem (int *p, int linha, int coluna){
	int l, c, cont=0;
	
	system ("pause");
	system ("cls");
	system ("color 0a");
	printf ("SUA VEZ!\n");
	do{
	printf ("\nDigite o valor da coordenada da linha (0-%d): ", LIN-1);
		scanf ("%d", &l);
	printf ("\nDigite o valor da coordenada da coluna (0-%d): ", COL-1);
		scanf ("%d", &c);
	printf ("\n");
	}while ((l < 0 || l >= LIN) || (c < 0 || c >= COL));

	if ((l >= linha && l <= linha+2) && (c >= coluna && c <= coluna+4)){
		if (*(p+l*COL+c) != NAVIO)
			cont++;
		*(p+l*COL+c) = NAVIO;
	}else {
		if (*(p+l*COL+c) != AGUA)
			*(p+l*COL+c) = AGUA;
	}

	imprimir (p, LIN, COL);

	if (cont == 0)
		return 0;
	return 1;
}

int maquina (int *p, int *pn, int *tirol, int *tiroc, int linha, int coluna){
	int cont = 0;
	
	system ("pause");
	system ("cls");
	system ("color f0");
	printf ("VEZ DA MAQUINA!\n");
	
	srand (time(NULL));
	do{
		if ((((*tirol) >= linha && (*tirol) <= linha+2) && ((*tiroc) >= coluna && (*tiroc) <= coluna+4)) && (*(pn+(((*tirol)-linha)*5)+((*tiroc)-coluna)) == NAVIO)){
				*tirol = (rand() % 3) + linha;
				*tiroc = (rand() % 5) + coluna;
		}
		
	}while(*(pn+(((*tirol)-linha)*5)+((*tiroc)-coluna)) == NAVIO);
	printf ("Tiro na linha %d, coluna %d\n\n", *tirol, *tiroc);
		
	if (((*tirol) >= linha-2 && (*tirol) <= linha+4) && ((*tiroc) >= coluna-4 && (*tiroc) <= coluna+8)){
		if (((*tirol) >= linha && (*tirol) <= linha+2) && ((*tiroc) >= coluna && (*tiroc) <= coluna+4)){
			if (*(p+((*tirol)*COL)+(*tiroc)) != NAVIO){
				cont++;
			}
			*(p+((*tirol)*COL)+(*tiroc)) = NAVIO;
			*(pn+(((*tirol)-linha)*5)+((*tiroc)-coluna)) = NAVIO;
			*tirol = (rand() % 3) + linha;
			*tiroc = (rand() % 5) + coluna;
		}else{
			*(p+((*tirol)*COL)+(*tiroc)) = AGUA;
			*tirol = ((rand() % 5) - 2) + linha;
			*tiroc = ((rand() % 9) - 4) + coluna;
		}
		
	}else{
		*(p+((*tirol)*COL)+(*tiroc)) = AGUA;
		*tirol = rand()%(LIN-3);
		*tiroc = rand()%(COL-5);
	}
	
	system("pause");
	imprimir (p, LIN, COL);
	imprimir (pn, 3, 5);

	if (cont == 0)
		return 0;
	return 1;
}
