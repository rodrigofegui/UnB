#include "../../lib/Interfaces/InterAtributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

InterAtributo::InterAtributo(const u2 ind_nome, const u4 tam) : InterAtributo(){
    this->ind_nome = ind_nome;
    this->tam = tam;
}

void InterAtributo::decodificar (FILE *arq){
    ler_u2(arq, &this->ind_nome, 1);
    ler_u4(arq, &this->tam, 1);
}
