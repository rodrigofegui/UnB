#include "../../lib/Basicos/arq_class.h"

ArqClass* decodificar(FILE* arq_class){
    ArqClass* novo_class = (ArqClass*) calloc (1, sizeof(ArqClass));

    if (!novo_class){
        printf("\n[ERROR] Falha ao alocar um arquivo .CLASS para decodificação\n");
        exit(E_ALOCAR_CLASS);
    }

    ler_b_u4(arq_class, &novo_class->codigo_arq, 1);

    if (novo_class->codigo_arq != 0xCAFEBABE){
        free(novo_class);
        return NULL;
    }

    ler_b_u2(arq_class, &novo_class->versao_min, 1);
    ler_b_u2(arq_class, &novo_class->versao_max, 1);
    ler_b_u2(arq_class, &novo_class->qnt_tab_simbolo, 1);

    novo_class->tab_simbolo = (CPInfo*) calloc (novo_class->qnt_tab_simbolo - 1, sizeof(CPInfo));

    if (!novo_class->tab_simbolo) {
        printf("\n[ERROR] Falha ao alocar a tabela de símbolos\n");
        exit(E_ALOCAR_TAB_SIMB);
    }

    decodificar_tab_simbolos(arq_class, novo_class);

    ler_b_u2(arq_class, &novo_class->flag_acesso, 0);
    ler_b_u2(arq_class, &novo_class->class_atual, 0);
    ler_b_u2(arq_class, &novo_class->class_super, 0);
    ler_b_u2(arq_class, &novo_class->qnt_interfaces, 1);

    if (!novo_class->qnt_interfaces) {
        novo_class->interfaces = NULL;
    }

    ler_b_u2(arq_class, &novo_class->qnt_campos, 1);

    if (!novo_class->qnt_campos) {
        novo_class->campos = NULL;
    } else {
        novo_class->campos = (InfoCampo*) calloc (novo_class->qnt_campos, sizeof(InfoCampo));

        if (!novo_class->campos){
            printf("\n[ERROR] Falha ao alocar a tabela de campos\n");
            exit(E_ALOCAR_TAB_CAMPOS);
        }

        decodificar_tab_campos(arq_class, novo_class);
    }

    return novo_class;
}

void decodificar_tab_simbolos(FILE* arq, ArqClass* java_class){
    u1 temp;
    int ignora = 0;

    for (int cnt = 0; cnt < java_class->qnt_tab_simbolo; cnt++){
        fread(&temp, sizeof(u1), 1, arq);

        switch (temp){
            case TAG_UTF:
                decodificar_utf8(arq, java_class, cnt);
                break;
            case TAG_INT:
                break;
            case TAG_FLT:
                break;
            case TAG_LNG:
                break;
            case TAG_DBL:
                decodificar_dbl(arq, java_class, cnt);
                ignora ^= 1;
                break;
            case TAG_CLAS:
                decodificar_class(arq, java_class, cnt);
                break;
            case TAG_STR:
                break;
            case TAG_REF_CMP:
                decodificar_ref_cmp(arq, java_class, cnt);
                break;
            case TAG_REF_MTD:
                decodificar_ref_mtd(arq, java_class, cnt);
                break;
            case TAG_REF_MTD_ITF:
                break;
            case TAG_NOM_TIP:
                decodificar_nom_tip(arq, java_class, cnt);
                break;
            default:
                temp = 0;
        }

        if (temp)
            java_class->tab_simbolo[cnt].tag = temp;

        if (ignora){
            cnt++;
            ignora ^= 1;
        }
    }
}

void decodificar_utf8(FILE* arq, ArqClass* java_class, int ind){
    u2 *aux_t = &java_class->tab_simbolo[ind].dados.utf_8.tam;

    ler_b_u2(arq, aux_t, 1);

    java_class->tab_simbolo[ind].dados.utf_8.bytes = (u1*) calloc ((*aux_t) + 1, sizeof(u1));

    if (!java_class->tab_simbolo[ind].dados.utf_8.bytes){
        printf("\n[ERROR] Falha ao alocar bytes para UTF-8\n");
        exit(E_ALOCAR_UTF8);
    }

    for (int cnt = 0; cnt < *aux_t; cnt++)
        fread(&java_class->tab_simbolo[ind].dados.utf_8.bytes[cnt], sizeof(u1), 1, arq);

    java_class->tab_simbolo[ind].dados.utf_8.bytes[*aux_t] = '\0';
}

