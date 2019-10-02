#include <iostream>
#include "../../lib/Tipos/CPInfo.hpp"

void CPInfo::exibir(int qnt_tab){
    if (this->dados)
        this->dados->exibir(qnt_tab);
    else
        std::cout << "Extensão de número largo" << std::endl;
}

void CPInfo::deletar(){
    if (!this->dados) return;

    this->dados->deletar();

    delete this->dados;
}
