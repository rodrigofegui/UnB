#include <iostream>
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void InfoPadding::exibir (const u1 qnt_tabs){
    std::cout << "Extensão de número largo" << std::endl;
}



void InfoClasse::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_nome);
}

void InfoClasse::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Class" << std::endl;

    std::cout << tabs + "Índice para o nome: ";
    std::cout << this->ind_nome;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome) << std::endl;
}



void InfoRefCampo::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_classe);
    ler_u2(arq, &this->ind_nome_tipo);
}

void InfoRefCampo::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Fieldref" << std::endl;

    std::cout << tabs + "Índice para a classe: ";
    std::cout << this->ind_classe;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_classe) << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome_tipo) << std::endl;
}



void InfoNomeTipo::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_nome);
    ler_u2(arq, &this->ind_descritor);
}

void InfoNomeTipo::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_NameAndType" << std::endl;

    std::cout << tabs + "Índice para o nome: ";
    std::cout << this->ind_nome;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome) << std::endl;
    std::cout << tabs + "Índice para o descritor: ";
    std::cout << this->ind_descritor;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_descritor) << std::endl;
}



void InfoUTF8::decodificar (FILE *const arq){
    u1 temp;

    ler_u2(arq, &this->tam);

    for (int cnt = 0; cnt < this->tam; cnt++){
        ler_u1(arq, &temp);
        this->bytes.push_back(temp);
    }
}

void InfoUTF8::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Utf8" << std::endl;

    std::cout << tabs + "Tamanho da string: " << this->tam << std::endl;
    std::cout << tabs + "String: "<< get_string() << std::endl;
}

std::string InfoUTF8::get_string (){
    std::string str(this->bytes.begin(), this->bytes.end());

    return str;
}

void InfoUTF8::deletar (){
    std::vector<u1>().swap(this->bytes);

    InterCPDado::deletar();
}



void InfoRefMetodo::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_classe);
    ler_u2(arq, &this->ind_nome_tipo);
}

void InfoRefMetodo::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Methodref" << std::endl;

    std::cout << tabs + "Índice para a clase: ";
    std::cout << this->ind_classe;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_classe) << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome_tipo) << std::endl;
}



void InfoRefMetInterface::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_classe);
    ler_u2(arq, &this->ind_nome_tipo);
}

void InfoRefMetInterface::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_InterfaceMethodref" << std::endl;

    std::cout << tabs + "Índice para a clase: ";
    std::cout << this->ind_classe;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_classe) << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome_tipo) << std::endl;
}



void InfoString::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_string);
}

void InfoString::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_String" << std::endl;

    std::cout << tabs + "Índice para a string: ";
    std::cout << this->ind_string;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_string) << std::endl;
}



void InfoInteiro::decodificar (FILE *const arq){
    ler_u4(arq, &this->bytes);
}

void InfoInteiro::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Integer" << std::endl;

    std::cout << tabs + "Bytes: " << get_hex_4(this->bytes) << std::endl;
}



void InfoFloat::decodificar (FILE *const arq){
    ler_u4(arq, &this->bytes);
}

void InfoFloat::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Float" << std::endl;

    std::cout << tabs + "Bytes: " << get_hex_4(this->bytes) << std::endl;
}



void InfoLong::decodificar (FILE *const arq){
    ler_u4(arq, &this->bytes_mais);
    ler_u4(arq, &this->bytes_menos);
}

void InfoLong::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Long" << std::endl;

    std::cout << tabs + "Bytes mais significativos: " << get_hex_4(this->bytes_mais) << std::endl;
    std::cout << tabs + "Bytes menos significativos: " << get_hex_4(this->bytes_menos) << std::endl;
}



void InfoDouble::decodificar (FILE *const arq){
    ler_u4(arq, &this->bytes_mais);
    ler_u4(arq, &this->bytes_menos);
}

void InfoDouble::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Double" << std::endl;

    std::cout << tabs + "Bytes mais significativos: " << get_hex_4(this->bytes_mais) << std::endl;
    std::cout << tabs + "Bytes menos significativos: " << get_hex_4(this->bytes_menos) << std::endl;
}
