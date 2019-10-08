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

        if (!cnt){
            InterAtributo::flag_0_p_1 = 0;
            InterAtributo::flag_0_p_2 = 0;
            InterAtributo::flag_2_p_1 = 2;
            InterAtributo::flag_3_p_1 = 3;
        } else {
            std::cout << "trocou as flags" << std::endl;
            InterAtributo::flag_0_p_1 = 1;
            InterAtributo::flag_0_p_2 = 2;
            InterAtributo::flag_2_p_1 = 3;
            InterAtributo::flag_3_p_1 = 1;
        }

        ler_u2(arq, &temp, InterAtributo::flag_0_p_1 || this->attr_code);

        if ((dynamic_cast<TabSimbolo*>(this->tab_simbolos)))
            nome = (dynamic_cast<TabSimbolo*>(this->tab_simbolos))->get_nome(temp);

        if (nome.empty()) continue;

        if (!nome.compare("Code"))
            attr = new AttrCode(this->tab_simbolos, temp);
        else if (!nome.compare("LineNumberTable"))
            attr = new AttrLinhaNum(temp);
        else
            attr = new AttrU2(temp);

        std::cout << "flag_0_p_1: " << InterAtributo::flag_0_p_1 << std::endl;
        std::cout << "flag_0_p_2: " << InterAtributo::flag_0_p_2 << std::endl;
        std::cout << "flag_2_p_1: " << InterAtributo::flag_2_p_1 << std::endl;
        std::cout << "flag_3_p_1: " << InterAtributo::flag_3_p_1 << std::endl;

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
