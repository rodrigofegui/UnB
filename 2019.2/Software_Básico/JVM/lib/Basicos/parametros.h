#ifndef BASICO_PARAMETROS_H
    #define BASICO_PARAMETROS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "erros.h"
    #include "tipos.h"

    #define DELIMITADOR_ARGS    ","
    #define TIPO_ARQ_ACEITO     ".class"

    u1 check_parametros(int argc, char *argv[]);

#endif
