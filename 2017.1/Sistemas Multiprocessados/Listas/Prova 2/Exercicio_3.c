/*****************************************************************
 *  Responsável:
 *      Rodrigo Ferreira Guimaraes
 *  Finalidade:
 *      Controlar um Display de 7 seg de anodo comum, a partir da
 *      porta 1
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
#define CONT_1S (int)(1048576 / 65536)
unsigned int contador;
unsigned int num;
unsigned int display7seg_AC[] = {   0x03, // 0
                                    0x9F, // 1
                                    0x25, // 2
                                    0x0D, // 3
                                    0x99, // 4
                                    0x49, // 5
                                    0x41, // 6
                                    0x1F, // 7
                                    0x01, // 8
                                    0x19, // 9
                                    0x11, // A
                                    0xC1, // B
                                    0x63, // C
                                    0x85, // D
                                    0x61, // E
                                    0x71, // F
                                };


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

    #ifndef MSP430
    printf("Cont 1seg = %d\n", CONT_1S);
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
    P1DIR = 0xFF;

    /*  Escrevendo em alta */
    P1OUT = 0xFF;
    #endif
}

void confTimerA0 (){
    #ifdef MSP430
    //  Configura divisor por 1
    TA0EX0 = TAIDEX_0;

    //  Controle do PWM
    //TA0CCR0 = (PASSO_COMUM - 1);

    //  SMCLK como fonte + Divisão po 1 + Modo Contínuo + Clear
    TA0CTL = TASSEL_2 | ID_0 | MC_2 | TACLR;

    //  Habilitar interrupção
    TA0CCTL0 = CCIE;
    #endif
}

void iniciaOperacao (){
    #ifdef MSP430
    num = 0;
    contador = CONT_1S;

    /*  Liberar contagem do temporizador */
    TA0CTL &= ~TACLR;

    __enable_interrupt();
    #endif
}

#ifdef MSP430
#pragma vector = TIMER0_A0_VECTOR
__interrupt void isrTA0CCR0(void){
    if (!(--contador)){
        P1OUT = display7seg_AC[num++];

        if (num > 0xF) num = 0;

        contador = CONT_1S;
    }
}
#endif
