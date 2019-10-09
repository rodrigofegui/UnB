#include <iostream>
#include "../../lib/Tipos/CPInfo.hpp"

void CPInfo::exibir (u1 qnt_tabs){
    if (this->dados)
        this->dados->exibir(qnt_tabs);
    else
        std::cout << "Extensão de número largo" << std::endl << std::endl;
}

void CPInfo::deletar(){
    if (!this->dados) return;

    this->dados->deletar();

    delete this->dados;
}
