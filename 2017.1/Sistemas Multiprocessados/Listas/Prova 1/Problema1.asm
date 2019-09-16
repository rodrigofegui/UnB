;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
; Responsável:		  Rodrigo Guimarães
; Última mod.:		  26/mar/2017
; Finalidade:       Multiplicação de Matrizes genéricas (A*B = C)
; Registradores:    R5  -> matriz A
;                   R6  -> matriz B
;                   R7  -> matriz C
;                   R15 -> Lin(A)
;                   R14 -> Medidas comuns => Col(A) = Lin(B)
;                   R13 -> Col(B)

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
Main:		    mov 	#matrizA, R5			; R5 = matrizA
            mov 	#matrizB, R6			; R6 = matrizB
            mov 	#matrizC, R7			; R7 = matrizC
			      call	#MultiM		   			; Chamada de sub-rotina
FimMain:    jmp 	$						      ; Travar execução ao retornar da subrotina

;-------------------------------------------------------------------------------
; Sub-rotina: MultiM, multiplicação de matrizes
;-------------------------------------------------------------------------------
MultiM:     call    #MultiVal               ; Chamada de sub-rotina
            jnc     FimMultiM               ; Multiplicação impossível
            call    #MultiAtri              ; Chamada de sub-rotina
            call    #MultiCont              ; Chamada de sub-rotina
            setc                            ; Carry sinal concluído
FimMultiM:  ret                             ; Finalização da sub-rotina

;-------------------------------------------------------------------------------
; Sub-rotina: MultiVal, validação da multiplicação
;-------------------------------------------------------------------------------
MultiVal:   mov     R5, R8                  ; R8 = aux matrizA
            mov     R6, R9                  ; R9 = aux matrizB
            mov     @R8, R15                ; R15 = Linhas matrizA = Lin(A)
            incd    R8                      ; Movimentação
            mov     @R9, R4                 ; R4 = aux linhas matrizB
            cmp     @R8, R4                 ; Col(A) ? Lin(B)
            jeq     MultVal                 ; Multiplicação possível
            clrc                            ; Sinal inválido
            jmp     FimMultiV               ; Finalização
MultVal:    mov     @R9, R14                ; R14 = Col(A) = Lin(B)
            incd    R9                      ; Movimentação
            mov     @R9, R13                ; R13 = Colunas matrizB = Col(B)
            setc                            ; Sinal válido
FimMultiV:  ret                             ; Finalização da sub-rotina

;-------------------------------------------------------------------------------
; Sub-rotina: MultiAtri, atribuição das dimensões na matriz C (resultado)
;-------------------------------------------------------------------------------
MultiAtri:  mov     R15, 0(R7)              ; Lin(C) = Lin(A)
            incd    R7                      ; Movimentação
            mov     R13, 0(R7)              ; Col(C) = Col(B)
            incd    R7                      ; Movimentação, já nos dados
            add     #4, R5                  ; Movimentação, já nos dados
FimMultiA:  ret                             ; Finalização da sub-rotina

;-------------------------------------------------------------------------------
; Sub-rotina: MultiCont, operação de multiplicação em si
;-------------------------------------------------------------------------------
MultiCont:
LoopLinA:   push    R5                      ; Salvando última posição A(n, 1)
            mov     #matrizB, R6            ; Recuperando início matrizB
            add     #4, R6                  ; Movimentação, já nos dados
            mov     R13, R10                ; R10 = aux, Col(B)

LoopColB:   push    R6                      ; Salvando última posição B(1, k)
            clr     R8                      ; R8 = soma final
            mov     R14, R9                 ; R9 = contador medidas comuns

LoopLinB:   mov     @R5, R4                 ; R4 = aux (R5)
            mult    @R6, R4                 ; R4 = mult
            add     R4, R8                  ; Somando multi. atual à Sum
            mov     R13, R4                 ; R4 = Col(B)
            mult    #2, R4                  ; Garantindo a palavra
            add     R4, R6                  ; Pulando para B(n+1, k)
            incd    R5                      ; Movimentação
            dec     R9                      ; Célula visitada
            jnz     LoopLinB                ; Havendo linhas em B, continua

            mov     R8, 0(R7)               ; Atribuindo C(n, k)
            incd    R7                      ; Movimentação
            pop     R6                      ; Recuperando posicao B(1, k)
            pop     R5                      ; Recuperando posição A(n, 1)
            incd    R6                      ; Movimentação
            dec     R10                     ; Coluna B, visitada
            jnz     LoopColB                ; Hevendo coluna em B, continua

            mov     R14, R4                 ; R4 = aux, medidas comuns
            mult    #2, R4                  ; Garantindo a palavra
            add     R4, R5                  ; Movimentação A(n+1, 1)
            dec     R15                     ; Lin(A) finalizada
            jnz     LoopLinA                ; Retorna proxima linha

FimMultiC:  ret                             ; Finalização da sub-rotina

;-------------------------------------------------------------------------------
; Variáveis iniciais
;-------------------------------------------------------------------------------
			.data
matrizA:	  .word	2, 4
            .word   -98,    -118,   -91,    12
            .word   -49,    35,     28,     95

matrizB:    .word   4, 2
            .word   12,  -8
            .word   -8,  30
            .word   -54, 7
            .word   -83, -40
                                            ; Gabarito:
                                            ; 3686    −3873
                                            ; -10265  −2162
matrizC     .word   0, 0

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
