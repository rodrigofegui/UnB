#include "../../lib/Interfaces/InterAtributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include <iostream>

int InterAtributo::flag_0_p_1 = 0;
int InterAtributo::flag_0_p_2 = 0;
int InterAtributo::flag_2_p_1 = 2;
int InterAtributo::flag_3_p_1 = 3;

InterAtributo::InterAtributo(const u2 ind_nome): InterAtributo(){
    this->ind_nome = ind_nome;
};

InterAtributo::InterAtributo(const u2 ind_nome, const u4 tam) : InterAtributo(ind_nome){
    this->tam = tam;
}

void InterAtributo::decodificar (FILE *arq){
    if (!this->ind_nome)
        ler_u2(arq, &this->ind_nome, InterAtributo::flag_0_p_1);

    if (!this->tam)
        ler_u4(arq, &this->tam, InterAtributo::flag_2_p_1);

}

void InterAtributo::deletar(){
    delete this;
}
