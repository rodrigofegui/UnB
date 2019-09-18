;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
; Responsável:		Rodrigo Guimarães
; Última mod.:		26/mar/2017
; Finalidade:       Gerar números pseudo-aleatorios, considerando o LFSR
; Registradores:    R5  -> número gerado

;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file

;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
			      .text
Main:       mov     #0, R5                  ; R5 = nº pseudo-aleatório
            call    #ALEAT                  ; Chamada de sub-rotina
            jmp     $                       ; Travar execução ao retornar da subrotina

;-------------------------------------------------------------------------------
; Sub-rotina: ALEAT, gerar nº pseudo-aleatorio
;-------------------------------------------------------------------------------
ALEAT:      mov     #1, R7                  ; R7 = fonte
			      mov		  #65536, R8				      ; R8 = qnt sem repetição
LoopIn:     mov     R7, R4                  ; R4 = aux
            mov     R7, R6                  ; R6 = aux
            and     #0x0001, R4             ; R4 = 16º bit
            and     #0x0004, R6             ; R6 = 14º bit
            xor     R4, R6                  ; R6 = R6 xor R4
            mov     R7, R4                  ; R4 = aux
            and     #0x0010, R4             ; R4 = 12º bit
            xor     R4, R6                  ; R6 = R6 xor 12
            mov     R7, R4                  ; R4 = aux
            and     #0x0020, R4             ; R4 = 11º bit
            xor     R4, R6                  ; R6 bit final
            tst     R6                      ; Verificando bit resultado
            jne     Carry1                  ; Sendo 1
            clrc                            ; Senão, limpa carry
            jmp     Giro
Carry1:     setc                            ; Configura 1 no carry
Giro:       rrc     R7                      ; Carry no MSB, R7
            rrc     R5                      ; Jogando LSB no Resultado
			      dec		  R8						          ; Nº gerado
            jnz		  LoopIn					        ; Ainda havendo, continua
            ret

;-------------------------------------------------------------------------------
; Variáveis iniciais
;-------------------------------------------------------------------------------
			.data


;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack

;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
