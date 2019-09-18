#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "global.h"
#include "funcoes.h"

#define MEM_SIZE 4096

	enum OPCODES { /* Só são considerados os 6 primeiros bits */
		EXT=0x00, LW=0x23, LB=0x20, LBU=0x24,
		LH=0x21, LHU=0x25, LUI=0x0F, SW=0x2B,
		SB=0x28, SH=0x29, BEQ=0x04, BNE=0x05,
		BLEZ=0x06, BGTZ=0x07, ADDI=0x08, ADDIU=0x09,
		SLTI=0x0A, SLTIU=0x0B, ANDI=0x0C, ORI=0x0D,
		XORI=0x0E, J=0x02, JAL=0x03
	};
	
	enum FUNCT {
		ADD=0x20, SUB=0x22, MULT=0x18, DIV=0x1A, AND=0x24,
		OR=0x25, XOR=0x26, NOR=0x27, SLT=0x2A, JR=0x08,
		SLL=0x00, SRL=0x02, SRA=0x03, SYSCALL=0x0c, MFHI=0x10, MFLO=0x12
	};		

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	int32_t $zero = 0;
	int32_t $at = 0;
	int32_t $v0 = 0;
	int32_t $v1 = 0;
	int32_t $a0 = 0;
	int32_t $a1 = 0;
	int32_t $a2 = 0;
	int32_t $a3 = 0;
	int32_t $t0 = 0;
	int32_t $t1 = 0;
	int32_t $t2 = 0;
	int32_t $t3 = 0;
	int32_t $t4 = 0;
	int32_t $t5 = 0;
	int32_t $t6 = 0;
	int32_t $t7 = 0;
	int32_t $s0 = 0;
	int32_t $s1 = 0;
	int32_t $s2 = 0;
	int32_t $s3 = 0;
	int32_t $s4 = 0;
	int32_t $s5 = 0;
	int32_t $s6 = 0;
	int32_t $s7 = 0;
	int32_t $t8 = 0;
	int32_t $t9 = 0;
	int32_t $k0 = 0;
	int32_t $k1 = 0;
	int32_t $gp = 0;
	int32_t $sp = 0;
	int32_t $fp = 0;
	int32_t $ra = 0;
	
	/* Registradores Especiais */
	
	uint32_t PC = 0;
	uint32_t RI = 0;
	int32_t HI = 0;
	int32_t LO = 0;

	/* Memória do simulador */
	
	int32_t *mem;
	
	/* Campos da Instrução*/

	int opcode;
	int rs;
	int rt;
	int rd;
	int shamt;
	int funct;
	short int k16;
	long int k26;
	
int main(int argc, char *argv[]) {
	
	FILE *fp_text;
	FILE *fp_data;
	
	/* Alocação do ponteiro -> Iniciaçizando a memória do Simulador com Zeros*/ 
	mem = (int32_t*) calloc(4096, sizeof(int32_t)); 
	
	/* O número de argumentos DEVE ser igual a 4 */
	/* Sendo eles: o nome do programa; endereço text.bin; endereço data.bin e tipo de execução (f ou p) */
	//if(argc != 4){
	//	printf("\nNumero de argumentos insuficiente!\n");
	//	exit(-1);
	//}
	  
	/* Carregando a memória do simulador*/
	fp_text = fopen("primos_text.bin", "rb");
	if( !fp_text ) {read_error();}
	
	fp_data = fopen("primos_data.bin", "rb");
	if( !fp_data ) {read_error();}
	
	load_mem(fp_text, mem, 0);
	load_mem(fp_data, mem, 1);
	//print_mem(mem);
	
	//if(argv[3] = 'p'){
		//interface();
	//} else if(argv[3] = 'f') {
		//run();
	//} else {
		//printf("\nValor do terceiro argmumento invalido!\n");
		//exit(-5);
	//}
	
	fclose(fp_text);
	fclose(fp_data);
	free(mem);
		
	system("PAUSE");
	return 0;
}
