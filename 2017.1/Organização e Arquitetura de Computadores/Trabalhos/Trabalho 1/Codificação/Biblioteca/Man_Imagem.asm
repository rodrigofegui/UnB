#########################################################
#	Nome:
#		Man_Imagem
#	Finalidade:
#		Conjunto de manipulações referente a imagens,
#		como obter e desenhar ponto
#########################################################

#########################################################
#	Finalidade:
#		Interface GetPoint
#	Descrição:
#		Como a escolha do usuário foi de obter ponto,
#		são lidas as coordenadas do ponto e são exibidas
#		as componentes RGB naquele ponto
#	Parâmetros:
#		Não requer parâmetros
#	Valor retornado:
#		Não possui retorno
#########################################################
.macro	INS_OBTER_PONTO
	# Armazenando os registradores a serem manipulados
		PUSH		($t0)
		PUSH		($t1)
		PUSH		($t2)
		PUSH		($a0)
		PUSH		($a1)
		PUSH		($a2)
		PUSH		($v0)
	# Aquisição das entradas necessárias
		PRINT_STR 	(mNewL)
		PRINT_STR 	(mNewL)
		STR_CAT 	(mFinal, mMrg, mBV)
		STR_ADD		($v0, mTI1)
		STR_ADD		($v0, mNewL)
		STR_ADD		($v0, mDigite)
		STR_ADD		($v0, mDCoorX)
	# Requisitando coordenada X
		PRINT_STR 	(mFinal)
		READ_INT	($t0)
	# Requisitando coordenada Y
		PRINT_STR 	(mDCoorY)
		READ_INT	($t1)
	# Núcleo
		PRINT_STR	(mProcessar)
		move		$a0, $t0
		move		$a1, $t1
		jal			getPonto
		move		$t0, $v0
		move		$t1, $v1
		move		$t2, $a2
	# Exibindo resultados
		PRINT_STR	(mNewL)
		PRINT_COMP	($t0, $t1, $t2)
	# Finalizando função
		PRINT_STR	(mNewL)
		PRINT_STR	(mTermOp)
		PRINT_STR	(mMrg)
		STR_CLR		(mFinal, 2000)
	# Recuperando os registradores manipulados
		POP			($v0)
		POP			($a2)
		POP			($a1)
		POP			($a0)
		POP			($t2)
		POP			($t1)
		POP			($t0)
	# Retorno à principal
		PRESS_CONT
		b			AvaliarMain
.end_macro

#########################################################
#	Finalidade:
#		Interface DrawPonto
#	Descrição:
#		Como a escolha do usuário foi de desenhar um  ponto,
#		são lidas as coordenadas do ponto e os valores
#		das componentes RGB naquele ponto
#	Parâmetros:
#		Não requer parâmetros
#	Valor retornado:
#		Não possui retorno
#########################################################
.macro INS_DESENHAR_PONTO
	# Armazenando os registradores a serem manipulados
		PUSH		($t0)
		PUSH		($t1)
		PUSH		($t2)
		PUSH		($t3)
		PUSH		($t4)
		PUSH		($s0)
		PUSH		($a0)
		PUSH		($a1)
		PUSH		($a2)
		PUSH		($v0)
	# Aquisição das entradas necessárias
		PRINT_STR 	(mNewL)
		PRINT_STR 	(mNewL)	
		STR_CAT 	(mFinal, mMrg, mBV)
		STR_ADD		($v0, mTI2)
		STR_ADD		($v0, mNewL)
		STR_ADD		($v0, mDigite)
		STR_ADD		($v0, mDCoorX)
	# Requisitando coordenada X
		PRINT_STR 	(mFinal)
		READ_INT	($t0)
	# Requisitando coordenada Y
		PRINT_STR 	(mDCoorY)
		READ_INT	($t1)
	# Requisitando componente R
		PRINT_STR	(mCompR)
		READ_INT	($t2)
	# Requisitando componente G
		PRINT_STR	(mCompG)
		READ_INT	($t3)
	# Requisitando componente B
		PRINT_STR	(mCompB)
		READ_INT	($t4)
	# Núcleo
		# DESENVOLVER DRAW_PONTO
		PRINT_STR	(mProcessar)
		move		$a0, $t0				# Linha
		move		$a1, $t1				# Coluna
		move		$a2, $t2				# R
		move		$a3, $t3				# G
		move		$s0, $t4				# B
		jal			drawPonto				# Executando		
	# Exibindo resultados, via BitMap Display
		PRINT_STR	(mNewL)
		PRINT_STR	(mTermOp)
		PRINT_STR	(mVisuBMD)
		PRINT_STR	(mMrg)
		STR_CLR		(mFinal, 2000)
	# Recuperando os registradores manipulados
		POP			($v0)
		POP			($a2)
		POP			($a1)
		POP			($a0)
		POP			($s0)
		POP			($t4)
		POP			($t3)
		POP			($t2)
		POP			($t1)
		POP			($t0)
	# Retorno à função principal
		PRESS_CONT
		b			AvaliarMain
