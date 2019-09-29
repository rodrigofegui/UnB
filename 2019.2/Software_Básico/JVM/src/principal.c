#include <stdio.h>
#include <stdlib.h>
#include "../lib/Basicos/parametros.h"
#include "../lib/Basicos/tipos.h"
#include "../lib/Manipulacao/arquivos.h"
#include "../lib/Basicos/arq_class.h"

int main(int argc, char *argv[]){
    u1 leitura = check_parametros(argc, argv);

    if (leitura)
        printf("operando como leitura\n");
    else
        printf("operando como interpretador\n");

    return 0;

    // ArqClass *java_class = NULL;

    // FILE *arq = leitura(nome_arq);

    // java_class = decodificar(arq);

    // exibir(java_class);

    // liberar(java_class);

    // fclose(arq);

    // return 0;
}
