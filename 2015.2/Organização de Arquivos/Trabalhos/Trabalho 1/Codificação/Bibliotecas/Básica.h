#ifndef Basica_H
    /*****************************************************************
    **  Criador:
    **          Rodrigo Ferreira Guimaraes
    **  Nome:
    **          Básica.h
    **  Finalidade:
    **          Armazenar as funções básicas utilizadas por várias
    **          outras funções mais especializadas:
    **              - Abertura de arquivo;
    **              - Apresentação do projeto;
    **              - Leitura de resposta binária;
    **              - Limpa tela;
    **              - Pausas na execução:
    **                  + Por Enter;
    **                  + Por Tempo;
    **              - Tratamento de strings:
    **                  + Comparação de n caracteres;
    **                  + Concatenação de n caracteres;
    **                  + N-última ocorrência de um caractere;
    **                  + Configuração de n caracteres para '\0'.
    *****************************************************************/

    /** Definição da Biblioteca na Tabela de Símbolos **/
        #define Basica_H

    /**  Inclusão das bibliotecas requisitadas: **/
        #include <time.h>
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

    /**  Definição de constantes **/
        /*  'VERDADE' define o estado verdadeiro para as operações binárias */
        #define VERDADE 'V'
        /*  'FALSO' define o estado verdadeiro para as operações binárias */
        #define FALSO 'F'

    /**  Protótipos das funções da biblioteca **/
        /*  Função 'inicio_geral', apresentação breve do projeto */
        char inicio_geral ();

        /*  Função 'ler_simounao', verifica resposta positiva ou não */
        char ler_simounao ();

        /*  Função 'limpa_tela', limpa o terminal de execução */
        void limpa_tela();

        /*  Função 'pausa', realiza uma pausa por ENTER no processamento */
        void pausa ();

        /*  Função 'string_compara_n', compra duas strings */
        int string_compara_n (char *, char *, int, int, int);

        /*  Função 'string_concat_n', concatena strings, a partir de um ponto ate outro */
        void string_concat_n (char *, char *, int, int);

        /*  Função 'string_n_ult_ocorrencia', descobre a n-ultima ocorrencia de um caracter numa string */
        int string_n_ult_ocorrencia (char *, char, int);

        /*  Função 'string_zera', anula os caracteres de uma string, de um ponto a outro */
        void string_zera (char *, int, int);

        /*  Função 'temporizador', realiza uma pausa por TEMPO no processamento */
        void temporizador (float);

#endif // Basica_H
