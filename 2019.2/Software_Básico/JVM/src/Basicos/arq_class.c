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
    novo_class->interfaces = NULL;

    if (novo_class->qnt_interfaces) {
        printf("deveria ter interface!!\n");
    }

    ler_b_u2(arq_class, &novo_class->qnt_campos, 0);
    novo_class->campos = NULL;

    if (novo_class->qnt_campos) {
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
                decodificar_int(arq, java_class, cnt);
                break;
            case TAG_FLT:
                decodificar_float(arq, java_class, cnt);
                break;
            case TAG_LNG:
                decodificar_long(arq, java_class, cnt);
                ignora ^= 1;
                break;
            case TAG_DBL:
                decodificar_dbl(arq, java_class, cnt);
                ignora ^= 1;
                break;
            case TAG_CLAS:
                decodificar_class(arq, java_class, cnt);
                break;
            case TAG_STR:
                decodificar_string(arq, java_class, cnt);
                break;
            case TAG_REF_CMP:
                decodificar_ref_cmp(arq, java_class, cnt);
                break;
            case TAG_REF_MTD:
                decodificar_ref_mtd(arq, java_class, cnt);
                break;
            case TAG_REF_MTD_ITF:
                decodificar_ref_mtd_itf(arq, java_class, cnt);
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

void decodificar_int(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.inteiro.bytes, 1);
}

void decodificar_float(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.decimal.bytes, 1);
}

void decodificar_long(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.longo.bytes_mais, 1);
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.longo.bytes_menos, 1);
}

void decodificar_dbl(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.duplo.bytes_mais, 1);
    ler_b_u4(arq, &java_class->tab_simbolo[ind].dados.duplo.bytes_menos, 1);
}

void decodificar_class(FILE *arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.classe.ind_nome, 1);
}

void decodificar_string(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.string.ind_str, 1);
}

void decodificar_ref_cmp(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.ref_campo.ind_classe, 1);
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.ref_campo.ind_nome_tipo, 1);
}

void decodificar_ref_mtd(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.metodo.ind_classe, 1);
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.metodo.ind_nome_tipo, 1);
}

void decodificar_ref_mtd_itf(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.metodo_interface.ind_classe, 1);
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.metodo_interface.ind_nome_tipo, 1);
}

void decodificar_nom_tip(FILE* arq, ArqClass* java_class, int ind){
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.nome_tipo.ind_nome, 1);
    ler_b_u2(arq, &java_class->tab_simbolo[ind].dados.nome_tipo.ind_descritor, 1);
}

void decodificar_tab_campos(FILE* arq, ArqClass* java_class){
    for (int cnt = 0; cnt < java_class->qnt_campos; cnt++){
        ler_b_u2(arq, &java_class->campos[cnt].flag_acesso, 0);
        ler_b_u2(arq, &java_class->campos[cnt].ind_nome, 0);
        ler_b_u2(arq, &java_class->campos[cnt].ind_descritor, 0);
        ler_b_u2(arq, &java_class->campos[cnt].qnt_atributos, 1);

        if (!java_class->campos[cnt].qnt_atributos) {
            java_class->campos[cnt].atributos = NULL;
        } else {
            java_class->campos[cnt].atributos = (InfoAtributo*) calloc (java_class->campos[cnt].qnt_atributos, sizeof(InfoAtributo));

            if (!java_class->campos[cnt].atributos){
                printf("\n[ERROR] Falha ao alocar a tabela de campos\n");
                exit(E_ALOCAR_ATTR_CAMPOS);
            }

            ler_b_u2(arq, &java_class->campos[cnt].atributos->ind_nome_attr, 1);
            ler_b_u4(arq, &java_class->campos[cnt].atributos->qnt_attr, 1);

            if (!java_class->campos[cnt].atributos->qnt_attr) {
                java_class->campos[cnt].atributos->info = NULL;
            } else {
                java_class->campos[cnt].atributos->info = (u1*) calloc (java_class->campos[cnt].atributos->qnt_attr, sizeof(u1));

                if (!java_class->campos[cnt].atributos->info){
                    printf("\n[ERROR] Falha ao alocar info de atributo da tabela de campos\n");
                    exit(E_ALOCAR_INFO_ATTR_CAMPOS);
                }

                for (int cnt2 = 0; cnt2 < java_class->campos[cnt].atributos->qnt_attr; cnt2++)
                    fread(&java_class->campos[cnt].atributos->info[cnt2], sizeof(u1), 1, arq);
            }

        }
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
                printf("\t[%02d] CONSTANT_Integer\n", ind + 1);
                printf("\t\tBytes: 0x%08X\n", c_dados.inteiro.bytes);
                break;
            case TAG_FLT:
                printf("\t[%02d] CONSTANT_Float\n", ind + 1);
                printf("\t\tBytes: 0x%08X\n", c_dados.decimal.bytes);
                break;
            case TAG_LNG:
                printf("\t[%02d] CONSTANT_Long\n", ind + 1);
                printf("\t\tByte mais significativo: 0x%08X\n", c_dados.longo.bytes_mais);
                printf("\t\tByte menos significativo: 0x%08X\n", c_dados.longo.bytes_menos);
                ignora ^= 1;
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
                printf("\t[%02d] CONSTANT_String\n", ind + 1);
                printf("\t\tÍndice para a string: %d\n", c_dados.string.ind_str);
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
                printf("\t[%02d] CONSTANT_InterfaceMethodref\n", ind + 1);
                printf("\t\tIndíce para a classe: %d\n", c_dados.metodo_interface.ind_classe);
                printf("\t\tÍndice para o nome e tipo: %d\n", c_dados.metodo_interface.ind_nome_tipo);
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
            ind++;
            printf("\t[%02d] Extensão de número largo\n", ind + 1);
            ignora ^= 1;
        }
    }
}

