#include "../Bibliotecas_Tst/TesteClasse.hpp"

bool TesteClasse::executar(){
    inicializar();

    validar();

    finalizar();

    return status;
}
