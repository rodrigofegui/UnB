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


    #define DEGTORAD(deg) (deg * (180.0f/M_PI))
    #define DOT 46

    /*****************************************************************
    **      Inclusão das bibliotecas auxiliares
    *****************************************************************/
    #include <stdio.h>
    #include <stdlib.h>
//    #include <ncurses.h>
    #include <math.h>
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
    /* Funções de interface grafica */
    /* Desenha um círuclo na tela */
    void circulo (int, int, int, char);
    /* Desenha um ciruclo */
    void triangulo (int, int, int, char);
    /* Desenha um triangulo */
    void retangulo (int, int, int, int, char);
    /* Escreve um texto */
    void texto (int, int, char *);
    /* Desenha uma linha */
    void linha( int, int, int, int);
    /* Desenha a interface completa na tela */
    void interface_cria (Rede*);



#endif
