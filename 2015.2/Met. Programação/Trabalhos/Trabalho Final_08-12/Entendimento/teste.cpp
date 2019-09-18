#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>
#include <string.h>
#include "../Codificação_FINAL/Bibliotecas/Rede.hpp"


#define DEGTORAD(deg) (deg * (180.0f/M_PI))
#define DOT 46



/*! interface_cria
Desenha na tela todas o a rede de estruturas
/***********************************************************************************!
* Funcao: Montar a rede
* Descricao
*     A partir da lista de geradores, adaptadores, cidades e interconexões e desenha cada um na tela
* Parametros
*     Rede - struct que contém os cabeçalhos das listas
*
* Valor retornado
*     A função não retorna nenhum valor
* Assertiva de entrada
*     Rede != NULL
* Assertiva de saida
*     Não possui assertivas de saida
***********************************************************************************/

void interface_cria(Rede* rede) {
    Conexao* p;
    Posicao* q;
    initscr();
    start_color();
    init_pair(0,7,7);
    init_pair(1,2,5);
    init_pair(2,3,4);
    init_pair(3,1,1);

	for(p=rede->in_conex->inic;p!=NULL;p=p->prox_i){
            if(p->status==-1){
                attrset(COLOR_PAIR(3));
            }else{
                attrset(COLOR_PAIR(2));
            }

            linha(p->col_i,p->lin_i,p->col_f,p->lin_f);
            move(p->col_i,p->lin_i);
            printw("*");
            move(p->col_f,p->lin_f);
            printw("*");
	}

	attrset(COLOR_PAIR(1));

    for(q=rede->inicio;q!=NULL;q=q->prox){
        if(q->tipo=='A'){
            move(q->x,q->y);
            printw("*");
            texto(q->x,(q->y)+2,q->adapt->nome);
        }
        if(q->tipo=='C'){
            move(q->y,q->x);
            printw("*");
            texto(q->y,(q->x)+2,q->cid->nome);
        }
        if(q->tipo=='G'){
            move(q->y,q->x);
            printw("*");
            texto(q->y,(q->x)+2,q->gera->nome);
        }
    }

	refresh();
    getch();
    endwin();


}

/*! ciruclo
/***********************************************************************************!
* Funcao: Desenhar um círculo na tela
*
* Parametros
*     pos_x - posição vertical do centro do círculo
*     pos_y - posição horizontal do centro do círculo
*     raio - raio do círculo
*     letra - carctere usado no desenho di círculo
* Valor retornado
*     A função não retorna nenhum valor
* Assertiva de entrada
*     pos_x > 0
*     pos_y > 0
*     raio > 0
*     letra > 33
*     letra <= 128
* Assertiva de saida
*     Não possui assertivas de saida
***********************************************************************************/

void circulo (int pos_x, int pos_y, int raio, char letra){
    float angulo, comp;
	int y, x;

	/* Convert to int */
	comp = raio * 2;

	/* Initialize ncurses */
	initscr();

	/* Disable mouse pointer */
	curs_set(0);

	/* Draw circle */
	for (angulo = 0; angulo < 360.0f; angulo += 1.0f){
		x = pos_x + (int)(comp * cos(DEGTORAD(angulo)));
		y = pos_y + (int)(raio * sin(DEGTORAD(angulo)));

        mvaddch (y, x, letra);
	}

	/* Refresh screen */
	//refresh();

	/* Wait for user input before exiting program */
	//getch();

	/* Escape from ncurses mode */
	endwin();
}

/*! triangulo
/***********************************************************************************!
* Funcao: Desenhar um triângulo na tela
*
* Parametros
*     pos_x - posição vertical do centro do triangulo
*     pos_y - posição horizontal do centro do triangulo
*     larg - largura do triangulo
*     letra - carctere usado no desenho do triangulo
* Valor retornado
*     A função não retorna nenhum valor
* Assertiva de entrada
*     pos_x > 0
*     pos_y > 0
*     larg > 0
*     letra > 33
*     letra <= 128
* Assertiva de saida
*     Não possui assertivas de saida
***********************************************************************************/

void triangulo (int pos_x, int pos_y, int larg, char letra){
    int y = pos_y;

    /* Initialize ncurses */
	initscr();

    for(int lin = pos_x; lin <= (pos_x + larg); lin++){
        for(int col = pos_y; col <= y; col++){
            move (lin, col);
            if ((col == pos_y) || (col == y) || (lin == (pos_x + larg)))
                printw("%c", letra);
        }
        y++;
        pos_y--;
    }

    /* Refresh screen */
	//refresh();

	/* Wait for user input before exiting program */
	//getch();

	/* Escape from ncurses mode */
	endwin();
}


