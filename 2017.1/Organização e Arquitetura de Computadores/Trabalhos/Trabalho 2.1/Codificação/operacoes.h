/* Declaração das funções presentes em funcoes.c*/
void add (unsigned int rd, unsigned int rs, unsigned int rt);

void addi (unsigned int rt, unsigned int rs, int imediato);

void addiu (unsigned int rt, unsigned int rs, unsigned int imediato);

void sub (unsigned int rd, unsigned int rs, unsigned int rt);

void div_ (unsigned int rs, unsigned int rt);

void mult (signed int rs, signed int rt);

void and_ (unsigned int rd, unsigned int rs, unsigned int rt);

void andi_ (unsigned int rt, unsigned int rs, int imediato);

void or_ (unsigned int rd, unsigned int rs, unsigned int rt);

void ori_ (unsigned int rt, unsigned int rs, int imediato);

void nor (unsigned int rd, unsigned int rs, unsigned int rt);

void xor_ (unsigned int rd, unsigned int rs, unsigned int rt);

void xori_ (unsigned int rt, unsigned int rs, int imediato);

void slt (unsigned int rd, unsigned int rs, unsigned int rt);

void slti (unsigned int rs, unsigned int rt, int imediato);

void sltiu (unsigned int rs, unsigned int rt, unsigned int imediato);

void sll (unsigned int rd, unsigned int rt, unsigned int shamt);

void srl (unsigned int rd, unsigned int rt, unsigned int shamt);

void sra (unsigned int rd, unsigned int rt, unsigned int shamt);

void mfhi (unsigned int rd);

void mflo (unsigned int rd);

void j (unsigned int target);

void jal (unsigned int target);

void jr (unsigned int rs);

void beq (unsigned int rs, unsigned int rt, int offset);

void bne (unsigned int rs, unsigned int rt, int offset);

void bgtz (unsigned int rs, int offset);

void blez (unsigned int rs, int offset);

void lb (unsigned int rs, unsigned int rt, int offset);

void lbu (unsigned int rs, unsigned int rt, int offset);

void lh (unsigned int rs, unsigned int rt, int offset);

void lhu (unsigned int rs, unsigned int rt, int offset);

void lw (unsigned int rs, unsigned int rt, int offset);

void lui (unsigned int rt, int imediato);

void sb (unsigned int rs, unsigned int rt, int offset);

void sh (unsigned int rs, unsigned int rt, int offset);

void sw (unsigned int rs, unsigned int rt, int offset);

void syscall();

void print_string();