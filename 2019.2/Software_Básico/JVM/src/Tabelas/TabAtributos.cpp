#include <iostream>
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tipos/Atributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


TabAtributos::TabAtributos (u2 *tam) : InterTabela(tam){};

TabAtributos::TabAtributos (u2 *tam, InterTabela *tab_simbolos) : TabAtributos(tam){
    this->tab_simbolos = tab_simbolos;
}

void TabAtributos::decodificar (FILE *arq){
    for (int cnt = 0; cnt < *this->tam; cnt++){
        std::string nome("");
        InterAtributo *attr;
        u2 temp = 0;

        ler_u2(arq, &temp);

        if ((dynamic_cast<TabSimbolo*>(this->tab_simbolos)))
            nome = (dynamic_cast<TabSimbolo*>(this->tab_simbolos))->get_string(temp);

        if (nome.empty()) continue;

        if (!nome.compare("Code"))
            attr = new AttrCode(temp, this->tab_simbolos);
        else if (!nome.compare("LineNumberTable"))
            attr = new AttrLinhaNum(temp);
        else if (!nome.compare("SourceFile"))
            attr = new AttrArqFonte(temp);
        else
            attr = new AttrSilenciado(temp);

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

    std::vector<InterAtributo*>().swap(this->registros);

    delete this;
}
