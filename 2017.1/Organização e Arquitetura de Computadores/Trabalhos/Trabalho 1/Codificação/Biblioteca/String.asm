#########################################################
#	Nome:
#		String
#	Finalidade:
#		Conjunto de sub-rotinas referente a string,
#		como copiar e limpar
#########################################################

#########################################################
#	Finalidade:
#		Copia de string para um espaço de memória
#	Descrição:
#		Dada uma string (.asciiz) e um espaço de memória
#		reservado (.space), há a cópia do conteúdo da
#		string para o espaço de memória
#	Parâmetros:
#		a0	- string a ser copiada
#		a1	- espaço de memória que acolherá a string
#	Valor retornado:
#		v0 - última posição no resultado
#########################################################
strCpy:
	# Salvando registradores a serem manipulados
		PUSH	($t0)
		PUSH	($t1)
		PUSH	($t2)
		PUSH	($a0)
		PUSH	($a1)
		
		or		$t0, $a0, $zero			# t0 = fonte
		or		$t1, $a1, $zero			# t1 = destino
	LoopStrCpy:
		lb		$t2, ($t0)				# t2 = fonte[t0]
		beq 	$t2, $zero, FStrCpy		# sendo \0, finaliza
		addiu 	$t0, $t0, 1				# movimentação na string
		sb 		$t2, ($t1)				# guardando na memória
		addiu 	$t1, $t1, 1				# movimentação na memória
		b  		LoopStrCpy
		nop
	FStrCpy:
		or	 	$v0, $t1, $zero			# Return last position on result buffer
	# Recuperando registradores manipulados
		POP		($a1)
		POP		($a0)
		POP		($t2)
		POP		($t1)
		POP		($t0)
		jr 		$ra
		nop

#########################################################
#	Finalidade:
#		Concatenação de strings
#	Descrição:
#		Dada duas strings (.asciiz) e um espaço de memória
#		reservado (.space), há a junção do conteúdo das
#		duas string no espaço; conforme ordem apresentada
#	Parâmetros:
#		a0	- string primeira parte
#		a1	- string segunda parte
#		a2	- espaço de memória que acolherá as strings
#	Valor retornado:
#		v0	- última posição no resultado
#########################################################
strCat:
		PUSH	($ra)
		PUSH	($a1)
		or		$a1, $a2, $zero			# põe o espaço como parâmetro
		jal		strCpy
		POP		($a0)
		or		$a1, $v0, $zero			# põe o última posição como parâmetro
		jal		strCpy
		POP		($ra)
		jr		$ra
		nop

#########################################################
#	Finalidade:
#		Limpeza de string
#	Descrição:
#		Dada uma string e seu intervalo de trabalho, todo
#		o conteúdo da mesma será limpo, ou seja, será
#		atribuido '\0'
#	Parâmetros:
#		a0	- string a ser limpa
#		a1	- posição de inicio a ser limpo
#		a2	- tamanho a ser limpo
#	Valor retornado:
#		v0	- última posição no resultado
#########################################################
strClr:
	# Armazenando registradores a serem manipulados
		PUSH	($t0)
		PUSH	($t1)
		PUSH	($a0)
		PUSH	($a1)
		PUSH	($a2)

		add		$t0, $a0, $a1			# configurando posição de início
		move	$t1, $a2
		
	LoopStrClr:
		beq 	$t1, $zero, FStrClr
		sb		$zero, ($t0)
		addiu	$t0, $t0, 1
		addiu	$t1, $t1, -1
		j		LoopStrClr
	FStrClr:
		POP		($a2)
		POP		($a1)
		POP		($a0)
		POP		($t1)
		POP		($t0)
		jr		$ra
		nop
