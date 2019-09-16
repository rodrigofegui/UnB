#include "../headers/MIPSS_ops.h"
//Todas as simulacoes foram baseadas em http://www.mrc.uidaho.edu/mrc/people/jff/digital/MIPSir.html e http://www.cse.ohio-state.edu/~crawfis/cse675-02/Slides/MIPS%20Instruction%20Set.pdf
//Aritimetica
void addi(unsigned int rdest,unsigned int rs, signed int immediate)
{
    breg[rdest].value = breg[rs].value + immediate;
    return;
}
void addiu(unsigned int rdest,unsigned int rs, unsigned int immediate)
{
    breg[rdest].value = breg[rs].value + immediate;
    return;
}
void add(unsigned int rdest,unsigned int r1,unsigned int r2)
{
    breg[rdest].value = breg[r1].value + breg[r2].value;
    return;
}

void subi(unsigned int rdest,unsigned int rt, signed int immediate)
{
    breg[rdest].value = breg[rt].value - immediate;
    return;
}

void subiu(unsigned int rdest,unsigned int rt, unsigned int immediate)
{
    breg[rdest].value = breg[rt].value - immediate;
    return;
}

void sub(unsigned int rdest,unsigned int r1,unsigned int r2)
{
    breg[rdest].value = breg[r1].value - breg[r2].value;
    return;
}

void mult(unsigned int rdest,unsigned int r1)
{
    long _tmp = breg[rdest].value * breg[r1].value;
    std::bitset<64> tmp(_tmp);
    std::string btmp = tmp.to_string();
    std::string lo32 (btmp.begin()+32,btmp.end());
    std::string hi32 (btmp.begin(),btmp.begin()+32);
    std::bitset<32> blo (lo32);
    std::bitset<32> bhi (hi32);
    lo = blo.to_ulong();
    hi = bhi.to_ulong();
    return;
}

void div(unsigned int r1,unsigned int r2)
{
    lo = (breg[r1].value / breg[r2].value);
    hi = (breg[r1].value % breg[r2].value);
    return;
}

void andi_(unsigned int rdest,unsigned int r1, int immediate)
{
    breg[rdest].value = breg[r1].value & immediate;
    return;
}

void and_(unsigned int rdest,unsigned int r1,unsigned int r2)
{
    breg[rdest].value = breg[r1].value & breg[r2].value;
    return;
}

void ori_(unsigned int rdest,unsigned int r1, signed int immediate)
{
    breg[rdest].value = breg[r1].value | immediate;
    return;
}

void or_(unsigned int rdest,unsigned int r1,unsigned int r2)
{
    breg[rdest].value = breg[r1].value | breg[r2].value;
    return;
}

void xori_(unsigned int rdest,unsigned int r1, signed int immediate)
{
    breg[rdest].value = breg[r1].value ^ immediate;
    return;
}

void xor_(unsigned int rdest,unsigned int r1,unsigned int r2)
{
    breg[rdest].value = breg[r1].value ^ breg[r2].value;
    return;
}

void nor(unsigned int rdest,unsigned int r1,unsigned int r2)
{
    breg[rdest].value = ~(breg[r1].value | breg[r2].value);
    return;
}

void slt(unsigned int rd,unsigned int rs,unsigned int rt)
{
    breg[rd].value = (breg[rs].value<breg[rt].value?1:0);
    return;
}

void slti(unsigned int rs, unsigned int rt, int immediate)
{
    breg[rt].value = (breg[rs].value<immediate?1:0);
}

void sltiu(unsigned int rs, unsigned int rt,unsigned int immediate)
{
    breg[rt].value = (breg[rs].value<<(int)immediate?1:0);
}

void sll(unsigned int rdest,unsigned int r1, unsigned int shift)
{
    for(unsigned int i=0;i<shift;i++)
    {
        breg[rdest].value = breg[r1].value<<2;
    }
    return;
}

void srl(unsigned int rdest,unsigned int r1, unsigned int shift)
{
    int i = shift;
    if(shift> 31) {
        i = 32;
        //TODO:                             ------------------------------ERROS!
    } else if (shift < 0) {
        i = 0;
    }

    std::bitset<32> bit_num(breg[r1].value);

    bit_num >>= i;
    int int_num = (int) bit_num.to_ulong();

    breg[rdest].value = int_num;

    return;
}

