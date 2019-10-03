#include "../../lib/Tipos/Atributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

void AttrU1::decodificar (FILE *arq){
    u1 temp;

    InterAtributo::decodificar(arq);

    for (int cnt = 0; cnt < this->tam; cnt++){
        ler_u1(arq, &temp);
        this->dados.push_back(temp);
    }

    this->dados.push_back('\0');
}

void AttrU1::exibir (u1 qnt_tabs){
}

void AttrU1::deletar(){
    std::vector<u1>().swap(dados);
}


void AttrU2::decodificar (FILE *arq){
    InterAtributo::decodificar(arq);

    ler_u2(arq, &this->ind, 1);
}

void AttrU2::exibir (u1 qnt_tabs){

}


void AttrCode::decodificar (FILE *arq){
    u1 temp;

    InterAtributo::decodificar(arq);

    ler_u2(arq, &this->max_pilha, 0);
    ler_u2(arq, &this->max_locais, 0);
    ler_u4(arq, &this->tam_codigo, 3);

    for (int cnt = 0; cnt < this->tam_codigo; cnt++){
        ler_u1(arq, &temp);
        this->codigo.push_back(temp);
    }
    this->codigo.push_back('\0');

    ler_u2(arq, &this->tam_tab_excessao, 0);
}

void AttrCode::exibir (u1 qnt_tabs){
}

void AttrCode::deletar(){
    std::vector<u1>().swap(this->codigo);
}


void AttrLinhaNum::decodificar (FILE *arq){
    InterAtributo::decodificar(arq);

}

void AttrLinhaNum::exibir (u1 qnt_tabs){

}
