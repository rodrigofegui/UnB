#include <iostream>
#include <string>
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void TabSimbolo::decodificar(FILE *arq){
    if (!this->tam) return;

    u1 temp, ignora = 0;

    for (int cnt = 0; cnt < this->tam; cnt++){
        ler_u1(arq, &temp);

        this->registros.push_back(CPInfo(temp));
        InterCPDados *c_dados = this->registros[this->registros.size() - 1].dados;

        switch (temp){
            case TAG_UTF:
                c_dados = new InfoUTF8(this); break;
            case TAG_INT:
                c_dados = new InfoInteiro(this); break;
            case TAG_FLT:
                c_dados = new InfoFloat(this); break;
            case TAG_LNG:
                c_dados = new InfoLong(this); ignora ^= 1; break;
            case TAG_DBL:
                c_dados = new InfoDouble(this); ignora ^= 1; break;
            case TAG_CLAS:
                c_dados = new InfoClasse(this); break;
            case TAG_STR:
                c_dados = new InfoString(this); break;
            case TAG_REF_CMP:
                c_dados = new InfoRefCampo(this); break;
            case TAG_REF_MTD:
                c_dados = new InfoRefCampo(this); break;
            case TAG_REF_MTD_ITF:
                c_dados = new InfoRefMetInterface(this); break;
            case TAG_NOM_TIP:
                c_dados = new InfoNomeTipo(this); break;
            default:
                temp = 0;
        }

        c_dados->decodificar(arq);

        if (ignora){
            cnt++; ignora ^= 1;
        }
    }
}

void TabSimbolo::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');

    if (!(this->tam - 1)){
        std::cout << tabs + "Não há itens na tabela de símbolos" << std::endl;
        return;
    }

    u1 ignora = 0;

    for (int cnt = 0; cnt < this->tam - 1; cnt++){
        u1 tag = this->registros[this->registros.size() - 1].tag;

        InterCPDados *c_dados = this->registros[this->registros.size() - 1].dados;
        std::cout << tabs + "[";
        std::cout << cnt + "] CONSTANT_";

        switch (tag){
            case TAG_UTF:
                std::cout << "Utf8" << std::endl; break;
            case TAG_INT:
                std::cout << "Integer" << std::endl; break;
            case TAG_FLT:
                std::cout << "Float" << std::endl; break;
            case TAG_LNG:
                std::cout << "Long" << std::endl; ignora ^= 1; break;
            case TAG_DBL:
                std::cout << "Double" << std::endl; ignora ^= 1; break;
            case TAG_CLAS:
                std::cout << "Class" << std::endl; break;
            case TAG_STR:
                std::cout << "String" << std::endl; break;
            case TAG_REF_CMP:
                std::cout << "Fieldref" << std::endl; break;
            case TAG_REF_MTD:
                std::cout << "Methodref" << std::endl; break;
            case TAG_REF_MTD_ITF:
                std::cout << "InterfaceMethodref" << std::endl; break;
            case TAG_NOM_TIP:
                std::cout << "NameAndType" << std::endl; break;
            default:
                tag = 0;
        }

        if (tag) c_dados->exibir(qnt_tab + 1);

        if (ignora){
            cnt++; ignora ^= 1;
        }
    }
}

void TabSimbolo::deletar(){
    for (auto &registro: this->registros){
        registro.dados->deletar();
        registro.deletar();
    }

    this->registros.clear();
}
