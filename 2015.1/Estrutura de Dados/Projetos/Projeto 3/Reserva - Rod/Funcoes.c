/*  Descritivo das funções para andamento do Projeto */

/*  Bibliotecas requisitada */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Funcoes.h"
#define T 70000

/*  Lista das funcoes de manipulacao */

/*  Funcao 'inicio_geral', realiza a apresentacao das regras do jogo e questiona sobre
**  o inicio ou nao do mesmo */
char inicio_geral (){
    /*  Apresentacao das Regras para o Jogo Caminho com Numeros Primos */
    system ("clear");
    printf ("Bem-Vindo ao Jogo Caminho com Numeros Primos!\n");
    printf ("Vamos as Regras:\n");
	printf ("\n1. O jogo consiste de um tabuleiro quadrado, com lado variante de 6 a 10\nunidades, definido pelo usuario;\n");
	printf ("\n2. O caminho sera feito apenas por numeros primos, comecando pelo 2;\n");
	printf ("\n3. O usuario fornece o(s) numero(s) que gostaria de inserir no tabuleiro,\nassim como sua(s) respectiva(s) coordenada(s);\n");
	printf ("\n4. Caso haja solucao, a mesma sera apresentada para o tabuleiro fornecido\npelo usuario;\n");
	printf ("\n5. Caso contrario, a mensagem 'ENTRADA FORNECIDA NAO POSSUI SOLUCAO'\nsera exibida;\n");

	pausa ();

	/*  Questionamento sobre o inicio do jogo */
    printf ("Dados as regras, deseja iniciar o jogo? s/n ou S/N\n");
    return ler_resposta ();
}

/*  Funcao 'inicio_real', realiza a apresentacao dos modos de inicio do jogo e questiona
**  qual sera utilizado */
char inicio_real (){
    /*  Apresentacao dos Modos de Inicio */
    system ("clear");
    printf ("Ha dois modos para inicio do jogo Caminho com Numeros Primos:\n");
    printf ("\t1 - Leitura do arquivo 'entradaProj3.txt';\n");
    printf ("\t2 - Configuracao inicial do jogo por seu desejo.\n");
    printf ("\nDadas as opcoes, qual voce escolhe?\n");

    return ler_intervalo (1, 2);
}

/*  Funcao 'pergunta_tam', realiza a pergunta sobre o tamanho do tabuleiro e verifica
**  a validade do valor ofertado */
int pergunta_tam (){
    /*  'tam' armazena o tamanho do lado do tabuleiro */
    int tam;

    printf ("Digite o tamanho para o lado do tabuleiro, entre 6 - 10:\n");

    /*  Enquanto for um tamanho invalido */
    do{
        scanf ("%d", &tam);
        getchar();

        /*  Condicao valida: 6 <= tam <= 10 */
        if (tam < 6 || tam > 10)
            /*  Mensagem de erro */
            printf ("Tamanho invalido, digite novamente!\n");

    }while (tam < 6 || tam > 10);

    return tam;
}

