#include <iomanip>
#include <iostream>
#include <string>
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void InfoClasse::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_nome, 1);
}

void InfoClasse::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Class" << std::endl;

    std::cout << tabs + "Índice para o nome: ";
    std::cout << this->ind_nome<< std::endl << std::endl;
    // std::cout << tabs + "Nome: " << std::endl;
}


void InfoRefCampo::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_classe, 1);
    ler_u2(arq, &this->ind_nome_tipo, 1);
}

void InfoRefCampo::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Fieldref" << std::endl;

    std::cout << tabs + "Índice para a classe: ";
    std::cout << this->ind_classe << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo << std::endl << std::endl;
}


void InfoNomeTipo::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_nome, 1);
    ler_u2(arq, &this->ind_descritor, 1);
}

void InfoNomeTipo::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_NameAndType" << std::endl;

    std::cout << tabs + "Índice para o nome: ";
    std::cout << this->ind_nome << std::endl;
    std::cout << tabs + "Índice para o descritor: ";
    std::cout << this->ind_descritor << std::endl << std::endl;
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

void InfoUTF8::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Utf8" << std::endl;

    std::cout << tabs + "Tamanho da string: ";
    std::cout << this->tam << std::endl;
    std::cout << tabs + "String: ";
    for (auto &letra : this->bytes)
        std::cout << letra;
    std::cout << std::endl << std::endl;
}

std::string InfoUTF8::get_utf8 (){
    std::string str(this->bytes.begin(), this->bytes.end());

    return str;
}

void InfoUTF8::deletar(){
    std::vector<u1>().swap(this->bytes);
}


void InfoRefMetodo::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_classe, 1);
    ler_u2(arq, &this->ind_nome_tipo, 1);
}

void InfoRefMetodo::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Methodref" << std::endl;

    std::cout << tabs + "Índice para a clase: ";
    std::cout << this->ind_classe << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo << std::endl << std::endl;
}


void InfoRefMetInterface::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_classe, 1);
    ler_u2(arq, &this->ind_nome_tipo, 1);
}

void InfoRefMetInterface::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_InterfaceMethodref" << std::endl;

    std::cout << tabs + "Índice para a clase: ";
    std::cout << this->ind_classe << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo << std::endl << std::endl;
}


void InfoString::decodificar(FILE *arq){
    ler_u2(arq, &this->ind_string, 1);
}

void InfoString::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_String" << std::endl;

    std::cout << tabs + "Índice para a string: ";
    std::cout << this->ind_string << std::endl << std::endl;
}


void InfoInteiro::decodificar(FILE *arq){
    ler_u4(arq, &this->bytes, 1);
}

void InfoInteiro::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Integer" << std::endl;

    std::cout << tabs + "Bytes: 0x";
    exibir_hex_2(this->bytes);
    std::cout << std::endl << std::endl;
}


void InfoFloat::decodificar(FILE *arq){
    ler_u4(arq, &this->bytes, 1);
}

void InfoFloat::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Float" << std::endl;

    std::cout << tabs + "Bytes: 0x";
    exibir_hex_2(this->bytes);
    std::cout << std::endl << std::endl;
}


void InfoLong::decodificar(FILE *arq){
    ler_u4(arq, &this->bytes_mais, 1);
    ler_u4(arq, &this->bytes_menos, 1);
}

void InfoLong::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Long" << std::endl;

    std::cout << tabs + "Bytes mais significativos: 0x";
    exibir_hex_4(this->bytes_mais);
    std::cout << std::endl;
    std::cout << tabs + "Bytes menos significativos: 0x";
    exibir_hex_4(this->bytes_menos);
    std::cout << std::endl;
}


void InfoDouble::decodificar(FILE *arq){
    ler_u4(arq, &this->bytes_mais, 1);
    ler_u4(arq, &this->bytes_menos, 1);
}

void InfoDouble::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Double" << std::endl;

    std::cout << tabs + "Bytes mais significativos: 0x";
    exibir_hex_4(this->bytes_mais);
    std::cout << std::endl;
    std::cout << tabs + "Bytes menos significativos: 0x";
    exibir_hex_4(this->bytes_menos);
    std::cout << std::endl;
}
