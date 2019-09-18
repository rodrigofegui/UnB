#########################################################
#	Nome:
#		Man_String
#	Finalidade:
#		Conjunto de manipulações referente às string,
#		interfaciando os métodos desenvolvidos
#########################################################

########################################################
#	Finalidade:
#		Adicionar strings
#	Descrição:
#		Dado uma posição de memória e uma string, a mesma
#		será escrita a partir da posição de memória informada
#	Parâmetros:
#		inico	- posição de memória que começará a string
#		str		- string a ser escrita
#	Valor retornado:
#		v0	- última posição no resultado
#########################################################
.macro	STR_ADD (%inicio, %str)
		PUSH	($a0)
		PUSH	($a1)
		
		la		$a0, %str
		la		$a1, (%inicio)
		jal		strCpy
		
		POP		($a1)
		POP		($a0)
.end_macro

#########################################################
#	Finalidade:
#		Concatenação de strings
#	Descrição:
#		Dado duas strings, a concatenação será armazenada
#		no espaço de memória armazenado no destino
#	Parâmetros:
#		dest	- resultado da concatenação
#		str1	- string primeira parte
#		str2	- string segunda parte
#	Valor retornado:
#		v0	- última posição no resultado
#########################################################
.macro	STR_CAT (%dest, %str1, %str2)
		PUSH	($a0)
		PUSH	($a1)
		PUSH	($a2)

		la		$a0, %str1
		la		$a1, %str2
		la		$a2, %dest
		jal		strCat
		
		POP		($a2)
		POP		($a1)
		POP		($a0)
.end_macro

#########################################################
#	Finalidade:
#		Limpeza de string
#	Descrição:
#		Dada uma string e seu intervalo de trabalho, todo
#		o conteúdo da mesma será limpo, ou seja, será
#		atribuido '\0'
#	Parâmetros:
#		str	- string a ser limpa
#		in	- posição de inicio a ser limpo
#		tam	- tamanho a ser limpo
#	Valor retornado:
#		v0	- última posição no resultado
#########################################################
.macro	STR_CLR	(%str, %in, %tam)
		PUSH	($a0)
		PUSH	($a1)
		PUSH	($a2)

		la		$a0,  %str
		li		$a1, %in
		li		$a2, %tam
		jal		strClr
		
		POP		($a2)
		POP		($a1)
		POP		($a0)
.end_macro

#########################################################
#	Finalidade:
#		Limpeza de string
#	Descrição:
#		Dada uma string e seu intervalo de trabalho, todo
#		o conteúdo da mesma será limpo, ou seja, será
#		atribuido '\0'
#	Parâmetros:
#		str	- string a ser limpa
#		tam	- tamanho a ser limpo
#	Valor retornado:
#		v0	- última posição no resultado
#########################################################
.macro	STR_CLR	(%str, %tam)
		PUSH	($a0)
		PUSH	($a1)
		PUSH	($a2)

		la		$a0,  %str
		li		$a1, 0
		li		$a2, %tam
		jal		strClr
		
		POP		($a2)
		POP		($a1)
		POP		($a0)
.end_macro
