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
        u2 qnt_interfaces;
        InfoClasse* interfaces;
        u2 qnt_campos;
        InfoCampo* campos;
        u2 qnt_metodos;
        InfoMetodo *metodos;
        u2 qnt_atributos;
        // atributos;
    } ArqClass;

    ArqClass* decodificar (FILE* java_class);

    void decodificar_tab_simbolos(FILE* arq, ArqClass* java_class);
    void decodificar_utf8(FILE* arq, ArqClass* java_class, int ind);
    void decodificar_int(FILE* arq, ArqClass* java_class, int ind);
    void decodificar_float(FILE* arq, ArqClass* java_class, int ind);
    void decodificar_long(FILE* arq, ArqClass* java_class, int ind);
    void decodificar_dbl(FILE* arq, ArqClass* java_class, int ind);
    void decodificar_class(FILE *arq, ArqClass* java_class, int ind);
    void decodificar_string(FILE *arq, ArqClass* java_class, int ind);
    void decodificar_ref_cmp(FILE* arq, ArqClass* java_class, int ind);
    void decodificar_ref_mtd(FILE* arq, ArqClass* java_class, int ind);
    void decodificar_ref_mtd_itf(FILE* arq, ArqClass* java_class, int ind);
    void decodificar_nom_tip(FILE* arq, ArqClass* java_class, int ind);

    void decodificar_tab_campos(FILE* arq, ArqClass* java_class);

    void decodificar_tab_metodos(FILE* arq, ArqClass* java_class);

    void exibir (ArqClass* java_class);
    void exibir_versao_java(u2 a_verificar);
    void exibir_tab_simbolos(CPInfo* tab_simbolo, int cnt);
    void exibir_flag(u2 a_verificar);
    void exibir_tab_campos(InfoCampo* tab_campos, int lim, CPInfo* tab_simbolo);
    void exibir_tab_metodos(InfoMetodo* tab_metodos, int lim, CPInfo* tab_simbolo);

    void liberar(ArqClass *java_class);

#endif
