#include <iostream>
#include <string>
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void InfoClasse::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_nome, 1);
}

void InfoClasse::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Índice para o nome: ";
    std::cout << this->ind_nome << std::endl;
    std::cout << tabs + "Nome: " << std::endl;
}


void InfoRefCampo::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_classe, 1);
    ler_u2(arq, &this->ind_nome_tipo, 1);
}

void InfoRefCampo::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Índice para a classe: ";
    std::cout << this->ind_classe << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo << std::endl;
}


void InfoNomeTipo::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_nome, 1);
    ler_u2(arq, &this->ind_descritor, 1);
}

void InfoNomeTipo::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Índice para o nome: ";
    std::cout << this->ind_nome << std::endl;
    std::cout << tabs + "Índice para o descritor: ";
    std::cout << this->ind_descritor << std::endl;
}


void InfoUTF8::decodificar(FILE *arq){
    u1 temp;

    ler_u2(arq, &this->tam, 1);

    for (int cnt = 0; cnt < this->tam; cnt++){
        ler_u1(arq, &temp);
        this->bytes.push_back(temp);
    }

    this->bytes.push_back('\0');
}

void InfoUTF8::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Tamanho da string: ";
    std::cout << this->tam << std::endl;
    std::cout << tabs + "String: ";
    for (auto &letra : this->bytes)
        std::cout << letra;
    std::cout << std::endl;
}

void InfoUTF8::deletar(){
    this->bytes.clear();
}


void InfoRefMetodo::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_classe, 1);
    ler_u2(arq, &this->ind_nome_tipo, 1);
}

void InfoRefMetodo::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Índice para a clase: ";
    std::cout << this->ind_classe << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo << std::endl;
}


void InfoRefMetInterface::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_classe, 1);
    ler_u2(arq, &this->ind_nome_tipo, 1);
}

void InfoRefMetInterface::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Índice para a clase: ";
    std::cout << this->ind_classe << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo << std::endl;
}


void InfoString::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_string, 1);
}

void InfoString::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Índice para a string: ";
    std::cout << this->ind_string << std::endl;
}


void InfoInteiro::decodificar(FILE *arq){
    ler_u4(arq, &this->bytes, 1);
}

void InfoInteiro::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Bytes: ";
    std::cout << this->bytes << std::endl;
}


void InfoFloat::decodificar(FILE *arq){
    ler_u4(arq, &this->bytes, 1);
}

void InfoFloat::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Bytes: ";
    std::cout << this->bytes << std::endl;
}


void InfoLong::decodificar(FILE *arq){
    ler_u4(arq, &this->bytes_mais, 1);
    ler_u4(arq, &this->bytes_menos, 1);
}

void InfoLong::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Bytes mais significativos: ";
    std::cout << this->bytes_mais << std::endl;
    std::cout << tabs + "Bytes menos significativos: ";
    std::cout << this->bytes_menos << std::endl;
}


void InfoDouble::decodificar(FILE *arq){
    ler_u4(arq, &this->bytes_mais, 1);
    ler_u4(arq, &this->bytes_menos, 1);
}

void InfoDouble::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    std::cout << tabs + "Bytes mais significativos: ";
    std::cout << this->bytes_mais << std::endl;
    std::cout << tabs + "Bytes menos significativos: ";
    std::cout << this->bytes_menos << std::endl;
}