/*  Funcao 'resolve_ant', realiza o preenchimento do tabuleiro com os numeros primos
**  na ordem decrescente a partir do menor numero primo fornecido ate o 2 */
char resolve_ant (Historico *hist, Tabuleiro *tabu, Primo *primo,
                  int posiprimo, int posiin, char linha, char coluna, int *movimentos, char cond_post){
    /*  'hist' armazena o historico de jogadas; 'tabu' armazena informacoes sobre o tabuleiro
    **  do jogo; 'primo' armazena os numeros primos; 'tam' armazena o tamanho do lado do
    **  tabuleiro; 'posiprimo' armazena a posicao a ser manipulada no vetor 'primo'; 'linha' e
    **  'coluna' armazenam em conjunto o ponto especifico do tabuleiro a ser manipulado */

    (*movimentos)++;
    //printf("%d", *movimentos);
    if((*movimentos) > T)
        return 'S';

    //temporizador (0.1);
    //system ("clear");
    //imprime_tabu (tabu);

    /*  Chegando ao Primo 2 */
    if (posiprimo == 0){
        if (primo[posiprimo].status != 'I')
            tabu->campo[linha - 65][coluna - 65] = primo[posiprimo].valor;

        constroi_historico (hist, tabu, primo, posiprimo, 47, linha, coluna);
        return 'S';
    }

    if (hist->topo != NULL && hist->base != NULL
        && hist->topo == hist->base && hist->base->pcardeais[3] == 'O')
        return 'N';


    /*  Condicoes Para Preenchimento em comum a todas as direcoes: Estar no espaco do tabuleiro;
    **  posicao livre; nao ter historico de movimentos ou ser o ultimo do historico mas sem ter
    **  acessado a posicao anteriormente ou nao esta registrado no historico */

    /*  Acesso pelo Norte */
    if (((linha - 66) >= 0)
        && (((tabu->campo[linha - 66][coluna - 65] == 0)
            && primo[posiprimo - 1].status == 'L')
            || tabu->campo[linha - 66][coluna - 65] == primo[posiprimo - 1].valor)
        && ((hist->topo == NULL)
            || ((hist->topo != NULL)
                && (((hist->topo->numero == primo[posiprimo].valor)
                    && (hist->topo->pcardeais[0] == 'L'))
                || (hist->topo->numero != primo[posiprimo].valor))))){
        tabu->campo[linha - 66][coluna - 65] = primo[posiprimo-1].valor;
        constroi_historico (hist, tabu, primo, posiprimo, 48, linha, coluna);
        return resolve_ant (hist, tabu, primo, posiprimo - 1, posiin, linha - 1, coluna, movimentos, cond_post);

    /*  Acesso pelo Leste */
    }else if (((coluna - 64) <= (tabu->tam - 1))
        && (((tabu->campo[linha - 65][coluna - 64] == 0)
            && primo[posiprimo - 1].status == 'L')
            || tabu->campo[linha - 65][coluna - 64] == primo[posiprimo - 1].valor)
        && ((hist->topo == NULL)
            || ((hist->topo != NULL)
                && (((hist->topo->numero == primo[posiprimo].valor)
                    && (hist->topo->pcardeais[1] == 'L'))
                || (hist->topo->numero != primo[posiprimo].valor))))){
        tabu->campo[linha - 65][coluna - 64] = primo[posiprimo-1].valor;
        constroi_historico (hist, tabu, primo, posiprimo, 49, linha, coluna);
        return resolve_ant (hist, tabu, primo, posiprimo - 1, posiin, linha, coluna + 1, movimentos, cond_post);

    /*  Acesso pelo Sul */
    }else if (((linha - 64) <= (tabu->tam - 1))
        && (((tabu->campo[linha - 64][coluna - 65] == 0)
            && primo[posiprimo - 1].status == 'L')
            || tabu->campo[linha - 64][coluna - 65] == primo[posiprimo - 1].valor)
        && ((hist->topo == NULL)
            || ((hist->topo != NULL)
                && (((hist->topo->numero == primo[posiprimo].valor)
                    && (hist->topo->pcardeais[2] == 'L'))
                || (hist->topo->numero != primo[posiprimo].valor))))){
        tabu->campo[linha - 64][coluna - 65] = primo[posiprimo-1].valor;
        constroi_historico (hist, tabu, primo, posiprimo, 50, linha, coluna);
        return resolve_ant (hist, tabu, primo, posiprimo - 1, posiin, linha + 1, coluna, movimentos, cond_post);

    /*  Acesso pelo Oeste */
    }else if (((coluna - 66) >= 0)
        && (((tabu->campo[linha - 65][coluna - 66] == 0)
            && primo[posiprimo - 1].status == 'L')
            || tabu->campo[linha - 65][coluna - 66] == primo[posiprimo - 1].valor)
        && ((hist->topo == NULL)
            || ((hist->topo != NULL)
                && (((hist->topo->numero == primo[posiprimo].valor)
                    && (hist->topo->pcardeais[3] == 'L'))
                || (hist->topo->numero != primo[posiprimo].valor))))){
        tabu->campo[linha - 65][coluna - 66] = primo[posiprimo-1].valor;
        constroi_historico (hist, tabu, primo, posiprimo, 51, linha, coluna);
        return resolve_ant (hist, tabu, primo, posiprimo - 1, posiin, linha, coluna - 1, movimentos, cond_post);

    /*  Nao havendo movimentacao permitida */
    }else{
        if (hist->topo != NULL && hist->topo->numero == primo[posiprimo].valor){
            Ponto *ponto = remove_historico (hist, tabu, primo, posiprimo);
            return resolve_ant (hist, tabu, primo, posiprimo + 1, posiin, ponto->linha, ponto->coluna, movimentos, cond_post);

        }else{
            if (tabu->campo[linha - 65][coluna - 65] == primo[posiprimo].valor
                && primo[posiprimo].status != 'I')
                tabu->campo[linha - 65][coluna - 65] = 0;
            return resolve_ant (hist, tabu, primo, posiprimo + 1, posiin, hist->topo->coord[0],
                                hist->topo->coord[1], movimentos, cond_post);
        }
    }
}

