#########################################################
#	Nome:
#		Man_Sistema
#	Finalidade:
#		Conjunto de manipulações referente ao sistema,
#		como manipulação em pilha e syscall
#########################################################

#########################################################
#	Finalidade:
#		Encerrar execução da aplicação
#	Descrição:
#		Encerrar aplicação atual junto ao processador
#	Parâmetros:
#		Não requisita parâmetros
#	Valor retornado:
#		Não possui valor de retorno
#########################################################
.macro	CLOSE_APP
		PUSH	($v0)
		
		li		$v0, 10
		syscall

		POP		($v0)
.end_macro

#########################################################
#	Finalidade:
#		Empilhar
#	Descrição:
#		Dado um valor, um registrador, o mesmo é empilhado
#		para preservação do valor para futura recuperação
#	Parâmetros:
#		in		- valor a ser armazenado na pilha
#	Valor retornado:
#		Não possui valor de retorno
#########################################################
.macro	PUSH (%in)
		addi	$sp, $sp, -4
		sw		%in, ($sp)
.end_macro

#########################################################
#	Finalidade:
#		Desempilhar
#	Descrição:
#		Recuperação do dado armazenado no topo da pilha,
#		efetivando sua retirada
#	Parâmetros:
#		out		- recipiente para o elemento da pilha
#	Valor retornado:
#		Não possui valor de retorno
#########################################################
.macro	POP (%out)
		lw		%out, ($sp)
		addi	$sp, $sp, 4		
.end_macro

#########################################################
#	Finalidade:
#		Escrever no terminal
#	Descrição:
#		Dada um inteiro qualquer, escrever no terminal
#		de comunicação com o usuário tal string
#	Parâmetros:
#		int		- inteiro a ser escrito
#	Valor retornado:
#		Não possui valor de retorno
#########################################################
.macro	PRINT_INT (%int)
		PUSH	($a0)
		PUSH	($v0)

		add		$a0, %int, $zero
		li		$v0, 1
		syscall
		
		POP		($v0)
		POP		($a0)
.end_macro

#########################################################
#	Finalidade:
#		Escrever no terminal
#	Descrição:
#		Dada um inteiro qualquer, escrever no terminal
#		de comunicação com o usuário tal string, em hex
#	Parâmetros:
#		int		- inteiro a ser escrito
#	Valor retornado:
#		Não possui valor de retorno
#########################################################
.macro	PRINT_HEX (%int)
		PUSH	($a0)
		PUSH	($v0)

		add		$a0, %int, $zero
		li		$v0, 34
		syscall
		
		POP		($v0)
		POP		($a0)
.end_macro

#########################################################
#	Finalidade:
#		Escrever no terminal
#	Descrição:
#		Dada uma string qualquer, escrever no terminal
#		de comunicação com o usuário tal string
#	Parâmetros:
#		str		- string a ser escrita
#	Valor retornado:
#		Não possui valor de retorno
#########################################################
.macro	PRINT_STR (%str)
		PUSH	($a0)
		PUSH	($v0)

		la		$a0, %str
		li		$v0, 4
		syscall
		
		POP		($v0)
		POP		($a0)
.end_macro

#########################################################
#	Finalidade:
#		Ler do terminal
#	Descrição:
#		Receber dados fornecidos pelo usuário através
#		da interface do terminal; com o acréscimo de uma
#		mensagem padrão
#	Parâmetros:
#		int		- registrador que armazenará o valor lido
#	Valor retornado:
#		Inteiro fornecido pelo usuário
#########################################################
.macro	READ_INT (%int)
		PUSH	($v0)

		li		$v0, 5
		syscall
		move	%int, $v0
		
		POP		($v0)	
.end_macro

#########################################################
#	Finalidade:
#		Ler do terminal
#	Descrição:
#		Receber dados fornecidos pelo usuário através
#		da interface do terminal; com o acréscimo de uma
#		mensagem padrão
#	Parâmetros:
#		chr		- registrador que armazenará o valor lido
#	Valor retornado:
#		Char fornecido pelo usuário
#########################################################
.macro	READ_CHAR (%chr)
		PUSH		($v0)

		li			$v0, 12
		syscall
		move		%chr, $v0
		
		POP			($v0)
.end_macro

#########################################################
#	Finalidade:
#		Ler do terminal
#	Descrição:
#		Receber dados fornecidos pelo usuário através
#		da interface do terminal; com o acréscimo de uma
#		mensagem padrão
#	Parâmetros:
#		ini		- registrador que armazena o início da
#				string
#		tam		- registrador que armazena o tamanho máx
#	Valor retornado:
#		Char fornecido pelo usuário
#########################################################
.macro	READ_STR (%ini, %tam)
		PUSH		($v0)
		PUSH		($a0)
		PUSH		($a1)

		li			$v0, 8
		la			$a0, %ini
		li			$a1, %tam
		syscall
		
		POP			($a1)
		POP			($a0)
		POP			($v0)