void exibir_flag(u2 a_verificar){
    char flag[100] = "\0";

    if ((a_verificar & 0x000F) == FLG_PBC)
        strcat(flag, "pública ");

    if ((a_verificar & 0x000F) == FLG_PVD)
        strcat(flag, "privada ");

    if ((a_verificar & 0x000F) == FLG_PTD)
        strcat(flag, "protegida ");

    if ((a_verificar & 0x000F) == FLG_STC)
        strcat(flag, "estática ");

    if ((a_verificar & 0x00F0) == FLG_FNL)
        strcat(flag, "final ");

    if ((a_verificar & 0x00F0) == FLG_SPR)
        strcat(flag, "super ");

    if ((a_verificar & 0x00F0) == FLG_VLT)
        strcat(flag, "volátil ");

    if ((a_verificar & 0x00F0) == FLG_TST)
        strcat(flag, "transiente ");

    if ((a_verificar & 0x0F00) == FLG_NTV)
        strcat(flag, "nativo ");

    if ((a_verificar & 0x0F00) == FLG_ITF)
        strcat(flag, "interface ");

    if ((a_verificar & 0x0F00) == FLG_ABS)
        strcat(flag, "abstrata ");

    if ((a_verificar & 0x0F00) == FLG_STT)
        strcat(flag, "estrito ");

    if (!strlen(flag))
        printf("Sem expecificação");

    else {
        flag[strlen(flag) - 1] = '\0';
        printf("%s", flag);
    }

    printf(" [0x%04X]\n", a_verificar);
}

void exibir_tab_campos(InfoCampo* tab_campos, int lim, CPInfo* tab_simbolo){
    for (int cnt = 0; cnt < lim; cnt++){
        int ind_nome = tab_campos[cnt].ind_nome,
            qnt_atributos = tab_campos[cnt].qnt_atributos;

        printf("\t[%02d] %s\n", cnt + 1, tab_simbolo[ind_nome - 1].dados.utf_8.bytes);
        printf("\t\tFlag de acesso: ");
            exibir_flag(tab_campos[cnt].flag_acesso);
        printf("\t\tÍndice para o nome: %d\n", ind_nome);
        printf("\t\tÍndice para o descritor: %d\n", tab_campos[cnt].ind_descritor);
        printf("\t\tQnt. de atributos: %d\n", qnt_atributos);

        if (!qnt_atributos) {
            printf("\t\tNão há atributos\n");
        } else {
            printf("\t\tAtributos:\n");
            for (int cnt2 = 0; cnt < qnt_atributos; cnt2++){
                printf("\t\t\tÍndice para o nome do atributo: %d\n", tab_campos[cnt].atributos[cnt2].ind_nome_attr);
                printf("\t\t\tQnt. dados: %u\n", tab_campos[cnt].atributos[cnt2].qnt_attr);
                printf("\t\t\tDados: %s\n", tab_campos[cnt].atributos[cnt2].info);
            }
        }
    }
}

void liberar(ArqClass *java_class){
    CPInfo *tab_simbolo = java_class->tab_simbolo;
    InfoCampo *tab_campos = java_class->campos;

    for (int ind = 0; ind < java_class->qnt_tab_simbolo - 1; ind++)
        if (tab_simbolo[ind].tag == TAG_UTF)
            free(tab_simbolo[ind].dados.utf_8.bytes);

    for (int ind = 0; ind < java_class->qnt_campos; ind++){
        for (int ind2 = 0; ind2 < tab_campos[ind].qnt_atributos; ind2++)
            free(tab_campos[ind].atributos[ind2].info);


        if (tab_campos[ind].atributos != NULL)
            free(tab_campos[ind].atributos);
    }

    free(tab_campos);
    free(tab_simbolo);
    free(java_class);
}