void decodificar_dbl(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.duplo.bytes_mais, 1);
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.duplo.bytes_menos, 1);
}

void decodificar_class(FILE *arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.classe.ind_nome, 1);
}

void decodificar_ref_cmp(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.ref_campo.ind_classe, 1);
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.ref_campo.ind_nome_tipo, 1);
}

void decodificar_ref_mtd(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.metodo.ind_classe, 1);
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.metodo.ind_nome_tipo, 1);
}

void decodificar_nom_tip(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.nome_tipo.ind_nome, 1);
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.nome_tipo.ind_descritor, 1);
}

void decodificar_tab_campos(FILE* arq, ArqClass* java_class){
    for (int cnt = 0; cnt < java_class->qnt_campos; cnt++){
        ler_b_u2(arq, &java_class->campos[cnt].flag_acesso, 0);
        ler_b_u2(arq, &java_class->campos[cnt].ind_nome, 1);
        ler_b_u2(arq, &java_class->campos[cnt].ind_descritor, 1);
        ler_b_u2(arq, &java_class->campos[cnt].qnt_atributos, 1);
    }
}

void exibir (ArqClass* java_class){
    int temp;
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

    printf("Flag de acesso: ");
        exibir_flag(java_class->flag_acesso);

    printf("Classe corrente: %d\n", java_class->class_atual);

    printf("Classe super: %d\n", java_class->class_super);

    temp = java_class->qnt_interfaces;
    printf("Qnt. de interfaces: %d\n", temp);

    if (temp){
        // exibir
    }

    temp = java_class->qnt_campos;
    printf("Qnt. de campos: %d\n", temp);

    if (temp){
        printf("Tabela de campos: \n");
        exibir_tab_campos(java_class->campos, java_class->qnt_campos, java_class->tab_simbolo);
    }
}

void exibir_versao_java(u2 a_verificar){
    switch (a_verificar){
        case V1_1:
            printf("JDK 1.1\n"); break;
        case V1_2:
            printf("JDK 1.2\n"); break;
        case V1_3:
            printf("JDK 1.3\n"); break;
        case V1_4:
            printf("JDK 1.4\n"); break;
        case V5:
            printf("Java SE 5.0\n"); break;
        case V6:
            printf("Java SE 6.0\n"); break;
        case V7:
            printf("Java SE 7\n"); break;
        case V8:
            printf("Java SE 8\n"); break;
        case V9:
            printf("Java SE 9\n"); break;
        case V10:
            printf("Java SE 10\n"); break;
        case V11:
            printf("Java SE 11\n"); break;
        case V12:
            printf("Java SE 12\n"); break;
        case V13:
            printf("Java SE 13\n"); break;
        case V14:
            printf("Java SE 14\n"); break;
        default:
            printf("Sem expecificação\n");
    }
}

void exibir_tab_simbolos(CPInfo* tab_simbolo, int cnt){
    int ignora = 0;

    for (int ind = 0; ind < cnt - 1; ind++){
        union dados_cp_info c_dados = tab_simbolo[ind].dados;

        switch (tab_simbolo[ind].tag) {
            case TAG_UTF:
                printf("\t[%02d] CONSTANT_Utf8\n", ind + 1);
                printf("\t\tTamanho da string: %d\n", c_dados.utf_8.tam);
                printf("\t\tString: %s\n", c_dados.utf_8.bytes);
                break;
            case TAG_INT:
                break;
            case TAG_FLT:
                break;
            case TAG_LNG:
                break;
            case TAG_DBL:
                printf("\t[%02d] CONSTANT_Double\n", ind + 1);
                printf("\t\tByte mais significativo: 0x%08X\n", c_dados.duplo.bytes_mais);
                printf("\t\tByte menos significativo: 0x%08X\n", c_dados.duplo.bytes_menos);
                ignora ^= 1;
                break;
            case TAG_CLAS:
                printf("\t[%02d] CONSTANT_Class\n", ind + 1);
                printf("\t\tÍndice para o nome: %d\n", c_dados.classe.ind_nome);
                break;
            case TAG_STR:
                break;
            case TAG_REF_CMP:
                printf("\t[%02d] CONSTANT_Fieldref\n", ind + 1);
                printf("\t\tIndíce para a classe: %d\n", c_dados.ref_campo.ind_classe);
                printf("\t\tÍndice para o nome e tipo: %d\n", c_dados.ref_campo.ind_nome_tipo);
                break;
            case TAG_REF_MTD:
                printf("\t[%02d] CONSTANT_Methodref\n", ind + 1);
                printf("\t\tIndíce para a classe: %d\n", c_dados.metodo.ind_classe);
                printf("\t\tÍndice para o nome e tipo: %d\n", c_dados.metodo.ind_nome_tipo);
                break;
            case TAG_REF_MTD_ITF:
                break;
            case TAG_NOM_TIP:
                printf("\t[%02d] CONSTANT_NameAndType\n", ind + 1);
                printf("\t\tIndíce para o nome: %d\n", c_dados.nome_tipo.ind_nome);
                printf("\t\tÍndice para o descritor: %d\n", c_dados.nome_tipo.ind_descritor);
                break;
            default:
                printf("\t[%02d] NÃO DECODIFICADO\n", ind + 1);
        }

        if (ignora){
            printf("\t[%02d] Extensão de número largo\n", ind + 2);
            ind++;
            ignora ^= 1;
        }
    }
}

