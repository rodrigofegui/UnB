/*  Descritivo das funções para andamento do Projeto */

/*  Bibliotecas requisitada */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes.h"

/*  Lista das funcoes de manipulacao */

/*  Funcao 'cria_historico', aloca espaco para o Historico e inicializa suas variaveis
**  de controle */
Historico *cria_historico (){
    /*  'novo' armazena o espaco alocado para o Historico */
    Historico *novo;

    /* Enquanto der erro na alocacao */
    do{
        novo = (Historico *) malloc (sizeof(Historico));

        /*  Dando erro na alocacao */
        if (novo == NULL)   printf ("ERRO CRIACAO DO HISTORICO\n");

    }while (novo == NULL);

    /*  Inicializacao das variaveis de controle */
    novo->topo = novo->base =  NULL;
    novo->quant = 0;

    return novo;
}

/*  Funcao 'cria_elemento', aloca espaco para um elemento a ser inserido no Historico */
Elemento * cria_elemento (){
    /*  'novo' armazena o espaco alocado para um elemento; 'ind' armazena o indice
    **  a ser utilizado na simplificacao da inicializacao */
    Elemento *novo;
    char ind;

    /*  Enquanto der erro na alocacao */
    do{
        novo = (Elemento *) malloc (sizeof(Elemento));

        /*  Dando erro na alocacao */
        if (novo == NULL)   printf ("ERRO CRIACAO DE UM ELEMENTO\n");

    }while (novo == NULL);

    /* Inicializacao das variaveis de controle */
    novo->numero = 0;
    for (ind = 65; ind < 69; ind++)
        novo->pcardeais[ind - 65] = 'L';
    novo->prox = novo->ante = NULL;

    return novo;
}

