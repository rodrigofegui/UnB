#include <iostream>
#include "../../lib/Tipos/Excessao.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Tabelas/TabSimbolo.hpp"

void Excessao::decodificar (FILE *arq){
    ler_u2(arq, &this->lin_comeco);
    ler_u2(arq, &this->lin_final);
    ler_u2(arq, &this->lin_tratamento);
    ler_u2(arq, &this->ind_tipo_catch);
}

void Excessao::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << tabs << this->lin_comeco << '\t';
    std::cout << this->lin_final << '\t';
    std::cout << this->lin_tratamento << '\t';
    std::cout << this->ind_tipo_catch;
    std::cout << " -> " << (dynamic_cast<TabSimbolo*>(tab_simbolos))->get_string (this->ind_tipo_catch) << std::endl;
}
