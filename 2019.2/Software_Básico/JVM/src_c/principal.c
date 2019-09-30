#include <stdio.h>
#include <stdlib.h>
#include "../lib/Tipos/ArqClass.hpp"
#include "../lib_c/Basicos/parametros.h"
// #include "../lib/Basicos/parametros.h"
// #include "../lib/Basicos/tipos.h"
// #include "../lib/Manipulacao/arquivos.h"
// #include "../lib/Basicos/arq_class.h"

int main(int argc, char *argv[]){
    u1 *controle = check_parametros(argc, argv);

    if (controle[0]){
        ArqClass arq_class = new ArqClass(controle[1]);

    } else
        printf("operando como interpretador\n");

    printf("qnt. arqs: %d\n", controle[1]);

    free(controle);

    return 0;

    // ArqClass *java_class = NULL;

    // FILE *arq = leitura(nome_arq);

    // java_class = decodificar(arq);

    // exibir(java_class);

    // liberar(java_class);

    // fclose(arq);

    // return 0;
}
