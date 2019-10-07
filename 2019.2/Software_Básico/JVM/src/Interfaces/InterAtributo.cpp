#include "../../lib/Interfaces/InterAtributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

u1 InterAtributo::flag_ler_tam = 0;

InterAtributo::InterAtributo(const u2 ind_nome): InterAtributo(){
    this->ind_nome = ind_nome;
};

InterAtributo::InterAtributo(const u2 ind_nome, const u4 tam) : InterAtributo(ind_nome){
    this->tam = tam;
}

void InterAtributo::decodificar (FILE *arq){
    if (!this->ind_nome)
        ler_u2(arq, &this->ind_nome, 0);

    if (!this->tam)
        ler_u4(arq, &this->tam, 2);
}

void InterAtributo::deletar(){
    delete this;
}
