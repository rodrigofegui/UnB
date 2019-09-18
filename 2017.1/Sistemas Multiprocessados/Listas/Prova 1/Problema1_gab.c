#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define COMUN 4
#define LIN(C) 2
#define COL(C) 2


/*
    Gabarito:
    3686    −3873
    −10265  −2162
*/

int main (){
    //*
    int matrizA [LIN(C)][COMUN] = { -98, -118, -91, 12,
                                    -49, 35, 28, 95};
    int matrizB [COMUN][COL(C)] = { 12, -8,
                                    -8, 30,
                                    -54, 7,
                                    -83, -40};
    int matrizC [LIN(C)][COL(C)];
    int soma = 0;
    int linA, linB;
    int colB;

    printf("Calculando Matriz C:\n");
    for (linA = 0; linA < LIN(C); linA++){
        for (colB = 0; colB < COL(C); colB++){
            soma = 0;

            for (linB = 0; linB < COMUN; linB++)
                soma += matrizA[linA][linB] * matrizB[linB][colB];

            matrizC[linA][colB] = soma;
        }
    }

    printf("MatrizA:\n");
    for (linA = 0; linA < LIN(C); linA++){
        for (colB = 0; colB < COMUN; colB++)
            printf("%d\t", matrizA[linA][colB]);
        printf("\n");
    }

    printf("\n");
    printf("MatrizB:\n");
    for (linA = 0; linA < COMUN; linA++){
        for (colB = 0; colB < COL(C); colB++)
            printf("%d\t", matrizB[linA][colB]);
        printf("\n");
    }

    printf("\n");
    printf("MatrizC:\n");
    for (linA = 0; linA < LIN(C); linA++){
        for (colB = 0; colB < COL(C); colB++)
            printf("%d\t", matrizC[linA][colB]);
        printf("\n");
    }
    //*/

    return 0;
}