void sra(unsigned int rdest,unsigned int r1, unsigned int shift)
{
    breg[rdest].value = breg[r1].value>>shift;
    return;
}

void mfhi(unsigned int rdest)
{
    breg[rdest].value = hi;
    return;
}

void mflo(unsigned int rdest)
{
    breg[rdest].value = lo;
    return;
}

//Syscall
std::string hex_to_string (std::string str, unsigned int resto, unsigned int &done)
{
    std::string tmp;
    const char *c = str.c_str();
    c+=resto*2;
    int x;
    while(*c != 0)
    {
        sscanf(c, "%2X", &x);//Le 2 digitos hex e transforma em inteiro
        if(x==0xa0)
        {
            x = '\n';
        }
        else if(x==0x0)
        {
            done = 1;
            break;
        }
        tmp += x;//Adiciona o inteiro a str sera entao printado como char
        c += 2;//Anda 2 na string de hex
    }
    return tmp;
}
void print_string()
{
    unsigned int inicio = breg[4].value;
    unsigned int resto = inicio%4;
    unsigned int tmp = mem[inicio>>2];
    unsigned int done = 0;
    inicio-=resto;
    while(!done)
    {
        inicio+=4;
        std::stringstream ss;
        ss <<std::hex<<(int)__builtin_bswap32((int32_t)tmp);
//        hex_to_string(ss.str(),resto);
        std::cout<<hex_to_string(ss.str(),resto,done);
        resto = inicio%4;
        tmp = mem[inicio>>2];
    }
}
void syscall()
{
    switch(breg[2].value)
    {
    case PRINT_INT:
        std::cout<<breg[4].value;
        break;
    case PRINT_STRING:
        print_string();
        break;
    case END:
        running = 0;
        break;
    }
}

//Jumps
void j(unsigned int target)
{
    int npc = ((pc & 0xf0000000) | (target<<2));
    pc = npc;
    return;
}

void jal(unsigned int target)
{
    int npc = ((pc & 0xf0000000) | (target<<2));
    breg[31].value = pc;
    pc = npc;
    return;
}

void jr(unsigned int rdest)
{
    pc = (breg[rdest].value);
    return;
}

void beq(unsigned int rs, unsigned int rt, int target)
{
    if(breg[rs].value==breg[rt].value)
        pc += target<<2;
}

void bne(unsigned int rs,unsigned int rt, int target)
{
    if(breg[rs].value!=breg[rt].value)
        pc += target<<2;
}

void blez(unsigned int rs, int target)
{
    if(breg[rs].value<1)
        pc += target<<2;
}

void bgtz(unsigned int rs, int target)
{
    if(breg[rs].value>0)
        pc += (target<<2);
}

//Memoria
void lw(unsigned int rs,unsigned int rt, int immediate)
{
    breg[rt].value = mem[((breg[rs].value) + (immediate))>>2];
    return;
}

void lb(unsigned int rs, unsigned int rt, int immediate)
{
    int aux = mem[(((breg[rs].value) + immediate))>>2] << 24;
    aux>>=24;
    breg[rt].value = aux;
    return;
}

void lbu(unsigned int rs, unsigned int rt,unsigned int immediate)
{
    breg[rt].value = mem[((breg[rs].value) + (immediate))>>2] & 0xff;
    return;
}

void lh(unsigned int rs, unsigned int rt, int immediate)
{
    int aux = mem[(((breg[rs].value) + immediate))>>2] << 16;
    aux>>=16;
    breg[rt].value = aux;
    return;
}

void lhu(unsigned int rs, unsigned int rt, int immediate)
{
    int aux = mem[(((breg[rs].value) + immediate))>>2] & 0xffff;
    breg[rt].value = aux;
    return;
}

void lui(unsigned int rt, int immediate)
{
    breg[rt].value = immediate<<16;
    return;
}

void sw(unsigned int rs, unsigned int rt, int immediate)
{
    mem[(immediate+breg[rs].value)>>2] = breg[rt].value;
    return;
}

void sb(unsigned int rs, unsigned int rt, int immediate)
{
    mem[(breg[rs].value + immediate)>>2] = (0xff & breg[rt].value);
    return;
}

void sh(unsigned int rs, unsigned int rt, int immediate)
{
    mem[(((breg[rs].value) + (immediate))>>2)] = (0xffff & breg[rt].value);
    return;
}
