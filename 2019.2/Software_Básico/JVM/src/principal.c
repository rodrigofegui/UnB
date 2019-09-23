#include <stdio.h>
#include <stdlib.h>
#include "../lib/Basicos/tipos.h"
#include "../lib/Manipulacao/arquivos.h"
#include "../lib/Basicos/arq_class.h"

int main(int argc, char *argv[]){
    // char nome_arq[] = "Referências/double_aritmetica.class";
    char nome_arq[] = "Referências/ControladorMidi.class";
    // char nome_arq[] = "Referências/ControladorMidi.java";

    ArqClass *java_class = NULL;

    FILE *arq = leitura(nome_arq);

    java_class = decodificar(arq);

    exibir(java_class);

    liberar(java_class);

    fclose(arq);

    return 0;
}
