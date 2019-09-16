#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct CABECA{
	unsigned char numagico[2];
	unsigned long int tamarquivo, aplicacao, deslocamento, bytecabeca, colunas, linhas, coresusdas;
	unsigned long int numbits, compressao, dadosbrutos, resoluhori, resoluvert, numcores, coresimport;
};

void INICIASTRUCT (struct CABECA *);
void IMPRIMESTRUCT (struct CABECA *);
void LERCABECA (struct CABECA *, char *);
void LERDADOS (unsigned char **, unsigned char **, unsigned char **, struct CABECA*, char *, int, int*);
unsigned char **ALOCAPLANO (struct CABECA *, int);
void DESALOCAPLANO (unsigned char **, struct CABECA *, int);
void IMPRIMEPLANO (unsigned char **, struct CABECA *, int);
void FILTROMEDIA (struct CABECA *, unsigned char **, unsigned char **, int);
void ESCREVECABECA (struct CABECA *, char *);
void ESCREVEDADOS (unsigned char **, unsigned char **, unsigned char **, struct CABECA*, char *, int*);

int main (){
	struct CABECA cabeca;
	unsigned char **planoR, **planoG, **planoB, **planoRF, **planoGF, **planoBF;
	int filtro = 3, pad = 0;
	char arq[50] = "\0", arqnovo[50] = "\0";
	FILE *leitura;
	
	INICIASTRUCT (&cabeca);
	printf ("\nDigite o nome da imagem origem, com '.bmp' no final do nome: ");
		scanf ("%[^\n]", arq);
	getchar();
	printf ("\nDigite o nome da imagem destino, com '.bmp' no final do nome: ");
		scanf ("%[^\n]", arqnovo);
	do{
	printf ("\nDigite o tamanho do filtro de media a ser implementado, validos acima de 3 e impares apenas: ");
		scanf("%d", &filtro);
		if (filtro < 3 || (filtro%2) == 0){
			printf("Valor invalido! Digite novamente!!");
		}
	}while(filtro < 3 || (filtro%2) == 0);
		
	LERCABECA (&cabeca, arq);
	IMPRIMESTRUCT (&cabeca);
	
	pad = (cabeca.colunas*3)%4;
	planoR = ALOCAPLANO (&cabeca, filtro);
	planoG = ALOCAPLANO (&cabeca, filtro);
	planoB = ALOCAPLANO (&cabeca, filtro);
	planoRF = ALOCAPLANO (&cabeca, 0);
	planoGF = ALOCAPLANO (&cabeca, 0);
	planoBF = ALOCAPLANO (&cabeca, 0);
		printf ("\n\nALOCACAO REALIZADA COM SUCESSO!!\n");
	LERDADOS (planoB, planoG, planoR, &cabeca, arq, filtro, &pad);
		printf ("\nLEITURA DE DADOS REALIZADA COM SUCESSO!!\n");
	FILTROMEDIA (&cabeca, planoB, planoBF, filtro);
		printf ("\nFILTRO DE MEDIA DO PLANO B, REALIZADA COM SUCESSO!!\n");
	FILTROMEDIA (&cabeca, planoG, planoGF, filtro);
		printf ("\nFILTRO DE MEDIA DO PLANO G, REALIZADA COM SUCESSO!!\n");
	FILTROMEDIA (&cabeca, planoR, planoRF, filtro);
		printf ("\nFILTRO DE MEDIA DO PLANO R, REALIZADA COM SUCESSO!!\n");
	ESCREVECABECA (&cabeca, arqnovo);
		printf ("\nCABECALHO ESCRITO COM SUCESSO!!\n");
	ESCREVEDADOS (planoBF, planoGF, planoRF, &cabeca, arqnovo, &pad);
		printf ("\nDADOS ESCRITOS COM SUCESSO!!\n");
	DESALOCAPLANO (planoR, &cabeca, filtro);
		printf ("\nDESALOCACAO PLANO R REALIZADA COM SUCESSO!!\n");
	DESALOCAPLANO (planoG, &cabeca, filtro);
		printf ("\nDESALOCACAO PLANO G REALIZADA COM SUCESSO!!\n");
	DESALOCAPLANO (planoB, &cabeca, filtro);
		printf ("\nDESALOCACAO PLANO B REALIZADA COM SUCESSO!!\n");
	DESALOCAPLANO (planoRF, &cabeca, 0);
		printf ("\nDESALOCACAO PLANO RF REALIZADA COM SUCESSO!!\n");
	DESALOCAPLANO (planoGF, &cabeca, 0);
		printf ("\nDESALOCACAO PLANO GF REALIZADA COM SUCESSO!!\n");
	DESALOCAPLANO (planoBF, &cabeca, 0);
		printf ("\nDESALOCACAO PLANO BF REALIZADA COM SUCESSO!!\n\n\n");
	
	system ("pause");
	return 0;
}

