/*	Inclusão das Bibliotecas Requesitadas: */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Biblioteca/Vetor.hpp"

tpDado procura (info *vetor, info alvo){
    tpDado corrente = primeiro (vetor);

    while (!terminou(vetor, corrente)){
        if (compara(obtervalor(corrente), alvo)){
            return corrente;
        }

        corrente = definirproximo (vetor, corrente);
    };

    return estadonulo();
}

tpDado primeiro (info *vetor){
    tpDado novo;
    novo.dado = vetor[0];
    novo.indice = 0;
    return novo;
}

bool terminou (info *vetor, tpDado corrente){
    if ((corrente.indice > static_cast<int>(sizeof(vetor)))
        || (vetor[corrente.indice] != corrente.dado))
            return VERDADE;
    return !VERDADE;
}

info obtervalor (tpDado corrente){
    return corrente.dado;
}

bool compara (info corrente, info alvo){
    if (corrente == alvo)
        return VERDADE;
    return !VERDADE;
}

tpDado definirproximo (info *vetor, tpDado corrente){
    corrente.dado = vetor[corrente.indice + 1];
    corrente.indice++;
    return corrente;
}

tpDado estadonulo (){
    tpDado corrente;

    corrente.indice = -1;

    return corrente;
}
