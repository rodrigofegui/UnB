/*****************************************************************
**  Criadores:
**          Diego Brian COelho Leite
**          Pedro Aurélio Coelho Almeida
**          Rodrigo Ferreira Guimaraes
**  Nome:
**          Arquivos.hpp
**  Finalidade:
**          Armazenar as funções utilizadas para a leitura do arquivo
**          txt e inserção em listas encadeadas, tais como:
**              - Inserção em lista de geradores;
**              - Inserção em lista de cidades;
**              - Inserção em lista de adaptadores;
**              - Inserção em lista de geradores;
**
*****************************************************************/

/*  Caso não tenha sido declarada na tabela de símbolos */
#ifndef Arquivo_h
    #define Arquivo_h

    /*****************************************************************
    **      Inclusão das bibliotecas auxiliares
    *****************************************************************/
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "Basica.hpp"
    #include "Estruturas.hpp"

    /* Lê o arquivo txt base e gera as listas com os elementos contidos */
    Rede* arq_ler (Rede *);
    /* Insere elemento lido na lista de adaptadores */
    Adaptador* adaptador_insere (Adaptador*, Info);
    /* Insere elemento lido na lista de geradores */
    Gerador* gerador_insere (Gerador*, Info);
    /* Insere elemento lido na lista de cidades */
    City* city_insere (City*, Info);
    /* Insere elemento lido na lista de interconexoes */
    Conexao* conexao_insere(Conexao*, Info);
    /* Insere elemento lido na lista de posições */
    Posicoes* pos_insere(Posicoes*, Info);

#endif
