/*include de bibliotecas e headers*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "funcoes.h"

/* Memoria do simulador */
int32_t mem[MEM_SIZE] = {0};//inicializa mem com zeros

/*continua_run -> variavel para verificar se ocorreu interrupcao ou fim do simulador*/
int continua_run;

/* Registradores Especiais */
uint32_t PC;
uint32_t RI;
int32_t HI;
int32_t LO;

/* Campos da Instrucao*/
int opcode;
int rs;
int rt;
int rd;
int shamt;
int funct;
short int k16;//imediato em instrucoes tipo I
long int k26;//uso em instrucoes tipo J


int main(int argc, char *argv[]) {
	FILE *fp_text;
	FILE *fp_data;

	/* O numero de argumentos DEVE ser igual a 4 */
	/* Sendo eles: o nome do programa; endereco text.bin; endereco data.bin e tipo de execucao (f ou p) */
	if(argc != 4){
		printf("\nNumero de argumentos insuficiente!\n");
		exit(-1);
	}

	/* Carregando a memoria do simulador*/
	fp_text = fopen(argv[1], "rb");
	if( !fp_text ) {
		read_error();
	}

	fp_data = fopen(argv[2], "rb");
	if( !fp_data ) {
		read_error();
	}

	load_mem(fp_text, mem, 0);
	load_mem(fp_data, mem, 1);


	if(!strcmp (argv[3], "p")){//argumento p inicializa menu para usuario
		interface();
	}else if(!strcmp (argv[3], "f")) {//argumento f realiza run e gera arquivos .txt com memoria e banco de registradores
		run();
		registrar ();
		printf("Arquivos mem.txt e reg.txt gerados com sucesso! Tecle Enter para sair...\n");
		getchar();
	} else {
		printf("\nValor do terceiro argmumento invalido!\n");
		exit(-5);
	}

	/*fechamento de arquivos utilizados*/
	fclose(fp_text);
	fclose(fp_data);

	return 0;
}