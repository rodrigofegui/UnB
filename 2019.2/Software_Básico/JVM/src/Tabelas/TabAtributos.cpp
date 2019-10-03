#include <iostream>
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tipos/Atributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

TabAtributos::TabAtributos (u1 e_metodo, u2 *tam) : TabAtributos(tam){
    this->e_metodo = e_metodo;
}

void TabAtributos::decodificar(FILE *arq){
    for (int cnt = 0; cnt < *this->tam; cnt++){
        InterAtributo *attrU2;

        if (this->e_metodo)
            attrU2 = new AttrCode();
        else
            attrU2 = new AttrU2();

        attrU2->decodificar(arq);

        this->registros.push_back(attrU2);
    }
}

void TabAtributos::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');
    int tam = *this->tam;

    if (!tam){
        std::cout << tabs + "Não há itens na tabela de atributos" << std::endl;
        return;
    }

    for (int cnt = 0; cnt < tam; cnt++){
        this->registros[cnt]->exibir(qnt_tabs);
    }
}

void TabAtributos::deletar (){
    for (auto &registro : registros)
        registro->deletar();

    std::vector<InterAtributo *>().swap(this->registros);

    delete this;
}
