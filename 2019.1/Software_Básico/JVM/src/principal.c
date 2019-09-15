#include <stdio.h>
#include <stdlib.h>
#include "../lib/Basicos/tipos.h"

int main(int argc, char *argv[]){
    CPInfo teste;
    InfoClasse p;

    p.tag = 0x0003;
    p.ind_nome = 0xffff;

    teste.tag = 0x0023;
    teste.dados.classe = p;

    printf("hello world! -> %d\n", teste.tag);
    printf("tag => %04X\tind_name=%04X\n", teste.dados.classe.tag, teste.dados.classe.ind_nome);

    return 0;
}
