#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DADOS {
	char nome [30];
	int quant;
};

struct INFORMACOES{
	struct DADOS *informa;
};

struct CAND {
	char nome [100];
	char data [8];
	char uf [2];
};

struct ORCA {
	char partido [7];
	char cargo [13];
	float verba;
};

void MENU (char *);
void NOMEARQ (char *, char *);
void ALOCAINFOS (struct INFORMACOES *, int, int);
void DESALOCAINFOS (struct INFORMACOES *);
void INICIAINFOS (struct INFORMACOES *, struct CAND *, struct ORCA *);
void IMPRIMEINFOS (struct INFORMACOES *, struct CAND *, struct ORCA *);
void IMPRIMEDADOS (struct INFORMACOES *, int, int);
int LEVANTAMENTO (FILE *, struct INFORMACOES *, struct CAND *, struct ORCA *);
void COMPARA (struct INFORMACOES *, char *, int, int, int);

int main (){
	struct CAND candidato [2];
	struct INFORMACOES info[7];
	struct ORCA orcamento [2];
	char ufarq [3], nomearq [28], intermedio[30];
	int i, totcand = 0;
	FILE *pontfl;

	for (i = 0; i < 28; i++){
		nomearq[i] = '\0';
	}

	ALOCAINFOS (info, 0, 32);
	ALOCAINFOS (info, 1, 28);
	ALOCAINFOS (info, 2, 26);
	ALOCAINFOS (info, 3, 8);
	ALOCAINFOS (info, 4, 5);
	ALOCAINFOS (info, 5, 3);
	ALOCAINFOS (info, 6, 2);
		printf ("ALOCACAO REALIZADA COM SUCESSO!\n");
	INICIAINFOS (info, candidato, orcamento);
		printf ("\nINICIALIZAO DAS INFORMACOES FOI UM SUCESSO!\n\n");
	MENU (ufarq);
	
	if (atoi(ufarq) == 1){
		for (i = 0; i < 26; i++){
			pontfl = fopen (info[2].informa[i].nome, "r");
			if (pontfl == NULL){
				printf("FALHA ABERTURA ARQUIVO %d CASCATA!", i);
				exit (i);
			}
			printf ("Lendo arquivo: %s\n", info[2].informa[i].nome);
			totcand += LEVANTAMENTO (pontfl, info, candidato, orcamento);
			fclose (pontfl);
		}
	}else if (ufarq[0] == '0'){
		printf ("PROGRAMA FINALIZADO!\n");
		DESALOCAINFOS (info);
			printf ("\nDESALOCACAO REALIZADA COM SUCESSO!\n\n");
		system ("pause");
		return 0;
	}else{
		NOMEARQ (ufarq, nomearq);
		printf ("Lendo arquivo: %s\n\n", nomearq);
		pontfl = fopen (nomearq, "r");
			if (pontfl == NULL){
				printf ("ERRO ABERTURA ARQUIVO!!\n\n");
				exit (1);
			}
		totcand = LEVANTAMENTO (pontfl, info, candidato, orcamento);
		fclose (pontfl);
	}
	
	IMPRIMEINFOS (info, candidato, orcamento);
	DESALOCAINFOS (info);
		printf ("\nDESALOCACAO REALIZADA COM SUCESSO!\n\n");
		
	system ("pause");
	return 0;
}

void ALOCAINFOS (struct INFORMACOES *info, int linha, int quant){
	info[linha].informa = (struct DADOS *) calloc (quant, sizeof(struct DADOS));
		if (info[linha].informa == NULL){
			printf ("FALHA NA ALOCACAO DE INFO[%d]!!\n", linha);
			exit(1);
		}
}

void DESALOCAINFOS (struct INFORMACOES *info){
	int i=0;
	
	for (i = 0; i < 7; i++){
		free(info[i].informa);
	}
}

