#include <iostream>
#include <string>
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tipos/Campo.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"

void Campo::decodificar(FILE *arq){
    ler_u2(arq, &this->flag_acesso, 0);
    ler_u2(arq, &this->ind_nome, 0);
    ler_u2(arq, &this->ind_descritor, 0);
    ler_u2(arq, &this->tam_tab_atributos, 1);

    if(this->tam_tab_atributos){
        this->tab_atributos = new TabAtributos(this->e_metodo, &this->tam_tab_atributos);
        this->tab_atributos->decodificar(arq);
    }
}

void Campo::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "ind: " << this << std::endl;

    std::cout << (dynamic_cast<TabSimbolo*>(tab_simbolos))->get_name(this->ind_nome - 1) << std::endl;

    std::cout << tabs + "Flag de acesso: ";
        exibir_flag(this->flag_acesso);
    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Índice para o descritor: " << this->ind_descritor << std::endl;
    std::cout << tabs + "Qnt. de entradas na tabela de atributos: " << this->tam_tab_atributos << std::endl;
}

void Campo::deletar(){
    tab_atributos->deletar();

    delete this;
}