/*  Funcao 'resolve_post', realiza o preenchimento do tabuleiro com os numeros primos
**  na ordem crescente a partir do menor numero primo fornecido ate o tam^2 numero
**  primo */
char resolve_post (Historico *hist, Tabuleiro *tabu, Primo *primo,
                  int posiprimo, int posiin, char linha, char coluna, int *movimentos){
    /*  'hist' armazena o historico de jogadas; 'tabu' armazena informacoes sobre o tabuleiro
    **  do jogo; 'primo' armazena os numeros primos; 'tam' armazena o tamanho do lado do
    **  tabuleiro; 'posiprimo' armazena a posicao a ser manipulada no vetor 'primo'; 'linha' e
    **  'coluna' armazenam em conjunto o ponto especifico do tabuleiro a ser manipulado */
    (*movimentos)++;
    //printf("%d", *movimentos);
    if((*movimentos) > T)
        return 'S';

    //temporizador (0.1);
    //system ("clear");
    //imprime_tabu (tabu);

    /*  Chegando ao Primo tam^2 */
    if (primo[posiprimo].valor == primo[(tabu->tam * tabu->tam) - 1].valor){
        tabu->campo[linha - 65][coluna - 65] = primo[posiprimo].valor;
        constroi_historico (hist, tabu, primo, posiprimo, 51, linha, coluna);
        return 'S';
    }

    /*  Chegando ao ultimo movimento dos anteriores, e o anterior a ele nao tiver movimentacao
    **  disponivel */
    if (posiprimo > pow(tabu->tam,2) - 1 || hist->quant >= pow(tabu->tam, 2))
        return 'S';

    if ((hist->topo->numero == primo[posiin].valor && hist->topo->pcardeais[3] == 'O')
        || (posiprimo < 0))
        return 'N';


    /*  Condicoes Para Preenchimento em comum a todas as direcoes: estar no espaco do tabuleiro;
    **  posicao livre e com o proximo primo estando livre OU esta ocupada com o proximo primo;
    **  nao ter historico de movimentos ou ser o ultimo do historico mas sem ter acessado a
    **  posicao anteriormente ou nao esta registrado no historico */

    /*  Acesso pelo Norte */
    if (((linha - 66) >= 0)
        && (((tabu->campo[linha - 66][coluna - 65] == 0)
            && primo[posiprimo+1].status == 'L')
            || tabu->campo[linha - 66][coluna - 65] == primo[posiprimo+1].valor)
        && ((hist->topo == NULL)
            || ((hist->topo != NULL)
                && (((hist->topo->numero == primo[posiprimo].valor)
                    && (hist->topo->pcardeais[0] == 'L'))
                || (hist->topo->numero != primo[posiprimo].valor))))){
        tabu->campo[linha - 66][coluna - 65] = primo[posiprimo+1].valor;
        constroi_historico (hist, tabu, primo, posiprimo, 48, linha, coluna);
        return resolve_post (hist, tabu, primo, posiprimo + 1, posiin, linha - 1, coluna, movimentos);

    /*  Acesso pelo Leste */
    }else if (((coluna - 64) <= (tabu->tam - 1))
        && (((tabu->campo[linha - 65][coluna - 64] == 0)
            && primo[posiprimo+1].status == 'L')
            || tabu->campo[linha - 65][coluna - 64] == primo[posiprimo+1].valor)
        && ((hist->topo == NULL)
            || ((hist->topo != NULL)
                && (((hist->topo->numero == primo[posiprimo].valor)
                    && (hist->topo->pcardeais[1] == 'L'))
                || (hist->topo->numero != primo[posiprimo].valor))))){
        tabu->campo[linha - 65][coluna - 64] = primo[posiprimo+1].valor;
        constroi_historico (hist, tabu, primo, posiprimo, 49, linha, coluna);
        return resolve_post (hist, tabu, primo, posiprimo + 1, posiin, linha, coluna + 1, movimentos);

    /*  Acesso pelo Sul */
    }else if (((linha - 64) <= (tabu->tam - 1))
        && (((tabu->campo[linha - 64][coluna - 65] == 0)
            && primo[posiprimo+1].status == 'L')
            || tabu->campo[linha - 64][coluna - 65] == primo[posiprimo+1].valor)
        && ((hist->topo == NULL)
            || ((hist->topo != NULL)
                && (((hist->topo->numero == primo[posiprimo].valor)
                    && (hist->topo->pcardeais[2] == 'L'))
                || (hist->topo->numero != primo[posiprimo].valor))))){
        tabu->campo[linha - 64][coluna - 65] = primo[posiprimo+1].valor;
        constroi_historico (hist, tabu, primo, posiprimo, 50, linha, coluna);
        return resolve_post (hist, tabu, primo, posiprimo + 1, posiin, linha + 1, coluna, movimentos);

    /*  Acesso pelo Oeste */
    }else if (((coluna - 66) >= 0)
        && (((tabu->campo[linha - 65][coluna - 66] == 0)
            && primo[posiprimo+1].status == 'L')
            || tabu->campo[linha - 65][coluna - 66] == primo[posiprimo+1].valor)
        && ((hist->topo == NULL)
            || ((hist->topo != NULL)
                && (((hist->topo->numero == primo[posiprimo].valor)
                    && (hist->topo->pcardeais[3] == 'L'))
                || (hist->topo->numero != primo[posiprimo].valor))))){
        tabu->campo[linha - 65][coluna - 66] = primo[posiprimo+1].valor;
        constroi_historico (hist, tabu, primo, posiprimo, 51, linha, coluna);
        return resolve_post (hist, tabu, primo, posiprimo + 1, posiin, linha, coluna - 1, movimentos);

    /*  Nao havendo movimentacao permitida */
    }else{
        if (hist->topo != NULL && hist->topo->numero == primo[posiin].valor)
            return 'N';

        if (hist->topo != NULL && hist->topo->numero == primo[posiprimo].valor){
            Ponto *ponto = remove_historico (hist, tabu, primo, posiprimo);
            return resolve_post (hist, tabu, primo, posiprimo - 1, posiin, ponto->linha, ponto->coluna, movimentos);

        }else{
            if (tabu->campo[linha - 65][coluna - 65] == primo[posiprimo].valor
                && primo[posiprimo].status != 'I')
                tabu->campo[linha - 65][coluna - 65] = 0;
            return resolve_post (hist, tabu, primo, posiprimo - 1, posiin, hist->topo->coord[0], hist->topo->coord[1], movimentos);
        }
    }
}

