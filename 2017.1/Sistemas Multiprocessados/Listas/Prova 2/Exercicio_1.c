/*****************************************************************
 *  Responsável:
 *      Rodrigo Ferreira Guimaraes
 *  Finalidade:
 *      Gerar ondas de PWM nos pinos 1.0 e 1.1:
 *          - 80 (H) / 100 (L)
 *          - 120 (H) / 200 (L)
 *      respectivamente. Tempo em microsegundos.
 *****************************************************************/
/*****************************************************************
 *  Bibliotecas necessárias
 ****************************************************************/
/*
#define MSP430
//*/
#ifdef MSP430
    #include <msp430.h>
#else
    #include <stdio.h>
    #include <stdlib.h>
#endif

/*****************************************************************
 *  Definições necessárias
 ****************************************************************/
enum pinos {PIN0, PIN1};
/*  Para o SMCLK de 1Mhz, 1us = 2^20 * 10^-6 */
#define PASSO_1US (int)(1048576 * 0.000001)
/*  MDC{80, 100, 120, 200} = 20 */
#define PASSO_COMUM (20 * PASSO_1US)
unsigned int ctrlPin0[2];
unsigned int ctrlPin1[2];

/*****************************************************************
 *  Protótipo Funções desenvolvidas
 ****************************************************************/
void iniciaPinos ();
void confTimerA0 ();
void iniciaOperacao ();
#ifdef MSP430
__interrupt void isrTA0CCR0(void);
#endif

/*****************************************************************
 *  Programa principal
 ****************************************************************/
void main (){
    // Stop watchdog timer
    #ifdef MSP430
    WDTCTL = WDTPW | WDTHOLD;
    #endif

    iniciaPinos ();

    confTimerA0 ();

    iniciaOperacao ();

    printf("Passo = %d\n", PASSO_1US);

    while (1);
}

/*****************************************************************
 *  Protótipo Funções desenvolvidas
 ****************************************************************/
void iniciaPinos (){
    #ifdef MSP430
    /*  Configurando como saída */
    P1DIR |= PIN0;
    P1DIR |= PIN1;

    /*  Escrevendo em baixa */
    P1OUT &= ~PIN0;
    P1OUT &= ~PIN1;
    #endif
}

void confTimerA0 (){
    #ifdef MSP430
    //  Configura divisor por 1
    TA0EX0 = TAIDEX_0;

    //  Controle do PWM
    TA0CCR0 = (PASSO_COMUM - 1);

    //  SMCLK como fonte + Divisão po 1 + Modo Up + Clear
    TA0CTL = TASSEL_2 | ID_0 | MC_1 | TACLR;

    //  Habilitar interrupção
    TA0CCTL0 = CCIE;
    #endif
}

void iniciaOperacao (){
    #ifdef MSP430
    /*  Inicialização controle das curvas */
    ctrlPin0[0] = ctrlPin0[1] = 0;
    ctrlPin1[0] = ctrlPin1[1] = 0;

    /*  Liberar contagem do temporizador */
    TA0CTL &= ~TACLR;

    __enable_interrupt();
    #endif
}

#ifdef MSP430
#pragma vector = TIMER0_A0_VECTOR
__interrupt void isrTA0CCR0(void){
    /*  Contagem das interrupções */
    ctrlPin0[0]++;
    ctrlPin1[0]++;

    switch (ctrlPin0[1]) {
        /* Estado de LOW */
        case 0:
            if (ctrlPin0[0] == 5){ // 100us
                P1OUT |= PIN0;
                ctrlPin0[1] = 1;
                ctrlPin0[0] = 0;
            }
            break;
        /* Estado de HIGH */
        case 1:
            if (ctrlPin0[0] == 4){ // 80us
                P1OUT &= ~PIN0;
                ctrlPin0[1] = 0;
                ctrlPin0[0] = 0;
            }
            break;
    }

    switch (ctrlPin1[1]) {
        /* Estado de LOW */
        case 0:
            if (ctrlPin1[0] == 10){ // 200us
                P1OUT |= PIN1;
                ctrlPin1[1] = 1;
                ctrlPin1[0] = 0;
            }
            break;
        /* Estado de HIGH */
        case 1:
            if (ctrlPin1[0] == 6){ // 120us
                P1OUT &= ~PIN1;
                ctrlPin1[1] = 0;
                ctrlPin1[0] = 0;
            }
            break;
    }
}
#endif
