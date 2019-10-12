#include <iomanip>
#include <iostream>
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"


u1 TabSimbolos::decodificar (FILE *const arq){
    int tam = *this->tam;
    if (!tam) return 2;

    u1 temp, ignora = 0, tem_main = 0;

    for (int cnt = 0; cnt < tam - 1; cnt++){
        ler_u1(arq, &temp);

        InterCPDado *c_dados = nullptr;

        switch (temp){
            case TAG_UTF:           c_dados = new InfoUTF8(this); break;
            case TAG_INT:           c_dados = new InfoInteiro(this); break;
            case TAG_FLT:           c_dados = new InfoFloat(this); break;
            case TAG_LNG:           c_dados = new InfoLong(this); ignora = 1; break;
            case TAG_DBL:           c_dados = new InfoDouble(this); ignora = 1; break;
            case TAG_CLAS:          c_dados = new InfoClasse(this); break;
            case TAG_STR:           c_dados = new InfoString(this); break;
            case TAG_REF_CMP:       c_dados = new InfoRefCampo(this); break;
            case TAG_REF_MTD:       c_dados = new InfoRefMetodo(this); break;
            case TAG_REF_MTD_ITF:   c_dados = new InfoRefMetInterface(this); break;
            case TAG_NOM_TIP:       c_dados = new InfoNomeTipo(this); break;
        }

        if (c_dados)
            c_dados->decodificar(arq);

        if (ignora){
            cnt++;
            ignora = 0;
        }

        if (dynamic_cast<InfoUTF8*>(c_dados)
                && !(dynamic_cast<InfoUTF8*>(c_dados))->get_string().compare("main"))
            tem_main = 1;

        this->registros.push_back(c_dados);
    }

    return tem_main;
}

void TabSimbolos::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');
    int tam = *this->tam;

    if (!tam){
        std::cout << tabs + "Não há itens na tabela de símbolos" << std::endl;
        return;
    }

    u1 padding = get_padding(tam);

    for (int cnt = 0; cnt < tam - 1; cnt++){
        std::cout << tabs + "[";
        std::cout << std::setfill('0') << std::setw(padding) << cnt + 1;
        std::cout << "] ";

        if (this->registros[cnt])
            this->registros[cnt]->exibir(qnt_tabs + 1);
        else
            std::cout << "Extensão de número largo" << std::endl;
    }
}

std::string TabSimbolos::get_string (u2 ind_nome){
    if (!this->tam) return "";

    if (ind_nome == 0 || (ind_nome > *this->tam)) return "";

    ind_nome--;

    InterCPDado *c_dados = this->registros[ind_nome];

    if (dynamic_cast<InfoUTF8*>(c_dados))
        return (dynamic_cast<InfoUTF8*>(c_dados))->get_string();

    if (dynamic_cast<InfoClasse*>(c_dados)){
        return get_string((dynamic_cast<InfoClasse*>(c_dados))->ind_nome);
    }

    if (dynamic_cast<InfoNomeTipo*>(c_dados)){
        return get_string((dynamic_cast<InfoNomeTipo*>(c_dados))->ind_nome)
                + " : " + get_string((dynamic_cast<InfoNomeTipo*>(c_dados))->ind_descritor);
    }

    return "";
}

void TabSimbolos::deletar (){
    for (auto &registro: this->registros)
        registro->deletar();

    std::vector<InterCPDado*>().swap(this->registros);

    delete this;
}
