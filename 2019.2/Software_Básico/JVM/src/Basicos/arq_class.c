#include "../../lib/Basicos/arq_class.h"

ArqClass* decodificar(FILE* arq_class){
    ArqClass* novo_class = (ArqClass*) calloc (1, sizeof(ArqClass));

    if (!novo_class){
        printf("\n[ERROR] Falha ao alocar um arquivo .CLASS para decodificação\n");
        exit(E_ALOCAR_CLASS);
    }

    ler_b_u4(arq_class, &novo_class->codigo_arq);

    if (novo_class->codigo_arq != 0xCAFEBABE){
        free(novo_class);
        return NULL;
    }

    ler_b_u2(arq_class, &novo_class->versao_min);
    ler_b_u2(arq_class, &novo_class->versao_max);
    ler_b_u2(arq_class, &novo_class->qnt_tab_simbolo);

    novo_class->tab_simbolo = (CPInfo *) calloc (novo_class->qnt_tab_simbolo - 1, sizeof(CPInfo));

    if (!novo_class->tab_simbolo) {
        printf("\n[ERROR] Falha ao alocar a tabela de símbolos\n");
        exit(E_ALOCAR_TAB_SIMB);
    }

    decodificar_tab_simbolos(arq_class, novo_class);

    return novo_class;
}

void decodificar_tab_simbolos(FILE* arq, ArqClass* java_class){
    u1 temp;

    for (int cnt = 0; cnt < java_class->qnt_tab_simbolo; cnt++){
        fread(&temp, sizeof(u1), 1, arq);

        switch (temp){
            case TAG_UTF:
                break;
            case TAG_INT:
                break;
            case TAG_FLT:
                break;
            case TAG_LNG:
                break;
            case TAG_DBL:
                decodificar_dbl(arq, java_class, temp, cnt);
                cnt++;
                break;
            case TAG_CLAS:
                break;
            case TAG_STR:
                break;
            case TAG_REF_CMP:
                decodificar_ref_cmp(arq, java_class, temp, cnt);
                break;
            case TAG_REF_MTD:
                decodificar_ref_mtd(arq, java_class, temp, cnt);
                break;
            case TAG_REF_MTD_ITF:
                break;
            case TAG_NOM_TIP:
                break;
        }
    }
}

void decodificar_dbl(FILE* arq, ArqClass* java_class, u1 byte, int ind){
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.duplo.bytes_mais);
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.duplo.bytes_menos);
    java_class->tab_simbolo[ind].tag = byte;
}

void decodificar_ref_cmp(FILE* arq, ArqClass* java_class, u1 byte, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.ref_campo.ind_classe);
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.ref_campo.ind_nome_tipo);
    java_class->tab_simbolo[ind].tag = byte;
}

void decodificar_ref_mtd(FILE* arq, ArqClass* java_class, u1 byte, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.metodo.ind_classe);
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.metodo.ind_nome_tipo);
    java_class->tab_simbolo[ind].tag = byte;
}

void exibir (ArqClass* java_class){
    printf("\n");

    if (!java_class) {
        printf("O arquivo não é um .CLASS válido\n");

        return;
    }

    printf("Código indentificador: 0x%08X\n", java_class->codigo_arq);

    printf("Versão mínima compilador: ");
        exibir_versao_java(java_class->versao_min);

    printf("Versão máxima compilador: ");
        exibir_versao_java(java_class->versao_max);

    printf("Qnt. de entradas na tabela de símbolos: %d\n", java_class->qnt_tab_simbolo);

    printf("Tabela de símbolos: \n");
        exibir_tab_simbolos(java_class->tab_simbolo, java_class->qnt_tab_simbolo);

    printf("Flag de acesso: %X\n", java_class->flag_acesso);

    printf("Classe corrente: %d\n", java_class->class_atual);

    printf("Classe super: %d\n", java_class->class_super);
}

void exibir_versao_java(u2 a_verificar){
    switch (a_verificar){
        case V1_2:
            printf("Java 1.2\n"); break;
        case V1_3:
            printf("Java 1.3\n"); break;
        case V1_4:
            printf("Java 1.4\n"); break;
        case V5:
            printf("Java 5\n"); break;
        case V6:
            printf("Java 6\n"); break;
        case V7:
            printf("Java 7\n"); break;
        case V8:
            printf("Java 8\n"); break;
        case V9:
            printf("Java 9\n"); break;
        case V10:
            printf("Java 10\n"); break;
        case V11:
            printf("Java 11\n"); break;
        default:
            printf("Sem expecificação\n");
    }
}

void exibir_tab_simbolos(CPInfo* tab_simbolo, int cnt){
    CPInfo temp;
    int ignora = 0;

    for (int ind = 0; ind < cnt; ind++){
        temp = tab_simbolo[ind];

        switch (temp.tag) {
            case TAG_UTF:
                break;
            case TAG_INT:
                break;
            case TAG_FLT:
                break;
            case TAG_LNG:
                break;
            case TAG_DBL:
                printf("\t[%02d] CONSTANT_Double\n", ind + 1);
                printf("\t\tByte mais significativo: 0x%08X\n", temp.dados.duplo.bytes_mais);
                printf("\t\tByte menos significativo: 0x%08X\n", temp.dados.duplo.bytes_menos);
                ignora ^= 1;
                break;
            case TAG_CLAS:
                break;
            case TAG_STR:
                break;
            case TAG_REF_CMP:
                printf("\t[%02d] CONSTANT_Fieldref\n", ind + 1);
                printf("\t\tIndíce para a classe: %d\n", temp.dados.ref_campo.ind_classe);
                printf("\t\tÍndice para o nome e tipo: %d\n", temp.dados.ref_campo.ind_nome_tipo);
                break;
            case TAG_REF_MTD:
                printf("\t[%02d] CONSTANT_Methodref\n", ind + 1);
                printf("\t\tIndíce para a classe: %d\n", temp.dados.metodo.ind_classe);
                printf("\t\tÍndice para o nome e tipo: %d\n", temp.dados.metodo.ind_nome_tipo);
                break;
            case TAG_REF_MTD_ITF:
                break;
            case TAG_NOM_TIP:
                break;
        }

        if (ignora){
            printf("\t[%02d] Extensão de número largo\n", ind + 2);
            ind++;
            ignora ^= 1;
        }
    }
}
