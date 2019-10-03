#include <stdio.h>
#include <stdlib.h>
#include "../lib_c/Basicos/parametros.h"
#include "../lib_c/Basicos/parametros.h"
#include "../lib_c/Basicos/tipos.h"
#include "../lib_c/Manipulacao/arquivos.h"
#include "../lib_c/Basicos/arq_class.h"

int main(int argc, char *argv[]){
    // char *nome_arq = "Referências/double_aritmetica.class";
    char *nome_arq = "Referências/ControladorMidi.class";
    ArqClass *java_class = NULL;

    FILE *arq = leitura(nome_arq);

    java_class = decodificar(arq);

    exibir(java_class);

    liberar(java_class);

    fclose(arq);

    return 0;
}
