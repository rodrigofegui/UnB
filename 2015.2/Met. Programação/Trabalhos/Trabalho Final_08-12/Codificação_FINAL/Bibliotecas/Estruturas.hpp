/*****************************************************************
**  Criadores:
**			Diego Brian Coelho Leite
**          Pedro Aurélio Coelho Almeida
**          Rodrigo Ferreira Guimaraes
**  Nome:
**          Estruturas.hpp
**  Finalidade:
**          Armazenar as funções manipuladoras das estruturas
**			utilizadas nesta bibliota, como:
**              - Impressao da lista de adaptadores;
**              - Impressao da lista de geradores;
**              - Impressao da lista de cidades;
**              - Impressao da lista de interconexoes;
**              - Impressao da lista de posicoes;
**              - Calculo da distancia geometrica entre dois elementos via Teorema de Pitagoras.
*****************************************************************/

/*  Caso não tenha sido declarada na tabela de símbolos */
#ifndef Estrutura_H
    #define Estrutura_H

	/*****************************************************************
    **      Inclusão das bibliotecas auxiliares
    *****************************************************************/
		#include <stdio.h>
		#include <stdlib.h>
		#include <iostream>
		#include <math.h>
    /*****************************************************************
    **      Definicoes de tipos e Namespaces
    *****************************************************************/

		using namespace std;
        typedef struct info Info;
        typedef struct ger Gerador;
        typedef struct ct City;
        typedef struct adp Adaptador;
        typedef struct intercon Conexao;
        typedef struct pos Posicao;

    /*****************************************************************
    **      Definicoes das estruturas
    *****************************************************************/

    /********************************************************
    **	Estrutura:
    **		Info
    **	Descrição:
    **		Estrutura, nomeada como 'Info', responsável
	**		por armazenar todas informações que serao inseridas nas estruturas
	**          que compoem a malha
    **	Campos:
    **      'tipo_info' - informa se a informacao atual e relativa a um gerador, um adaptador, uma interconexao ou a uma cidade
	**		'nome_info' - informa o nome da informacao (fornecida logo apos o seu tipo no arquivo de entrada de dados)
	**		'lin_i' + 'col_i' - informam onde esta o elemento por corrdenadas do tipo (linha,coluna). Para o caso de interconexao, informa onde ela comeca.
	**		'lin_f' + 'col_f' - informam onde esta o elemento por corrdenadas do tipo (linha,coluna). Aplicavel somente para interconexoes.
	**		'cpcd' - informa a capaicade que a interconexao tem para passar energia
	**		'custo' - informa o custo de reparo de um gerador ou interconexao
	**		'falha' - indic a proabilidade de falha de uma interconexao.
	**		'tempo' - indica o tempo necessario para consertar uma interconexao ou um gerador
	**		'enderecoC' - guarda o endereco de memoria do elemento inserido, o qual sera utilizado para ser inserido na estrutura Posicao. Aplicavel somente para cidades.
	**		'enderecoG' - guarda o endereco de memoria do elemento inserido, o qual sera utilizado para ser inserido na estrutura Posicao. Aplicavel somente para geradores.
	**		'enderecoA' - guarda o endereco de memoria do elemento inserido, o qual sera utilizado para ser inserido na estrutura Posicao. Aplicavel somente para adaptadores.
    ********************************************************/

		typedef struct info{
			char tipo_info;
			char nome_info[50];
			int lin_i, col_i;
			int lin_f, col_f;
			int cpcd;
			int custo;
			float falha;
			int tempo;
			City* enderecoC;
			Gerador* enderecoG;
			Adaptador* enderecoA;
		}
		Info;

		typedef struct ger{
			char nome[50];
			int lin_i, col_i;
			int rec, custo;
			struct ger *prox;
		}
		Gerador;

		typedef struct ct{
			char nome[50];
			int lin_i, col_i;
			int rec;
			int recebida;/*! Iniciar como 0*/
			/*! Iniciar com 0 as variaveis t_s_rec, t_30_rec*/
			int t_s_rec, t_30_rec;/*! Vao jogar em cada struct o tempo total que levou para cada elemento*/
			struct ct *prox;
		}
		City;

		typedef struct adp{
			char nome[50];
			int lin_i, col_i,entrada;/*!< entrada eh a energia que entra no adaptador. Iniciar como 0*/
			Conexao *entradas, *saidas;
			struct adp *prox;
		}
		Adaptador;

	/********************************************************
    **	Estrutura:
    **		Conexao
    **	Descrição:
    **		Estrutura, nomeada como 'Conexao', responsável
	**		por armazenar todas informações que serao inseridas nas interconexoes, bem como
	**          indicar as ligacoes que as interconexoes realizam com os outros elementos (adaptadores, cidades e geradores)
    **	Campos que nao pertencem a estruturas Infos:
    **      'tipo_prox' - Informa o tipo do elemento esta ligado ao final da interconexao.
    **      'tipo_ant' -Informa o tipo do elemento esta ligado ao inicio da interconexao.
    **      'status' - Vai registrar se o elemento de interconexao foi verificado.
    **      'prox_c' - Vai registrar o elemento se que liga ao final da interconexao
    **          caso ele seja uma cidade.
    **      'ant_c' - Vai registrar o elemento se que liga ao inicio da interconexao
    **          caso ele seja uma cidade.
	**		'prox_g' - Vai registrar o elemento se que liga ao final da interconexao
    **          caso ele seja um gerador.
	**		'ant_g' - Vai registrar o elemento se que liga ao inicio da interconexao
    **          caso ele seja um gerador.
	**		'prox_a' - Vai registrar o elemento se que liga ao final da interconexao
    **          caso ele seja um adaptador.
	**		'ant_a' - Vai registrar o elemento se que liga ao inicio da interconexao
    **          caso ele seja um adaptador.

    ********************************************************/

		typedef struct intercon{
			char tipo_atual,tipo_ant,tipo_prox;/*!< Vai registrar qual eh o elementos que liga atars, qual que liga na frente e qual e o atual. */
			char nome[50];
			int lin_i, col_i;
			int lin_f, col_f;
			int cpc;/*!< Capacidade de energia*/

			float prob_falha;
			int temp,comeco,custo;/*!< A variavel "comeco" vai registrar o inicio da falha*/
			int ordem;/*!< Vai registrar a ordem em que os elementos foram inseridos na lista. */
			int status;/*!< Vai registrar se o elemento de interconexao foi verificado.Iniciar como 0 */
			struct intercon *prox_i, *proxima;
			City *prox_c,*ant_c;
			Gerador *prox_g,*ant_g;
			Adaptador *prox_a,*ant_a;
		}
		Conexao;


	/********************************************************
    **	Estrutura:
    **		Posicoes
    **	Descrição:
    **		Estrutura, nomeada como 'Posicoes', responsável
	**		por armazenar todas as posicoes (geograficas e em memoria do dispositivo) dos geradores, adaptadores e cidades
	**      lidos no arquivo de entrada
    **	Campos que nao pertencem a estruturas Infos:
    **      'x' + 'y' - posicoes geograficas dos elementos.
    **      'tipo' - vai armazenar a informacao sobre o elemento ser um gerador, uma ciade ou um adapatdor.
    **      'status' - Vai registrar se o elemento de interconexao foi verificado.
    **      'gera' - aramazena o endereco de memoria de onde esta o gerador inserido. Aplicavel somente a geradores.
    ** 		'adapt' - aramazena o endereco de memoria de onde esta o adaptador inserido. Aplicavel somente a adaptadores.
    **      'cid' - aramazena o endereco de memoria de onde esta a cidade inserido. Aplicavel somente a cidades.


    ********************************************************/

		typedef struct pos{/*!< Vai registrar a posicao em que os geradores, adaptadores e cidades estao, para simplificar a ligacao das interconexoes. */
			int x,y;
			char tipo;
			struct pos *prox;
            struct ger *gera;
            struct adp *adapt;
            struct ct *cid;
		}
		Posicoes;

	/*****************************************************************
    **      Cabecalhos das estruturas
    *****************************************************************/

		typedef struct h_ger{
			Gerador *inicio;
			int qnt;
			int rec, custo;
		}
		Header_ger;

		typedef struct h_ct{
			City *inicio;
			int qnt;
			int rec;
			int ct_insuf;//quantiade de cidades com menos recurso que o especificado no .txt
			int t_s_recurso;
			int menos_30_recurso;//quantiade de cidades com menos que 30% recurso que o especificado no .txt
			int t_m_30_rec;
		}
		Header_city;

		typedef struct h_inter{
			Adaptador *inicio;
			int qnt;
		}
		Header_adap;

		struct c_inter{
			Conexao *inic;
			int custo_tot;
			int tam_tot,temp_tot_falha,total,total_falhas;
		};
		typedef struct c_inter Cabecalho_conex;

		typedef struct rede{
			Header_ger *in_ger;
			Header_adap *in_adap;
			Header_city *in_city;
			Cabecalho_conex *in_conex;
			Posicoes *inicio;

		}
		Rede;

	/*****************************************************************
    **      Cabeçalho das Funções
    *****************************************************************/

		/********************************************************
		**	Função:
		**		Impressao da lista de adaptadores
		**	Descrição:
		**
		**	Parâmetros:
		**		Ponteiro para o inicio da lista de adaptadores
		**	Assertivas de entrada:
		**
		**  Assertivas de controle:
        **
		**	Valor retornado:
		**		Nao existe
		**	Assertivas de saida:
		**
		********************************************************/

        void adaptador_imprime (Adaptador*);

		/********************************************************
		**	Função:
		**		Impressao da lista de geradores
		**	Descrição:
		**
		**	Parâmetros:
		**		Ponteiro para o inicio da lista de geradores
		**	Assertivas de entrada:
		**
		**  Assertivas de controle:
        **
		**	Valor retornado:
		**		Nao existe
		**	Assertivas de saida:
		**
		********************************************************/

        void gerador_imprime (Gerador*);

		/********************************************************
		**	Função:
		**		Impressao da lista de cidades
		**	Descrição:
		**
		**	Parâmetros:
		**		Ponteiro para o inicio da lista de cidades
		**	Assertivas de entrada:
		**
		**  Assertivas de controle:
        **
		**	Valor retornado:
		**		Nao existe
		**	Assertivas de saida:
		**
		********************************************************/

        void cidade_imprime (City*);

		/********************************************************
		**	Função:
		**		Impressao da lista de interconexoes
		**	Descrição:
		**
		**	Parâmetros:
		**		Ponteiro para o inicio da lista de interconexoes
		**	Assertivas de entrada:
		**
		**  Assertivas de controle:
        **
		**	Valor retornado:
		**		Nao existe
		**	Assertivas de saida:
		**
		********************************************************/

        void interconex_imprime (Conexao*);

		/********************************************************
		**	Função:
		**		Impressao da lista de posicoes
		**	Descrição:
		**
		**	Parâmetros:
		**		Ponteiro para o inicio da lista de posicoes
		**	Assertivas de entrada:
		**
		**  Assertivas de controle:
        **
		**	Valor retornado:
		**		Nao existe
		**	Assertivas de saida:
		**
		********************************************************/

        void pos_imprime (Posicoes*);

        /********************************************************
		**	Função:
		**		Calcular a distancia euclidana entre dois pontos (atraves do Teorema de Pitagoras)
		**	Descrição:
		**
		**	Parâmetros:
		**		Estrutura do tipo Info
		**	Assertivas de entrada:
		**
		**  Assertivas de controle:
        **
		**	Valor retornado:
		**		inteiro contendo a distancia entre os pontos
		**	Assertivas de saida:
		**
		********************************************************/


        int pitagoras (Info);

#endif