.end_macro

#########################################################
#	Finalidade:
#		Delay
#	Descrição:
#		Dada uma duração, em milisegundos, espera-se
#		ociosamente até a continuação das atividades
#	Parâmetros:
#		tmp		- tempo a ser empregado o delay
#	Valor retornado:
#		Inteiro fornecido pelo usuário
#########################################################
.macro	DELAY (%tmp)
		PUSH	($a0)
		PUSH	($v0)

		li		$a0, %tmp
		li		$v0, 32
		syscall
		
		POP		($v0)
		POP		($a0)
.end_macro

#########################################################
#	Finalidade:
#		Exibir tela inicial
#	Descrição:
#		Fornecer ao usuários todas as operações disponíveis
#		na aplicação, dando uma visão geral e modo de uso
#		das mesmas
#	Parâmetros:
#		Não requer parâmetros
#	Valor retornado:
#		Não possui retorno
#########################################################
.macro	PRINT_TELA_IN
		STR_CAT (mFinal, mMrg, mTG)
	#Exibindo Operação 1
		STR_ADD	($v0, mTI1)
		STR_ADD	($v0, mI1Cp0)
		STR_ADD	($v0, mI1Cp1)
		STR_ADD	($v0, mI1Cp2)
		STR_ADD	($v0, mI1Cp3)
		STR_ADD	($v0, mI1Cp4)
	#Exibindo Operação 2
		STR_ADD	($v0, mTI2)
		STR_ADD	($v0, mI2Cp0)
		STR_ADD	($v0, mI2Cp1)
		STR_ADD	($v0, mI2Cp2)
		STR_ADD	($v0, mI2Cp3)
		STR_ADD	($v0, mI2Cp4)
		STR_ADD	($v0, mI2Cp5)
	#Exibindo Operação 3
		STR_ADD	($v0, mTI3)
		STR_ADD	($v0, mI3Cp0)
		STR_ADD	($v0, mI3Cp1)
		STR_ADD	($v0, mI3Cp2)
		STR_ADD	($v0, mI3Cp3)
		STR_ADD	($v0, mI3Cp4)
		STR_ADD	($v0, mI3Cp5)
		STR_ADD	($v0, mI3Cp6)
		STR_ADD	($v0, mI3Cp7)
	#Exibindo até o momento
		PRINT_STR (mFinal)
		STR_CLR	(mFinal, 2000)
	#Exibindo Operação 4
		STR_CAT (mFinal, mTI4, mI4Cp0)
		STR_ADD	($v0, mI4Cp1)
		STR_ADD	($v0, mI4Cp2)
		STR_ADD	($v0, mI4Cp3)
		STR_ADD	($v0, mI4Cp4)
	#Exibindo Operação 5
		STR_ADD	($v0, mTI5)
		STR_ADD	($v0, mI5Cp0)
		STR_ADD	($v0, mI5Cp1)
		STR_ADD	($v0, mI5Cp2)
		STR_ADD	($v0, mI5Cp3)
		STR_ADD	($v0, mI5Cp4)
		STR_ADD	($v0, mI5Cp5)
	#Exibindo Operação 6
		STR_ADD	($v0, mTI6)
		STR_ADD	($v0, mI6Cp0)
	#Finalização
		STR_ADD	($v0, mMrg)
		PRINT_STR (mFinal)
		STR_CLR	(mFinal, 2000)
.end_macro

#########################################################
#	Finalidade:
#		Exibir componentes RGB
#	Descrição:
#		Fornecer ao usuários todas as componentes de um
#		pixel, no espaço de cores RGB; nessa sequência
#	Parâmetros:
#		R	- Valor da componente R
#		G	- Valor da componente G
#		B	- Valor da componente B
#	Valor retornado:
#		Não possui retorno
#########################################################
.macro	PRINT_COMP (%R, %G, %B)
		PRINT_STR	(mCompR)
		PRINT_INT	(%R)
		PRINT_STR	(mNewL)
		PRINT_STR	(mCompG)
		PRINT_INT	(%G)
		PRINT_STR	(mNewL)
		PRINT_STR	(mCompB)
		PRINT_INT	(%B)
		PRINT_STR	(mNewL)
.end_macro

#########################################################
#	Finalidade:
#		Pausa por tecla
#	Descrição:
#		Pausa na aplicação, controlada pela entrada de
#		qualquer tecla por meio do usuário
#	Parâmetros:
#		Não requer parâmetros
#	Valor retornado:
#		Não possui retorno
#########################################################
.macro	PRESS_CONT
		PRINT_STR	(mPQlqTecla)
		READ_CHAR	($a0)
.end_macro
