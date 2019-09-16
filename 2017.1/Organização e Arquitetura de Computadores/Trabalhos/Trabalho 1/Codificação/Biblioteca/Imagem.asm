#########################################################
#	Nome:
#		Imagem
#	Finalidade:
#		Conjunto de sub-rotinas referente a imagens,
#		como obter e desenhar ponto
#########################################################

#########################################################
#	Finalidade:
#		Obter ponto RGB
#	Descrição:
#		Uma imagem é constituida de pixeis, cada qual
#		com seu valor (cor), representado pelo espaço
#		de cor RGB; dessa forma, dado uma posição na imagem
#		recupera-se as componentes em tal espaço
#	Parâmetros:
#		a0		- coordenada da linha
#		a1		- coordenada da coluna
#	Valor retornado:
#		v0		- valor na componente R
#		v1		- valor na componente G
#		a2		- valor na componente B
#########################################################
getPonto:
	# Armazenando os registradores a serem manipulados
		PUSH		($ra)
		PUSH		($t0)
		PUSH		($t1)
		PUSH		($t2)
		PUSH		($a0)
		PUSH		($a1)
	# Determinar posição de memória real do pixel	
		COORD2MEM	($a0, $a1)
		move		$t0, $v0				# Armazenando posição
		lw			$t1, ($t0)				# Recuperando pixel
	# Recuperando R
		andi		$t2, $t1, 0x00FF0000
		sra			$t2, $t2, 16
		move		$v0, $t2
	# Recuperando G
		andi		$t2, $t1, 0x0000FF00
		sra			$t2, $t2, 8
		move		$v1, $t2
	# Recuperando B
		andi		$t2, $t1, 0x000000FF
		move		$a2, $t2
	# Recuperando os registradores manipulados
		POP			($a1)
		POP			($a0)
		POP			($t2)
		POP			($t1)
		POP			($t0)
		POP			($ra)
	# Fim
		jr			$ra

#########################################################
#	Finalidade:
#		Desenhar ponto RGB
#	Descrição:
#		Uma imagem é constituida de pixeis, cada qual
#		com seu valor (cor), representado pelo espaço
#		de cor RGB; dessa forma, dado uma posição na imagem
#		e um valor de uma cor, em tal espaço, é possível
#		desenha-lo numa imagem
#	Parâmetros:
#		a0		- coordenada da linha
#		a1		- coordenada da coluna
#		a2		- valor na componente R
#		a3		- valor na componente G
#		s0		- valor na componente B
#	Valor retornado:
#		Posição da memória, referente ao pixel, com a cor
#		modificada
#########################################################
drawPonto:
	# Armazenando os registradores a serem manipulados
		PUSH		($ra)
		PUSH		($t0)
		PUSH		($t1)
		PUSH		($a0)
		PUSH		($a1)
		PUSH		($a2)
		PUSH		($a3)
		PUSH		($s0)
	# Determinar posição de memória real do pixel	
		COORD2MEM	($a0, $a1)
		move		$t0, $v0
	# Montando valor do pixel
		sll			$t1, $a2, 16
		sll			$a3, $a3, 8
		xor			$t1, $a3, $t1
		xor			$t1, $s0, $t1
	# Armazenando na memória
		sw			$t1, ($t0)
	# Recuperando os registradores manipulados
		POP			($s0)
		POP			($a3)
		POP			($a2)
		POP			($a1)
		POP			($a0)
		POP			($t1)
		POP			($t0)
		POP			($ra)
	# Fim
		jr			$ra

		
#########################################################
#	Finalidade:
#		Carregar imagem para o display
#	Descrião:
#		Dada uma imagem e suas configurações, é possível
#		abri-lá e carregá-la no display do BitMap Display
#	Parâmetros:
#		a0	- nome da imagem 
#		a1	- endereço base para o display
#		a2	- configuração do MARS
#		a3	- tamanho total da imagem
#	Valor retornado:
#		Memória preenchida com os pixels da imagem
#########################################################
imgLoad:
	# Armazenando os registrados a serem manipulados
		PUSH	($ra)
		PUSH	($t0)
		PUSH	($t1)
		PUSH	($t2)
		PUSH	($t3)
		PUSH	($a0)
		PUSH	($a1)
		PUSH	($a2)
		PUSH	($a3)
	Conf:
		move	$t0, $a1			# Endereco de carga
		move	$t1, $a2			# Buffer para leitura de um pixel do arquivo
	OpenFile:
		li		$v0, 13				# System call para abertura de arquivo
		li		$a1, 0				# Abre arquivo para leitura (parâmtros são 0: leitura, 1: escrita)
		li		$a2, 0				# Modo é ignorado
		syscall						# Abre um arquivo (descritor do arquivo é retornado em $v0)
		move	$a0, $v0			# Descritor do arquivo 
		move	$a1, $t1      		# Endereço do buffer 
		li		$a2, 3      		# Largura do buffer
	LoopImgLoad:
		beq		$a3, $zero, ClsFile
		li		$v0, 14       		# System call para leitura de arquivo
		syscall						# Lê o arquivo
		lw		$t2, 0($a1)			# Lê pixel do buffer	
		sw		$t2, 0($t0)			# Escreve pixel no display
		addi	$t0, $t0, 4			# Próximo pixel
		addi	$a3, $a3, -1		# Decrementa contador
		j		LoopImgLoad
	ClsFile:  
		li		$v0, 16				# System call para fechamento do arquivo
		syscall						# Fecha arquivo
	# Recuperando registradores manipulados
		POP		($a3)
		POP		($a2)
		POP		($a1)
		POP		($a0)
		POP		($t3)
		POP		($t2)
		POP		($t1)
		POP		($t0)
		POP		($ra)
		jr $ra
		
		
