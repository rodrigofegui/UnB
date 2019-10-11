#include <iostream>
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tipos/Atributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


AttrCode::AttrCode (const u2 ind_nome) : InterAtributo(ind_nome){}

AttrCode::AttrCode (const u2 ind_nome, InterTabela *tab_simbolos) : AttrCode(ind_nome){
    this->tab_simbolos = tab_simbolos;
}

void AttrCode::decodificar (FILE *arq){
    u1 temp;

    InterAtributo::decodificar(arq);

    ler_u2(arq, &this->max_pilha);
    ler_u2(arq, &this->max_locais);
    ler_u4(arq, &this->tam_codigo);

    for (int cnt = 0; cnt < this->tam_codigo; cnt++){
        ler_u1(arq, &temp);
        this->codigo.push_back(temp);
    }

    ler_u2(arq, &this->tam_tab_excessao);

    if (this->tam_tab_excessao){
        for (int cnt =0; cnt < this->tam_tab_excessao; cnt++){
            Excessao excessao;
            excessao.decodificar(arq);

            this->tab_excessao.push_back(excessao);
        }
    }

    ler_u2(arq, &this->tam_tab_atributos);

    if (this->tam_tab_atributos){
        this->tab_atributos = new TabAtributos(&this->tam_tab_atributos, this->tab_simbolos);
        this->tab_atributos->decodificar(arq);
    }
}

void AttrCode::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "Code" << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Tamanho máximo da pilha: " << this->max_pilha << std::endl;
    std::cout << tabs + "Tamanho máximo das variáveis locais: " << this->max_locais << std::endl;
    std::cout << tabs + "Tamanho do código: " << this->tam_codigo << std::endl;

    for (auto &linha : this->codigo){
        std::cout << tabs + '\t' << get_hex(linha) << std::endl;
    }

    std::cout << tabs + "Tamanho da tabela de excessões: " << this->tam_tab_excessao << std::endl;

    if (this->tam_tab_excessao)
        std::cout << tabs + "\tIni.\tFim\tTrat.\tCatch" << std::endl;

    for (auto &excessao : this->tab_excessao)
        excessao.exibir(this->tab_simbolos, qnt_tabs + 1);

    std::cout << tabs + "Tamanho da tabela de atributos: " << this->tam_tab_atributos << std::endl;

     if (this->tab_atributos) this->tab_atributos->exibir(qnt_tabs + 1);
}

void AttrCode::deletar (){
    std::vector<u1>().swap(this->codigo);

    std::vector<Excessao>().swap(tab_excessao);

    if (this->tab_atributos)
        this->tab_atributos->deletar();

    InterAtributo::deletar();
}



AttrLinhaNum::AttrLinhaNum (const u2 ind_nome) : InterAtributo(ind_nome){}

void AttrLinhaNum::decodificar (FILE *arq){
    ler_u4(arq, &this->tam);

    ler_u2(arq, &this->tam_tab_valores);

    for (int cnt = 0; cnt < this->tam_tab_valores; cnt++){
        InfoNumero info;

        ler_u2(arq, &info.pc_comeco);
        ler_u2(arq, &info.lin_num);

        this->tab_valores.push_back(info);
    }
}

void AttrLinhaNum::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "LineNumberTable" << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Tamanho da tabela de numeros: " << this->tam_tab_valores << std::endl;

    for (auto &valores : this->tab_valores){
        std::cout << tabs + '\t';
        std::cout << "Vale " << valores.lin_num;
        std::cout << " após a linha " << valores.pc_comeco <<std::endl;
    }
}

void AttrLinhaNum::deletar (){
    std::vector<InfoNumero>().swap(tab_valores);

    InterAtributo::deletar ();
}



AttrArqFonte::AttrArqFonte (const u2 ind_nome) : InterAtributo(ind_nome){}

void AttrArqFonte::decodificar (FILE *arq){
    InterAtributo::decodificar (arq);

    ler_u2(arq, &this->ind);
}

void AttrArqFonte::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "SourceFile" << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Índice para o nome do arquivo-fonte: " << this->ind;
    std::cout << " -> " << (dynamic_cast<TabSimbolo*>(tab_simbolos))->get_string(this->ind) << std::endl;
}

void AttrArqFonte::deletar (){
    InterAtributo::deletar();
}



AttrSilenciado::AttrSilenciado (const u2 ind_nome) : InterAtributo(ind_nome){}

void AttrSilenciado::decodificar (FILE *arq){
    InterAtributo::decodificar(arq);

    fseek(arq, this->tam, SEEK_CUR);
}

void AttrSilenciado::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "Não reconhecido";
    std::cout << " -> " << (dynamic_cast<TabSimbolo*>(tab_simbolos))->get_string(this->ind_nome) << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
}

void AttrSilenciado::deletar (){
    InterAtributo::deletar();
}
