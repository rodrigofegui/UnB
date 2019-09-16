##################################################################
#	Organização e Arquitetura de Computadores - Turma C - 116394
#	Professor:
#		Marcelo Grandi Mandelli
#	Responsáveis:
#		Danillo Neves 		- 14/0135839
#		Luiz Gustavo		- 13/0123293
#		Rodrigo Guimarães	- 14/0170740
#	Finalidades:
#		* Familiarização com o MARS;
#		* Manipulação de imagem em memória.
##################################################################

#########################################################
#	Inclusões prévias
#########################################################
.include	"Biblioteca/Msg_Pad.asm"
.include	"Biblioteca/Man_Sistema.asm"
.include	"Biblioteca/Man_String.asm"
.include	"Biblioteca/Man_Imagem.asm"

#########################################################
#	Dados necessários
#########################################################
.data
dirBase:		.asciiz		"/home/rodrigo/Dropbox/UnB/UnB 2017.1/Organização e Arquitetura de Computadores/Trabalhos/Trabalho 1/"
nomeImgFull:	.asciiz		"Imagens/lenaeye.raw"
nomeImg:		.space		350
endBase:		.word		268697600 #DEC(0x10040000)
endBuffer:		.word		0
areaImg:		.word		4096
negativo:		.word		255	#valor do qual será subtraído as componentes RGB para formar negativo

#########################################################
#	Main
#########################################################
.text
main:
	# Inicialização da aplicação
		PRINT_TELA_IN
		PRINT_STR	(mReq)
		READ_INT	($t0)
	# Armazenando escolha
		PUSH		($t0)
	# Quando a validação estiver pronta, retirar a próxima linha
	# e descomentar a leitura das entradas da LOAD_IMG
		#STR_CAT		(nomeImg, dirBase, nomeImgFull)

	# Escolha da operação a ser executada						
		bne			$t0, 1, Avaliar2
		INS_OBTER_PONTO
	Avaliar2:
		bne			$t0, 2, Avaliar3
		INS_DESENHAR_PONTO
	Avaliar3:
		bne			$t0, 3, Avaliar4
		INS_DESENHAR_BORDA_RET
	Avaliar4:
		bne			$t0, 4, Avaliar5
		INS_INVERTER_IMG
	Avaliar5:
		bne			$t0, 5, AvaliarMain
		INS_CARREGAR_IMG
	AvaliarMain:
	# Recuperando Escolha
		POP			($t0)
		bne			$t0, 0, main		# Não sendo 0, continua
	# Encerrar aplicação
		CLOSE_APP

#########################################################
#	Inclusões posteriores
#########################################################
.include	"Biblioteca/String.asm"
.include	"Biblioteca/Imagem.asm"
