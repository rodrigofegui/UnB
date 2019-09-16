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

/* Impelementação das funções */

/* Função FETCH */
/*Essa função lê uma instrução da memória e coloca-a em ri, atualizando o pc 
para apontar para a próxima instrução (soma 4).*/
void fetch(){
	
	RI = mem[PC];
	PC = PC + 4; /* Palavra -> 32 Bits*/
	
}

/* Função DECODE */
/*Essa função deve extrair todos os campos da instrução proveniente
da função FETCH*/
void decode(){

	///* Instruções tipo R*///
	/* Opcode -> 6 Bits
	Rs/Rt/Rd -> 5 Bits
	Sa -> 5 Bits
	Funct -> 6 Bits*/
	
	///* Instruções tipo I*///
	/* Opcode -> 6 Bits
	Rs/Rt -> 5 Bits
	Imediato -> 16 Bits*/
	
	///* Instruções tipo J*///
	/* Opcode -> 6 Bits
	Destino do Jump -> 26 Bits*/
	
	opcode = ((uint32_t)RI >> 26) & 0x3F;
	rs = ((uint32_t)RI >> 21) & 0x1F;
	rt = ((uint32_t)RI >> 16) & 0x1F;
	rd = ((uint32_t)RI >> 11) & 0x1F;
	shamt = ((uint32_t)RI >> 6) & 0x3F;
	funct = (uint32_t)RI & 0x3F;
	k16 = (uint32_t)RI & 0xFFFF;
	k26 = (uint32_t)RI & 0x3FFFFFF;
	
}

/* Função STEP */
/*Essa executa uma instrução do MIPS:
step() => fetch(), decode(), execute()*/
void step(){
	
	fetch();
	decode();
	execute();
	adv_PC();
	
}

/* Função RUN */
/*Essa função executa o programa até encontrar uma chamada de sistema para encerramento,
ou até o pc ultrapassar o limite do segmento de código (2k words).*/
void run(){
	
	while(PC <= 0x2000){
		step();
	}
	system("PAUSE");
	exit(0);
}

/* Função ADVANCE PC */
/* Aponta PC para a próxima instrução*/
void adv_PC(){
	PC = PC + 4;
}

