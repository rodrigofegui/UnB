#ifndef BASICOS_ARQ_CLASS_H
    #define BASICOS_ARQ_CLASS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "./tags_flags.h"
    #include "./erros.h"
    #include "./tipos.h"
    #include "../Manipulacao/arquivos.h"

    typedef struct aqrClass {
        u4 codigo_arq;
        u2 versao_min;
        u2 versao_max;
        u2 qnt_tab_simbolo;
        CPInfo* tab_simbolo;
        u2 flag_acesso;
        u2 class_atual;
        u2 class_super;
    } ArqClass;

    ArqClass* decodificar (FILE* java_class);

    void decodificar_tab_simbolos(FILE* arq, ArqClass* java_class);
    void decodificar_dbl(FILE* arq, ArqClass* java_class, u1 byte, int ind);
    void decodificar_ref_cmp(FILE* arq, ArqClass* java_class, u1 byte, int ind);
    void decodificar_ref_mtd(FILE* arq, ArqClass* java_class, u1 byte, int ind);

    void exibir (ArqClass* java_class);
    void exibir_versao_java(u2 a_verificar);
    void exibir_tab_simbolos(CPInfo* tab_simbolo, int cnt);

#endif
