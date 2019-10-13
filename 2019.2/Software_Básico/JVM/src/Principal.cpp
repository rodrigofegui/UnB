#include <iostream>
#include <vector>
#include "../lib/Tipos/ArqClass.hpp"
#include "../lib/Uteis/Arquivos.hpp"
#include "../lib/Uteis/Parametros.hpp"


int main(int argc, char *argv[]){
    Parametros param;

    param.get_entradas(argc, argv);

    std::vector<ArqClass> arqs_class;

    for (auto &nome_arq : param.nome_arqs){
        arqs_class.push_back(ArqClass(nome_arq));

        arqs_class[arqs_class.size() - 1].decodificar();
    }

    if (param.e_leitura()){
        for (auto &arq_class : arqs_class){
            arq_class.exibir();
            arq_class.deletar();
        }
    } else{
        std::cout << "operando como interpretador" << std::endl;

        for (auto &arq_class : arqs_class){
            arq_class.deletar();
        }
    }

    ArqClass::executar();

    std::vector<ArqClass>().swap(arqs_class);

    param.deletar();

    return 0;
}
