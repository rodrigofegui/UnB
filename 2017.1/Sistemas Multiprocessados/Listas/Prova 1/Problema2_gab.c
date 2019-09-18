#include <stdio.h>
#include <stdlib.h>

int charTipo (char letra);
void charControle (int tipo, int *contador, int *controle);

int main (){
    char texto[] = "LISTA PARA A PROVA UM,\tVALENDO PONTO.\nMELHOR ESTUDAR E TIRAR BOA NOTA.";
    int tipo = 0, controle = 0;
    int cnt[3] = {0, 0, 1}; // Letras, Palavras, Linhas
    int pos = 0;

    for (pos = 0; pos < 71; pos++)
        charControle(charTipo(texto[pos]), cnt, &controle);
        //printf("%c -> Tipo: %d\n", texto[pos], charTipo(texto[pos]));

    printf("Contador:\n");
    printf("\tLetras => %d\n", cnt[0]);
    printf("\tPalavras => %d\n", cnt[1]);
    printf("\tLinhas => %d\n", cnt[2]);

    return 0;
}

int charTipo (char letra){
    if ((letra >= 0x41) && (letra <= 0x5A))
        return 0;

    else if (letra == 0x0A)
        return 1;

    return 2;
}

void charControle (int tipo, int *contador, int *controle){
    if (tipo == 0){
        contador[0]++;
        *(controle) = 1;

    }else{
        if (*(controle) == 1){
            contador[1]++;
            *(controle) = 0;
        }

        if (tipo == 1)
            contador[2]++;
    }
}
