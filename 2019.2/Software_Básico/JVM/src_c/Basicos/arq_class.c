#include "../../lib_c/Basicos/arq_class.h"

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

    if (feof(arq_class))
        return novo_class;

    ler_b_u2(arq_class, &novo_class->flag_acesso, 0);
    ler_b_u2(arq_class, &novo_class->class_atual, 0);
    ler_b_u2(arq_class, &novo_class->class_super, 0);
    ler_b_u2(arq_class, &novo_class->qnt_interfaces, 1);
    novo_class->interfaces = NULL;

    if (novo_class->qnt_interfaces) {
        printf("deveria ter interface!!\n");
    }

    if (feof(arq_class))
        return novo_class;

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

    if (feof(arq_class))
        return novo_class;

    ler_b_u2(arq_class, &novo_class->qnt_metodos, 0);
    novo_class->metodos = NULL;

    if (novo_class->qnt_metodos) {
        novo_class->metodos = (InfoMetodo*) calloc (novo_class->qnt_metodos, sizeof(InfoMetodo));

        if (!novo_class->metodos){
            printf("\n[ERROR] Falha ao alocar a tabela de métodos\n");
            exit(E_ALOCAR_TAB_METODOS);
        }

        decodificar_tab_metodos(arq_class, novo_class);
    }

    if (feof(arq_class))
        return novo_class;

    ler_b_u2(arq_class, &novo_class->qnt_atributos, 1);
    novo_class->atributos = NULL;

    if (novo_class->qnt_atributos){
        novo_class->atributos = (InfoAtributos*) calloc (novo_class->qnt_atributos, sizeof(InfoAtributos));

        if (!novo_class->metodos){
            printf("\n[ERROR] Falha ao alocar a tabela de atributos\n");
            exit(E_ALOCAR_TAB_ATRIBUTOS);
        }

        decodificar_tab_atributos(arq_class, novo_class);
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
        if (feof(arq))
            return;

        ler_b_u2(arq, &java_class->campos[cnt].flag_acesso, 0);
        ler_b_u2(arq, &java_class->campos[cnt].ind_nome, 0);
        ler_b_u2(arq, &java_class->campos[cnt].ind_descritor, 0);
        ler_b_u2(arq, &java_class->campos[cnt].qnt_atributos, 1);
        java_class->campos[cnt].atributos = NULL;

        if (java_class->campos[cnt].qnt_atributos) {
            java_class->campos[cnt].atributos = (InfoAtributos*) calloc (java_class->campos[cnt].qnt_atributos, sizeof(InfoAtributos));

            if (!java_class->campos[cnt].atributos){
                printf("\n[ERROR] Falha ao alocar os atributos de um campo\n");
                exit(E_ALOCAR_ATTR_CAMPOS);
            }

            for (int cnt2 = 0; cnt < java_class->campos[cnt].qnt_atributos; cnt2++){
                if (feof(arq))
                    return;
                ler_b_u2(arq, &java_class->campos[cnt].atributos[cnt2].ind_nome_attr, 1);
                ler_b_u4(arq, &java_class->campos[cnt].atributos[cnt2].tam_attr, 1);
                ler_b_u2(arq, &java_class->campos[cnt].atributos[cnt2].especifico.vlr_u2.ind, 1);
            }
        }
    }
}