void INICIAINFOS (struct INFORMACOES *info, struct CAND *candidato, struct ORCA *orcamento){
	FILE *pontf;
	char le, leitura[30];
	int cont = 0, asp = 0;
	int i = 0, j = 0, informacao = 0;

	pontf = fopen("AUXILIAR.txt", "r");
	if (pontf == NULL){
		printf("FALHA ABERTURA AUXILIAR!\n");
		exit(1);
	}
	do{
		i = 0;
		do{
			le = fgetc(pontf);
			if (le == ';'){
				cont++;
			}
			if (le != ';' && le != '"' && le != '\n'){
				leitura [i] = le;
				i++;
			}
			
		}while (le != ';');
		leitura[i] = '\0';
		
		strcpy (info[informacao].informa[j].nome, leitura);
		
		if (cont == 32 || cont == 60 || cont == 86 || cont == 94 || cont == 99 || cont == 102){
			j = 0;
			informacao++;
		}else{
			j++;
			info[informacao].informa[j].quant = 0;
		}
		
	}while(cont < 104 && !feof(pontf));

	fclose (pontf);
	orcamento[0].verba = 99999999.0;
	orcamento[1].verba = 0.0;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 10; j++){
			orcamento[i].partido[j] = '\0';
		}
		for (j = 0; j < 13; j++){
			orcamento[i].cargo[j] = '\0';
		}
	}
	for(i = 0; i < 2; i++){
		info[6].informa[i].quant = 0;
		for(j = 0; j < 100; j++){
			candidato[i].nome[j] = '\0';
		}
		for(j = 0; j < 2; j++){
			candidato[i].uf[j] = '\0';
		}
	}
	for(i = 0; i < 8; i++){
		candidato[0].data[i] = 57;
		candidato[1].data[i] = 48;
	}
}

void IMPRIMEINFOS (struct INFORMACOES *info, struct CAND *candidato, struct ORCA *orcamento){
	int i, j;
	
	system ("pause");
	system ("cls");
	printf("\n\n\t\tPartidos:\n\n");
		IMPRIMEDADOS (info, 0, 32);
	printf("\t\tUF's:\n\n");
		IMPRIMEDADOS (info, 1, 28);
	printf("\t\tEscolaridade:\n\n");
		IMPRIMEDADOS (info, 3, 8);
	printf("\t\tEstado Civil:\n\n");
		IMPRIMEDADOS (info, 4, 5);
	printf("\t\tCargo:\n\n");
		IMPRIMEDADOS (info, 5, 3);
	printf("\t\tSexo:\n\n");
		IMPRIMEDADOS (info, 6, 2);
	printf("\t\tCandidatos:\n\n");
	for (i = 0; i < 2; i++){
		printf("nome candidato[%d] ==> %s\n", i, candidato[i].nome);
		printf("nascimento candidato[%d] ==> ", i);
		for(j = 6; j < 8; j++){
			printf("%c", candidato[i].data[j]);
		}
		printf(" / ");
		for(j = 4; j < 6; j++){
			printf("%c", candidato[i].data[j]);
		}
		printf(" / ");
		for(j = 0; j < 4; j++){
			printf("%c", candidato[i].data[j]);
		}
		printf("\nUF de nasc candidato[%d] ==> ", i);
		for(j = 0; j < 2; j++){
			printf("%c", candidato[i].uf[j]);
		}
		printf("\n\n");
	}
	printf("\t\tCampanhas:\n\n");
	for (i = 0; i < 2; i ++){
		printf ("Despesa Oficial (RS): %.0f\n", orcamento[i].verba);
		printf ("Partido: %s\t\tCargo: %s\n\n", orcamento[i].partido, orcamento[i].cargo);
	}
}

void IMPRIMEDADOS (struct INFORMACOES *info, int linha, int quant){
	int soma = 0, i;
	
	for (i = 0; i < quant; i++){
		printf ("[%d]\tQuant = %d \t", i, info[linha].informa[i].quant);
		printf ("Nome = %s \n", info[linha].informa[i].nome);
		soma += info[linha].informa[i].quant;
	}
	printf("somatorio: %d\n\n", soma);
}