.end_macro

#########################################################
#	Finalidade:
#		Interface DrawBordaRet
#	Descri��o:
#		Como a escolha do usu�rio foi de desenhar uma
#		borda retangular, s�o lidas as coordenadas do
#		inferior esquerdo e superior direito e os valores
#		das componentes RGB
#	Par�metros:
#		Não requer par�metros
#	Valor retornado:
#		N�o possui retorno
#########################################################
.macro INS_DESENHAR_BORDA_RET
	# Armazenando os registradores a serem manipulados
		PUSH		($t0)
		PUSH		($t1)
		PUSH		($t2)
		PUSH		($t3)
		PUSH		($t4)
		PUSH		($t5)
		PUSH		($t6)
		PUSH		($s0)
		PUSH		($s1)
		PUSH		($s2)
		PUSH		($a0)
		PUSH		($a1)
		PUSH		($a2)
		PUSH		($v0)
	# Aquisi��o das entradas necess�rias
		PRINT_STR 	(mNewL)
		PRINT_STR 	(mNewL)
		STR_CAT 	(mFinal, mMrg, mBV)
		STR_ADD		($v0, mTI3)
		STR_ADD		($v0, mNewL)
		STR_ADD		($v0, mDigite)
		STR_ADD		($v0, mPonto1)
		STR_ADD		($v0, mDCoorX)
	# Requisitando coordenada X_i
		PRINT_STR 	(mFinal)
		READ_INT	($t0)
	# Requisitando coordenada Y_i
		PRINT_STR 	(mDCoorY)
		READ_INT	($t1)
		PRINT_STR 	(mPonto2)
	# Requisitando coordenada X_f
		PRINT_STR 	(mDCoorX)
		READ_INT	($t2)
	# Requisitando coordenada Y_f
		PRINT_STR 	(mDCoorY)
		READ_INT	($t3)
	# Requisitando componente R
		PRINT_STR	(mCompR)
		READ_INT	($t4)
	# Requisitando componente G
		PRINT_STR	(mCompG)
		READ_INT	($t5)
	# Requisitando componente B
		PRINT_STR	(mCompB)
		READ_INT	($t6)
	# N�cleo
		PRINT_STR	(mProcessar)
		move		$a0, $t0				# Linha 1
		move		$a1, $t1				# Coluna 1
		move		$a2, $t2				# Linhas 2
		move		$a3, $t3				# Coluna 2
		move		$s0, $t4				# R
		move		$s1, $t5				# G
		move		$s2, $t6				# B
		jal			draw_empty_rectangle	# Executando
	# Exibindo resultados, via BitMap Display
		PRINT_STR	(mNewL)
		PRINT_STR	(mTermOp)
		PRINT_STR	(mVisuBMD)
		PRINT_STR	(mMrg)
		STR_CLR		(mFinal, 2000)
	# Recuperando os registradores manipulados
		POP			($v0)
		POP			($a2)
		POP			($a1)
		POP			($a0)
		POP			($s2)
		POP			($s1)
		POP			($s0)
		POP			($t6)
		POP			($t5)
		POP			($t4)
		POP			($t3)
		POP			($t2)
		POP			($t1)
		POP			($t0)
	# Retorno � fun��o principal
		PRESS_CONT
		b			AvaliarMain
.end_macro

#########################################################
#	Finalidade:
#		Interface InvImagem
#	Descri��o:
#		Como a escolha do usu�rio foi de inverter uma
#		imagem, considerando a imagem j� em mem�ria;
#		troca-se o espa�o de cores e exibe no Bitmap
#		Display
#	Par�metros:
#		N�o requer par�metros
#	Valor retornado:
#		N�o possui retorno
#########################################################
.macro INS_INVERTER_IMG
	# Armazenando os registradores a serem manipulados
		PUSH		($v0)
	# Aquisi��o das entradas necess�rias
		PRINT_STR 	(mNewL)
		PRINT_STR 	(mNewL)	
		STR_CAT 	(mFinal, mMrg, mBV)
		STR_ADD		($v0, mTI4)
		STR_ADD		($v0, mNewL)
		PRINT_STR 	(mFinal)
	# N�cleo
		PRINT_STR	(mProcessar)
		jal		convert_negative					# Executando
	# Exibindo resultados, via BitMap Display
		PRINT_STR	(mNewL)
		PRINT_STR	(mTermOp)
		PRINT_STR	(mVisuBMD)
		PRINT_STR	(mMrg)
		STR_CLR		(mFinal, 2000)
	# Recuperando os registradores manipulados
		POP			($v0)
	# Retorno � fun��o principal
		PRESS_CONT
		b			AvaliarMain