/*  Funcao 'ler_resposta', verifica a validade da resposta para uma pergunta de "sim ou nao"
**  ao longo do progresso do jogo */
char ler_resposta (){
    /*  'resp' armazena a resposta do usuario para a pergunta */
    char resp;

    /*  Enquanto for invalida */
    do{
        scanf ("%c", &resp);

        /*  Sendo invalido, mensagem correspondente */
        if ((resp != 's') && (resp != 'S') && (resp != 'n') && (resp != 'N'))
            printf ("Resposta invalida, digite novamente!\n");

    }while ((resp != 's') && (resp != 'S') && (resp != 'n') && (resp != 'N'));

    return resp;
}

/*  Funcao 'ler_intervalo', realiza a leitura e verifica a validade da coordenada do tabuleiro */
int ler_intervalo (int min, int max){
    /*  'max' armazena o valor maximo para o intervalo de validade; 'num' armazena a coordenada
    **  a ser lida */
    int num;

    /*  Enquanto for invalido */
    do{
        scanf ("%d", &num);

        /*  Sendo invalido, mensagem correspondente */
        if (num < min || num > max)
            printf ("\nO valor fornecido eh invalido! Digite novamente!\n");
        getchar();

    }while (num < min || num > max);

    return num;
}

/*  Funcao 'ler_primo', realiza a leitura do numero e verifica a validade do mesmo */
int ler_primo (int max){
    /*  'max' armazena o valor maximo para o intervalo de validacao; 'numero' armazena o numero
    **  a ser verificado; 'cond' armazena uma das condicoes de validacao */
    int numero;
    char cond;

    /*  Enquanto for invalido*/
    do{
        /*  Condicao Positivo, ou seja, cond = 'P' */
        cond = 'P';
        scanf ("%d", &numero);
        getchar();

        /*  Verificacao da validade do numero digitado */
        /*  Falha por nao ser um numero primo */
        if (verifica_primo(numero, 2) == 'N')
            printf ("\nO numero fornecido nao e primo!");

        /*  Falha por estar fora do intervalo, independente de ser primo ou nao */
        if (numero < 2 || numero > max){
            printf ("\nO numero fornecido nao pertence ao intervalo estabelecido!");
            cond = 'N';
        }
        if ((verifica_primo (numero, 2) != 'P') || cond == 'N')
            printf ("\nDigite novamente!\n");

    }while ((verifica_primo (numero, 2) != 'P') || cond == 'N');

    return numero;
}


