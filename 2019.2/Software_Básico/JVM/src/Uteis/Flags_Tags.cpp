#include <iostream>
#include <string.h>
#include "../../lib/Uteis/Flags_Tags.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

void exibir_flag(u2 a_verificar){
    char flag[100] = "\0";

    if (a_verificar & FLG_PBC)
        strcat(flag, "pública ");

    if (a_verificar & FLG_PVD)
        strcat(flag, "privada ");

    if (a_verificar & FLG_PTD)
        strcat(flag, "protegida ");

    if (a_verificar & FLG_STC)
        strcat(flag, "estática ");

    if (a_verificar & FLG_FNL)
        strcat(flag, "final ");

    if (a_verificar & FLG_SPR)
        strcat(flag, "super ");

    if (a_verificar & FLG_VLT)
        strcat(flag, "volátil ");

    if (a_verificar & FLG_TST)
        strcat(flag, "transiente ");

    if (a_verificar & FLG_NTV)
        strcat(flag, "nativo ");

    if (a_verificar & FLG_ITF)
        strcat(flag, "interface ");

    if (a_verificar & FLG_ABS)
        strcat(flag, "abstrata ");

    if (a_verificar & FLG_STT)
        strcat(flag, "estrito ");

    if (!strlen(flag))
        std::cout << "Sem expecificação";

    else {
        flag[strlen(flag) - 1] = '\0';
        std::cout << flag;
    }

    std::cout << " [";
    exibir_hex_2(a_verificar);
    std::cout << "]" << std::endl;
}
