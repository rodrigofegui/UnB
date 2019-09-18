#include <stdio.h>
#include <stdlib.h>

struct REGISTROS{
	unsigned long int matricula;
	float prova[3], trabalho[5], media;
};

int main(){
	FILE *pfile;
	int i, j, tot;
	struct REGISTROS *aluno;
	char nomedoarquivo[50];
	
	printf("Digite o nome do arquivo: ");
		scanf("%[^\n]", nomedoarquivo);
		
	pfile=fopen(nomedoarquivo, "r");
	fscanf(pfile, "%i",&tot);
	aluno = (struct REGISTROS*) calloc (tot, sizeof(struct REGISTROS));
		
	for(i = 0; i < tot; i++){
		fscanf(pfile, "%li", &aluno[i].matricula);
		for(j = 0; j < 3; j++){
			fscanf(pfile, "%f ", &aluno[i].prova[j]);
		}
		for(j = 0; j < 5; j++){
			fscanf(pfile, "%f ", &aluno[i].trabalho[j]);
		}
	}
	
	fclose(pfile);
	for (i = 0; i < tot; i++){
		for (j = 0; j< 3; j++){
			aluno[i].media += aluno[i].prova[j];
		}
		aluno[i].media = aluno[i].media/8;
	}
	
	pfile=fopen("media.txt", "w");
	
	for(i = 0; i < tot; i++){
		fprintf(pfile, "%li ",aluno[i].matricula);
		fprintf(pfile, "%f ", aluno[i].media);
	}
	
	fclose(pfile);
	free(aluno);
	
	system ("pause");
	return 0;
	
}