float questiona_impressao (int *numero, int *opcao){
    float tempo;

    printf ("\nUma resolucao foi encontrada!\n");
    printf("\nResolucao encontrada em %d movimentos\n", *numero);
    printf ("\nHa dois modos para exibicao da mesma:\n");
    printf ("\t1 - Exibicao pausada por tempo;\n");
    printf ("\t2 - Exibicao direta.\n");
    printf ("\t3 - Exibicao pausada por ENTER.\n");
    printf ("\nDigite a sua escolha:\n");

    switch (ler_intervalo (1, 3)){
        case 1:
            printf ("\nEntao, agora digite o tempo digitado ");
            printf ("(Lembrando que pode ser decimal):\n");
            scanf ("%f", &tempo);
            *opcao = 1;
            break;

        case 2:
            printf ("\nA exibicao direta foi selecionada\n");
            tempo = 0.0;
            *opcao = 2;
            break;

        case 3:
            printf ("\nA exibicao pausada por ENTER foi selecionada\n");
            tempo = 999.99;
            *opcao = 3;
            break;
    }

    return tempo;
}


void imprime_pausa (Tabuleiro *tabu, Historico *hist, float tempo){
    Elemento *auxiliar = hist->base;

    do{
        temporizador (tempo);
        system ("clear");
        if (auxiliar->numero > hist->topo->numero)
            tabu->campo[auxiliar->coord[0] - 65 ][auxiliar->coord[1] - 65] = 2;
        else
            tabu->campo[auxiliar->coord[0] - 65 ][auxiliar->coord[1] - 65] = auxiliar->numero;
        imprime_tabu (tabu);
        auxiliar = auxiliar->ante;

    }while (auxiliar != NULL);

}

