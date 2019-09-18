#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 3
#define MAXD 5
#define MAXNM 1000
#define MAXNT 3

struct taluno{
	int nr;
	char nome [MAXNM], departamento [MAXD];
	float nota [MAXNT], media;
};


int main (){
	struct taluno aluno[MAX];
	char nomemaxmed [MAXNM], nome[MAXNM];
	int i, j, n;
	float soma, media=0, menota1, memedia;
	float controle=10;
	
	system ("color 0f");
	for(i=0; i<MAX; i++){
		system ("pause");
		system ("cls");
		printf("\ndigite nr do aluno[%d]: ", i);
			scanf("%d", &aluno[i].nr);
		getchar ();
		printf("\ndigite nome do aluno[%d]: ", i);
			scanf("%[^\n]", aluno[i].nome);
		getchar();
		printf("\ndigite departamento do aluno[%d]: ", i);
			scanf("%[^\n]", aluno[i].departamento);
		
		getchar();
		for(j=0; j<MAXNT; j++){
		printf("\ndigite nota [%d] do aluno[%d] (0-10): ", j, i);
			scanf("%f", &aluno[i].nota[j]);
		}
	}
	
	system ("cls");
	for (i = 0; i < MAX; i++){
		soma = 0;
		for(j=0; j<MAXNT; j++){
			soma += aluno[i].nota[j];
		}
		aluno[i].media=soma/MAXNT;
	}
	
	for (i = 0; i < MAX; i++){
		strcpy (nome, aluno[i].nome);
		for(j=0; j<strlen(nome); j++){
			if(j==0 || (nome[j]==32) || (nome[j-1]==32)) {
				aluno[i].nome[0]=toupper(nome[0]);
				aluno[i].nome[j+1]=toupper(nome[j+1]);
			}else if((nome[j-1]!=32)){
				aluno[i].nome[j]=tolower(nome[j]);
			}
			
		}
	}
	
	for (i = 0; i < MAX; i++){
		strcpy (nome, aluno[i].departamento);
		for(j=0; j<strlen(nome); j++){
		 	aluno[i].departamento[j]=toupper(nome[j]);
		}
	}

	for(i=0; i<MAX; i++){
		printf("\nnr do aluno[%d]: %d", i, aluno[i].nr);
		printf("\nNome do aluno[%d]: %s", i, aluno[i].nome);
		printf("\nDepartamento do aluno[%d]: %s", i, aluno[i].departamento);
			
		for(j=0; j<MAXNT; j++){
		printf("\nNota [%d] do aluno[%d]: %.2f", j, i, aluno[i].nota[j]);
		}
		printf("\nMedia do aluno[%d] : %.2f", i, aluno[i].media);
		printf("\n\n\n");
		
	}
	
	soma=0;
	for (i = 0; i < MAX; i++){
		soma += aluno[i].media;
	}
	media=soma/MAXNT;
	printf("\nA media da turma eh: %.2f", media);
	
	for (i = 0; i < MAX; i++){
		if (aluno[i].nota[0] < controle)
			controle = aluno[i].nota[0];
	}
	menota1 = controle;
	printf("\nA menor nota da prova 1: %.2f", menota1);

	controle = 0;
	for (i = 0; i < MAX; i++){
		if (aluno[i].media > controle){
			strcpy (nomemaxmed, aluno[i].nome);
			controle = aluno[i].media;
		}
	}
	
	printf("\nO aluno, %s, obteve a maior media, %.2f\n", nomemaxmed, controle);
	n=0;
	printf("\nOs alunos abaixo da media da turma sao:\n");
	for (i = 0; i < MAX; i++){
		if (aluno[i].media < media){
			printf("\t* %s\n", aluno[i].nome);
			n++;
		}
	}
	if(n==0)
		printf("\nNao ha aluno abaixo da media\n");
	
	n=0;
	printf("\nOs alunos reprovados sao:\n");
	for (i = 0; i < MAX; i++){
		if (aluno[i].media < 5.0){
			printf("\t* %s\n", aluno[i].nome);
			n++;
		}
	}
	if(n==0)
		printf("\nNao ha aluno reprovado\n");

	system ("pause");
	return 0;
}
