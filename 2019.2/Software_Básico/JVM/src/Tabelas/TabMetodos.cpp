#include <iomanip>
#include <iostream>
#include "../../lib/Interfaces/InterAtributos.hpp"
#include "../../lib/Tabelas/TabMetodos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

TabMetodos::TabMetodos(InterTabela *tab, u2 *tam): TabMetodos(tam) {
    this->tab_simbolos = tab;
}

void TabMetodos::decodificar(FILE *arq){
    for (int cnt = 0; cnt < *this->tam; cnt++){
        if (cnt == 1){
            InterAtributo::flag_0_p_1 = 1;
            InterAtributo::flag_0_p_2 = 2;
            InterAtributo::flag_2_p_1 = 1;
            InterAtributo::flag_3_p_1 = 1;

        } else {
            InterAtributo::flag_0_p_1 = 0;
            InterAtributo::flag_0_p_2 = 0;
            InterAtributo::flag_2_p_1 = 2;
            InterAtributo::flag_3_p_1 = 3;
        }

        Campo c_campo(this->tab_simbolos);

        c_campo.decodificar(arq, InterAtributo::flag_0_p_1);

        this->registros.push_back(c_campo);
    }

    InterAtributo::flag_0_p_1 = 1;
    InterAtributo::flag_0_p_2 = 2;
    InterAtributo::flag_2_p_1 = 1;
    InterAtributo::flag_3_p_1 = 1;
}

void TabMetodos::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
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

void TabMetodos::deletar(){
    for (auto &registro : registros)
        registro.deletar();

    // std::vector<Campo>().swap(this->registros);

    delete this;
}