void decodificar_tab_metodos(FILE* arq, ArqClass* java_class){
    int flag_0_p_1, flag_0_p_2, flag_2_p_1, flag_3_p_1;

    for (int cnt = 0; cnt < java_class->qnt_metodos; cnt++){
        if (feof(arq))
            return;
        if (!cnt){
            flag_0_p_1 = 0;
            flag_0_p_2 = 0;
            flag_2_p_1 = 2;
            flag_3_p_1 = 3;
        } else {
            flag_0_p_1 = 1;
            flag_0_p_2 = 2;
            flag_2_p_1 = 1;
            flag_3_p_1 = 1;
        }

        ler_b_u2(arq, &java_class->metodos[cnt].flag_acesso, flag_0_p_1);
        ler_b_u2(arq, &java_class->metodos[cnt].ind_nome, flag_0_p_1);
        ler_b_u2(arq, &java_class->metodos[cnt].ind_descritor, flag_0_p_1);
        ler_b_u2(arq, &java_class->metodos[cnt].qnt_atributos, flag_0_p_1);
        java_class->metodos[cnt].atributos = NULL;

        if (java_class->metodos[cnt].qnt_atributos) {
            java_class->metodos[cnt].atributos = (InfoAtributos*) calloc (java_class->metodos[cnt].qnt_atributos, sizeof(InfoAtributos));

            if (!java_class->metodos[cnt].atributos){
                printf("\n[ERROR] Falha ao alocar os atributos de um método\n");
                exit(E_ALOCAR_ATTR_METODOS);
            }

            for (int cnt2 = 0; cnt2 < java_class->metodos[cnt].qnt_atributos; cnt2++){
                if (feof(arq))
                    return;
                int flag_0_p_1_2;

                if (!cnt) flag_0_p_1_2 = 1;
                else flag_0_p_1_2 = 0;

                ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].ind_nome_attr, flag_0_p_1);
                ler_b_u4(arq, &java_class->metodos[cnt].atributos[cnt2].tam_attr, flag_2_p_1);
                ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.max_pilha, flag_0_p_1);
                ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.max_locais, flag_0_p_1);
                ler_b_u4(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tam_codigo, flag_3_p_1);
                java_class->metodos[cnt].atributos[cnt2].especifico.codigo.codigo = NULL;

                if (java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tam_codigo){
                    java_class->metodos[cnt].atributos[cnt2].especifico.codigo.codigo = (u1*) calloc (java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tam_codigo, sizeof(u1));

                    if (!java_class->metodos[cnt].atributos[cnt2].especifico.codigo.codigo){
                        printf("\n[ERROR] Falha ao alocar o código de um método\n");
                        exit(E_ALOCAR_COD_METODOS);
                    }

                    for (int cnt3 = 0; cnt3 < java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tam_codigo; cnt3++)
                        fread(&java_class->metodos[cnt].atributos[cnt2].especifico.codigo.codigo[cnt3], sizeof(u1), 1, arq);
                }

                ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tam_tab_excessao, flag_0_p_2);
                java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao = NULL;

                if (java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tam_tab_excessao){
                    java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao = (Excessao*) calloc (java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tam_tab_excessao, sizeof(Excessao));

                    if (!java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao){
                        printf("\n[ERROR] Falha ao alocar as excessões de um código de um método\n");
                        exit(E_ALOCAR_EXC_COD_METODOS);
                    }

                    for (int cnt3 = 0; cnt3 < java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tam_tab_excessao; cnt3++){
                        if (feof(arq))
                            return;
                        ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao[cnt3].pc_comeco, 0);
                        ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao[cnt3].pc_final, 0);
                        ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao[cnt3].pc_tratamento, 0);
                        ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao[cnt3].ind_tipo_tratamento, 0);
                    }
                }

                ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.qnt_attr, 1);
                java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos = NULL;

                if (java_class->metodos[cnt].atributos[cnt2].especifico.codigo.qnt_attr){
                    java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos = (InfoAtributos2*) calloc (java_class->metodos[cnt].atributos[cnt2].especifico.codigo.qnt_attr, sizeof(InfoAtributos2));

                    if (!java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos){
                        printf("\n[ERROR] Falha ao alocar os atributos de um código de um método\n");
                        exit(E_ALOCAR_ATTR_COD_METODOS);
                    }

                    for (int cnt3 = 0; cnt3 < java_class->metodos[cnt].atributos[cnt2].especifico.codigo.qnt_attr; cnt3++){
                        if (feof(arq))
                            return;
                        ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].ind_nome_attr, 1);
                        ler_b_u4(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].tam_attr, 1);

                        if (!strcmp(java_class->tab_simbolo[java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].ind_nome_attr - 1].dados.utf_8.bytes, "LineNumberTable")){
                            ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tam_tab_numero, 1);
                            java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tab_numero = NULL;

                            if (java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tam_tab_numero){
                                java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tab_numero = (InfoNumero*) calloc (java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tam_tab_numero, sizeof(InfoNumero));

                                if (!java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tab_numero){
                                    printf("\n[ERROR] Falha ao alocar um atributo <LINENUMBERTABLE> de um código de um método\n");
                                    exit(E_ALOCAR_LIN_NMB_ATTR_COD_METODOS);
                                }

                                for (int cnt4 = 0; cnt4 < java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tam_tab_numero; cnt4++){
                                        if (feof(arq))
                                            return;
                                    ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tab_numero[cnt4].pc_comeco, 1);
                                    ler_b_u2(arq, &java_class->metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tab_numero[cnt4].lin_num, 1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void decodificar_tab_atributos(FILE* arq, ArqClass* java_class){
    for (int cnt = 0; cnt < java_class->qnt_atributos; cnt++){
        ler_b_u2(arq, &java_class->atributos[cnt].ind_nome_attr, 1);
        ler_b_u4(arq, &java_class->atributos[cnt].tam_attr, 1);

        if (!strcmp(java_class->tab_simbolo[java_class->atributos[cnt].ind_nome_attr - 1].dados.utf_8.bytes, "SourceFile")){
            ler_b_u2(arq, &java_class->atributos[cnt].especifico.vlr_u2.ind, 1);
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
    printf("Tabela de interfaces:\n");

    if (!temp){
        printf("\tNão há interfaces\n");
    }

    temp = java_class->qnt_campos;
    printf("Qnt. de campos: %d\n", temp);
    printf("Tabela de campos:\n");

    if (!temp){
        printf("\tNão há campos\n");
    } else {
        exibir_tab_campos(java_class->campos, java_class->qnt_campos, java_class->tab_simbolo);
    }

    temp = java_class->qnt_metodos;
    printf("Qnt. de métodos: %d\n", temp);
    printf("Tabela de métodos:\n");

    if (!temp){
        printf("\tNão há métodos\n");
    } else {
        exibir_tab_metodos(java_class->metodos, java_class->qnt_metodos, java_class->tab_simbolo);
    }

    temp = java_class->qnt_atributos;
    printf("Qnt. de atributos: %d\n", temp);
    printf("Tabela de atributos:\n");

    if (!temp){
        printf("\tNão há atributos\n");
    } else {
        exibir_tab_atributos(java_class->atributos, java_class->qnt_atributos, java_class->tab_simbolo);
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
                printf("\t\t\tQnt. dados: %u\n", tab_campos[cnt].atributos[cnt2].tam_attr);
                printf("\t\t\tÍndice do valor constante: %d\n", tab_campos[cnt].atributos[cnt2].especifico.vlr_u2.ind);
            }
        }
    }
}

void exibir_tab_metodos(InfoMetodo* tab_metodos, int lim, CPInfo* tab_simbolo){
    for (int cnt = 0; cnt < lim; cnt++){
        int ind_nome = tab_metodos[cnt].ind_nome,
            qnt_atributos = tab_metodos[cnt].qnt_atributos;

        printf("\t[%02d] %s\n", cnt + 1, tab_simbolo[ind_nome - 1].dados.utf_8.bytes);
        printf("\t\tFlag de acesso: ");
            exibir_flag(tab_metodos[cnt].flag_acesso);
        printf("\t\tÍndice para o nome: %d\n", ind_nome);
        printf("\t\tÍndice para o descritor: %d\n", tab_metodos[cnt].ind_descritor);
        printf("\t\tQnt. de atributos: %d\n", qnt_atributos);

        if (!qnt_atributos) {
            printf("\t\tNão há atributos\n");
        } else {
            printf("\t\tAtributos:\n");
            for (int cnt2 = 0; cnt2 < qnt_atributos; cnt2++){
                int ind_nome_2 = tab_metodos[cnt].atributos[cnt2].ind_nome_attr,
                    tam_excessao = tab_metodos[cnt].atributos[cnt2].especifico.codigo.tam_tab_excessao,
                    tam_attrs =  tab_metodos[cnt].atributos[cnt2].especifico.codigo.qnt_attr;

                printf("\t\t\t[%02d] <%s>\n", cnt + 1, tab_simbolo[ind_nome_2 - 1].dados.utf_8.bytes);
                printf("\t\t\t\tÍndice para o nome do atributo: %d\n", ind_nome_2);
                printf("\t\t\t\tTamanho do atributo: %u\n", tab_metodos[cnt].atributos[cnt2].tam_attr);
                printf("\t\t\t\tTamanho máximo da pilha: %d\n", tab_metodos[cnt].atributos[cnt2].especifico.codigo.max_pilha);
                printf("\t\t\t\tTamanho máximo da variáveis locais: %d\n", tab_metodos[cnt].atributos[cnt2].especifico.codigo.max_locais);
                printf("\t\t\t\tTamanho do código: %u\n", tab_metodos[cnt].atributos[cnt2].especifico.codigo.tam_codigo);
                printf("\t\t\t\tCódigo:\n");
                    for (int cnt3 = 0; cnt3 < tab_metodos[cnt].atributos[cnt2].especifico.codigo.tam_codigo; cnt3++)
                        printf("\t\t\t\t\t0x%02X\n", tab_metodos[cnt].atributos[cnt2].especifico.codigo.codigo[cnt3]);
                printf("\t\t\t\tTamanho da tabela de excessões: %d\n", tam_excessao);
                printf("\t\t\t\tTab. excessões:\n");
                    if (!tam_excessao)
                        printf("\t\t\t\t\tNão há excessoes\n");
                    else {
                        for (int cnt3 = 0; cnt3 < tam_excessao; cnt3++){
                            printf("\t\t\t\t\tExcessão [%d]\n:", cnt3);
                            printf("\t\t\t\t\t\tPC inicial: %d\n", tab_metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao[cnt3].pc_comeco);
                            printf("\t\t\t\t\t\tPC final: %d\n", tab_metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao[cnt3].pc_final);
                            printf("\t\t\t\t\t\tPC do tratamento: %d\n", tab_metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao[cnt3].pc_tratamento);
                            printf("\t\t\t\t\t\tÍndice do tipo de tratamento: %d\n", tab_metodos[cnt].atributos[cnt2].especifico.codigo.tab_excessao[cnt3].ind_tipo_tratamento);
                        }
                    }
                printf("\t\t\t\tQuantidade de atributos: %d\n", tam_attrs);
                printf("\t\t\t\tAtributos:\n");
                    if (!tam_attrs)
                        printf("\t\t\t\t\tNão há atributos\n");
                    else {
                        for (int cnt3 = 0; cnt3 < tam_attrs; cnt3++){
                            u2 ind_attr = tab_metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].ind_nome_attr;

                            printf("\t\t\t\t\t[%d] %s\n", cnt3, tab_simbolo[ind_attr - 1].dados.utf_8.bytes);
                            printf("\t\t\t\t\t\tÍndice para o nome do atributo: %d\n", ind_attr);
                            printf("\t\t\t\t\t\tTamanho do atributo: %u\n", tab_metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].tam_attr);

                            if (!strcmp(tab_simbolo[ind_attr - 1].dados.utf_8.bytes, "LineNumberTable")){
                                u2 tam_tab_numero = tab_metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tam_tab_numero;

                                printf("\t\t\t\t\t\tTamanho da tabela de numeros: %d\n", tam_tab_numero);

                                printf("\t\t\t\t\t\t\t\t#\t|\tPC Inicial\t|\tValor\n");
                                for (int cnt4 = 0; cnt4 < tam_tab_numero; cnt4++){
                                    printf("\t\t\t\t\t\t\t\t%d\t|\t  %02d\t\t|\t%d\n", cnt4, tab_metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tab_numero[cnt4].pc_comeco, tab_metodos[cnt].atributos[cnt2].especifico.codigo.atributos[cnt3].especifico.numero.tab_numero[cnt4].lin_num);
                                }
                            }
                        }
                    }
            }
        }
    }
}

