#ifndef MANIPULACAO_ARQUIVOS_H
    #define MANIPULACAO_ARQUIVOS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "../Basicos/erros.h"
    #include "../Basicos/tipos.h"

    FILE* leitura(const char *nome_arq);

    void ler_b_u2(FILE* arq, u2* dst, int inverter);

    void ler_b_u4(FILE* arq, u4* dst, int inverter);

#endif