#########################################################
#	Finalidade:
#		Desenhar retângulo no Bitmap Display
#	Descrição:
#		O usuário infoma dois pontos. Temos três casos:
#		uma reta, um ponto ou formar retângulo.
#		O retângulo é construído com as componentes
#		RGB informadas pelo usuário.
#	Parâmetros:
#		a0		- linha ponto inicial (xi)
#		a1		- coluna ponto inicial (yi)
#		a2		- linha ponto final (xf)
#		a3		- coluna ponto final (yf)
#		so		- componente R
#		s1		- componente G
#		s2		- componente B
#	Valor retornado:
#		O retorno é a imagem no Bitmap Display
#########################################################
draw_empty_rectangle:
	# Armazenando os registrados a serem manipulados
		PUSH		($ra)
		PUSH		($v0)
		PUSH		($a0)
		PUSH		($a1)
		PUSH		($a2)
		PUSH		($a3)
		PUSH		($s0)
		PUSH		($s1)
		PUSH		($s2)
	define_RGB:								# aqui é formado a componente RGB a partir do parametros do usuario
		sll			$t0, $s0, 16			# desloca 2 bytes para formar componente R
		sll			$s1, $s1, 8				# desloca 1 byte para formar componente G
		xor			$t0, $t0, $s1			# agrupa componentes R e G
		xor			$t0, $s2, $t0			# forma RGB

		sub			$t1, $a2, $a0			# t1 recebe delta x, diferença entre xf e xi (pode ser positiva ou negativa)
		sub			$t2, $a3, $a1			# t2 recebe delta y, diferença entre yf e yi (pode ser positiva ou negativa)
		beq			$t1, $zero, Caso1_DERec
		j			Caso2_DERec
	# xi = xf
	Caso1_DERec:
		# yi = yf
		beq			$a1, $a3, ApenasPonto_DERec
		# yi != yf, forma reta horizontal
		j			ArestaHorizontal_DERec
	# xi != xf
	Caso2_DERec:
		# yi = yf, forma reta vertical
		beq			$a1, $a3, ArestaVertical_DERec
		# yi != yf, forma retângulo
		j			retangulo
	# desenha ponto inicial
	ApenasPonto_DERec:
		COORD2MEM	($a0, $a1)
		move		$t5, $v0
		sw			$t0, ($t5)
		jr			$ra
	# desenha ponto final
	PontoFinal_DERec:	
		COORD2MEM	($a2, $a3)
		move		$t5, $v0
		sw			$t0, ($t5)
		jr			$ra
	# desenha reta horizontal
	ArestaHorizontal_DERec:
		PUSH		($ra)
		# ponto inicial
		jal			ApenasPonto_DERec
		POP			($ra)
		# demais pontos
		LoopHorizontal_DERec:
			add			$t4, $a1, $t2						# t4 recebe yi + delta y
			COORD2MEM	($a0, $t4)
			move		$t5, $v0
			sw			$t0, ($t5)
		
			slt			$t6, $t2, $zero
			bne			$t6, $zero, DifNegativa_DERec
			addi		$t2, $t2, -1						# decrementa delta y, caso seja positivo
			bne			$t2, $zero, LoopHorizontal_DERec	# loop ocorre até o contador zerar
			j			Fim_DERec
		# caso para incrementar contador delta y, caso ele seja negativo
		DifNegativa_DERec:	
			addi		$t2, $t2, 1
			bne			$t2, $zero, LoopHorizontal_DERec
			j			Fim_DERec
	# Desenha reta vertical
	ArestaVertical_DERec:
		PUSH			($ra)
		jal				ApenasPonto_DERec
		POP				($ra)
		# demais pontos
		LoopVertical_DERec:
			add			$t4, $a0, $t1						# t4 recebe xi + delta x
			COORD2MEM	($t4, $a1)
			move		$t5, $v0
			sw			$t0, ($t5)
		
			slt			$t6, $t1, $zero
			bne			$t6, $zero, DifNegativa2_DERec
			addi		$t1, $t1, -1						# decrementa contador delta x, caso seja positivo
			bne			$t1, $zero, LoopVertical_DERec		# loop ocorre até o contador zerar
			j			Fim_DERec
		# caso para incrementar contador delta x, caso ele seja negativo
		DifNegativa2_DERec:
			addi		$t1, $t1, 1
			bne			$t1, $zero, LoopVertical_DERec
			j			Fim_DERec
	#desenha retângulo
	retangulo:	
		PUSH			($ra)
		jal				ApenasPonto_DERec					# desenha ponto inicial
		jal				PontoFinal_DERec
		POP				($ra)
		# loop para desenhar arestas verticais do retângulo
		Loop1Retangulo_DERec:
			add			$t3, $a0, $t1						# t3 recebe xi + delta x
			sub			$t4, $a2, $t1						# t4 recebe xf - delta x
			COORD2MEM	($t3, $a1)
			move		$t5, $v0
			sw			$t0, ($t5)
			COORD2MEM	($t4, $a3)
			move		$t5, $v0
			sw			$t0, ($t5)
			
			slt 		$t6, $t1, $zero
			bne			$t6, $zero, DifNegativa3_DERec
			addi		$t1, $t1, -1						# decrementa contador, caso seja positivo
			bne			$t1, $zero, Loop1Retangulo_DERec 	# loop ocorre até zerar o contador
			j			Loop2Retangulo_DERec
		# caso para incrementar o contador, caso seja negativo
		DifNegativa3_DERec:	
			addi		$t1, $t1, 1
			bne			$t1, $zero, Loop1Retangulo_DERec
		# loop para desenhar arestas horizontais do ret�ngulo
		Loop2Retangulo_DERec:	
			add			$t6, $a1, $t2						# t6 recebe yi + delta y
			sub			$t4, $a3, $t2						# t4 recebe yf - delta y
			COORD2MEM	($a0, $t6)
			move		$t5, $v0
			sw			$t0, ($t5)
			COORD2MEM	($a2, $t4)
			move		$t5, $v0
			sw			$t0, ($t5)	
					
			slt			$t6, $t2, $zero
			bne			$t6, $zero, DifNegativa4_DERec	
			addi		$t2, $t2, -1						# decrementa contador, caso seja positivo
			bne			$t2, $zero, Loop2Retangulo_DERec	# loop ocorre até zerar o contador
			j			Fim_DERec
		# caso para incrementar o contador, caso seja negativo
		DifNegativa4_DERec: 
			addi		$t2, $t2, 1
			bne			$t2, $zero, Loop2Retangulo_DERec
			j			Fim_DERec
			
	Fim_DERec:
		POP		($s2)
		POP		($s1)
		POP		($s0)
		POP		($a3)
		POP		($a2)
		POP		($a1)
		POP		($a0)
		POP		($v0)
		POP		($ra)
		
		jr	$ra
		