void exibir_tab_atributos(InfoAtributos* tab_atributos, int lim, CPInfo* tab_simbolo){
    for (int cnt = 0; cnt < lim; cnt++){
        u2 ind_attr = tab_atributos[cnt].ind_nome_attr;

        printf("\t[%d] %s\n", cnt, tab_simbolo[ind_attr - 1].dados.utf_8.bytes);
        printf("\t\tÍndice para o nome do atributo: %d\n", ind_attr);
        printf("\t\tTamanho do atributo: %u\n", tab_atributos[cnt].tam_attr);

        if (!strcmp(tab_simbolo[ind_attr - 1].dados.utf_8.bytes, "SourceFile")){
            printf("\t\tÍndice do nome do arquivo fonte: %d\n", tab_atributos[cnt].especifico.vlr_u2.ind);
        }
    }
}

void liberar(ArqClass *java_class){
    CPInfo *tab_simbolo = java_class->tab_simbolo;
    InfoCampo *tab_campos = java_class->campos;
    InfoMetodo *tab_metodos = java_class->metodos;
    InfoAtributos *tab_atributos = java_class->atributos;

    for (int ind = 0; ind < java_class->qnt_metodos; ind++){
        for (int ind2 = 0; ind2 < tab_metodos[ind].qnt_atributos; ind2++){
            if (tab_metodos[ind].atributos[ind2].especifico.codigo.tam_tab_excessao)
                free(tab_metodos[ind].atributos[ind2].especifico.codigo.tab_excessao);

            if (tab_metodos[ind].atributos[ind2].especifico.codigo.qnt_attr){
                for (int cnt3 = 0; cnt3 < tab_metodos[ind].atributos[ind2].especifico.codigo.qnt_attr; cnt3++){
                    if (!strcmp(tab_simbolo[tab_metodos[ind].atributos[ind2].especifico.codigo.atributos[cnt3].ind_nome_attr - 1].dados.utf_8.bytes, "LineNumberTable"))
                        free(tab_metodos[ind].atributos[ind2].especifico.codigo.atributos[cnt3].especifico.numero.tab_numero);
                }

                free(tab_metodos[ind].atributos[ind2].especifico.codigo.atributos);
            }

            free(tab_metodos[ind].atributos[ind2].especifico.codigo.codigo);
        }

        if (tab_metodos[ind].atributos)
            free(tab_metodos[ind].atributos);
    }

    for (int ind = 0; ind < java_class->qnt_campos; ind++)
        if (tab_campos[ind].atributos)
            free(tab_campos[ind].atributos);

    for (int ind = 0; ind < java_class->qnt_tab_simbolo - 1; ind++)
        if (tab_simbolo[ind].tag == TAG_UTF)
            free(tab_simbolo[ind].dados.utf_8.bytes);


    free(tab_atributos);
    free(tab_metodos);
    free(tab_campos);
    free(tab_simbolo);
    free(java_class);
}
