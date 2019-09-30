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
        for (int cnt = 0; cnt < arqs_class.size(); cnt++){
            arqs_class[cnt].exibir();
            arqs_class[cnt].reset();
        }
    } else{
        std::cout << "operando como interpretador" << std::endl;

        for (int cnt = 0; cnt < arqs_class.size(); cnt++){
            arqs_class[cnt].reset();
        }
    }

    return 0;
}