/*! retangulo
/***********************************************************************************!
* Funcao: Desenhar um triângulo na tela
*
* Parametros
*     pos_x - posição vertical do retangulo
*     pos_y - posição horizontal do retangulo
*     larg - largura do retangulo
*     comp - comprimento do retangulo
*     letra - carctere usado no desenho do retangulo
* Valor retornado
*     A função não retorna nenhum valor
* Assertiva de entrada
*     pos_x > 0
*     pos_y > 0
*     larg > 0
*     comp > 0
*     letra > 33
*     letra <= 128
* Assertiva de saida
*     Não possui assertivas de saida
***********************************************************************************/
void retangulo (int pos_x, int pos_y, int comp, int larg, char letra){
    /* Initialize ncurses */
	initscr();

    for(int lin = pos_x; lin <= (pos_x + comp); lin++){
        for(int col = pos_y; col <= (pos_y + larg); col++){
            move(lin, col);
            if ((col == pos_y) || (col == (pos_y + larg))
                || (lin == pos_x) || (lin == (pos_x + comp)))
                printw("%c", letra);
        }
    }

    /* Refresh screen */
	//refresh();

	/* Wait for user input before exiting program */
	//getch();

	/* Escape from ncurses mode */
	endwin();
}


/*! texto
/***********************************************************************************!
* Funcao: Desenhar um texto na tela
*
* Parametros
*     pos_x - posição vertical do texto
*     pos_y - posição horizontal do textp
*     frase - texto a ser impresso na tela
* Valor retornado
*     A função não retorna nenhum valor
* Assertiva de entrada
*     pos_x > 0
*     pos_y > 0
* Assertiva de saida
*     Não possui assertivas de saida
***********************************************************************************/

void texto (int pos_x, int pos_y, char *frase){
    /* Initialize ncurses */
	initscr();

    move (pos_x, pos_y);
    printw ("%s", frase);

    /* Refresh screen */
	//refresh();

	/* Wait for user input before exiting program */
	//getch();

	/* Escape from ncurses mode */
	endwin();
}

/*! linha
/***********************************************************************************!
* Funcao: Desenhar uma linha na tela
*
* Parametros
*     pos_x - posição inicial vertical da linha
*     pos_y - posição inicial horizontal da linha
*     posf_x - posição final vertical da linha
*     posf_y - posição final horizontal da linha
* Valor retornado
*     A função não retorna nenhum valor
* Assertiva de entrada
*     pos_x > 0
*     pos_y > 0
*     posf_x > 0
*     posf_y > 0
* Assertiva de saida
*     Não possui assertivas de saida
***********************************************************************************/
void linha(int pos_y, int pos_x, int posf_y, int posf_x) {
    int i, j;

    if(posf_y > pos_y && posf_x > pos_x){
        for(i=pos_x, j = pos_y; i<posf_x || j < posf_y; i++, j++) {
            if(i<posf_x && j < posf_y){
                move(j,i);
                printw("\\");
            }else if(i < posf_x){
                move(posf_y,i);
                addch (ACS_HLINE);
            }else{
                move(j, posf_x);
                addch (ACS_VLINE);
            }
        }
    }
    else if(posf_y > pos_y && posf_x < pos_x){
        for(i=pos_x, j=pos_y; i > posf_x || j < posf_y;i--,j++){
            if(i > posf_x && j < posf_y){
                move(j,i);
                printw("/");
            }else if(i > posf_x){
                move(posf_y,i);
                addch (ACS_HLINE);
            }else{
                move(j,posf_x);
                addch (ACS_VLINE);
            }
        }
    }
    else if(posf_y < pos_y && posf_x > pos_x){
        for(i=pos_x, j=pos_y; i < posf_x || j > posf_y;i++,j--){
            if(i < posf_x && j > posf_y){
                move(j,i);
                printw("/");
            }else if(i < posf_x){
                move(posf_y,i);
                addch (ACS_HLINE);
            }else{
                move(j,posf_x);
                addch (ACS_VLINE);
            }
        }
    }
    else if(posf_y < pos_y && posf_x < pos_x){
        for(i=pos_x, j = pos_y; i>posf_x || j > posf_y; i--, j--) {
            if(i>posf_x && j > posf_y){
                move(j,i);
                printw("\\");
            }else if(i > posf_x){
                move(posf_y,i);
                addch (ACS_HLINE);
            }else{
                move(j, posf_x);
                addch (ACS_VLINE);
            }
        }
    }
    else if(posf_y > pos_y && posf_x == pos_x){
        for(i=pos_y; i < posf_y;i++){
            move(i, pos_x);
            addch (ACS_VLINE);
        }
    }
    else if(posf_y < pos_y && posf_x == pos_x){
        for(i=pos_y; i > posf_y;i--){
            move(i, pos_x);
            addch (ACS_VLINE);
        }
    }
    else if(posf_y == pos_y && posf_x > pos_x){
        for(i=pos_x; i < posf_x;i++){
            move(pos_y,i);
            addch (ACS_HLINE);
        }
    }
    else if(posf_y == pos_y && posf_x < pos_x){
        for(i=pos_x; i > posf_x;i--){
            move(pos_y,i);
            addch (ACS_HLINE);
        }
    }

}
