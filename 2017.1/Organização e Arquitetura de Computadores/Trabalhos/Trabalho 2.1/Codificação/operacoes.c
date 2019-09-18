/*include de bibliotecas e headers*/
#include "global.h"
#include "operacoes.h"

/*implementacao de algumas funcoes mnemonicas presentes no MIPS*/

void add (unsigned int rd, unsigned int rs, unsigned int rt){
	breg[rd].valor = breg[rs].valor + breg[rt].valor;
}

void addi (unsigned int rt, unsigned int rs, signed int imediato){
	breg[rt].valor = breg[rs].valor + imediato;
}

void addiu (unsigned int rt, unsigned int rs, unsigned int imediato){
	breg[rt].valor = breg[rs].valor + imediato;
}

void sub (unsigned int rd, unsigned int rs, unsigned int rt){
	breg[rd].valor = breg[rs].valor - breg[rt].valor;
}

void div_ (unsigned int rs, unsigned int rt){
	LO = (breg[rs].valor / breg[rt].valor);
	HI = (breg[rs].valor % breg[rt].valor);
}

void mult (signed int rs, signed int rt){
	int32_t rs_lo = (uint16_t)breg[rs].valor;
	int32_t rs_hi = (breg[rs].valor)>>16;
	int32_t rt_lo = (uint16_t)breg[rt].valor;
	int32_t rt_hi = (breg[rt].valor)>>16;

    int32_t rs_x_rt_hi = rs_hi*rt_hi;
    int32_t rs_x_rt_mid = rs_hi*rt_lo;
    int32_t rt_x_rs_mid = rt_hi*rs_lo;
    int32_t rs_x_rt_lo = rs_lo*rt_lo;

    int32_t carry = ((uint16_t)rs_x_rt_mid + (uint16_t)rt_x_rs_mid + (uint16_t)(rs_x_rt_lo>>16))>>16;

	LO =  ((rs_x_rt_mid<<16) + (rt_x_rs_mid<<16)) + (rs_x_rt_lo);
    HI = rs_x_rt_hi + (rs_x_rt_mid>>16) + (rt_x_rs_mid>>16) + carry;
}

void and_ (unsigned int rd, unsigned int rs, unsigned int rt){
	breg[rd].valor = breg[rs].valor & breg[rt].valor;
}

void andi_ (unsigned int rt, unsigned int rs, int imediato){
	breg[rt].valor = breg[rs].valor & imediato;
}

void or_ (unsigned int rd, unsigned int rs, unsigned int rt){
	breg[rd].valor = breg[rs].valor | breg[rt].valor;
}

void ori_ (unsigned int rt, unsigned int rs, int imediato){
	breg[rt].valor = breg[rs].valor | imediato;
}

void nor (unsigned int rd, unsigned int rs, unsigned int rt){
	breg[rd].valor = ~(breg[rs].valor | breg[rt].valor);
}

void xor_ (unsigned int rd, unsigned int rs, unsigned int rt){
	breg[rd].valor = breg[rs].valor ^ breg[rt].valor;
}

void xori_ (unsigned int rt, unsigned int rs, int imediato){
	breg[rt].valor = breg[rs].valor ^ imediato;
}

void slt (unsigned int rd, unsigned int rs, unsigned int rt){
	if(breg[rs].valor < breg[rt].valor){
		breg[rd].valor = 0x01;
	} else {
		breg[rd].valor = 0x00;
	}
}

void slti (unsigned int rs, unsigned int rt, int imediato){
	if(breg[rs].valor < imediato){
		breg[rt].valor = 0x01;
	} else {
		breg[rt].valor = 0x00;
	}
}

void sltiu (unsigned int rs, unsigned int rt, unsigned int imediato){
	if(breg[rs].valor < imediato){
		breg[rt].valor = 0x01;
	} else {
		breg[rt].valor = 0x00;
	}
}

void sll (unsigned int rd, unsigned int rt, unsigned int shamt){
	breg[rd].valor = breg[rt].valor<<shamt;
}

void srl (unsigned int rd, unsigned int rt, unsigned int shamt){
	int32_t aux = breg[rt].valor;
    int cnt;

    for (cnt = 0; cnt < shamt; cnt++){
        aux = ((aux >> 1) & (0x7fffffff));
    }

	breg[rd].valor = aux;
}

