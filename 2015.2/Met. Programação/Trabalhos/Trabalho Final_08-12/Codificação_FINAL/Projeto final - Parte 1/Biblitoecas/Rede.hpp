/*****************************************************************
**  Criadores:
**          Diego Brian COelho Leite
**          Pedro Aurélio Coelho Almeida
**          Rodrigo Ferreira Guimaraes
**  Nome:
**          Rede.hpp
**  Finalidade:
**          Armazenar as funções utilizadas para a criação das
**          estruturas em forma de grafo, tais como:
**              - Criação da rede;
**              - Inicialização:
**                  + Lista de geradores;
**                  + Lista de adaptadores;
**                  + Lista de cidades;
**                  + Lista de interconexões;
**              - Desalocação da rede:
*****************************************************************/

/*  Caso não tenha sido declarada na tabela de símbolos */
#ifndef Rede_h
    #define Rede_h

    /*****************************************************************
    **      Inclusão das bibliotecas auxiliares
    *****************************************************************/
    #include <stdio.h>
    #include <stdlib.h>
    #include "Estruturas.hpp"

    /*****************************************************************
    **      Cabeçalho das Funções
    *****************************************************************/
    /* Cria uma estrutura de rede */
    Rede * rede_cria (void);
    /* Desaloca o espaço de memoria de uma estrutura de rede */
    void rede_libera (Rede *);
    /* Inicializa a estrutura de cabeçalho da lista de adaptadores */
    Header_adap* adaptador_inicio (Header_adap*);
    /* Inicializa a estrutura de cabeçalho da lista de cidades */
    Header_city* cidade_inicio (Header_city*);
    /* Inicializa a estrutura de cabeçalho da lista de geradores */
    Header_ger* gerador_inicio (Header_ger*);
    /* Inicializa a estrutura de cabeçalho da lista de interconexoes */
    Cabecalho_conex* interconex_inicio (Cabecalho_conex*);

#endif