void INICIASTRUCT (struct CABECA *cabeca){
	cabeca->numagico[0] = '\0';	cabeca->numagico[1] = '\0';
	cabeca->tamarquivo = 0; cabeca->aplicacao = 0; cabeca->deslocamento = 0; cabeca->bytecabeca = 0;
	cabeca->colunas = 0; cabeca->linhas = 0; cabeca->coresusdas = 0; cabeca->numbits = 0;
	cabeca->compressao = 0;	cabeca->dadosbrutos = 0; cabeca->resoluhori = 0;
	cabeca->resoluvert = 0;	cabeca->numcores = 0; cabeca->coresimport = 0;
}

void IMPRIMESTRUCT (struct CABECA *cabeca){
	system ("pause");
	system ("cls");
	printf ("\t\tCABECALHO\n\n");
	printf ("Codificacao extensao: %c %c\n", cabeca->numagico[0], cabeca->numagico[1]);
	printf ("Tamanho do arquivo: %d\n", cabeca->tamarquivo);
	printf ("Aplicacao Especiica: %d\n", cabeca->aplicacao);
	printf ("Deslocamento: %d\n", cabeca->deslocamento);
	printf ("Numero de bytes no cabecalho, a partir desse ponto: %d\n", cabeca->bytecabeca);
	printf ("Colunas na imagem bitmap: %d\n", cabeca->colunas);
	printf ("Linhas na imagem bitmap: %d\n", cabeca->linhas);
	printf ("Numero do plano de cores a ser usados: %d\n", cabeca->coresusdas);
	printf ("Numero de bits/pixel: %d\n", cabeca->numbits);
	printf ("Compressao usada: %d\n", cabeca->compressao);
	printf ("Tamanho de dados brutos, apos o cabecalho: %d\n", cabeca->dadosbrutos);
	printf ("Resolucao Horizontal: %d\n", cabeca->resoluhori);
	printf ("Resolucao Vertical: %d\n", cabeca->resoluvert);
	printf ("Numero de cores na paleta: %d\n", cabeca->numcores);
	printf ("Cores Importantes: %d\n\n", cabeca->coresimport);
	system ("pause");
}

void LERCABECA (struct CABECA *cabeca, char *arquivo){
	FILE *leitura;
	leitura = fopen (arquivo, "rb");
	if (leitura == NULL){
		printf ("ERRO ABERTURA PARA LEITURA CABECALHO!\n\n");
		exit (1);
	}
	fread (&cabeca->numagico[0], sizeof(char), 1, leitura);
	fread (&cabeca->numagico[1], sizeof(char), 1, leitura);
	fread (&cabeca->tamarquivo, sizeof(int), 1, leitura);
	fread (&cabeca->aplicacao, sizeof(int), 1, leitura);
	fread (&cabeca->deslocamento, sizeof(int), 1, leitura);
	fread (&cabeca->bytecabeca, sizeof(int) , 1, leitura);
	fread (&cabeca->colunas, sizeof(int) , 1, leitura);
	fread (&cabeca->linhas, sizeof(int) , 1, leitura);
	fread (&cabeca->coresusdas, sizeof(char), 2, leitura);
	fread (&cabeca->numbits, sizeof(char), 2, leitura);
	fread (&cabeca->compressao, sizeof(int) , 1, leitura);
	fread (&cabeca->dadosbrutos, sizeof(int) , 1, leitura);
	fread (&cabeca->resoluhori, sizeof(int), 1, leitura);
	fread (&cabeca->resoluvert, sizeof(int), 1, leitura);
	fread (&cabeca->numcores, sizeof(int), 1, leitura);
	fread (&cabeca->coresimport, sizeof(int), 1, leitura);
	fclose (leitura);
}

