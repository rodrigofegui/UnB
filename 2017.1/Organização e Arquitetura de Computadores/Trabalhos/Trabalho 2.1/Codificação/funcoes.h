/* Declaração das funções presentes em funcoes.c*/
void iniciar_breg ();

void add_breg (int i, char nome[6], int32_t valor);

void fetch();

void decode();

void step();

void run();

void execute();

void dump_reg(char format);

void dump_mem(unsigned int start,unsigned int end, char format);

void load_mem(FILE *fp, int32_t *mem, int mode);

void print_mem(int32_t *mem);

void read_error();

void interface();

void registrar ();

void dump_reg_arq(FILE *arq);

void dump_mem_arq (FILE *arq);