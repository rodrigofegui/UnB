#include "../../lib/Tabelas/TabMetodos.hpp"

void TabMetodos::decodificar(FILE *arq){
    for (int cnt = 0; cnt < *this->tam; cnt++){
        Campo c_campo = Campo(1);

        c_campo.decodificar(arq);

        this->registros.push_back(c_campo);
    }
}


void TabMetodos::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    TabCampos::exibir(tab_simbolos, qnt_tabs);
}

void TabMetodos::deletar(){
    TabCampos::deletar();
}