void imprime_enter (Tabuleiro *tabu, Historico *hist, float tempo){
    Elemento *auxiliar = hist->base;

    do{
        system ("clear");
        if (auxiliar->numero > hist->topo->numero)
            tabu->campo[auxiliar->coord[0] - 65 ][auxiliar->coord[1] - 65] = 2;
        else
            tabu->campo[auxiliar->coord[0] - 65 ][auxiliar->coord[1] - 65] = auxiliar->numero;
        imprime_tabu (tabu);
        auxiliar = auxiliar->ante;
        pausa();

    }while (auxiliar != NULL);

}

/*  Funcao 'verifica_primo', realiza o teste de primaridade de um numero fornecido */
char verifica_primo (int num, int div){
    /*  'num' armazena o numero a ser realizado o teste; 'div' armazena o divisor a ser utilizado
    **  no teste */

    /*  Retorno Positivo(P) ou Negativo(N) */
    if (num == 2 || num == 3 || pow(div,2) > num) return 'P';
    if (num < 2 || !(num % div)) return 'N';
    return verifica_primo (num, ++div);
}

char calcula_distancia (Seqpontos *pontos, Primo *primos, int max){
    if (pontos->inicio != NULL){

        Ponto *auxiliar = pontos->inicio;
        int dist1;
        char cond = 'S';

        while (auxiliar->prox != NULL){
            dist1 = (abs(auxiliar->linha- auxiliar->prox->linha)
                    + abs(auxiliar->coluna - auxiliar->prox->coluna));
            if (dist1 > abs(localiza_primo (primos, -1, max, auxiliar->valor)
                          - localiza_primo (primos, -1, max, auxiliar->prox->valor))){
                cond = 'N';
                break;
            }
            auxiliar = auxiliar->prox;
        };

        return cond;

    }else   return 'S';
}

/*  Funcao 'pausa', realiza a pausa do programa ate pressionar o ENTER */
void pausa (){

    printf ("\nPressione ENTER para continuar.\n");
	getchar ();
}

/*  Funcao 'temporizador', realiza a pausa do programa por um periodo de tempo
**  definido pelo usuario */
void temporizador (float pausa){

    if (pausa < 0.0) return;

    float tempoin = 0.0, tempofim = 0.0;

    tempoin = ((float) clock()) / ((float) CLOCKS_PER_SEC);

    while ((tempofim - tempoin) < pausa){
        tempofim = ((float) clock()) / ((float) CLOCKS_PER_SEC);
    };

   return;
}

Tabuleiro leitura_arquivo (){
	FILE *p_arquivo;
	Tabuleiro tabu;
	int lin_col, lin, col;

	p_arquivo = fopen("entradaProj3.txt", "r");
	if (p_arquivo == NULL){
        printf("\nFALHA NA ABERTURA DO ARQUIVO!!\n");
        exit(-1);
	}

    fscanf(p_arquivo, "%d", &lin_col);

    tabu.campo = cria_tabuleiro (lin_col);
    tabu.tam = lin_col;
    tabu.zeros = pow(lin_col, 2);

    if (lin_col >= 6 && lin_col <= 10){
        for(lin = 0; lin < lin_col; lin++){
            for (col = 0; col < lin_col; col++){
                fscanf(p_arquivo, "%d", &tabu.campo[lin][col]);
                if (tabu.campo[lin][col] != 0)
                    tabu.zeros--;
                //printf("%d", tabu.campo[lin][col]);
            }
        }

	}else{
        printf("\nARQUIVO INVALIDO!\nMODIFIQUE-O PARA USAR O PROGRAMA!\n");
        exit(-2);
	}

    fclose(p_arquivo);

    return tabu;
}