void LERDADOS (unsigned char **planoB, unsigned char **planoG, unsigned char **planoR, struct CABECA *cabeca, char *arquivo, int filtro, int *pad){
	FILE *leitura;
	int lixo, lin, col;
	
	leitura = fopen (arquivo, "rb");
	if (leitura == NULL){
		printf ("ERRO ABERTURA PARA LEITURA DE DADOS!!\n\n");
		exit (4);
	}
	rewind (leitura);
	fseek(leitura, 14+cabeca->bytecabeca, SEEK_SET);
	for (lin = (cabeca->linhas + ((filtro/2) - 1)); lin >= filtro/2; lin--){
		for (col = (filtro/2); col < (cabeca->colunas + (filtro/2)); col++){
			fread (&planoB[lin][col], sizeof(char), 1, leitura);
			fread (&planoG[lin][col], sizeof(char), 1, leitura);
			fread (&planoR[lin][col], sizeof(char), 1, leitura);
		}
		fread (&lixo, sizeof(char), *(pad), leitura);
		//printf("Linha %d preenchida!\n", lin);
	}

	fclose (leitura);
}

unsigned char **ALOCAPLANO (struct CABECA *cabeca, int filtro){
	int i;
	unsigned char **plano;
	
	if (filtro > 0){
		plano = (unsigned char **) malloc ((cabeca->linhas + (filtro-1))*sizeof (unsigned char *));
		if (plano == NULL){
			printf("ERRO ALOCACAO DE LINHAS !\n");
			exit (2);
		}
		for(i = 0; i < (cabeca->linhas + (filtro-1)); i++){
			plano[i] = (unsigned char *) calloc ((cabeca->colunas + (filtro-1)), sizeof(char));
			if (plano[i] == NULL){
				printf("ERRO ALOCACAO DA COLUNA %d!\n", i);
				exit (3);
			}
		}
	}else{
		plano = (unsigned char **) malloc (cabeca->linhas*sizeof(unsigned char *));
		if (plano == NULL){
			printf("ERRO ALOCACAO DE LINHAS !\n");
			exit (2);
		}		
		for(i = 0; i < cabeca->linhas; i++){
			plano[i] = (unsigned char *) calloc (cabeca->colunas, sizeof(char));
			if (plano[i] == NULL){
				printf("ERRO ALOCACAO DA COLUNA %d!\n", i);
				exit (3);
			}
		}
		
	}
	return plano;
}

void DESALOCAPLANO (unsigned char **plano, struct CABECA *cabeca, int filtro){
	int i;
	
	if (cabeca->linhas < 1){
		printf ("LINHAS PASSADAS EH MENOR QUE 1!!! IMPOSSIVEL DESALOCAR!!\n\n");
		exit (7);
	}
	if (plano == NULL){
		printf ("MATRIZ NULA PASSADA!!");
		exit (8);
	}
	if (filtro > 0){
		for(i = 0; i < (cabeca->linhas + (filtro-1)); i++){
			free (plano[i]);
		}
		free (plano);
	}else{
		for(i = 0; i < cabeca->linhas; i++){
			free (plano[i]);
		}
		free (plano);
	}
}

void IMPRIMEPLANO (unsigned char **plano, struct CABECA *cabeca, int filtro){
	int i = 0, j = 0;

	if (filtro > 0){
		for (i = 0; i < (cabeca->linhas + (filtro-1)); i++){
			for (j = 0; j < (cabeca->colunas + (filtro-1)); j++){
				printf ("Plano [%d][%d]: %d\n", i, j, plano[i][j]);
			}
		}
	}else{
		for (i = 0; i < cabeca->linhas; i++){
			for (j = 0; j < cabeca->colunas; j++){
				printf ("Plano [%d][%d]: %d\n", i, j, plano[i][j]);
			}
		}
	}
	system ("pause");
}

