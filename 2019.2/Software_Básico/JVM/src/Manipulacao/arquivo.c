#include "../../lib/Manipulacao/arquivos.h"

FILE* leitura (const char *nome_arq){
    FILE *arq = fopen(nome_arq, "rb");

    if (arq == NULL){
        printf("\n[ERROR] Falha ao abrir o arquivo: '%s'\n", nome_arq);

        exit(E_ABRIR_ARQUIVO);
    }

    return arq;
}

void ler_b_u2(FILE *arq, u2 *dst){
    u1 temp;

    for (int ind = 1; ind <= sizeof(u2); ind++){
        fread(&temp, sizeof(u1), 1, arq);
        *dst <<= 8;
        *dst |= temp;
    }
}

void ler_b_u4(FILE *arq, u4 *dst){
    u1 temp;

    for (int ind = 1; ind <= sizeof(u4); ind++){
        fread(&temp, sizeof(u1), 1, arq);
        *dst <<= 8;
        *dst |= temp;
    }
}
