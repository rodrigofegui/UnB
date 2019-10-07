#ifndef UTEIS_ARQUIVOS_HPP
    #define UTEIS_ARQUIVOS_HPP

    #include <stdio.h>
    #include <string>
    #include "../Tipos/Basicos.hpp"

    FILE * abrir(const char *nome_arq);

    void ler_u1(FILE *arq, u1 *dst);

    void ler_u2(FILE *arq, u2 *dst, int modo);

    void ler_u4(FILE *arq, u4 *dst, int modo);

    int get_padding(int num_max);

    void exibir_hex(u1 fonte);

    void exibir_hex_2(u2 fonte);

    void exibir_hex_4(u4 fonte);

#endif
