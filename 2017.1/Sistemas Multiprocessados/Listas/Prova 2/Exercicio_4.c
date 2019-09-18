/*****************************************************************
 *  Responsável:
 *      Rodrigo Ferreira Guimaraes
 *  Finalidade:
 *      Controlar um Display de 7 seg de anodo comum, a partir da
 *      porta 1; assim como sua alimentação pelo pino 3.4
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
enum pinos {PIN0, PIN1, PIN_EN = 0x08};
/*  1seg = 2^20 (Sem alterar o SMCLK) */
#define PASSO_1S 1048576
/*  1ms = 1s * 10^-3 */
#define PASSO_1MS (int)(PASSO_1S * 0.001)
/*  100Hz */
#define PASSO_10MS (10 * PASSO_1MS)
/*  1Hz */
#define CTRL_DISPLAY (PASSO_1S / PASSO_10MS)
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
    printf("Passo = %d\n", PASSO_1S / PASSO_COMUM);
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
    P3DIR |= PIN_EN;

    /*  Escrevendo */
    P1OUT = 0xFF;
    P3OUT &= ~PIN_EN;
    #endif
}

void confTimerA0 (){
    #ifdef MSP430
    //  Configura divisor por 1
    TA0EX0 = TAIDEX_0;

    //  Controle do PWM
    TA0CCR0 = (PASSO_10MS - 1);

    //  SMCLK como fonte + Divisão po 1 + Modo Up + Clear
    TA0CTL = TASSEL_2 | ID_0 | MC_1 | TACLR;

    //  Habilitar interrupção
    TA0CCTL0 = CCIE;
    #endif
}

void iniciaOperacao (){
    #ifdef MSP430
    contador = CTRL_DISPLAY;

    /*  Liberar contagem do temporizador */
    TA0CTL &= ~TACLR;

    __enable_interrupt();
    #endif
}

#ifdef MSP430
#pragma vector = TIMER0_A0_VECTOR
__interrupt void isrTA0CCR0(void){
    /*  Piscar a 100Hz */
    P3OUT ^= PIN_EN;

    /*  Trocar letra a 1Hz */
    if (!(--contador)){
        P1OUT = display7seg_AC[num++];

        if (num > 0xF) num = 0;

        contador = CTRL_DISPLAY;
    }
}
#endif
