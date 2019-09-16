#########################################################
#	Nome:
#		Msg_Pad
#	Finalidade:
#		Conjunto de mensagens padrão
#########################################################

.data
	mFinal:		.space		2000
	mNewL:		.asciiz		"\n"
	mMrg:		.asciiz		"*****************************************************************\n"
	mTG:		.asciiz		"Operações disponiveis:\n"
	mBV:		.asciiz		"Foi escolhida a operação:\n"
	
	mTI1:		.asciiz		"   1 - Obter ponto:\n"
	mI1Cp0:		.asciiz		"       Resumo: para uma dada imagem é possível recuperar o\n"
	mI1Cp1:		.asciiz		"               valor do píxel (RGB) numa posição (x,y) desejada.\n"
	mI1Cp2:		.asciiz		"       Modo de Uso: informar a posição desejada: linha (x)\n"
	mI1Cp3:		.asciiz		"               e coluna (y); será retornado o valor do píxel em\n"
	mI1Cp4:		.asciiz		"               componentes RGB.\n\n"

	mTI2:		.asciiz		"   2 - Desenha ponto:\n"
	mI2Cp0:		.asciiz		"       Resumo: para uma dada imagem é possivel trocar o\n"
	mI2Cp1:		.asciiz		"               valor de um dado pixel (RGB) numa posição (x, y)\n"
	mI2Cp2:		.asciiz		"               desejada.\n"
	mI2Cp3:		.asciiz		"       Modo de Uso: informar a posição desejada: linha (x),\n"
	mI2Cp4:		.asciiz		"               coluna (y), além dos valores RGB; será retornado\n"
	mI2Cp5:		.asciiz		"               o pixel manipulado, com exibição no BitMapDisplay.\n\n"
	
	mTI3:		.asciiz		"   3 - Desenha borda retângular:\n"
	mI3Cp0:		.asciiz		"       Resumo: para um dada imagem é possível desenhar uma borda\n"
	mI3Cp1:		.asciiz		"               retangular, considerando as suas esquinas (canto\n"
	mI3Cp2:		.asciiz		"               inferior esquerdo e canto superior direito) e o\n"
	mI3Cp3:		.asciiz		"               valor de sua cor (RGB).\n"
	mI3Cp4:		.asciiz		"       Modo de Uso: informar as posições desejadas: linha inferior\n"
	mI3Cp5:		.asciiz		"               (xi), coluna inferior (y1), linha superior (xf),\n"
	mI3Cp6:		.asciiz		"               canto superior (yf), além dos valores RGB. Será\n"
	mI3Cp7:		.asciiz		"               retornado a borda desenhada, com exibição no BitMapDisplay.\n\n"
		
	mTI4:		.asciiz		"   4 - Inverter Cores:\n"
	mI4Cp0:		.asciiz		"       Resumo: para uma dada imagem é possível transformala no seu\n"
	mI4Cp1:		.asciiz		"               negativo, ou seja, transformar do espaço RGB para o CMYK.\n"
	mI4Cp2:		.asciiz		"       Modo de Uso: não requer parâmetros, uma vez que realiza tal operação\n"
	mI4Cp3:		.asciiz		"               com a imagem já armazenada no BitMapDisplay. Será exibido o\n"
	mI4Cp4:		.asciiz		"               resultado no mesmo.\n\n"
		
	mTI5:		.asciiz		"   5 - Carregar Imagem:\n"
	mI5Cp0:		.asciiz		"       Resumo: para uma dada imagem é possível carrega-lá para a aplicação,\n"
	mI5Cp1:		.asciiz		"               disponibilizando-a para as manipulações já descritas.\n"
	mI5Cp2:		.asciiz		"       Modo de Uso: informa o nome da imagem, se a mesma estiver no mesmo\n"
	mI5Cp3:		.asciiz		"               diretório que a aplicação, caso contrário inserir o destino,\n"
	mI5Cp4:		.asciiz		"               o endereço base para a manipulação, endereço de memória como buffer,\n"
	mI5Cp5:		.asciiz		"               e área, em pixels, da imagem.\n\n"
	
	mTI6:		.asciiz		"   0 - Encerra:\n"
	mI6Cp0:		.asciiz		"       Resumo: encerra a aplicação.\n\n"
	
	mReq:		.asciiz 	"\nPor favor, digite o valor desejado:\n"
	mConf:		.asciiz		"\nApenas conferindo valor:\n"

	mDigite:	.asciiz		"Digite, conforme requisitado:\n"
	mProcessar:	.asciiz		"\nA processar..."
	mTermOp:	.asciiz		"\nA operação acabou...\n"
	mVisuBMD:	.asciiz		"Resultado disponível no BitMap Display\n"
	mPonto1:	.asciiz		"Ponto 1\n"
	mPonto2:	.asciiz		"Ponto 2\n"
	mOpInv:		.asciiz		"\nOperação não realizada! Erros na validação dos dados:\n\tVerifique os dados fornecidos.\n"
	mPQlqTecla:	.asciiz		"\nPrecione QUALQUER TECLA para continuar\n"

	mDCoorX:	.asciiz		"Coordenada x (linha):\n"
	mDCoorY:	.asciiz		"Coordenada y (coluna):\n"

	mCompR:		.asciiz		"Componente R (red):\n"
	mCompG:		.asciiz		"Componente G (green):\n"
	mCompB:		.asciiz		"Componente B (blue):\n"
	
	mNomeImg:	.asciiz		"Nome da imagem (com diretório completo, de preferência, ou o relativo ao MARS):\n"
	mEndBase:	.asciiz		"Endereço base (em HEX (0x) ou DEC):\n"
	mEndBuffer:	.asciiz		"Endereço do buffer:\n"
	mAreaImg:	.asciiz		"Área da imagem (linhas x colunas):\n"
