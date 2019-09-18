#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	char nome[50];
	int i=0,j,l;
	
	printf("Digite o seu nome: ");
		scanf("%s", nome);
	j=strlen(nome);
	
	system("clear");
	for (i = 0; i < 5; i++){
		
		if (i == 0 || i == 4){
			
			for(l=0; l < j+9;l++)
				printf("*");
				
			printf("\n");
		}else if(i == 1 || i == 3){
			
			for(l = 0; l < j+9; l++){
				if(l == 0 || l == j+8)
					printf("*");
				else
					printf(" ");
			}
			
			printf("\n");
		}else{
			printf("* Ola, %s *\n", nome);
		}
	}
	printf("\n\n");
 
	getchar ();
	return 0;
}
