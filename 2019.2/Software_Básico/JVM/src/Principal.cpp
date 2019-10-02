#include <iostream>
#include <vector>
#include "../lib/Tipos/ArqClass.hpp"
#include "../lib/Uteis/Parametros.hpp"


int main(int argc, char *argv[]){
    u1 e_leitura = check_parametros(argc, argv);

    std::vector<ArqClass> arqs_class;

    char *temp = strtok(argv[2], DELIMITADOR_ARGS);

    while(temp){
        arqs_class.push_back(ArqClass(temp));

        arqs_class[arqs_class.size() - 1].decodificar();

        temp = strtok(NULL, DELIMITADOR_ARGS);
    }

    if (e_leitura){
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

    std::vector<ArqClass>().swap(arqs_class);

    return 0;
}
