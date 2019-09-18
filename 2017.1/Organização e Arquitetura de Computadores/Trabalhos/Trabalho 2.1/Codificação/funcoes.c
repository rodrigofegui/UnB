/*include de bibliotecas e headers*/
#include "global.h"
#include "funcoes.h"
#include "operacoes.h"

reg breg[BREG_SIZE];
int continua_run = 0;

/* Impelementacao das funcoes */

/*Funcao INICIAR_BREG*/
/*Essa funcao para inicializar banco de registradores e campos da instrucao*/
void iniciar_breg (){
	add_breg(0, "$zero",0);
	add_breg(1 , "$at",0);
	add_breg(2 , "$v0",0);
	add_breg(3 , "$v1",0);
	add_breg(4 , "$a0",0);
	add_breg(5 , "$a1",0);
	add_breg(6 , "$a2",0);
	add_breg(7 , "$a3",0);
	add_breg(8 , "$t0",0);
	add_breg(9 , "$t1",0);
	add_breg(10 , "$t2",0);
	add_breg(11 , "$t3",0);
	add_breg(12 , "$t4",0);
	add_breg(13 , "$t5",0);
	add_breg(14 , "$t6",0);
	add_breg(15 , "$t7",0);
	add_breg(16 , "$s0",0);
	add_breg(17 , "$s1",0);
	add_breg(18 , "$s2",0);
	add_breg(19 , "$s3",0);
	add_breg(20 , "$s4",0);
	add_breg(21 , "$s5",0);
	add_breg(22 , "$s6",0);
	add_breg(23 , "$s7",0);
	add_breg(24 , "$t8",0);
	add_breg(25 , "$t9",0);
	add_breg(26 , "$k0",0);
	add_breg(27 , "$k1",0);
	add_breg(28 , "$gp",4*1536);
	add_breg(29 , "$sp",4*4095);
	add_breg(30 , "$fp",0);
	add_breg(31 , "$ra",0);

	PC = RI = HI = LO = 0;
	opcode = rs = rt = rd = shamt = funct = k16 = k26 = 0;
}


/*Funcao ADD_BREG*/
/*Essa funcao adiciona nome e valor inicial para determinado registrador*/
void add_breg (int i, char nome[6], int32_t valor) {
	strcpy(breg[i].nome, nome);
	breg[i].valor = valor;
}


/* Funcao FETCH */
/*Essa funcao le uma instrucao da memoria e coloca-a em ri, atualizando o pc
para apontar para a proxima instrucao (soma 4).*/
void fetch(){

	RI = mem[PC>>2];

	PC = PC + 4; /* Palavra -> 32 Bits*/
	return;
}

/* Funcao DECODE */
/*Essa funcao deve extrair todos os campos da instrucao proveniente
da funcao FETCH*/
void decode(){
	///* Instrucoes tipo R*///
	/* Opcode -> 6 Bits
	Rs/Rt/Rd -> 5 Bits
	Sa -> 5 Bits
	Funct -> 6 Bits*/

	///* Instrucoes tipo I*///
	/* Opcode -> 6 Bits
	Rs/Rt -> 5 Bits
	Imediato -> 16 Bits*/

	///* Instrucoes tipo J*///
	/* Opcode -> 6 Bits
	Destino do Jump -> 26 Bits*/

	opcode = ((uint32_t)RI >> 26) & 0x3F;
	rs = ((uint32_t)RI >> 21) & 0x1F;
	rt = ((uint32_t)RI >> 16) & 0x1F;
	rd = ((uint32_t)RI >> 11) & 0x1F;
	shamt = ((uint32_t)RI >> 6) & 0x1F;
	funct = (uint32_t)RI & 0x3F;
	k16 = (uint32_t)RI & 0xFFFF;
	k26 = (uint32_t)RI & 0x3FFFFFF;

	return;
}

/* Funcao STEP */
/*Essa executa uma instrucao do MIPS:
step() => fetch(), decode(), execute()*/
void step(){
	fetch();
	decode();
	execute();
	return;
}

/* Funcao RUN */
/*Essa funcao executa o programa ate encontrar uma chamada de sistema para encerramento,
ou ate o pc ultrapassar o limite do segmento de codigo (2k words).*/
void run(){

	iniciar_breg();//inicia banco de registradores a cada chamada de run

	continua_run = 1;
	while((PC<=0x2000) && (continua_run!=0)){
		step();//executa step ate acontecer interrupcao ou chamada de saida do sistema
	}
}

