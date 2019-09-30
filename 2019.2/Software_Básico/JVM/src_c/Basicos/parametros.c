#include "../../lib_c/Basicos/parametros.h"

u1* check_parametros(int argc, char *argv[]){
    u1 *controle = (u1*) calloc (2, sizeof(u1));

    controle[0] = 1;

    if ((argc - 1) > 2){
        printf("\n[ERRO] Este programa só aceita até 2 argumentos, mas vieram %d.\n", argc - 1);
        exit(E_QNT_ARGS);
    }

    char *temp = argv[1];

    if (strcmp(temp, "-e") && strcmp(temp, "-i")){
        printf("\n[ERRO] Este programa só opera sobre 2 modos: -e ou -i; foi passado: %s.\n", temp);
        exit(E_MODO);

    }else if (!strcmp(temp, "-i")){
        controle[0] = 0;
    }

    temp = strtok(argv[2], DELIMITADOR_ARGS);

    while(temp){
        if (!strstr(temp, TIPO_ARQ_ACEITO)){
            printf("\n[ERRO] Este programa só analisa arquivos da extensão .class; foi passado o arquivo: '%s'.\n", temp);
            exit(E_TIPO);
        }

        controle[1]++;

        temp = strtok(NULL, DELIMITADOR_ARGS);
    }

    return controle;
}