void sra (unsigned int rd, unsigned int rt, unsigned int shamt){
	breg[rd].valor = breg[rt].valor >> shamt;
}

void mfhi (unsigned int rd){
	breg[rd].valor = HI;
}

void mflo (unsigned int rd){
	breg[rd].valor = LO;
}

void j (unsigned int target){
	int novo_pc = ((PC & 0xF0000000) | (target<<2));
	PC = novo_pc;
}

void jal (unsigned int target){
	int novo_pc = ((PC & 0xF0000000) | (target<<2));
	breg[31].valor = PC;
	PC = novo_pc;
}

void jr (unsigned int rs){
	PC = (breg[rs].valor);
}

void beq (unsigned int rs, unsigned int rt, int offset){
	if (breg[rs].valor == breg[rt].valor){
		PC += offset<<2;
	}
}

void bne (unsigned int rs, unsigned int rt, int offset){
	if (breg[rs].valor != breg[rt].valor){
		PC += offset<<2;
	}
}

void bgtz (unsigned int rs, int offset){
	if (breg[rs].valor > 0){
		PC += offset<<2;
	}
}

void blez (unsigned int rs, int offset){
	if (breg[rs].valor <= 0){
		PC += offset<<2;
	}
}

void lb (unsigned int rs, unsigned int rt, int offset){
	int32_t aux = *((int8_t *)&mem[breg[rs].valor>>2] + offset);
	breg[rt].valor = aux;
}

void lbu (unsigned int rs, unsigned int rt, int offset){
	int32_t aux = *((uint8_t *)&mem[breg[rs].valor>>2] + offset);
	breg[rt].valor = aux;
}

void lh (unsigned int rs, unsigned int rt, int offset){
	int32_t aux = *((int16_t *)&mem[breg[rs].valor>>2] + offset);
	breg[rt].valor = aux;
}

void lhu (unsigned int rs, unsigned int rt, int offset){
	int32_t aux = *((uint16_t *)&mem[breg[rs].valor>>2] + offset);
	breg[rt].valor = aux;
}

void lw (unsigned int rs, unsigned int rt, int offset){
	breg[rt].valor = mem[(breg[rs].valor + offset)>>2];
}

void lui (unsigned int rt, int imediato){
	breg[rt].valor = imediato<<16;
}

void sb (unsigned int rs, unsigned int rt, int offset){
	mem[(breg[rs].valor + offset)>>2] = (0xFF & breg[rt].valor);
}

void sh (unsigned int rs, unsigned int rt, int offset){
	mem[(breg[rs].valor + offset)>>2] = (0xFFFF & breg[rt].valor);
}

void sw (unsigned int rs, unsigned int rt, int offset){
	mem[(breg[rs].valor + offset)>>2] = breg[rt].valor;
}

void syscall(){
	int temp;

	//verifica valor de $v0
	switch(breg[V0].valor){
		case PRINT_INT:
			printf("%d", breg[A0].valor);
			break;
		case PRINT_STRING:
			print_string();
			break;
		case END:
			continua_run = 0;
	    	printf("\n\nFim da execucao do programa! Tecle Enter...");
			getchar();
			break;
	}
}

void print_string(){
	unsigned int inicio = breg[A0].valor;
	unsigned int resto = inicio%4;
	unsigned int tmp = mem[inicio>>2];
	unsigned int done = 0;
	unsigned int aux;
	char* string_final;
	int i, x, j;

	inicio -= resto;
	string_final = calloc(1,sizeof(char));

	while(!done) {
		inicio += 4;

		aux = (int)__builtin_bswap32((int32_t)tmp);//big_endian -> little_endian (reoordena os bytes)

		j = 0;
		for (i = resto*2; i<8; i+=2){

			x = (uint8_t)(aux>>(24-4*i));
			if (x==0xa0){
				x = '\n';
			} else if (x==0x0){
				done = 1;
				break;
			}
			string_final = (char*)realloc(string_final,(j+1)*sizeof(char));
			string_final[j] = x;
			j++;
		}
		string_final[j] = '\0';
		printf("%s", string_final);
		resto = inicio%4;
		tmp = mem[inicio>>2];
	}
	free(string_final);
}