/* Funcao EXECUTE */
/*Essa funcao executa a instrucao que foi lida pela funcao FETCH e decodificada por DECODE.*/
void execute(){
	switch (opcode) {//analise do opcode para determinar operacao a ser efetuada em determinada instrucao
		case EXT:
			switch (funct) {//analisa valor de funct
				case ADD:
					add(rd,rs,rt); break;
				case SUB:
					sub(rd,rs,rt); break;
				case MULT:
					mult(rs,rt); break;
				case DIV:
					div_(rs,rt); break;
				case AND:
					and_(rd,rs,rt); break;
				case OR:
					or_(rd,rs,rt); break;
				case XOR:
					xor_(rd,rs,rt); break;
				case NOR:
					nor(rd,rs,rt); break;
				case SLT:
					slt(rd,rs,rt); break;
				case JR:
					jr(rs); break;
				case SLL:
					sll(rd,rt,shamt); break;
				case SRL:
					srl(rd,rt,shamt); break;
				case SRA:
					sra(rd,rt,shamt); break;
				case SYSCALL:
					syscall();break;
				case MFHI:
					mfhi(rd); break;
				case MFLO:
					mflo(rd); break;
				default:
					printf("\nValor de <FUNCT> invalido!\n"); exit(-6);
			}
			break;
		case LW:
			lw(rs,rt,k16); break;
		case LB:
			lb(rs,rt,k16); break;
		case LBU:
			lbu(rs,rt,k16); break;
		case LH:
			lh(rs,rt,k16); break;
		case LHU:
			lhu(rs,rt,k16); break;
		case LUI:
			lui(rt,k16); break;
		case SW:
			sw(rs,rt,k16); break;
		case SB:
			sb(rs,rt,k16); break;
		case SH:
			sh(rs,rt,k16); break;
		case BEQ:
			beq(rs,rt,k16); break;
		case BNE:
			bne(rs,rt,k16); break;
		case BLEZ:
			blez(rs,k16); break;
		case BGTZ:
			bgtz(rs,k16); break;
		case ADDI:
			addi(rt,rs,k16); break;
		case ADDIU:
			addiu(rt,rs,k16); break;
		case SLTI:
			slti(rs,rt,k16); break;
		case SLTIU:
			sltiu(rs,rt,k16); break;
		case ANDI:
			andi_(rt,rs,k16); break;
		case ORI:
			ori_(rt,rs,k16); break;
		case XORI:
			xori_(rt,rs,k16); break;
		case J:
			j(k26); break;
		case JAL:
			jal(k26); break;
		default:
			printf("\nValor de <OPCODE> invalido!\n"); exit(-7);
	}
}


/* Funcao READ ERROR */
/*Caso ocorra algum erro ao abrir os arquivos binarios
O programa imprime uma mensagem de erro e encerra. */
void read_error(){
	printf("\n Erro ao abrir o arquivo!\n");
	exit(-2);
}

