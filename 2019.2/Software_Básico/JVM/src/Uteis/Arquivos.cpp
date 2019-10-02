#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Erros.hpp"

FILE * abrir(const char *nome_arq){
    FILE *arq = fopen(nome_arq, "rb");

    if (arq == NULL){
        printf("\n[ERROR] Falha ao abrir o arquivo: '%s'\n", nome_arq);

        exit(E_ABRIR_ARQUIVO);
    }

    return arq;
}

void ler_u1(FILE *arq, u1 *dst){
    fread(dst, sizeof(u1), 1, arq);
}

void ler_u2(FILE *arq, u2 *dst, int modo){
    if (modo == 0){
        fread(dst, sizeof(u2), 1, arq);
        return;
    }

    u1 temp;

    for (int ind = 1; ind <= sizeof(u2); ind++){
        fread(&temp, sizeof(u1), 1, arq);
        *dst <<= 8;
        *dst |= temp;
    }
}

void ler_u4(FILE *arq, u4 *dst, int modo){
    if (modo == 0){
        fread(dst, sizeof(u4), 1, arq);
        return;
    }

    if (modo == 1){
        u1 temp;

        for (int ind = 0; ind < sizeof(u4); ind++){
            fread(&temp, sizeof(u1), 1, arq);
            *dst <<= 8;
            *dst |= temp;
        }

        return;
    }

    if (modo == 2){
        u2 temp;

        for (int ind = 0; ind < sizeof(u2); ind++){
            fread(&temp, sizeof(u2), 1, arq);
            *dst <<= 16;
            *dst |= temp;
        }
        return;
    }

    if (modo == 3) {
        u1 temp1;

        fread(dst, sizeof(u2), 1, arq);
        fread(&temp1, sizeof(u1), 1, arq);

        *dst = *dst << 16 | temp1;

        return;
    }
}

int get_padding(int num_max){
    int padding = 1;

    do{
        if ((num_max >= pow10(padding - 1)) && (num_max < pow10(padding)))
            break;

        padding++;
    }while(true);

    return padding;
}
