#include <stdio.h>
#include <stdlib.h>

struct TESTE{
	char nome [10];
	int quant;
};

int main (){
	struct TESTE **teste;
	int lin, col;
	
	teste = (struct TESTE **) calloc (2, sizeof (struct TESTE *));
	
	*(teste+0) = (struct TESTE *) calloc (5, sizeof (struct TESTE));
	*(teste+1) = (struct TESTE *) calloc (2, sizeof (struct TESTE));
	
	teste[0].nome = "aki:P";
	teste[1].nome = "aki:P";
	
	for (col = 0; col < 5; col++)
		printf("s: %s e d: %d\t", teste[0][col]);
	
	printf("\n\n");
	for (col = 0; col < 2; col++)
		printf("s: %s e d: %d\t", teste[0][col]);
	
	for (lin = 0; lin < 2; col++){
		free (*(teste+lin));
	}
	
	free (teste);
	
	system ("pause");
	return 0;
}
