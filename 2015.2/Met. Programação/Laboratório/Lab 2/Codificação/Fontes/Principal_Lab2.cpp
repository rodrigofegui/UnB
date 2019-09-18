/*	Inclusão das Bibliotecas Requesitadas: */
#include "../Biblioteca/Pilha.hpp"
#include "stdio.h"
#include "stdlib.h"

using namespace listaenc;

int main (){
    Pilha teste;
    tpDado teste2;

    teste.criar();

    teste.inserir(2);

    teste.inserir(7);

    teste.inserir(81);

    teste.inserir(150);

    teste.inserir(200);

    teste.exibir();

    teste2 = teste.procura(2);

    //if (teste2.dados >= 0 && teste2.indice < 5){
    if (teste2 != teste.estadonulo()){
        printf("Encontrou o elemento %d\n", teste2->dados);
    }else{
        printf("Nao foi encontrado elemento procurado\n");
    }

    teste.liberar();

    return 0;
}