#########################################################
#	Finalidade:
#		Fazer o negativo de uma dada imagem ja em mem�ria
#	Descri��o:
#		J� com uma imagem carregada no Bitmap Display, se 
#		o usu�rio desejar ele pode obter o negativo da imagem
#		com o uso da fun��o.
#	Par�metros:
#		N�o h� par�metros
#	Valor retornado:
#		O retorno � a imagem no Bitmap Display
#########################################################
convert_negative:
  lw $t1, negativo
  lw $a1, endBase
  lw $a3, areaImg
  
	loop_negativo:	#loop para percorrer imagem e negativ�-la
		beq  $a3, $zero, fim_negativo	#loop ocorre ate percorrer todos os pixels do display
  
		lbu	$t2, 0($a1)	#carrega componente B
		sub	$t2,$t1,$t2	#negativa componente B
  
		lbu	$t3,1($a1)	#carrega componente G
		sub	$t3,$t1,$t3	#negativa componente G
		sll	$t3,$t3,8	#desloca 1 byte para posi��o da componente G
		add	$t0,$t3,$t2	#agrupa com componente B
  
		lbu	$t4,2($a1)	#carrega componente R
		sub	$t4,$t1,$t4	#negativa componente R
		sll	$t4,$t4,16	#desloca 2 bytes para posi�ao da componente R
		add	$t0,$t0,$t4	#agrupa formando componente RGB negativa
  
		sw	$t0,0($a1)	#escreve o pixel negativo no display
  
		addi $a1, $a1, 4   # proximo pixel
		addi $a3, $a3, -1  # decrementa contador
  
		j loop_negativo
  
	fim_negativo:	#t�rmino da funcao
		jr $ra
