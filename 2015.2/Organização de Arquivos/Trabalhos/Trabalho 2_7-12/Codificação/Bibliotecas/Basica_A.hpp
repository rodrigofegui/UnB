/*****************************************************************
**  Criadores:
**          Pedro Aurélio Coelho Almeida
**          Rodrigo Ferreira Guimarães
**  Nome:
**          Basica.hpp
**  Finalidade:
**          Armazenar as funções básicas utilizadas por várias
**          outras funções mais especializadas:
**              - Abertura de arquivo;
**              - Leitura de resposta binária;
**              - Leitura de resposta numérica num intervalo;
**              - Limpa tela;
**              - Pausas na execução:
**                  + Por Enter;
**                  + Por Tempo;
**              - Tratamento de strings:
**                  + Comparação de n caracteres;
**                  + Concatenação de n caracteres;
**                  + N-última ocorrência de um caractere.
*****************************************************************/

/*  Caso não tenha sido declarada na tabela de símbolos */
#ifndef Basica_A_h
    #define Basica_A_h

    /*****************************************************************
    **      Inclusão das bibliotecas auxiliares
    *****************************************************************/
        #include <string>
        #include <time.h>
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>


    /*****************************************************************
    **      Constantes Globais e Namespaces
    *****************************************************************/
        /*  'VERDADE' define o estado verdadeiro para as operações binárias */
            #define VERDADE 1
        /*  'ESPACO' define o caracter espaço */
            #define ESPACO 32
        using namespace std;


    /*****************************************************************
    **      Cabeçalho das Funções
    *****************************************************************/
        /*  Função 'arq_abre', abre um arquivo lógico */
        FILE * arq_abre (char *, string, char);

        /*  Função 'ler_simounao', verifica resposta positiva ou não */
        bool ler_simounao ();

        /*  Função 'ler_intervalo', verifica resposta positiva ou não */
        int ler_intervalo (int, int);

        /*  Função 'limpa_tela', limpa o terminal de execução */
        void limpa_tela();

        /*  Função 'pausa', realiza uma pausa por ENTER no processamento */
        void pausa ();

        /*  Função 'temporizador', realiza uma pausa por TEMPO no processamento */
        void temporizador (float);

        /*  Função 'string_compara_n', compra duas strings */
        int string_compara_n (char *, char *, int, int, int);

        /*  Função 'string_completa', realiza a configuração dos caracteres desejados para um caracter
        **  escolhido */
        void string_completa (char *, char, int, int);

        /*  Função 'string_concat_n', concatena strings, a partir de um ponto ate outro */
        void string_concat_n (char *, char *, int, int);

        /*  Função 'string_n_ult_ocorrencia', descobre a n-ultima ocorrencia de um caracter numa string */
        int string_n_ult_ocorrencia (string, char, int);

        /*  Função 'string_zera', realiza a inicialização dos caracteres desejados para um caracter
        **  nulo, '\0' */
        void string_zera (char *, int, int);

#endif// Basica_H
