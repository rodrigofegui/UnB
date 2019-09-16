/* São 32 registradores, mais os registradores especiais Pc, Ri, Hi e Lo*/
/* Todos eles são variáveis globais */

	extern int32_t $zero;
	extern int32_t $at;
	extern int32_t $v0;
	extern int32_t $v1;
	extern int32_t $a0;
	extern int32_t $a1;
	extern int32_t $a2;
	extern int32_t $a3;
	extern int32_t $t0;
	extern int32_t $t1;
	extern int32_t $t2;
	extern int32_t $t3;
	extern int32_t $t4;
	extern int32_t $t5;
	extern int32_t $t6;
	extern int32_t $t7;
	extern int32_t $s0;
	extern int32_t $s1;
	extern int32_t $s2;
	extern int32_t $s3;
	extern int32_t $s4;
	extern int32_t $s5;
	extern int32_t $s6;
	extern int32_t $s7;
	extern int32_t $t8;
	extern int32_t $t9;
	extern int32_t $k0;
	extern int32_t $k1;
	extern int32_t $gp;
	extern int32_t $sp;
	extern int32_t $fp;
	extern int32_t $ra;
	
/* Registradores Especiais */
	
	extern uint32_t PC;
	extern uint32_t RI;
	extern int32_t HI;
	extern int32_t LO;

/* Memória do simulador */
	
	extern int32_t *mem;
	
/* Campos da Instrução*/

	extern int opcode;
	extern int rs;
	extern int rt;
	extern int rd;
	extern int shamt;
	extern int funct;
	extern short int k16;
	extern long int k26;
