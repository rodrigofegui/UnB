;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
; Responsável:		  Rodrigo Guimarães
; Última mod.:		  26/mar/2017
; Finalidade:       Contar letras, palavras e linhas numa string
; Registradores:    R5  -> início da string
;                   R6  -> final da string
;                   R10 -> contador letras
;                   R11 -> contador palavras
;                   R12 -> contador linhas

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
;Main:       mov     #inicio, R5             ; R5 = início da string
;            mov     #final, R6              ; R6 = final da string
Main:       mov     #texto, R5              ; R5 = início da string
            mov     70(R5), R6              ; R6 = final da string
            clr     R10                     ; R10 = Cont. Letras
            clr     R11                     ; R11 = Cont. Palavras
            mov     #1, R12                 ; R12 = Cont. Linhas
            call    #CONTA                  ; Chamada de sub-rotina
            jmp     $                       ; Travar execução ao retornar da subrotina

;-------------------------------------------------------------------------------
; Sub-rotina: CONTA
;-------------------------------------------------------------------------------
CONTA:      clr     R4                      ; R4 = controle de fluxo
LoopIn:     call    #CharTipo               ; Chamada de sub-rotina
            call    #CharCtrl               ; Chamada de sub-rotina
            cmp     R5, R6                  ; Verificando final da string
            jnz     LoopIn                  ; Havendo, continua
            ret                             ; Finalização da sub-rotina

;-------------------------------------------------------------------------------
; Sub-rotina: charTipo, classificação do tipo de caracter lido
;-------------------------------------------------------------------------------
CharTipo:   mov.b   @R5, R8                 ; R8 = aux, char atual
            cmp     #0x0A, R8               ; Comparando com '\n'
            jeq     CharNewL                ; Sendo, classificar como '\n'
            cmp     #0x41, R8               ; Comparando com 'A'
            jlo     CharInval               ; R8 < 'A', char inválido
            cmp     #0x5B, R8               ; Comparando com 'Z' (indireto)
            jhs     CharInval               ; R8 > 'Z', char inválido
            clr     R7                      ; R7 = sinal letra
            ret                             ; Finalização da sub-rotina
CharNewL:   mov.b   #1, R7                  ; R7 = sinal '\n'
            ret                             ; Finalização da sub-rotina
CharInval:  mov.b   #2, R7                  ; R7 = sinal não letra
            ret                             ; Finalização da sub-rotina

;-------------------------------------------------------------------------------
; Sub-rotina: charCtrl, controle da string, propriamente dito
;-------------------------------------------------------------------------------
CharCtrl:   tst.b   R7                      ; Verificando tipo
            jnz     TratNLetra              ; Tratar de não Letras
            inc     R10                     ; Uma letra lida
            mov.b   #1, R4                  ; Controle = Houve letra
            jmp     FimCharC                ; Próximo char

TratNLetra: tst.b   R4                      ; Verificar ocorrência de letra
            jz      VerNewL                 ; Verificar nova linha
            inc     R11                     ; Uma palavra lida
            clr     R4                      ; Controle = Não houve letra

VerNewL:    cmp     #1, R7                  ; Verificando '\n'
            jne     FimCharC                ; Não sendo, próximo char
            inc     R12                     ; Uma linha lida

FimCharC:   inc     R5                      ; Movimentando na string
            ret                             ; Finalização da sub-rotina

;-------------------------------------------------------------------------------
; Variáveis iniciais
;-------------------------------------------------------------------------------
			.data
                                            ; 0x09 = Tabulação
                                            ; 0x0A = Nova linha
                                            ; 0x20 = Espaço
                                            ; 0x2E = Ponto final
                                            ; GABARITO:
                                            ; Letras = 55
                                            ; Palavras = 13;
                                            ; Linhas = 2
                                            ; Tamanho = 70
texto:      .byte   'L', 'I', 'S', 'T', 'A', 0x20, 'P', 'A', 'R', 'A', 0x20
            .byte   'A', 0x20, 'P', 'R', 'O', 'V', 'A', 0x20, 'U', 'M'
            .byte   0x09, 'V', 'A', 'L', 'E', 'N', 'D', 'O', 0x20
            .byte   'P', 'O', 'N', 'T', 'O', 0x2E, 0x0A
            .byte   'M', 'E', 'L', 'H', 'O', 'R', 0x20
            .byte   'E', 'S', 'T', 'U', 'D', 'A', 'R', 0x20
            .byte   'T', 'I', 'R', 'A', 'R', 0x20, 'B', 'O', A', 0x20
            .byte   'N', 'O', 'T', 'A', 0x2E

;inicio:     .word   0x2400                  ; Início da string
;final:      .word   0x2446                  ; Final = Inicio + 71


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
