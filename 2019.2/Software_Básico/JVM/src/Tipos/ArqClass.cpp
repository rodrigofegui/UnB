#include <iomanip>
#include <iostream>
#include "../../lib/Tipos/ArqClass.hpp"
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tabelas/TabCampos.hpp"
#include "../../lib/Tabelas/TabMetodos.hpp"
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Status.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"


ArqClass::ArqClass (char *nome_arq) : ArqClass() {
    this->nome_arq = nome_arq;
}

void ArqClass::check_valido(){
    ler_u4(this->arq, &this->codigo);

    if (this->codigo != COD_ARQ_CLASS) erro(E_NAO_CLASS);
}

void ArqClass::erro (u1 e_codigo){
    std::cout << "[ERRO] ";

    switch (e_codigo){
        case E_SEM_ARQ:
            std::cout << "Não há arquivo associado para este .class" << std::endl; break;
        case E_NAO_CLASS:
            std::cout << "Este arquivo .class o código mágico correto" << std::endl; break;
        default:
            std::cout << "Não especificado" << std::endl;
    }

    deletar();
    exit(e_codigo);
}


std::string ArqClass::get_versao_java (u2 versao){
    switch (versao){
        case V1_1:  return "JDK 1.1";
        case V1_2:  return "JDK 1.2";
        case V1_3:  return "JDK 1.3";
        case V1_4:  return "JDK 1.4";
        case V5:    return "Java SE 5.0";
        case V6:    return "Java SE 6.0";
        case V7:    return "Java SE 7";
        case V8:    return "Java SE 8";
        case V9:    return "Java SE 9";
        case V10:   return "Java SE 10";
        case V11:   return "Java SE 11";
        case V12:   return "Java SE 12";
        case V13:   return "Java SE 13";
        case V14:   return "Java SE 14";
        default:    return "Sem expecificação";
    }
}


void ArqClass::decodificar (){
    this->arq = abrir(nome_arq);

    if (!this->arq) erro(E_SEM_ARQ);

    check_valido();

    ler_u2(this->arq, &this->versao_min);
    ler_u2(this->arq, &this->versao_max);
    ler_u2(this->arq, &this->tam_tab_simbolo);

    if (this->tam_tab_simbolo){
        this->tab_simbolo = new TabSimbolo(&this->tam_tab_simbolo);
        this->tab_simbolo->decodificar(this->arq);
    }

    ler_u2(this->arq, &this->flag_acesso);
    ler_u2(this->arq, &this->class_atual);
    ler_u2(this->arq, &this->class_super);
    ler_u2(this->arq, &this->tam_tab_interfaces);

    if (this->tam_tab_interfaces){
        // A DESENVOLVER
    }

    ler_u2(this->arq, &this->tam_tab_campos);

    if (this->tam_tab_campos){
        this->tab_campos = new TabCampos(&this->tam_tab_campos, this->tab_simbolo);
        this->tab_campos->decodificar(this->arq);
    }

    ler_u2(this->arq, &this->tam_tab_metodos);

    if (this->tam_tab_metodos){
        this->tab_metodos = new TabMetodos(&this->tam_tab_metodos, this->tab_simbolo);
        this->tab_metodos->decodificar(this->arq);
    }

    ler_u2(this->arq, &this->tam_tab_atributos);

    if (this->tam_tab_atributos){
        this->tab_atributos = new TabAtributos(&this->tam_tab_atributos, this->tab_simbolo);
        this->tab_atributos->decodificar(this->arq);
    }

    fclose(this->arq);
    this->arq = nullptr;
}

void ArqClass::exibir (){
    std::cout << "Dados do arquivo: " << this->nome_arq << std::endl;
    std::cout << "Código indentificador: " << get_hex_4(this->codigo) << std::endl;

    std::cout << "Versão mínima compilador: ";
    std::cout << get_versao_java(this->versao_min) << std::endl;
    std::cout << "Versão máxima compilador: ";
    std::cout << get_versao_java(this->versao_max) << std::endl;

    std::cout << "Qnt. de entradas na tabela de símbolos: ";
    std::cout << this->tam_tab_simbolo << std::endl;

    if (this->tab_simbolo) this->tab_simbolo->exibir(1);

    std::cout << "Flag de acesso: " << get_flag(this->flag_acesso) << std::endl;

    std::cout << "Classe corrente: " << this->class_atual << std::endl;

    std::cout << "Classe super: " << this->class_super << std::endl;

    std::cout << "Qnt. de entradas na tabela de interfaces: ";
    std::cout << this->tam_tab_interfaces << std::endl;

    if (this->tab_interfaces) this->tab_interfaces->exibir(1);

    std::cout << "Qnt. de entradas na tabela de campos: ";
    std::cout << this->tam_tab_campos << std::endl;

    if (this->tab_campos) this->tab_campos->exibir(1);

    std::cout << "Qnt. de entradas na tabela de métodos: ";
    std::cout << this->tam_tab_metodos << std::endl;

    if (this->tab_metodos) this->tab_metodos->exibir(1);

    std::cout << "Qnt. de entradas na tabela de atributos: ";
    std::cout << this->tam_tab_atributos << std::endl;

    if (this->tab_atributos) this->tab_atributos->exibir(1);

    std::cout << "Fim dos dados" << std::endl;
}

void ArqClass::deletar (){
    if (this->tab_simbolo)
        this->tab_simbolo->deletar();

    if (this->tab_campos)
        this->tab_campos->deletar();

    if (this->tab_metodos)
        this->tab_metodos->deletar();

    if (this->tab_atributos)
        this->tab_atributos->deletar();

    if (this->arq) fclose(this->arq);
}