void MENU (char *uf){
	int i, j, l;
	
	system ("pause");
	system ("cls");
	j = strlen("LEVANTAMENTO ESTATISTICO TSE");
	for (i = 0; i < 5; i++){
		if (i == 0 || i == 4){
			printf("\t");
			for(l = 0; l < j + 8;l++)
				printf("*");
				
			printf("\n");
		}else if(i == 1 || i == 3){
			printf("\t");
			for(l = 0; l < j + 8; l++){
				if(l == 0 || l == j + 7)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}else{
			printf("\t*   LEVANTAMENTO ESTATISTICO TSE   *\n");
		}
	}
	printf("\n\t1 - Todos os arquivos\n");
	printf("\n\tUF - UF do arquivo\n");
	printf("\n\t0 - Sair\n");
	printf("\n\t************************************\n");
	printf("\n\n\tOBS: a UF pode ser dada em caixa baixa.\n\n");
	printf("\nDigite sua escolha: ");
		scanf("%[^\n]", uf);
	system("pause");
	system("cls");	
}

void NOMEARQ (char *uf, char *nomearq){
	int i;
	
	char uf1[2];
	for (i = 0; i < 2; i++){
		uf1[i] = toupper(uf[i]);
		uf[i] = uf1[i];
	}
	strcpy(nomearq, "consulta_cand_2012_");
	strcat(nomearq, uf);
	strcat(nomearq, ".txt");
}

int LEVANTAMENTO (FILE *pontfl, struct INFORMACOES *info, struct CAND *candidato, struct ORCA *orcamento){
  	char le, leitura [125], data [8], uf[2], teste[100];
  	char cargo[13], partido[8];
	int cont = 0, volta = 1, date = 0, j, i, lim, comp;
	float desp = 0;
	
	for (i = 0; i < 8; i++){
		data[i] = '\0';
		partido[i] = '\0';
	}
	for (i = 0; i < 13; i++){
		cargo[i] = '\0';
	}
	for (i = 0; i < 100; i++){
		teste [i] = '\0';
	}
	for (i = 0; i < 125; i++){
		leitura[i] = '\0';
	}
	for (i = 0; i < 2; i++){
		uf [i] = '\0';
	}
	do{
        j=0;
        do{
            le = fgetc (pontfl);
         
            if(le != ';' && le != '"'){
                leitura[j-1] = le;
            }
            if(le == ';'){
                cont++;
            }
 
            j++;
        }while (le != ';' && !feof(pontfl));
        leitura[j] = '\0';

        switch (cont){
            case 10:{
            	strcpy(cargo, leitura);
            	cargo[strlen(cargo)] = '\0';
            	COMPARA (info, leitura, 5, 3, cont);
                break;
            }
 
            case 11:{
                strcpy(teste, leitura);
                teste[strlen(teste)] = '\0';
                break;
            }
 
            case 18:{
            	strcpy(partido, leitura);
            	partido[strlen(partido)] = '\0';
            	COMPARA (info, leitura, 0, 32, cont);
                break;
            }
 
            case 26:{
                    for (i = 0; i < 4; i++){
                        data[i] = leitura[i+6];
                    }
                    for (i = 4; i < 6; i++){
                        data[i] = leitura[i-1];
                    }
                    for (i = 6; i < 8; i++){
                        data[i] = leitura[i-6];
                    }
                    data [i] = '\0';
                    date = atoi(data);
                break;
            }
 
            case 30:{
            	COMPARA (info, leitura, 6, 3, cont);
                break;
            }
 
            case 32:{
            	COMPARA (info, leitura, 3, 8, cont);
                break;
            }
 
            case 34:{
            	COMPARA (info, leitura, 4, 5, cont);
                break;
            }
 
            case 37:{
                strcpy(uf, leitura);
                COMPARA (info, leitura, 1, 28, cont);
                break;
            }
            case 40:{
            	desp = atoi(leitura);
            	break;
            }
 
            case 41:{
                if (date < atoi(candidato[0].data)){
                    itoa(date, candidato[0].data, 10);
                    strcpy(candidato[0].nome, teste);
                    strcpy(candidato[0].uf, uf);
                }else if (date > atoi(candidato[1].data)){
                    itoa(date, candidato[1].data, 10);
                    strcpy(candidato[1].nome, teste);
                    strcpy(candidato[1].uf, uf);
                }
                if (desp < orcamento[0].verba && desp > 0){
                	orcamento[0].verba = desp;
                	strcpy(orcamento[0].partido, partido);
                	strcpy(orcamento[0].cargo, cargo);
                }else if (desp > orcamento[1].verba){
               		orcamento[1].verba = desp;
                	strcpy(orcamento[1].partido, partido);
                	strcpy(orcamento[1].cargo, cargo);
				}
                cont = 0;
                volta++;
                break;
            }
        }
        for (i = 0; i < 100; i++){
            leitura[i] = '\0';
        }
 
    }while (!feof(pontfl));
     
    fclose(pontfl);
    return volta;
}

void COMPARA (struct INFORMACOES *info, char *leitura, int linha, int quant, int cont){
	int i;
	
	for (i = 0; i < quant; i++){
        if (strcmp(info[linha].informa[i].nome, leitura) == 0){
    		info[linha].informa[i].quant++;
            break;
    	}
    }
}
