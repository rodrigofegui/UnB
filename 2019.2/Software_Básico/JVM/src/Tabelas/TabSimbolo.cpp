#include <iomanip>
#include <iostream>
#include <string>
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void TabSimbolo::decodificar(FILE *arq){
    int tam = *(this->tam) - 1;
    if (!tam) return;

    u1 temp, ignora = 0;

    for (int cnt = 0; cnt < tam; cnt++){
        ler_u1(arq, &temp);

        CPInfo c_dados(temp);

        switch (temp){
            case TAG_UTF:
                c_dados.dados = new InfoUTF8(this); break;
            case TAG_INT:
                c_dados.dados = new InfoInteiro(this); break;
            case TAG_FLT:
                c_dados.dados = new InfoFloat(this); break;
            case TAG_LNG:
                c_dados.dados = new InfoLong(this); break;
            case TAG_DBL:
                c_dados.dados = new InfoDouble(this); break;
            case TAG_CLAS:
                c_dados.dados = new InfoClasse(this); break;
            case TAG_STR:
                c_dados.dados = new InfoString(this); break;
            case TAG_REF_CMP:
                c_dados.dados = new InfoRefCampo(this); break;
            case TAG_REF_MTD:
                c_dados.dados = new InfoRefMetodo(this); break;
            case TAG_REF_MTD_ITF:
                c_dados.dados = new InfoRefMetInterface(this); break;
            case TAG_NOM_TIP:
                c_dados.dados = new InfoNomeTipo(this); break;
            default:
                temp = 0;
        }

        if (temp)
            c_dados.dados->decodificar(arq);
        else
            c_dados.tag = temp;

        this->registros.push_back(c_dados);
    }
}

void TabSimbolo::exibir(int qnt_tab){
    std::string tabs(qnt_tab, '\t');
    int tam = *(this->tam) - 1;

    if (!tam){
        std::cout << tabs + "Não há itens na tabela de símbolos" << std::endl;
        return;
    }

    u1 padding = get_padding(tam);

    for (int cnt = 0; cnt < tam; cnt++){
        u1 tag = this->registros[cnt].tag;

        std::cout << tabs + "[";
        std::cout << std::setfill('0') << std::setw(padding) << cnt + 1;
        std::cout << "] ";

        this->registros[cnt].exibir(qnt_tab + 1);
    }
}

void TabSimbolo::deletar(){
    for (auto &registro: this->registros){
        registro.deletar();
    }

    std::vector<CPInfo>().swap(this->registros);

    delete this;
}
