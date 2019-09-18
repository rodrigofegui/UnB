/*****************************************************************
 *  Responsável:
 *      Rodrigo Ferreira Guimaraes
 *  Finalidade:
 *      Leitura de um teclado numérico matricial, a partir da
 *      porta 1; considerando um teclado com rebote.
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
enum pinos {EN = 0x04, IN1 = 0x08, IN2 = 0x10};
/*  1seg = 2^20 (Sem alterar o SMCLK) */
#define PASSO_1S 1048576
/*  1ms = 1s * 10^-3 */
#define PASSO_1MS (int)(PASSO_1S * 0.001)
#define MAX (100 * PASSO_1MS)
#define NORMAL  0
#define REVERSO 1
unsigned char sentido;

/*****************************************************************
 *  Protótipo Funções desenvolvidas
 ****************************************************************/
void iniciaPinos ();
void confTimerA0 ();
void iniciaOperacao ();
void crtl_motor (char PWM, char sentido);
#ifdef MSP430
__interrupt void isrTA0CCR0 ();
__interrupt void isrTA0CCR1a6 ();
#endif

void main (){
    // Stop watchdog timer
    #ifdef MSP430
    WDTCTL = WDTPW | WDTHOLD;
    #endif

    iniciaPinos ();

    confTimerA0 ();

    iniciaOperacao ();

    #ifndef MSP430
    printf("Enable = %d\n", EN);
    printf("In 1 = %d\n", IN1);
    printf("In 2 = %d\n", IN2);
    #else
    while (1);
    #endif
}

/*****************************************************************
 *  Protótipo Funções desenvolvidas
 ****************************************************************/
void iniciaPinos (){
    #ifdef MSP430
    /*  Configurando como saída */
    P1DIR |= EN;
    P1DIR |= IN1;
    P1DIR |= IN2;

    /*  Escrevendo */
    P1OUT &= ~EN;
    P1OUT &= ~IN1;
    P1OUT &= ~IN2;
    #endif
}

void confTimerA0 (){
    #ifdef MSP430
    //  Configura divisor por 1
    TA0EX0 = TAIDEX_0;

    //  Controle do PWM
    TA0CCR0 = MAX;
    TA0CCR1 = MAX / 2;

    //  SMCLK como fonte + Divisão po 1 + Modo Up + Clear
    TA0CTL = TASSEL_2 | ID_0 | MC_1 | TACLR;
    TA0CCTL1 = OUTMOD_6 | CCIE;

    //  Habilitar interrupção
    TA0CCTL0 = CCIE;
    #endif
}

void iniciaOperacao (){
    #ifdef MSP430
    sentido = NORMAL;

    /*  Liberar contagem do temporizador */
    TA0CTL &= ~TACLR;

    __enable_interrupt();
    #endif
}

void crtl_motor (char PWM, char sentido_){
    TA0CCR1 = PWM;
    sentido = sentido_;
}

#ifdef MSP430
#pragma vector = TIMER0_A0_VECTOR
__interrupt void isrTA0CCR0 (){
    P1OUT &= ~IN1;
    P1OUT &= ~IN2;
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void isrTA0CCR1a6 (){
    int n = __even_in_range (TA0IV, 0x10);
    switch (n){
        case 0x02:
            switch (sentido) {
                case NORMAL:
                    P1OUT |= IN1;
                    P1OUT &= ~IN2;
                    break;
                case REVERSO:
                    P1OUT &= ~IN1;
                    P1OUT |= IN2;
                    break;
            }
            break;
    }
}
#endif