/* Funcao INTERFACE */
/*Imprime a interface com o usuario e executa as funcoes pedidas*/
void interface(){

	int i;
	int start, end;
	char format;

	wipe();
	printf("\nDefina o numero da funcao desejada:\n"
			"1. step\n"
			"\tEssa funcao executa uma instrucao do MIPS\n\tstep() => fetch(), decode(), execute()\n"
			"\tModo de usar: Apos selecionar a funcao, sera executada uma instrucao do programa. Para executar \n"
			"\tdemais instrucoes, continue selecionando essa opcao. Pode selecionar dump_mem ou dump_reg apos cada step \n"
			"\tpara verificar estado da memoria e dos registradores.\n"
			"2. run\n"
			"\tEssa funcao executa o programa ate encontrar uma chamada de sistema para encerramento, ou ate o pc \n\tultrapassar o limite do segmento de codigo (2k words).\n"
			"\tModo de usar: Apos selecionar a funcao, sera executado o programa completo e sua saida sera apresentada na tela.\n"
			"3. dump_mem\n"
			"\tEssa funcao imprime o conteudo da memoria a partir do endere�o start ate o endere�o end.\n"
			"\tO formato pode ser em hexadecimal (h) ou decimal (d). A memoria deve ser impressa em palavras de 32 bits.\n"
			"\tModo de usar: Informe os valores de start e end e o formato desejado (h|d). Sera apresentado\n\t na tela o estado atual "
			"da memoria segundo o formato informado previamente.\n"
			"4. dump_reg\n"
			"\tEssa funcao imprime o conteudo dos registradores do MIPS, incluindo o banco de\n"
			"\tregistradores e os registradores pc, hi e lo. O formato pode ser em hexa (h) ou decimal (d).\n"
			"\tModo de usar: Informe o formato desejado (h|d). Sera apresentado na tela o estado atual \n"
			"\tda memoria segundo o formato informado previamente.\n"
			"5. Sair\n");

	printf("\nDigite a opcao desejada: ");
	scanf("%d", &i);
	getchar();

	switch (i) {
	    case 1 ://funcao step selecionada
	    	wipe();

	    	//caso o simulador nao tenha sido executado ou foi completamente executado (run), deve reiniciar registradores para realizar step
	    	if (continua_run == 0){
	    		continua_run = 1;
	    		iniciar_breg();//inicializacao do banco de registradores
	    	}
	    	printf("\nVoce selecionou a funcao Step!\n");
			printf("\n------ STEP REALIZADO -----\n");
			step();
			printf("\n\nTecle Enter para retornar...");
			getchar();
			break;

	    case 2 ://funcao run selecionada
	    	wipe();
	     	printf("\nVoce selecionou a funcao Run!\n");
	     	printf("\n----- PROGRAMA EXECUTADO -----\n");
	    	run();
	    	//printf("\n\nFim da execucao do programa! Tecle Enter...");
			//getchar();
	    	break;

	    case 3 ://funcao dump_mem selecionada
	    	wipe();
	     	printf("\nVoce selecionou a funcao Dump_Mem!\n");
	     	printf("Por favor, selecione o valor inicial da memoria: \n");
	     	scanf("%d", &start);
	     	printf("Por favor, selecione o valor final da memoria: \n");
	     	scanf("%d", &end);
	     	printf("Por favor, selecione a formatacao (h|d) da memoria: \n");
	     	scanf(" %c", &format);
	     	getchar();
	    	dump_mem(start, end, format);
	    	break;

	    case 4 ://funcao dump_reg selecionada
	    	wipe();
	     	printf("\nVoce selecionou a funcao Dump_Reg!\n");
	     	printf("Por favor, selecione a formatacao (h|d): \n");
	     	scanf(" %c", &format);
	     	getchar();
	    	dump_reg(format);
	    	break;

	    case 5 ://sair do simulador
	    	break;

	    default :
	    	wipe();
	    	printf ("Valor invalido!\n");
	    	getchar();
	    	break;
	}
	if (i != 5){//sempre retorna para menu caso nao escolha opcao sair
		interface();
	}
}


/* Funcao LOAD MEM */
/*Carrega o codigo e os dados dos arquivos binarios para a memoria do simulador*/
void load_mem(FILE *fp, int32_t *mem, int mode){

	int i;
	unsigned char c;

	//carrega dados do arquivo _text
	if(mode == 0){
		i = 0; /* Posicao 0x00000000 da memoria */
		while (fread(&c, sizeof(unsigned char), 1, fp)>0){
			mem[i/4] = c;
			fread(&c, sizeof(unsigned char), 1, fp);
			mem[i/4] = mem[i/4] | c<<8;
			fread(&c, sizeof(unsigned char), 1, fp);
			mem[i/4] = mem[i/4] | c<<16;
			fread(&c, sizeof(unsigned char), 1, fp);
			mem[i/4] = mem[i/4] | c<<24;
			i = i+4;
			if(i >= 4096*4){
				printf("\nUltrapassou o tamanho da memoria do simulador!\n");
				exit(-3);
			}
		}

	//carrega dados do arquivo _data
	} else if( mode == 1) {

		i = 2048*4; /* Posicao 0x00002000 da memoria */
		while (fread(&c, sizeof(unsigned char), 1, fp)>0){//shifts para esquerda na variavel 'c' para alocar adequadamente os bytes em mem
			mem[i/4] = c;
			fread(&c, sizeof(unsigned char), 1, fp);
			mem[i/4] = mem[i/4] | c<<8;
			fread(&c, sizeof(unsigned char), 1, fp);
			mem[i/4] = mem[i/4] | c<<16;
			fread(&c, sizeof(unsigned char), 1, fp);
			mem[i/4] = mem[i/4] | c<<24;
			i = i+4;
			if(i >= 4096*4){
				break; /* Carrega na memoria do simulador ate seu limite */
			}
		}

	} else {
		printf("\nModo de Carregamento da Memoria Invalido!\n");
		exit(-4);
	}

}

