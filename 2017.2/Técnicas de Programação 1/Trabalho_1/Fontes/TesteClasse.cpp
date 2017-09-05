#include "../Bibliotecas/TesteClasse.hpp"

bool TesteClasse::executar(){
    inicializar();

    validar();

    finalizar();

    return status;
}
