/* Declaração das funções*/

void fetch();

void decode();

void execute();

void step();

void run();

void dump_reg(char format);

void dump_mem(int start, int end, char format);

void load_mem(FILE *fp, int32_t *mem, int mode);

void print_mem(int32_t *mem);

void read_error();

void interface();

void adv_PC();

// syscall()???