/* Funcao DUMP MEM */
/*Essa funcao imprime o conteudo da memoria a partir do endereco start ate o endereco end.
O formato pode ser em hexa (h) ou decimal (d). A memoria deve ser impressa em palavras
de 32 bits, de acordo com o formato abaixo, onde o lado esquerdo apresenta o endereco da
memoria e o lado direito mostra o valor contido nesse endereco.*/
void dump_mem(unsigned int start, unsigned int end, char format){

	unsigned int i;

	if(start < 0 || end > MEM_SIZE){
		do{
			printf("Endereco de memoria invalido!\n Deseja digitar os valores novamente?\n Sim(1)/ Nao(0)\n");
			scanf("%u", &i);
			if(i == 0){
				exit(0);
			}
			printf("Digite o endereco inicial: ");
			scanf("%d", &start);
			printf("Digite o endereco final: ");
			scanf("%d", &end);
		}while(start < 0x0 || end > 0x2000);
	}

	//imprime em formato decimal
	if(format == 'd'){
		printf("\nMEMORY\n");
		for(i = start; i <= end; i++){
			printf("0x%08X\t=\t%i\n", i*4, mem[i]);
		}

	//caso contrario imprime em formato hexadecimal caso seja valido o formato informado
	} else if(format == 'h') {
		printf("\nMEMORY\n");
		for(i = start; i <= end; i++){
			printf("0x%08X\t=\t0x%08X\n", i*4, mem[i]);
		}
	} else {
		printf("\nFormato invalido! Tecle Enter...\n");
		getchar();
		exit(-7);
	}
	printf("\n\nTecle Enter para retornar...");
	getchar();
}


/* Funcao DUMP REG */
/*Funcao que imprime os valores de todos os
registradores */

void dump_reg(char format){

	//Imprime banco de registradores em formato decimal
	if(format == 'd'){
		printf("\nREGISTERS\n");
		for(unsigned int i = 0; i<32; i++) {
			printf("%s\t=\t%i\n", breg[i].nome, breg[i].valor);
		}
		printf("PC\t=\t%i\n", PC);
		printf("HI\t=\t%i\n", HI);
		printf("LO\t=\t%i\n", LO);

	//caso contrario imprime em formato padrao hexadecimal
	} else if(format == 'h'){
		printf("\nREGISTERS\n");
		for(unsigned int i = 0; i<32; i++) {
			printf("%s\t=\t0x%08X\n", breg[i].nome, breg[i].valor);
		}
		printf("PC\t=\t0x%08X\n", PC);
		printf("HI\t=\t0x%08X\n", HI);
		printf("LO\t=\t0x%08X\n", LO);
	} else {
		printf("\nFormato invalido! Tecle Enter...\n");
		getchar();
		exit(-7);
	}
	printf("\n\nTecle Enter para retornar...");
	getchar();
}

void dump_mem_arq (FILE *arq){
	int i;

	fprintf(arq, "MEMORY\n");

	//Imprime em formato padrao hexadecimal
	for(i = 0; i <= MEM_SIZE; i++)
		fprintf(arq, "0x%08X\t=\t0x%08X\n", i*4, mem[i]);
}

void dump_reg_arq(FILE *arq){
	int i;

	fprintf(arq, "REGISTERS\n");

	//Imprime em formato padrao hexadecimal
	for(i = 0; i<32; i++) {
		fprintf(arq, "%s\t=\t0x%08X\n", breg[i].nome, breg[i].valor);
	}
	fprintf(arq, "PC\t=\t0x%08X\n", PC);
	fprintf(arq, "HI\t=\t0x%08X\n", HI);
	fprintf(arq, "LO\t=\t0x%08X\n", LO);
}

void registrar (){
	FILE *arq = fopen ("reg.txt", "w+");

	dump_reg_arq (arq);

	fclose (arq);

	arq = fopen ("mem.txt", "w+");

	dump_mem_arq (arq);

	fclose (arq);
}