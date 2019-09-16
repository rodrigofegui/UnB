#include"estruturas.hpp"
#include "libera.hpp"
void libera_elementos (Elem* inicio){
    Elem *aux,*libera;
    while(inicio != NULL){
        aux = inicio;
        inicio = inicio->ger;//pega a proxima linha antes da tual ser liberada
        while(aux!=NULL){//libera a linha toda
            libera = aux;
            aux = aux->proximo;
            free(libera);
        }
    }

}

