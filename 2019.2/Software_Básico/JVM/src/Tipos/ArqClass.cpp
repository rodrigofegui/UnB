#include <iomanip>
#include <iostream>
#include "../../lib/Tipos/ArqClass.hpp"
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tabelas/TabCampos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Erros.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"

ArqClass::ArqClass(){
    reset();
}

ArqClass::ArqClass(FILE *arq) : ArqClass() {
    this->arq = arq;
}

ArqClass::ArqClass(const char *nome_arq) : ArqClass(abrir(nome_arq)) {
}


void ArqClass::check_valido(){
    ler_u4(this->arq, &this->codigo, 1);

    if (this->codigo != COD_ARQ_CLASS) erro(E_NAO_CLASS);
}

void ArqClass::reset(){
    this->e_principal =
    this->codigo =
    this->versao_min =
    this->versao_max =
    this->tam_tab_simbolo =
    this->flag_acesso =
    this->class_atual =
    this->class_super =
    this->tam_tab_interfaces =
    this->tam_tab_campos =
    this->tam_tab_metodos =
    this->tam_tab_atributos = 0;

    if (this->arq){
        fclose(this->arq);
        this->arq = NULL;
    }

    if (this->tab_simbolo) this->tab_simbolo->deletar();
    if (this->tab_interfaces) this->tab_interfaces->deletar();
    if (this->tab_campos) this->tab_campos->deletar();
    if (this->tab_metodos) this->tab_metodos->deletar();
    if (this->tab_atributos) this->tab_atributos->deletar();

    this->tab_simbolo =
    this->tab_interfaces =
    this->tab_campos =
    this->tab_metodos =
    this->tab_atributos = nullptr;
}

void ArqClass::erro(u1 e_codigo){
    std::cout << "[ERRO] ";

    switch (e_codigo){
        case E_SEM_ARQ:
            std::cout << "Não há arquivo associado para este .class" << std::endl; break;
        case E_NAO_CLASS:
            std::cout << "Este arquivo .class o código mágico correto" << std::endl; break;
        default:
            std::cout << "Não especificado" << std::endl;
    }

    this->reset();
    exit(e_codigo);
}

void ArqClass::exibir_versao_java(u2 versao){
    switch (versao){
        case V1_1:
            std::cout << "JDK 1.1" << std::endl; break;
        case V1_2:
            std::cout << "JDK 1.2" << std::endl; break;
        case V1_3:
            std::cout << "JDK 1.3" << std::endl; break;
        case V1_4:
            std::cout << "JDK 1.4" << std::endl; break;
        case V5:
            std::cout << "Java SE 5.0" << std::endl; break;
        case V6:
            std::cout << "Java SE 6.0" << std::endl; break;
        case V7:
            std::cout << "Java SE 7" << std::endl; break;
        case V8:
            std::cout << "Java SE 8" << std::endl; break;
        case V9:
            std::cout << "Java SE 9" << std::endl; break;
        case V10:
            std::cout << "Java SE 10" << std::endl; break;
        case V11:
            std::cout << "Java SE 11" << std::endl; break;
        case V12:
            std::cout << "Java SE 12" << std::endl; break;
        case V13:
            std::cout << "Java SE 13" << std::endl; break;
        case V14:
            std::cout << "Java SE 14" << std::endl; break;
        default:
            std::cout << "Sem expecificação" << std::endl;
    }
}



void ArqClass::decodificar(){
    if (!this->arq) erro(E_SEM_ARQ);

    check_valido();

    ler_u2(this->arq, &this->versao_min, 1);
    ler_u2(this->arq, &this->versao_max, 1);
    ler_u2(this->arq, &this->tam_tab_simbolo, 1);

    if (this->tam_tab_simbolo){
        this->tab_simbolo = new TabSimbolo(&this->tam_tab_simbolo);
        this->tab_simbolo->decodificar(this->arq);
    }

    // std::cout << "Arquivo: ";
    // exibir_hex_2(ftell(this->arq));

    ler_u2(this->arq, &this->flag_acesso, 0);
    ler_u2(this->arq, &this->class_atual, 0);
    ler_u2(this->arq, &this->class_super, 0);
    ler_u2(this->arq, &this->tam_tab_interfaces, 1);

    if (this->tam_tab_interfaces){
        // this->tab_interfaces = new
    }

    ler_u2(this->arq, &this->tam_tab_campos, 0);

    if (this->tam_tab_campos){
        this->tab_campos = new TabCampos(&this->tam_tab_campos);
        this->tab_campos->decodificar(this->arq);
    }

    // ler_u2(this->arq, &this->tam_tab_metodos, 0);

    // if (this->tam_tab_metodos){

    // }

    // ler_u2(this->arq, &this->tam_tab_atributos, 0);

    // if (this->tam_tab_atributos){

    // }
}

void ArqClass::exibir(){
    std::cout << "Código indentificador: 0x";
        exibir_hex_4(this->codigo);
        std::cout << std::endl;

    std::cout << "Versão mínima compilador: ";
        exibir_versao_java(this->versao_min);
    std::cout << "Versão máxima compilador: ";
        exibir_versao_java(this->versao_max);

    std::cout << "Qnt. de entradas na tabela de símbolos: " << this->tam_tab_simbolo << std::endl;
    if (this->tab_simbolo) this->tab_simbolo->exibir(1);

    std::cout << "Flag de acesso: ";
        exibir_flag(this->flag_acesso);

    std::cout << "Classe corrente: " << this->class_atual << std::endl;
    std::cout << "Classe super: " << this->class_super << std::endl;

    std::cout << "Qnt. de entradas na tabela de interfaces: " << this->tam_tab_interfaces << std::endl;
    if (this->tab_interfaces) this->tab_interfaces->exibir(1);

    std::cout << "Qnt. de entradas na tabela de campos: " << this->tam_tab_campos << std::endl;
    if (this->tab_campos) this->tab_campos->exibir(this->tab_simbolo, 1);
}

void ArqClass::deletar(){
    this->tab_simbolo->deletar();

    this->tab_campos->deletar();

    if (this->arq) fclose(this->arq);
}
