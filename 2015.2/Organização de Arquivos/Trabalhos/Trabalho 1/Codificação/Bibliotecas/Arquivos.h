#ifndef Arquivos_H
    /*****************************************************************
    **  Criador:
    **          Rodrigo Ferreira Guimaraes
    **  Nome:
    **          Arquivos.h
    **  Finalidade:
    **          Armazenar as funções manipuladoras de arquivos.
    *****************************************************************/

    /** Definição da Biblioteca na Tabela de Símbolos **/
        #define Arquivos_H

    /**  Inclusão das bibliotecas requisitadas: **/
        #include "Básica.h"
        #include "Lista.h"

    /*****************************************************************
	**	Constantes GLOBAIS:
	**		'ESPACO'    - define o caracter espaço;
	**      'ENTER'     - define o caracter enter;
	**      'TAB1'      - define o caracter tab;
	**      'TAB2'      - define o caracter tab especial;
	**      'FIM'       - define o caracter fim de arquivo;
	*****************************************************************/
        #define ESPACO 32
        #define ENTER 13
        #define TAB1 '\t'
        #define TAB2 '\r'
        #define FIM -1

    /**  Protótipos das funções da biblioteca **/
        /*  Função 'arq_abre', abre um arquivo lógico */
        FILE * arq_abre (char *, char *, char);

        /*  Função 'arq_le', realiza a leitura do arquivo lógico
        **  armazenando o resultado na lista de preferência */
        void arq_le (FILE *, Lista *);

#endif // Arquivos_h
