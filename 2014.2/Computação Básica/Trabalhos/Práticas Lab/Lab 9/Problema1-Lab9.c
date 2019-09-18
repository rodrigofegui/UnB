#include <stdio.h>
#include <stdlib.h>

struct REGISTROS{
	unsigned long int matricula;
	float prova[3], trabalho[5];
};

int main (int argc, char* argv[]){
	int i, j, tot;
	FILE *pfile;
	struct REGISTROS *alunos;

	printf("\nDigite o numero de alunos a serem cadastrados: ");
		scanf("%d", &tot);

	alunos = (struct REGISTROS *) calloc (tot, sizeof(struct REGISTROS));

	for (i = 0; i < tot; i++){
		printf("Digite a matricula do aluno %d: ", i);
		scanf("%li", &alunos[i].matricula);
	}
	
	for (i = 0; i < tot; i++){
		system ("pause");
		system ("cls");
		for (j = 0; j < 3; j++){
			printf("\nDigite a nota da prova %d do aluno %d: ", j, i);
				scanf("%f", &alunos[i].prova[j]);
		}
		for (j = 0; j < 5; j++){
			printf("\nDigite a nota do trabalho %d do aluno %d: ", j, i);
				scanf("%f", &alunos[i].trabalho[j]);
		}
	}
	
	printf("\n");
	for (i = 0; i < tot; i++){
		system ("pause");
		system ("cls");
		printf ("Aluno %d\t", i);
		printf("Matricula: %li\n", alunos[i].matricula);
		for (j = 0; j < 3; j++){
			printf("\tProva %d: %.2f\n", j, alunos[i].prova[j]);
		}
		printf("\n");
		for (j = 0; j < 5; j++){
			printf("\tTrabalho %d: %.2f\n", j, alunos[i].trabalho[j]);
		}
		printf("\n");		
	}
	
		
	pfile=fopen(argv[1], "w");
	if(pfile==NULL){
		printf("falha");
		exit(1);
	}
	fprintf(pfile, "%d ", tot);
	for (i = 0; i < tot; i++){
		fprintf(pfile, "%li ", alunos[i].matricula);
		for (j = 0; j < 3; j++){
			fprintf(pfile, "%f ", alunos[i].prova[j]);
		}
		for (j = 0; j < 5; j++){
			fprintf(pfile, "%f ", alunos[i].trabalho[j]);
		}		
	}
			
	fclose (pfile);		
	free (alunos);

	system("pause");
	return 0;
}

