#include <iomanip>
#include <iostream>
#include <string.h>
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tipos/Atributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

TabAtributos::TabAtributos (InterTabela *tab, u2 *tam) : TabAtributos(tam){
    this->tab_simbolos = tab;
}

TabAtributos::TabAtributos (InterTabela *tab, u2 *tam, u1 attr_code) : TabAtributos(tab, tam){
    this->attr_code = attr_code;
}

void TabAtributos::decodificar(FILE *arq){
    // std::cout << "veio decifrar TabA" << std::endl;
    for (int cnt = 0; cnt < *this->tam; cnt++){
        std::string nome("");
        InterAtributo *attr;
        u2 temp = 0;

        ler_u2(arq, &temp, this->attr_code);

        if ((dynamic_cast<TabSimbolo*>(this->tab_simbolos)))
            nome = (dynamic_cast<TabSimbolo*>(this->tab_simbolos))->get_nome(temp);

        if (nome.empty()) continue;

        if (!nome.compare("Code"))
            attr = new AttrCode(this->tab_simbolos, temp);
        else if (!nome.compare("LineNumberTable"))
            attr = new AttrLinhaNum(temp);
        else
            attr = new AttrU2(temp);

        attr->decodificar(arq);

        this->registros.push_back(attr);
    }
}

void TabAtributos::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');
    int tam = this->registros.size();

    if (!tam){
        std::cout << tabs + "Não há itens na tabela de atributos" << std::endl;
        return;
    }

    u1 padding = get_padding(tam);

    for (int cnt = 0; cnt < tam; cnt++){
        std::cout << tabs + "[";
        std::cout << std::setfill('0') << std::setw(padding) << cnt;
        std::cout << "] ";

        this->registros[cnt]->exibir(this->tab_simbolos, qnt_tabs + 1);
    }
}

void TabAtributos::deletar (){
    for (auto &registro : registros)
        registro->deletar();

    std::vector<InterAtributo *>().swap(this->registros);

    delete this;
}