.end_macro

#########################################################
#	Finalidade:
#		Interface LoadImagem
#	Descrição:
#		Como a escolha do usuário foi de carregar uma
#		imagem, pede-se o nome da imagem (com diretório
#		se necessário), o endereço base de manipulação,
#		o endereço do buffer e a área da imagem; será
#		exibida no BitMap Display
#	Parâmetros:
#		Não requer parâmetros
#	Valor retornado:
#		Não possui retorno
#########################################################
.macro INS_CARREGAR_IMG
	# Armazenando os registradores a serem manipulados
		PUSH		($v0)						# Armazerando os registrados que
		PUSH		($a0)						# serão manipulados
		PUSH		($a1)
		PUSH		($a2)
		PUSH		($a3)
	# Aquisição das entradas necessárias
		PRINT_STR 	(mNewL)
		PRINT_STR 	(mNewL)	
		STR_CAT 	(mFinal, mMrg, mBV)
		STR_ADD		($v0, mTI5)
		STR_ADD		($v0, mNewL)
		STR_ADD		($v0, mDigite)
	# Requisitando nome da imagem
		STR_ADD		($v0, mNomeImg)
		PRINT_STR 	(mFinal)
		READ_STR	(nomeImg, 350)
	# Requisitando end. base
		PRINT_STR	(mEndBase)
		READ_INT	($t0)
	# Requisitando end. buffer
		PRINT_STR	(mEndBuffer)
		READ_INT	($t1)
	# Requisitando área da imagem
		PRINT_STR	(mAreaImg)
		READ_INT	($t2)
	# Atribuição prévia para o núcleo
		# Falta ler o endereço base...
		# DESENVOLVER str2hex
		sw			$t0, endBase
		sw			$t1, endBuffer
		sw			$t2, areaImg
	# Núcleo
		PRINT_STR	(mNewL)
		PRINT_STR	(mProcessar)
		la			$a0, nomeImg
		lw			$a1, endBase
		la			$a2, endBuffer
		lw			$a3, areaImg
		jal			imgLoad
	# Exibindo resultados, via BitMap Display
		PRINT_STR	(mNewL)
		PRINT_STR	(mTermOp)
		PRINT_STR	(mVisuBMD)
		PRINT_STR	(mMrg)
		STR_CLR		(mFinal, 2000)
	# Recuperando os registradores manipulados
		POP			($a3)
		POP			($a2)
		POP			($a1)
		POP			($a0)
		POP			($v0)
	# Retorno à função principal
		PRESS_CONT
		b			AvaliarMain
.end_macro

#########################################################
#	Finalidade:
#		Converter (lin, col) para memória
#	Descrição:
#		Dada a localização do pixel na imagem, encontra-se
#		o valor do mesmo em memória
#	Parâmetros:
#		lin		- coordenada da linha
#		col		- coordenada da coluna
#	Valor retornado:
#		v0		- posição de memória correspondente
#########################################################
.macro	COORD2MEM (%lin, %col)
	# Armazenando os registradores a serem utilizados
		PUSH 		($t0)
		PUSH 		($t1)
		PUSH 		($t2)
		PUSH 		($t3)
		PUSH		(%lin)
		PUSH		(%col)
	# Núcleo
		li			$t0, 64				# Largura da imagem
		li			$t1, 4				# Tamanho do pixel em memória
		lw			$t2, endBase		# Endereço base
		addi		%lin, %lin, 1		# Trazer linha para o espaço de 64
		sub			$t3, $t0, %lin		# Determinando a linha relativa correta
		mul			$t3, $t3, $t1		# Garantindo salto de pixels nas linhas
		mul			$t3, $t3, $t0		# Salto para a linha
		mul			%col, %col, $t1		# Garantindo salto de pixels nas colunas
		add			$t3, $t3, %col		# Posição na imagem encontrada
		add			$v0, $t3, $t2		# Posição em memória
	# Recuperando os registradores manipulados
		POP			(%col)
		POP			(%lin)
		POP			($t3)
		POP			($t2)
		POP			($t1)
		POP			($t0)
.end_macro
