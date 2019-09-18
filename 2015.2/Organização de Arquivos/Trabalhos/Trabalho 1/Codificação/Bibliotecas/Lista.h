#ifndef Lista_H
    /*****************************************************************
    **  Criador:
    **          Rodrigo Ferreira Guimaraes
    **  Nome:
    **          Lista.h
    **  Finalidade:
    **          Armazenar as funções manipuladoras das listas
    *****************************************************************/

    /** Definição da Biblioteca na Tabela de Símbolos **/
        #define Lista_H

    /**  Inclusão das bibliotecas requisitadas: **/
        #include "Básica.h"
        #include <stdio.h>
        #include <stdlib.h>

    /*****************************************************************
	**	Constantes GLOBAIS:
	**		'TAM_SIGLA_CURSO'   - define o tamanho da sigla do curso;
	**      'TAM_MAX'           - define o tamanho da leitura das
	**                            informações;
	**      'RETORNO_OK'        - define uma condição de retorno
	**                            positiva;
	**      'TAM_CHAVE_PRI'     - define o tamanho da chave primaria;
	*****************************************************************/
	#define TAM_SIGLA_CURSO 3
	#define TAM_MAX 50
	#define RETORNO_OK 1
	#define TAM_CHAVE_PRI 15

    /** Definições das estruturas utilizadas **/
    typedef struct reg{
        int Matricula;
        char Nome[TAM_MAX];
        int OP;
        char Curso[TAM_SIGLA_CURSO];
        char Turma;
    }
    Registros;
    typedef struct aluno{
        int docseek;
        Registros Dados;
        struct aluno *anterior, *proximo;
    }
    Aluno;
    typedef struct lista{
        int quant;
        Aluno *primeiro, *ultimo;
    }
    Lista;

    typedef struct _indpri{
        char chave[TAM_CHAVE_PRI];
        int docseek;
        char status;
        Registros *infos;
        struct _indpri *anterior, *proximo;
    }
    Elempri;
    typedef struct indpri{
        int quant;
        Elempri *inicio, *fim;
    }
    IndicePrimario;


    typedef struct inter{
        Elempri *chave;
        struct inter *proximo;
    }
    Intermediario;
    typedef struct _indsec{
        Intermediario *inicio;
        char curso[TAM_SIGLA_CURSO];
        struct _indsec *proximo;
    }
    Elemsec;
    typedef struct indsec{
        int quant;
        Elemsec *inicio;
    }
    IndiceSecundario;



    /**  Protótipos das funções da biblioteca **/
    /*  Função 'lista_cria', realiza a alocação de memória para a lista
    **  a ser manipulada */
    Lista * lista_cria ();

    /*  Função 'aluno_cria', realiza a alocação de memória para os dados
    **  de um novo aluno */
    Aluno * aluno_cria (Registros, int);

    /*  Função 'indpri_cria', realiza a alocação de memória para o indice
    **  primario */
    IndicePrimario * indpri_cria (Lista *);

    /*  Função 'elempri_cria', realiza a alocação de memria para um elemento
    **  do elemento do indice primario */
    Elempri * elempri_cria (Aluno *);

    /*  Funçao 'indsec_cria', realiza a alocação de memoria para o indice
    **  secundario */
    IndiceSecundario * indsec_cria (IndicePrimario *);

    Elemsec * elemsec_cria ();

    Intermediario * inter_cria ();
    /*  Função 'lista_libera', realiza a liberação da memória alocada para
    **  a lista */
    void lista_libera (Lista *);

    /*  Função 'aluno_libera', realiza a liberação da memória alocada para
    **  um aluno */
    void aluno_libera (Aluno *);

    /*  Função 'indpri_libera', realiza a liberação da memória alocada para
    **  o indice primario */
    void indpri_libera (IndicePrimario *);

    void indsec_libera (IndiceSecundario *);

    /*  Funçao 'lista_insere', realiza a inserção de um novo registro na lista
    **  de alunos */
    void lista_insere (Lista *, Registros, int);

    void lista_manipula (Lista *, Registros, Registros, char);

    /*  Função 'indpri_monta', realiza a montagem do indice primario */
    void indpri_monta (IndicePrimario *, Lista *);

/*  Função 'indsec_monta', realiza a montagem do indice secundario */
    void indsec_monta (IndiceSecundario *, IndicePrimario *);

    /*  Função 'indpri_ordena', realiza a ordenação do indice primario */
    void indpri_ordena (IndicePrimario *);

    /*  Função 'lista_exibe', realiza a exibição da lista formada */
    void lista_exibe (Lista *);

    /*  Função 'indpri_exibe', realiza a exibiçao do indice primario */
    void indpri_exibe (IndicePrimario *);

    void indsec_exibe (IndiceSecundario *indicesec);

    /*  Função 'indpri_escreve', realiza a escrita do indice primario num arquivo */
    void indpri_escreve (IndicePrimario *, char);

    void indsec_escreve (IndiceSecundario *, char);

    void lista_escreve (FILE *, Lista *);

    void lista_merge (FILE *, IndicePrimario *, IndicePrimario *);

    void reg_escreve (FILE *, Registros);
    /*  Função 'reg_vazio', verifica se o registro está vazio */
    int reg_vazio (Registros);

    /*  Função 'reg_zera', realiza a limpeza dos dados de um dado aluno */
    void reg_zera (Registros *);

#endif // Lista_H