void FILTROMEDIA (struct CABECA *cabeca, unsigned char **porig, unsigned char **pdest, int filtro){
	int lin, col, linf, colf, soma = 0 , item = 0;
	
	item = pow(filtro, 2);
	for(lin = (filtro/2); lin <= (cabeca->linhas + (filtro/2 -1)); lin++){
		for(col = (filtro/2); col <= (cabeca->colunas + (filtro/2 - 1)); col++){
			soma = 0;
			for(linf = (lin-(filtro/2)); linf <= (lin+(filtro/2)); linf++){
				for(colf = (col-(filtro/2)); colf <= (col+(filtro/2)); colf++){
					soma += porig[linf][colf];
			//		printf ("Plano Origem: %d\n", porig[linf][colf]);
				}
			}
			pdest[lin-(filtro/2)][col-(filtro/2)] = soma/item;
			//printf ("Somatorio: %d\tItem: %d\tGravado: %d\n", soma, item, pdest[lin-(filtro/2)][col-(filtro/2)]);
			//system ("pause");
	    }
	}
}

void ESCREVECABECA (struct CABECA *cabeca, char *arquivo){
	FILE *leitura;
	leitura = fopen (arquivo, "wb");
	if (leitura == NULL){
		printf ("ERRO ABERTURA PARA ESCRITA CABECALHO!!\n\n");
		exit (5);
	}
	fwrite (&cabeca->numagico[0], sizeof(char), 1, leitura);
	fwrite (&cabeca->numagico[1], sizeof(char), 1, leitura);
	fwrite (&cabeca->tamarquivo, sizeof(int), 1, leitura);
	fwrite (&cabeca->aplicacao, sizeof(int), 1, leitura);
	fwrite (&cabeca->deslocamento, sizeof(int), 1, leitura);
	fwrite (&cabeca->bytecabeca, sizeof(int) , 1, leitura);
	fwrite (&cabeca->colunas, sizeof(int) , 1, leitura);
	fwrite (&cabeca->linhas, sizeof(int) , 1, leitura);
	fwrite (&cabeca->coresusdas, sizeof(char), 2, leitura);
	fwrite (&cabeca->numbits, sizeof(char), 2, leitura);
	fwrite (&cabeca->compressao, sizeof(int) , 1, leitura);
	fwrite (&cabeca->dadosbrutos, sizeof(int) , 1, leitura);
	fwrite (&cabeca->resoluhori, sizeof(int), 1, leitura);
	fwrite (&cabeca->resoluvert, sizeof(int), 1, leitura);
	fwrite (&cabeca->numcores, sizeof(int), 1, leitura);
	fwrite (&cabeca->coresimport, sizeof(int), 1, leitura);
	fclose (leitura);	
}

void ESCREVEDADOS (unsigned char **planoB, unsigned char **planoG, unsigned char **planoR, struct CABECA *cabeca, char *arquivo, int *pad){
	FILE *leitura;
	long int lixo = 0;
	int lin = cabeca->linhas, col = 0;
	
	leitura = fopen (arquivo, "ab");
	if (leitura == NULL){
		printf ("ERRO ABERTURA PARA ESCRITA DE DADOS!\n\n");
		exit (6);
	}
	fseek(leitura, 14+cabeca->bytecabeca, SEEK_SET);
	for (lin = cabeca->linhas-1; lin >= 0; lin--){
		for (col = 0; col < cabeca->colunas; col++){
			fwrite (&planoB[lin][col], sizeof(unsigned char), 1, leitura);
			fwrite (&planoG[lin][col], sizeof(unsigned char), 1, leitura);
			fwrite (&planoR[lin][col], sizeof(unsigned char), 1, leitura);
		}
		fwrite (&lixo, sizeof(char), *(pad), leitura);
	}

	fclose (leitura);	
}
