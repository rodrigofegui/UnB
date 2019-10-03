#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "../../lib/Interfaces/InterTabela.hpp"
#include "../../lib/Uteis/Erros.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void InterTabela::erro(u1 e_codigo){
    printf("[ERRO] ");

    switch (e_codigo){
        case E_ALOCAR:
            printf("Falha ao alocar os registros para tabela\n"); break;
        default:
            printf("Não especificado\n");
    }

    this->deletar();
    exit(e_codigo);
}
