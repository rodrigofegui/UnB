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
 #define ATZ_100us       3                   // Medido 104 useg (3)
 #define ATZ_500us       (9    * ATZ_100us)  // Medido 513 useg (27)
 #define ATZ_1ms         (2.1  * ATZ_500us)  // Medido 1,08 mseg (56)

/*  1seg = 2^20 (Sem alterar o SMCLK) */
#define PASSO_1S 1048576
/*  1ms = 1s * 10^-3 */
#define PASSO_1MS (int)(PASSO_1S * 0.001)
/*  100Hz */
#define PASSO_10MS (10 * PASSO_1MS)
#define LSByte 0x0F
#define MSByte 0xF0
#define PINOS_MASTER 3
unsigned int ctrlScan;
unsigned char tecla;

/*****************************************************************
 *  Protótipo Funções desenvolvidas
 ****************************************************************/
void iniciaPinos ();
void confTimerA0 ();
void iniciaOperacao ();
#ifdef MSP430
__interrupt void isrTA0CCR0(void);
#endif
char tecladoLe ();
char getTecla ();
void delay (unsigned long temp);
void delay_ms (unsigned long temp);

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
    /*  Configuranto como saída, as varreduras */
    P1DIR |= MSByte;

    /*  Escrevendo em alta */
    P1OUT = MSByte;

    /*  Configurando como entrada */
    P1DIR &= ~LSByte;
    P1REN = LSByte;
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
    ctrlScan = 0;

    /*  Liberar contagem do temporizador */
    TA0CTL &= ~TACLR;

    __enable_interrupt();
    #endif
}

#ifdef MSP430
#pragma vector = TIMER0_A0_VECTOR
__interrupt void isrTA0CCR0(void){
    char leitura;

    if (tecla == '\0'){
        for (ctrlScan = 0; ctrlScan < 3; ctrlScan++){
            leitura = tecladoLe;

            switch (leitura) {
                case ~BIT0:
                    switch (ctrlScan) {
                        case 0:
                            tecla = '*';
                            break;
                        case 1:
                            tecla = '0';
                            break;
                        case 2:
                            tecla = '#';
                            break;
                    }
                    break;
                case ~BIT1:
                    switch (ctrlScan) {
                        case 0:
                            tecla = '7';
                            break;
                        case 1:
                            tecla = '8';
                            break;
                        case 2:
                            tecla = '9';
                            break;
                    }
                    break;
                case ~BIT2:
                    switch (ctrlScan) {
                        case 0:
                            tecla = '4';
                            break;
                        case 1:
                            tecla = '5';
                            break;
                        case 2:
                            tecla = '6';
                            break;
                    }
                    break;
                case ~BIT3:
                    switch (ctrlScan) {
                        case 0:
                            tecla = '1';
                            break;
                        case 1:
                            tecla = '2';
                            break;
                        case 2:
                            tecla = '3';
                            break;
                    }
                    break;
                default:
                    tecla = '\0';
            }
        }
    }
}
#endif

char tecladoLe (){
    int leitura = ABERTA;

    leitura = !(P1IN & LSByte);

    delay_ms (25);

    return leitura;
}

char getTecla (){
    char result = tecla;

    tecla = '\0';

    return result;
}

void delay (unsigned long temp){
    volatile unsigned long cont = temp;

    while(cont != 0) cont--;
}

/*
 * Pausa na execução em milisegundos
 */
void delay_ms (unsigned long temp){
    delay (ATZ_1ms * temp);
}
