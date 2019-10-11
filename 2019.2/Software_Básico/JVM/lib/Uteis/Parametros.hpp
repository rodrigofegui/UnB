#ifndef UTEIS_PARAMETROS_HPP
    #define UTEIS_PARAMETROS_HPP

    /**
     *  @file   Parametros.hpp
     *  @author Rodrigo F. Guimarães
     *  @brief  Verificação dos parâmetros para a execução deste projeto
     */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Status.hpp"
    #include "../Tipos/Basicos.hpp"

    /** Controles dos parâmetros */
    #define DELIMITADOR_ARGS    ","
    #define TIPO_ARQ_ACEITO     ".class"

    /**
     *  Verifica os parâmetros passados via linha de comando
     *  @param argc Quantidade de parâmetros
     *  @param argv Argumentos
     *  @return Caso não tenha acontecido algum erro, retorna a flag se é para leitura
     *  ou interpretação
     */
    u1 check_parametros (int argc, char *argv[]);
    u1 check_qnt_args(int argc);
#endif