void exibir_flag(u2 a_verificar){
    char flag[100] = "\0";

    if ((a_verificar & 0x000F) == FLG_PBC)
        strcat(flag, "pública ");

    if ((a_verificar & 0x00F0) == FLG_FNL)
        strcat(flag, "final ");

    if ((a_verificar & 0x00F0) == FLG_SPR)
        strcat(flag, "super ");

    if ((a_verificar & 0x0F00) == FLG_ITF)
        strcat(flag, "interface ");

    if ((a_verificar & 0x0F00) == FLG_ABS)
        strcat(flag, "abstrata ");

    if (!strlen(flag))
        printf("INVÁLIDA");

    else {
        flag[strlen(flag) - 1] = '\0';
        printf("%s", flag);
    }

    printf(" [0x%04X]\n", a_verificar);

    // switch (a_verificar){
    //     case FLG_PBC:
    //         printf("pública\n"); break;
    //     case FLG_PVD:
    //         printf("privada\n"); break;
    //     case FLG_PTD:
    //         printf("protegida\n"); break;
    //     case FLG_STC:
    //         printf("estática\n"); break;
    //     case FLG_FNL:
    //         printf("final\n"); break;
    //     case FLG_SPR:
    //         printf("super\n"); break;
    //     case FLG_VLT:
    //         printf("volátil\n"); break;
    //     case FLG_TST:
    //         printf("transiente\n"); break;
    //     case FLG_NTV:
    //         printf("nativo\n"); break;
    //     case FLG_ITF:
    //         printf("interface\n"); break;
    //     case FLG_ABS:
    //         printf("abstrata\n"); break;
    //     case FLG_STT:
    //         printf("estrito\n"); break;
    //     default:
    //         printf("INVÁLIDA [%X]\n", a_verificar);
    // }
}

void exibir_tab_campos(InfoCampo* tab_campos, int lim, CPInfo* tab_simbolo){
    for (int cnt = 0; cnt < lim; cnt++){
        printf("\t[%02d] %s\n", cnt, tab_simbolo[cnt].dados.utf_8.bytes);
        printf("\t\tÍndice para o nome: %d\n", tab_campos[cnt].ind_nome);
        printf("\t\tÍndice para o descritor: %d\n", tab_campos[cnt].ind_descritor);
    }
}

void liberar(ArqClass *java_class){
    CPInfo *tab_simbolo = java_class->tab_simbolo;
    int ignora = 0;

    for (int ind = 0; ind < java_class->qnt_tab_simbolo - 1; ind++){
        u1 c_tag = tab_simbolo[ind].tag;

        switch (c_tag) {
            case TAG_UTF:
                free(tab_simbolo[ind].dados.utf_8.bytes);
                break;
            case TAG_INT:
                break;
            case TAG_FLT:
                break;
            case TAG_LNG:
                break;
            case TAG_DBL:
                ignora ^= 1;
                break;
            case TAG_CLAS:
                break;
            case TAG_STR:
                break;
            case TAG_REF_CMP:
                break;
            case TAG_REF_MTD:
                break;
            case TAG_REF_MTD_ITF:
                break;
            case TAG_NOM_TIP:
                break;
        }

        if (ignora){
            ind++;
            ignora ^= 1;
        }
    }

    free(tab_simbolo);
    free(java_class);
}
