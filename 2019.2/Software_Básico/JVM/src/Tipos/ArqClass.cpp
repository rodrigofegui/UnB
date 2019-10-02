#include "../../lib/Tipos/ArqClass.hpp"
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Erros.hpp"

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
    printf("[ERRO] ");

    switch (e_codigo){
        case E_SEM_ARQ:
            printf("Não há arquivo associado para este .class\n"); break;
        case E_NAO_CLASS:
            printf("Este arquivo .class o código mágico correto\n"); break;
        default:
            printf("Não especificado\n");
    }

    this->reset();
    exit(e_codigo);
}

void ArqClass::exibir_versao_java(u2 versao){
    switch (versao){
        case V1_1:
            printf("JDK 1.1\n"); break;
        case V1_2:
            printf("JDK 1.2\n"); break;
        case V1_3:
            printf("JDK 1.3\n"); break;
        case V1_4:
            printf("JDK 1.4\n"); break;
        case V5:
            printf("Java SE 5.0\n"); break;
        case V6:
            printf("Java SE 6.0\n"); break;
        case V7:
            printf("Java SE 7\n"); break;
        case V8:
            printf("Java SE 8\n"); break;
        case V9:
            printf("Java SE 9\n"); break;
        case V10:
            printf("Java SE 10\n"); break;
        case V11:
            printf("Java SE 11\n"); break;
        case V12:
            printf("Java SE 12\n"); break;
        case V13:
            printf("Java SE 13\n"); break;
        case V14:
            printf("Java SE 14\n"); break;
        default:
            printf("Sem expecificação\n");
    }
}



void ArqClass::decodificar(){
    if (!this->arq) erro(E_SEM_ARQ);

    check_valido();

    ler_u2(this->arq, &this->versao_min, 1);
    ler_u2(this->arq, &this->versao_max, 1);
    ler_u2(this->arq, &this->tam_tab_simbolo, 1);

    this->tab_simbolo = new TabSimbolo(&this->tam_tab_simbolo);
    this->tab_simbolo->decodificar(this->arq);
}

void ArqClass::exibir(){
    printf("Código indentificador: 0x%08X\n", this->codigo);

    printf("Versão mínima compilador: ");
        exibir_versao_java(this->versao_min);
    printf("Versão máxima compilador: ");
        exibir_versao_java(this->versao_max);

    printf("Qnt. de entradas na tabela de símbolos: %d\n", this->tam_tab_simbolo);
    this->tab_simbolo->exibir(1);
}

void ArqClass::deletar(){
    this->tab_simbolo->deletar();

    if (this->arq) fclose(this->arq);
}
