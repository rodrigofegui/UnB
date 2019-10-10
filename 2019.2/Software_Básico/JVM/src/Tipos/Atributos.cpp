#include <iostream>
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tipos/Atributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

void AttrU1::decodificar (FILE *arq){
    u1 temp;

    InterAtributo::decodificar(arq);

    for (int cnt = 0; cnt < this->tam; cnt++){
        ler_u1(arq, &temp);
        this->dados.push_back(temp);
    }

    this->dados.push_back('\0');
}

void AttrU1::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');
    std::cout << tabs + "AttrU1" << std::endl;
}

void AttrU1::deletar(){
    std::vector<u1>().swap(dados);
    InterAtributo::deletar();
}


void AttrU2::decodificar (FILE *arq){
    InterAtributo::decodificar(arq);

    ler_u2(arq, &this->ind, 1);
}

void AttrU2::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');
    std::cout << tabs + "U2 ";
}

void AttrU2::deletar(){
    InterAtributo::deletar();
}


AttrCode::AttrCode (InterTabela *tab, const u2 ind_nome) : AttrCode(ind_nome){
    this->tab_simbolos = tab;
}

void AttrCode::decodificar (FILE *arq){
    u1 temp;

    InterAtributo::decodificar(arq);

    ler_u2(arq, &this->max_pilha, 1);
    ler_u2(arq, &this->max_locais, 1);
    ler_u4(arq, &this->tam_codigo, 1);

    for (int cnt = 0; cnt < this->tam_codigo; cnt++){
        ler_u1(arq, &temp);
        this->codigo.push_back(temp);
    }

    ler_u2(arq, &this->tam_tab_excessao, 1);

    if (this->tam_tab_excessao){
        for (int cnt =0; cnt < this->tam_tab_excessao; cnt++){
            Excessao excessao;
            excessao.decodificar(arq);

            this->tab_excessao.push_back(excessao);
        }
    }

    ler_u2(arq, &this->tam_tab_atributos, 1);

    if (this->tam_tab_atributos){
        this->tab_atributos = new TabAtributos(this->tab_simbolos, &this->tam_tab_atributos, 1);
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
        std::cout << tabs + '\t';
        exibir_hex_2(linha);
        std::cout << std::endl;
    }

    std::cout << tabs + "Tamanho da tabela de excessões: " << this->tam_tab_excessao << std::endl;

    if (this->tam_tab_excessao)
        std::cout << tabs + "\tIni.\tFim\tTrat.\tCatch" << std::endl;

    for (auto &excessao : this->tab_excessao)
        excessao.exibir(tab_simbolos, qnt_tabs + 1);

    std::cout << tabs + "Tamanho da tabela de atributos: " << this->tam_tab_atributos << std::endl;

    this->tab_atributos->exibir(qnt_tabs + 1);
}

void AttrCode::deletar(){
    std::vector<u1>().swap(this->codigo);

    std::vector<Excessao>().swap(tab_excessao);

    if (this->tab_atributos)
        this->tab_atributos->deletar();

    InterAtributo::deletar();
}


void AttrLinhaNum::decodificar (FILE *arq){
    ler_u4(arq, &this->tam, 1);

    ler_u2(arq, &this->tam_tab_valores, 1);

    for (int cnt = 0; cnt < this->tam_tab_valores; cnt++){
        InfoNumero info;

        ler_u2(arq, &info.pc_comeco, 1);
        ler_u2(arq, &info.lin_num, 1);

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

    InterAtributo::deletar();
}


void AttrArqFonte::decodificar (FILE *arq){
    InterAtributo::decodificar(arq);

    ler_u2(arq, &this->ind, 1);
}

void AttrArqFonte::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "SourceFile" << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Índice para o nome do arquivo-fonte: " << this->ind;
    std::cout << " -> " << (dynamic_cast<TabSimbolo*>(tab_simbolos))->get_nome(this->ind) << std::endl;
}

void AttrArqFonte::deletar(){
    InterAtributo::deletar();
}


void AttrSilenciado::decodificar (FILE *arq){
    int temp = InterAtributo::flag_2_p_1;
    InterAtributo::flag_2_p_1 = 1;
    InterAtributo::decodificar(arq);
    InterAtributo::flag_2_p_1 = temp;

    fseek(arq, this->tam, SEEK_CUR);
}

void AttrSilenciado::exibir (InterTabela *tab_simbolos, u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "Não reconhecido";
    std::cout << " -> " << (dynamic_cast<TabSimbolo*>(tab_simbolos))->get_nome(this->ind_nome) << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
}

void AttrSilenciado::deletar(){
    InterAtributo::deletar();
}
