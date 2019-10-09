#include <iomanip>
#include <iostream>
#include <typeinfo>
#include "../../lib/Tabelas/TabSimbolo.hpp"
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"


void TabSimbolo::decodificar(FILE *arq){
    int tam = *this->tam;
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
                c_dados.dados = new InfoLong(this); ignora = 1; break;
            case TAG_DBL:
                c_dados.dados = new InfoDouble(this); ignora = 1; break;
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
        }

        if (c_dados.dados)
            c_dados.dados->decodificar(arq);

        this->registros.push_back(c_dados);

        if (ignora){
            this->registros.push_back(CPInfo());
            cnt++;
            ignora = 0;
        }
    }
}

void TabSimbolo::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');
    int tam = *(this->tam) - 1;

    if (!tam){
        std::cout << tabs + "Não há itens na tabela de símbolos" << std::endl;
        return;
    }

    std::cout << tabs << this->registros.size() << " e " << *this->tam << std::endl;

    u1 padding = get_padding(tam);

    for (int cnt = 0; cnt < tam; cnt++){
        std::cout << tabs + "[";
        std::cout << std::setfill('0') << std::setw(padding) << cnt + 1;
        std::cout << "] ";

        this->registros[cnt].exibir(qnt_tabs + 1);
    }
}

std::string TabSimbolo::get_nome (u2 ind_nome){
    if (!this->tam) return "";

    if (ind_nome == 0 || (ind_nome > *this->tam)) return "";

    ind_nome--;

    InterCPDados *c_cpdados = this->registros[ind_nome].dados;

    if (dynamic_cast<InfoUTF8*>(c_cpdados))
        return (dynamic_cast<InfoUTF8*>(c_cpdados))->get_utf8();

    if (dynamic_cast<InfoClasse*>(c_cpdados)){
        return get_nome((dynamic_cast<InfoClasse*>(c_cpdados))->ind_nome);
    }

    if (dynamic_cast<InfoNomeTipo*>(c_cpdados)){
        return get_nome((dynamic_cast<InfoNomeTipo*>(c_cpdados))->ind_nome)
                + " : " + get_nome((dynamic_cast<InfoNomeTipo*>(c_cpdados))->ind_descritor);
    }

    return "";
}

void TabSimbolo::deletar(){
    for (auto &registro: this->registros){
        registro.deletar();
    }

    std::vector<CPInfo>().swap(this->registros);

    delete this;
}
