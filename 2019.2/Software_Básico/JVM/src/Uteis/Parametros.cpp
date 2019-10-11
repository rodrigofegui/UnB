#include "../../lib/Uteis/Parametros.hpp"


u1 check_parametros(int argc, char *argv[]){
    u1 e_leitura = 1;

    if ((argc - 1) > 2){
        printf("\n[ERRO] Este programa só aceita até 2 argumentos, mas vieram %d.\n", argc - 1);
        exit(E_QNT_ARGS);
    }

    char *temp = argv[1];

    if (strcmp(temp, "-e") && strcmp(temp, "-i")){
        printf("\n[ERRO] Este programa só opera sobre 2 modos: -e ou -i; foi passado: %s.\n", temp);
        return E_MODO;

    }else if (!strcmp(temp, "-i")){
        e_leitura = 1;
    }

    temp = strtok(argv[2], DELIMITADOR_ARGS);

    while(temp){
        if (!strstr(temp, TIPO_ARQ_ACEITO)){
            printf("\n[ERRO] Este programa só analisa arquivos da extensão .class; foi passado o arquivo: '%s'.\n", temp);
            exit(E_TIPO);
        }

        temp = strtok(NULL, DELIMITADOR_ARGS);
    }

    return e_leitura;
}


// u1 check_qnt_args(int argc){
//     if (!(argc - 1))
//         return W_QNT_ARGS;

//     return 0;
// }