Ponto * cria_ponto (){
    Ponto *novo;

    /*  Enquanto der erro na alocacao */
    do{
        novo = (Ponto *) malloc (sizeof(Ponto));

        /*  Dando erro na alocacao */
        if (novo == NULL)   printf ("ERRO CRIACAO DE UM PONTO\n");

    }while (novo == NULL);

    novo->coluna = novo->linha = '\0';
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

/*  Criacao do Tabuleiro a ser realizado o Jogo */
int ** cria_tabuleiro (int tam){
    /*  'tam' armazena o tamanho dos lados que o tabuleiro deve ter; 'tabuleiro' armazena
    **  o tabuleiro que sera criado; 'lin' armazena a linha a ser alocada */
    int **tabuleiro, lin;

    /*  Enquanto nao houver exito na primeira alocacao do tabuleiro */
    do{
        tabuleiro = (int **) malloc (tam * sizeof(int *));

        /*  Havendo linhas alocadas, resta as colunas */
        if(tabuleiro != NULL){
            for (lin = 0; lin < tam; lin++){

                /*  Enquanto nao houver exito na alocacao das colunas */
                do{
                    tabuleiro[lin] = (int *) calloc (tam, sizeof(int));
                }while (tabuleiro[lin] == NULL);
            }
        }

    }while (tabuleiro == NULL);

    return tabuleiro;
}

/*  Funcao 'inicia_primos', realiza a alocacao para os numeros primos que devem ser utilizados
**  no exito do jogo */
Primo * inicia_primos (int tam){
    /*  'tam' armazena o tamanho do lado do tabuleiro; 'numero' armazena o numero a ser classificado
    **  como primo ou nao; 'ind' armazena o indice de ordem do n-esimo primo; 'primos' armazena
    **  os numeros primos a serem considerados */
    int numero = 2, ind = 0;
    Primo *primos;

    /*  Enquanto nao alocar o 'primos' */
    do{
        primos = (Primo *) calloc (pow (tam,2) , sizeof(Primo));

    }while (primos == NULL);

    /*  Determinar numeros primos ate o (tam^2)-esimo primo */
    do {
        /*  Sendo numero primo, adicionar no 'primos' */
        if (verifica_primo (numero, 2) == 'P'){
            primos[ind].valor = numero;
            primos[ind].status = 'L';
            ind++;
        }

        numero++;

    }while (ind < pow(tam, 2));

    return primos;
}

/*  Funcao 'inicia_tabu', realiza a alocacao do tabuleiro, o preenchimento previo do
**  tabuleiro */
void inicia_tabu (Primo *primos, Tabuleiro *tabu){
    /*  'primos' armazena os (tam^2) numeros primos; 'tabu' armazena o tabuleiro a ser
    **  realizado o jogo, assim como suas informacoes; 'numero' armazena o numero primo
    **  a ser inserido no tabuleiro; 'lin' e 'col' armazenam, em conjunto, as coordenadas
    **  para insercao do numero no tabuleiro; 'resp'
    **  armazena a reposta para a pergunta de "sim ou nao" */
    int numero, lin, col;
    char resp;

    /*  Configuracao de 'zeros', tento o tabuleiro completamente vazio, e
    **  exibicao do tabuleiro */
    tabu->zeros = 65 + pow(tabu->tam, 2);
    tabu->campo = cria_tabuleiro (tabu->tam);
    imprime_tabu (tabu);

    /*  Enquanto houver interesse em adicionar numeros no tabuleiro */
    printf ("\nDeseja adicionar um numero no tabuleiro? s/n ou S/N\n");
        resp = ler_resposta ();

    while (resp == 'S' || resp == 's'){
        /*  Grupo de Questionamento para correta insercao de numeros no tabuleiro */
        printf ("\nDigite um numero primo a ser inserido, de 2 a %d:\n", (primos+((tabu->tam * tabu->tam)-1))->valor);
            numero = ler_primo(primos[(tabu->tam * tabu->tam) - 1].valor);

        printf ("\nAgora, digite a linha a ser inserido o numero fornecido:\n");
            lin = ler_intervalo (0, tabu->tam);

        printf ("\nAgora, digite a coluna a ser inserido o numero fornecido:\n");
            col = ler_intervalo (0, tabu->tam);

        /*  Atribuicao do numero valido no tabuleiro, Diminuicao da quantidade de
        **  campos vazios no tabuleiro e Exibicao do tabuleiro na configuracao
        **  atual */
        if (tabu->campo[lin][col] == 0){
            tabu->campo[lin][col] = numero;
            tabu->zeros--;

            imprime_tabu (tabu);

            printf ("\nO valor foi adicionado, deseja adicionar outro? s/n ou S/N\n");
                resp = ler_resposta ();

        }else{
            printf ("\nA posicao escolhida ja esta ocupada! Recomece a insercao!\n");
                resp = 'S';

        }
    }
}


void zera_tabu (Tabuleiro *tabu, Primo *primos){
    char lin, col;

    for (lin = 65; lin < (tabu->tam + 65); lin++){
        for (col = 65; col < (tabu->tam + 65); col++){
            if (primos[localiza_primo(primos, -1, pow(tabu->tam,2), tabu->campo[lin - 65][col - 65])].status != 'I')
                tabu->campo[lin - 65][col - 65] = 0;
        }
    }
}

/*  Funcao 'libera_primos', desaloca o espaco alocado para o vetor Primos */
void libera_primos (Primo *primos){
    /*  'primos' armazena os numeros primos */
    free (primos);
}

/*  Funcao 'libera_tabuleiro', desaloca o espaco alocado para o Tabuleiro */
void libera_tabuleiro (Tabuleiro *tabu){
    /*  'tabu' armazena o tabuleiro a ser liberado; 'ind' armazena o indice
    **  da linha a ser liberada */
    char ind;

    /* Liberacao de todas as linhas */
    for(ind = 65; ind < (tabu->tam + 65); ind++){
		free (tabu->campo[ind - 65]);
	}/*  Criacao de uma letra *//*  Criacao de uma letra */
Letra * cria_letra ();
Letra * cria_letra ();
/*  Criacao de uma letra */
Letra * cria_letra ();
    /* Liberacao do tabuleiro em si */
	free (tabu->campo);

	tabu->campo = NULL;
}/*  Criacao de uma letra *//*  Criacao de uma letra */
Letra * cria_letra ();
Letra * cria_letra ();

/*  Funcao 'libera_elemento', desaloca o espaco para apenas um elemento
**  do Historico */
void libera_elemento (Elemento *elemento){
    /* 'elemento' armazena o elemento a ser desalocado */
    free (elemento);
}

/*  Funcao 'libera_elementos', desaloca o espaco para todos os elementos
**  existentes no Historico */
Historico * libera_elementos (Historico *hist){
    /*  'hist' armazena o Historico a ser "limpo" */

    /*  Havendo historico a ser "limpo" */
    if (hist->topo != NULL){
        /*  'auxiliar' auxilia na desalocacao dos elementos; 'ind' armazena
        **  o indice para a quantidade restante de elementos */
        Elemento *auxiliar;
        int ind;

        /*  Desalocacao de todos */
        for (ind = hist->quant; ind > 0; ind--){
            auxiliar = hist->topo;
            hist->topo = auxiliar->prox;
            libera_elemento (auxiliar);
        }

        /*  Reinicializacao do Historico */
        hist->topo = hist->base = NULL;

    }

    return hist;
}

/*  Funcao 'libera_historico', desaloca o Historico, propriamente dito */
void libera_historico (Historico *hist){
    /*  'hist' armazena o historico a ser desalocado *//* /*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra ();/*  Criacao de uma letra */
Letra * cria_letra (); Criacao de uma letra */
Letra * cria_letra ();
    free (hist);
}

void libera_ponto (Ponto *ponto){
    free (ponto);
}

void libera_point (Seqpontos *pontos){
    if (pontos->inicio != NULL){
        Ponto *auxiliar;

        while (pontos->inicio != NULL){
            auxiliar = pontos->inicio;
            pontos->inicio = auxiliar->prox;
            libera_ponto (auxiliar);
        }

        pontos->inicio = NULL;
    }
}

/*  Funcao 'constroi_historico', realiza a insercao dos elementos no historico */
void constroi_historico (Historico *hist, Tabuleiro *tabu, Primo *primos, int posiprimo,
                         char cardeal, char linha, char coluna){
    /*  'hist' armazena o historico a ser ampliado; 'tabu' armazena o tabuleiro a sofre
    **  alteracoes; 'primos' armazena os numeros primos; 'posiprimo' armazena a posicao
    **  de 'primos' a ser utilizada; 'cardeal' armazena a quantidade de movimentos que
    **  serao marcadas como ja visitadas; 'linha' e 'coluna' armazenam as coordenadas
    **  no tabuleiro */

    /*  Nao havendo historico disponivel */
    if (hist == NULL) return;

    /*  Nao havendo historico ou o valor a ser inserido nao estiver no topo */
    if ((hist->topo == NULL) || (primos[posiprimo].valor != hist->topo->numero)){
        /*  'novo' armazena o novo elemento a ser inserido no historico; 'ind' armazena
        **  o indice para os pontos cardeais */
        Elemento *novo = cria_elemento();
        char ind;

        /*  Atribuicoes ao novo elemento */
        novo->numero = primos[posiprimo].valor;
        for (ind = 48; ind < cardeal; ind++)
            novo->pcardeais[ind - 48] = 'O';

        novo->coord[0] = linha;
        novo->coord[1] = coluna;

        novo->prox = hist->topo;

        /*  Conexao ao Historico */
        if (hist->quant != 0) hist->topo->ante = novo;
        hist->topo = novo;
        if (hist->quant == 0)   hist->base = novo;
        hist->quant++;

        /*  Configuracao de 'primos' e do tabuleiro */
        if (primos[posiprimo].status != 'I'){
            primos[posiprimo].status = 'O';
            tabu->zeros--;
        }

    /*  Ja tendo o elemento no topo */
    }else   hist->topo->pcardeais[cardeal - 48] = 'O';

}


void insere_pontos (Seqpontos *pontos, int valor, char linha, char coluna){
    if (pontos == NULL) return;

    Ponto *novo = cria_ponto ();

    novo->valor = valor;
    novo->linha = linha;
    novo->coluna = coluna;
    novo->prox = pontos->inicio;

    pontos->inicio = novo;

}

/*  Funcao 'localiza_primo', realiza a procura de um determinado numero dentre os numeros
**  primos disponiveis */
int localiza_primo (Primo *primo, int esq, int dir, int numero){
    /*  'primo' armazena os numeros primos; 'esq' e 'dir' armazenam os extremos de 'primo'
    **  a serem considerados na procura; 'numero' armazena o numero a ser localizado */

    /*  Extremos vizinhos */
    if (esq == dir - 1) return dir;

    else {
        /*  'meio' armazena o meio entre os extremos */
        int meio = (esq + dir)/2;

        /*  Estando no meio de 'primo' */
        if ((primo+meio)->valor == numero)
            return meio;

        /*  Estando a direita */
        else if ((primo+meio)->valor < numero)
            return localiza_primo (primo, meio, dir, numero);

        /*  Estando a esquerda */
        else
            return localiza_primo (primo, esq, meio, numero);
    }
}

/*  Funcao 'menor_tabu', realiza a procura pelo menor numero primo fornecido pelo usuario */
char menor_tabu (Ponto *ponto, Primo *primos, Tabuleiro *tabu){
    /*  'ponto' armazenarah as informacoes do menor primo no tabuleiro; 'primos' armazena
    **  os numeros primos; 'tabu' armazena o tabuleiro a ser realizado a busca; 'menor'
    **  armazena o menor primo no tabuleiro; 'lin' e 'col' armazenam a linha e a coluna,
    **  respectivamente, do tabuleiro */
    Seqpontos filapontos;
    int menor = 999;
    char lin, col;

    filapontos.inicio = NULL;
    /*  Percorrendo todo o tabuleiro */
    for (lin = 65; lin < (tabu->tam + 65); lin++){
        for (col = 65; col < (tabu->tam + 65); col++){

            /*  Sendo diferente de 0*/
            if (tabu->campo[lin - 65][col - 65] != 0){

                insere_pontos (&filapontos, tabu->campo[lin - 65][col - 65], lin, col);

                /*  Armazenar o status desde primo como "INICIADO PELO USUARIO" ou simplesmente
                **  'I' */
                primos[localiza_primo(primos, -1, pow(tabu->tam,2), tabu->campo[lin - 65][col - 65])].status = 'I'; //seg

                /*  Sendo menor que 'menor', guardar as informacoes */
                if (tabu->campo[lin - 65][col - 65] < menor){
                    menor = tabu->campo[lin - 65][col - 65];
                    ponto->linha = lin;
                    ponto->coluna = col;
                }
            }
        }
    }

    /*  Havendo menor valor nao-nulo */
    if (menor != 999)   ponto->valor = menor;

    /*  Nao havendo */
    else{
        ponto->valor = 0;
        ponto->linha = ponto->coluna = 65;
    }

    lin = calcula_distancia (&filapontos, primos, pow(tabu->tam,2));

    libera_point (&filapontos);

    return lin;
}

/*  Funcao 'remove_historico', retira do historico o elemento do topo */
Ponto * remove_historico (Historico *hist, Tabuleiro *tabu, Primo *primo, int posi){
    /*  'hist' armazena o historico a ser manipulado; 'tabu' armazena o tabuleiro; 'primo'
    **  armazena os numeros primos; 'posi' armazena a posicao do numero primo */

    /*  Nao havendo historico */
    if (hist->topo == NULL) return NULL;

    /*  'aux' auxilia na manipulacao; 'ponto' armazena do ponto para o topo do Historico
    **  'p' armazena o endereco de 'ponto' */
    Elemento *aux = hist->topo;
    Ponto ponto, *p = &ponto;

    /*  Armazenando a localizao do proximo elemento */
    ponto.linha = aux->prox->coord[0];
    ponto.coluna = aux->prox->coord[1];

    /*  Configuracao do numero primo e do tabuleiro */
    if (primo[posi].status != 'I'){
        primo[posi].status = 'L';
        tabu->campo[aux->coord[0]- 65][aux->coord[1] - 65] = 0;
        tabu->zeros++;
    }

    /*  Amarracao do Historico */
    hist->quant--;
    if (hist->quant == 0){
        hist->topo = hist->base = NULL;

    }else
        hist->topo = aux->prox;

    libera_elemento (aux);

    return p;
}

/*  Funcao 'imprime_tabu', exibe na tela o tabuleiro na sua configuracao atual */
void imprime_tabu (Tabuleiro *tabu){
    /*  'tabu' armazena o tabuleiro a ser exibido; 'lin' e 'col' armazenam a linha
    **  e coluna corrente */
    char lin, col;

    printf ("\nConfiguracao Atual do Tabuleiro:\n");
    printf ("lin\\col\t");

    for (col = 65; col < (tabu->tam + 65); col++)
        printf ("%d\t", col - 65);

    printf ("\n");
    for (lin = 65; lin < (tabu->tam + 65); lin++){
        printf ("%d\t", lin - 65);

        for (col = 65; col < (tabu->tam + 65); col++){
            if (tabu->campo[lin - 65][col - 65] == 0) printf ("-\t");
            else
                printf ("%.3d\t", tabu->campo[lin - 65][col - 65]);
        }

        printf ("\n");
    }
}

/*  Funcao 'imprime_primo', exibe na tela os numeros primos */
void imprime_primo (Primo *primo, int tam){
    /*  'primo' armazena os numeros primos; 'tam' armazena o parametro para o tamanho
    **  de 'primo'; 'ind' armazena o indice a ser manipulado */
    char ind;

    printf ("Primos:\n");
    for (ind = 65; ind < pow(tam,2) + 65; ind++){
        printf ("(%.3d,%c)\t", (primo+(ind-65))->valor, (primo+(ind-65))->status);
        if (((ind - 65) > 0) && ((ind - 64)%tam == 0)) printf ("\n");
    }
}

/*  Exibicao na tela o Historico de movimentos */
void imprime_historico (Historico *hist){
    if (hist->base != NULL){
        Elemento *auxiliar = hist->base;
        char ind, ind2;

        printf ("\nHistorico de Movimentos:\n");
        for (ind = 65; ind < hist->quant + 65; ind++){
            printf ("%.2dº Primo = %.3d\n", ind - 64, auxiliar->numero);
            printf ("\tPosicao [%d][%d]\n", auxiliar->coord[0] - 65, auxiliar->coord[1] - 65);
            ind2 = 65;
            while (auxiliar->pcardeais[ind2 - 65] == 'O'){
                printf ("\tCardeal[%d] Ocupado\n", ind2 - 65);
                ind2++;
            }
            auxiliar = auxiliar->ante;
        }

    }else
        printf ("Sem historico!\n");

}
