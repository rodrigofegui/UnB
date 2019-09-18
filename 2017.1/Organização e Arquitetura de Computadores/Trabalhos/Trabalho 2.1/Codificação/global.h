/*include de bibliotecas e headers*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*comando para limpar tela (wipe)*/
#if defined(_WIN32)
    #define COMMAND "cls"
#else
    #define COMMAND "clear"
#endif

#define wipe() {system(COMMAND);}


/* Sao 32 registradores, mais os registradores especiais Pc, Ri, Hi e Lo*/
/* Todos eles sao variaveis globais */

typedef struct reg {//struct para banco de registradores
	char nome[6];
	int32_t valor;
}reg;

//Definicao do tamanho da memoria e quantidade de registradores padrao*/
#define MEM_SIZE 4096
extern int32_t mem[MEM_SIZE];
#define BREG_SIZE 32
extern reg breg[BREG_SIZE];

enum REGISTERS {//enumerar registradores
	ZERO=0, AT =1, V0=2,
	V1=3, A0=4, A1=5,
	A2=6, A3=7, T0=8,
	T1=9, T2=10, T3=11,
	T4=12, T5=13, T6=14,
	T7=15, T8=24, T9=25,
	S0=16, S1=17, S2=18,
	S3=19, S4=20, S5=21,
	S6=22, S7=23, K0=26,
	K1=27, GP=28, SP=29,
	FP=30, RA=31
};

enum SYSCALL_TYPE {//enumerar instrucoes de syscall
    PRINT_INT = 1, PRINT_STRING = 4, END = 10
};

enum OPCODES { /* So sao considerados os 6 primeiros bits */
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


/*continua_run -> variavel para verificar se ocorreu interrupcao ou fim do simulador*/
extern int continua_run;

/* Registradores Especiais */
extern uint32_t PC;
extern uint32_t RI;
extern int32_t HI;
extern int32_t LO;

/* Campos da Instrucao*/
extern int opcode;
extern int rs;
extern int rt;
extern int rd;
extern int shamt;
extern int funct;
extern short int k16;
extern long int k26;