/* Função EXECUTE */
/*Essa função executa a instrução que foi lida pela função FETCH e decodificada por DECODE.*/
void execute(){
	
	switch (opcode) {
		case EXT:
			switch (funct) {
				case ADD: mem[rd] = mem[rs] + mem[rt]; adv_PC(); break;
				case SUB: mem[rd] = mem[rs] - mem[rt]; adv_PC(); break;
				case MULT: LO = (mem[rs] * mem[rt]); HI = ((mem[rs] * mem[rt]) >> 32); adv_PC(); break;
				case DIV: LO = mem[rs] / mem[rt]; HI = mem[rs] % mem[rt]; adv_PC(); break;
				case AND: mem[rd] = mem[rs] & mem[rt]; adv_PC(); break;
				case OR: mem[rd] = mem[rs] | mem[rt]; adv_PC(); break;
				case XOR: mem[rd] = mem[rs] ^= mem[rt]; adv_PC(); break;
				case NOR: mem[rd] = mem[rs] |~ mem[rt]; adv_PC(); break;
				case SLT: if(mem[rs] < mem[rt]){
							mem[rd] = 0x01;
						  }
						adv_PC();
						break;
				case JR: PC = rs; adv_PC(); break;
				case SLL: mem[rd] = (int32_t)mem[rt] << shamt; adv_PC(); break;
				case SRL: mem[rd] = (int32_t)mem[rt] >> shamt; adv_PC(); break;
				case SRA: mem[rd] = mem[rt] >> shamt; adv_PC(); break;
				case SYSCALL:
				case MFHI: mem[rd] = HI; adv_PC(); break;
				case MFLO: mem[rd] = LO; adv_PC(); break;
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case LW:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case LB:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
				}
		case LBU:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case LH:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case LHU:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case LUI:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case SW:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case SB:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case SH:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case BEQ:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case BNE:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case BLEZ:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case BGTZ:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case ADDI:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case ADDIU:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case SLTI:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case SLTIU:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case ANDI:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case ORI:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case XORI:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case J:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		case JAL:
			switch (funct) {
				case ADD: //breg[rd] = breg[rs] + breg[rt]; break;
				case SUB:
				case MULT:
				case DIV:
				case AND:
				case OR:
				case XOR:
				case NOR:
				case SLT:
				case JR:
				case SLL:
				case SRL:
				case SRA:
				case SYSCALL:
				case MFHI:
				case MFLO:
				default: printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
		default:
			printf("\nValor de <OPCODE> invalido!\n"); exit(-7);
	}	
}


/* Função READ ERROR */
/*Caso ocorra algum erro ao abrir os arquivos binários
O programa imprime uma mensagem de erro e encerra. */
void read_error(){
	printf("\n Erro ao abrir o arquivo!\n");
	exit(-2);
}

/* Função INTERFACE */
/*Imprime a interface com o usuário e executa as funções pedidas*/
void interface(){
	
	int i, aux;
	int start, end;
	char format;
	
	printf("\nDefina o número função desejada:\n"
			"1. step\n"
			"Essa função executa uma instrução do MIPS\nstep() => fetch(), decode(), execute()\n"
			"Modo de usar: \n"
			"2. run\n"
			"Essa função executa o programa até encontrar uma chamada de sistema para encerramento, ou até o pc ultrapassar o limite do segmento de código (2k words).\n"
			"Modo de usar: \n"
			"3. dump_mem\n"
			"Essa função imprime o conteúdo da memória a partir do endereço start até o endereço end.\n"
			"O formato pode ser em hexadecimal (‘h’) ou decimal (‘d’). A memória deve ser impressa em palavras de 32 bits.\n"
			"Modo de usar: \n"
			"4. dump_reg\n"
			"Essa função imprime o conteúdo dos registradores do MIPS, incluindo o banco de\n"
			"registradores e os registradores pc, hi e lo. O formato pode ser em hexa (‘h’) ou decimal (‘d’).\n"
			"Modo de usar: \n"
			"5. Sair(Exit)\n");
	
	printf("\nDigite a opcao desejada: ");
	scanf("%d", &i);
	
	switch ( i )
  {
     case 1 :
     	printf("\nVoce selecionou a funcao Step!\n");
		void step();
     	interface();
     
     case 2 :
     	printf("\nVoce selecionou a funcao Run!\n");
    	void run();
     	interface();
 		
     case 3 :
     	printf("\nVoce selecionou a funcao Dump_Mem!\n");
     	printf("Por favor, selecione o valor inicial da memoria: \n");
     	scanf("%d", &start);
     	printf("Por favor, selecione o valor final da memoria: \n");
     	scanf("%d", &end);
     	printf("Por favor, selecione o valor final da memoria: \n");
     	scanf("%c", &format);
    	//dump_mem(start, end, format);
     	interface();
 
     case 4 :
     	printf("\nVoce selecionou a funcao Dump_Reg!\n");
     	printf("Por favor, selecione o valor final da memoria: \n");
     	scanf("%c", &format);
    	dump_reg(format);
    	interface();
 
     case 5 :
     break;
     
     default :
       printf ("Valor invalido!\n");
       interface();
  }
}


/* Função LOAD MEM */
/*Carrega o código e os dados para a memória do simulador*/
void load_mem(FILE *fp, int32_t *mem, int mode){
	
	int i;
	unsigned char c;
	
	if(mode == 0){
		i = 0; /* Posição 0x00000000 da memória */
		do{
			fread(&c, sizeof(unsigned char), 1, fp);
			mem[i] = c;
			i++;
			if(i >= 4096){
				printf("\nUltrapassou o tamanho da memoria do simulador!\n");
				exit(-3);
			}
		}while( !feof(fp) );
		
	} else if( mode == 1) {
		
		i = 2048; /* Posição 0x00002000 da memória */
		do{
			fread(&c, sizeof(unsigned char), 1, fp);
			mem[i] = c;
			//printf("\n%d e %02X\n", i, c);
			//system("PAUSE");
			i++;
			if(i >= 4096){
				break; /* Carrega na memória do simulador até seu limite */
			}
		}while( !feof(fp) );
		
	} else {
		printf("\nModo de Carregamento da Memoria Invalido!\n");
				exit(-4);
	}
	
}

/* Função PRINT MEM */
/*Imprime o código e os dados da memória do simulador*/
void print_mem(int32_t *mem){
	
	int i;
	int aux1 = 0, aux2 = 0;
	
	for(i=0; i<MEM_SIZE;i++){
		printf("%02X", mem[i]);
		aux1++;
		if(aux1 == 2){
			printf(" ");
			aux1 = 0;
			aux2 = aux2 +2;
			if(aux2 == 32){
				aux2 = 0;
				printf("\n");
			}
		}
	}
	printf("\n\n");
}

/* Função DUMP MEM */
/*Essa função imprime o conteúdo da memória a partir do endereço start até o endereço end.
O formato pode ser em hexa (‘h’) ou decimal (‘d’). A memória deve ser impressa em palavras
de 32 bits, de acordo com o formato abaixo, onde o lado esquerdo apresenta o endereço da
memória e o lado direito mostra o valor contido nesse endereço.*/

void dump_mem(int start, int end, char format){
	
	int i;
	
	if(start < 0x0 || end > 0x2000){
		do{
			printf("Endereco de memoria invalido!\n Deseja digitar os valores novamente?\n Sim(1)/ Nao(0)\n");
			scanf("%d", i);
			if(i == 0){
				exit(0);
			}
			printf("Digite o endereco inicial: ");
			scanf("%d", &start);
			printf("Digite o endereco final: ");
			scanf("%d", &end);
		}while(start < 0x0 || end > 0x2000);
	}
	
	if(format == 'd'){
		for(i = start; i <= end; i++){
			printf("%08X = %li", i, mem[i]);
		}	
	} else if(format == 'h') {
		for(i = start; i <= end; i++){
			printf("%08X = %08X", i, mem[i]);
		}
	} else {
		printf("\nFormato invalido!\n");
		exit(-7);
	}
	
}


/* Função DUMP REG */
/*Função que imprime os valores de todos os
registradores */

void dump_reg(char format){
	
	if(format == 'd'){
		printf("\nREGISTERS\n$zero = %li\n"
				"$at = %li\n"
				"$v0 = %li\n"
				"$v1 = %li\n"
				"$a0 = %li\n"
				"$a1 = %li\n"
				"$a2 = %li\n"
				"$a3 = %li\n"
				"$t0 = %li\n"
				"$t1 = %li\n"
				"$t2 = %li\n"
				"$t3 = %li\n"
				"$t4 = %li\n"
				"$t5 = %li\n"
				"$t6 = %li\n"
				"$t7 = %li\n"
				"$s0 = %li\n"
				"$s1 = %li\n"
				"$s2 = %li\n"
				"$s3 = %li\n"
				"$s4 = %li\n"
				"$s5 = %li\n"
				"$s6 = %li\n"
				"$s7 = %li\n"
				"$t8 = %li\n"
				"$t9 = %li\n"
				"$k0 = %li\n"
				"$k1 = %li\n"
				"$gp = %li\n"
				"$sp = %li\n"
				"$fp = %li\n"
				"$ra = %li\n"
				"PC = %li\n"
				"HI = %li\n"
				"LO = %li\n", 
				$zero,
				$at, 
				$v0, 
				$v1, 
				$a0, 
				$a1, 
				$a2, 
				$a3,
				$t0,
				$t1,
				$t2,
				$t3,
				$t4,
				$t5,
				$t6,
				$t7,
				$s0,
				$s1,
				$s2,
				$s3,
				$s4,
				$s5,
				$s6,
				$s7,
				$t8,
				$t9,
				$k0,
				$k1,
				$gp,
				$sp,
				$fp,
				$ra,
				PC,
				HI,
				LO);
	} else {
		printf("\nREGISTERS\n$zero = %08X\n"
				"$at = %08X\n"
				"$v0 = %08X\n"
				"$v1 = %08X\n"
				"$a0 = %08X\n"
				"$a1 = %08X\n"
				"$a2 = %08X\n"
				"$a3 = %08X\n"
				"$t0 = %08X\n"
				"$t1 = %08X\n"
				"$t2 = %08X\n"
				"$t3 = %08X\n"
				"$t4 = %08X\n"
				"$t5 = %08X\n"
				"$t6 = %08X\n"
				"$t7 = %08X\n"
				"$s0 = %08X\n"
				"$s1 = %08X\n"
				"$s2 = %08X\n"
				"$s3 = %08X\n"
				"$s4 = %08X\n"
				"$s5 = %08X\n"
				"$s6 = %08X\n"
				"$s7 = %08X\n"
				"$t8 = %08X\n"
				"$t9 = %08X\n"
				"$k0 = %08X\n"
				"$k1 = %08X\n"
				"$gp = %08X\n"
				"$sp = %08X\n"
				"$fp = %08X\n"
				"$ra = %08X\n"
				"PC = %08X\n"
				"HI = %08X\n"
				"LO = %08X\n", 
				$zero,
				$at, 
				$v0, 
				$v1, 
				$a0, 
				$a1, 
				$a2, 
				$a3,
				$t0,
				$t1,
				$t2,
				$t3,
				$t4,
				$t5,
				$t6,
				$t7,
				$s0,
				$s1,
				$s2,
				$s3,
				$s4,
				$s5,
				$s6,
				$s7,
				$t8,
				$t9,
				$k0,
				$k1,
				$gp,
				$sp,
				$fp,
				$ra,
				PC,
				HI,
				LO);
		
	}
}
