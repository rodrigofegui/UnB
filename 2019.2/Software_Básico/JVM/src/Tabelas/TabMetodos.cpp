#include <iomanip>
#include <iostream>
#include "../../lib/Interfaces/InterAtributo.hpp"
#include "../../lib/Tabelas/TabMetodos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


TabMetodos::TabMetodos (u2 *tam) : InterTabela(tam){}

TabMetodos::TabMetodos (u2 *tam, InterTabela *tab_simbolos): TabMetodos(tam) {
    this->tab_simbolos = tab_simbolos;
}

u1 TabMetodos::decodificar (FILE *arq){
    for (int cnt = 0; cnt < *this->tam; cnt++){
        Campo c_campo(this->tab_simbolos);

        c_campo.decodificar(arq);

        this->registros.push_back(c_campo);
    }

    return 0;
}

void TabMetodos::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');
    int tam = *this->tam;

    if (!tam){
        std::cout << tabs + "Não há itens na tabela de métodos" << std::endl;
        return;
    }

    u1 padding = get_padding(tam);

    for (int cnt = 0; cnt < tam; cnt++){
        std::cout << tabs + "[";
        std::cout << std::setfill('0') << std::setw(padding) << cnt;
        std::cout << "] ";

        this->registros[cnt].exibir(qnt_tabs + 1);
    }
}

void TabMetodos::deletar (){
    for (auto &registro : registros)
        registro.deletar();

    delete this;
}
