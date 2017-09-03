#include "../Bibliotecas/TesteClasse.hpp"

bool TesteClasse::executar(){
    inicializar();

    validar();

    finalizar();

    if(status)
        cout << "APROVADO!" << endl << endl;
    else cout << "REPROVADO!" << endl << endl;

    return status;
}
