###################
# Programas
###################
# Responsável por compilar a aplicação desenvolvida em C/C++
COMP = gcc
# Resposável pela análise estática do código C/C++
ESTATICO = cppcheck
# Responsável pela análise dinâmica do programa
DINAMICO = valgrind

###################
# Diretórios
###################
# Raiz do projeto
DIR_BASE = `pwd`
#
DIR_FONTES = `find . -type f -iname *.c -print |  sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/ /g'`

#DIR_OBJETOS = `find . -type f -iname *.c -print | sed 's/\.c/\.o/g' | sed 's/src/obj/g' | sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/ /g'`
DIR_OBJETOS = obj/

DIR_BIBLIOTECAS = lib/

DIR_EXECUTAVEL = leitor

TESTE= BLA BLE BLI


###################
# Constantes
###################
DESTAQUE = ************************************************

###################
# Regras
###################
estatico:
	@clear
	@echo "${DESTAQUE}"
	@echo "Verificação estática sobre o diretório:"
	@echo "'${DIR_BASE}/ asd${DIR_OBJETOS}'"
	@echo "${DESTAQUE}\n"

	@$(ESTATICO) $(DIR_BASE)/$(DIR_FONTE) --enable=warning,style,performance,portability,unusedFunction

objetos: estatico limpar_obj
	@echo "\n${DESTAQUE}"
	@echo "Compilando o projeto a partir do diretorio:"
	@echo "'${DIR_FONTES}'"
	@echo "${DESTAQUE}\n"

	@$(COMP) -c $(DIR_FONTES)
	@mv *.o $(DIR_OBJETOS)

compilar: objetos
	g++ obj/* -o leitor


executar: compilar limpar_bin
	# $(COMP) $(DIR_OBJETOS)* -o $(DIR_EXECUTAVEL)
	sudo ./leitor

limpar_obj:
	@rm -rf $(DIR_OBJETOS)
	@mkdir $(DIR_OBJETOS)

limpar_bin:
	@rm -rf $(DIR_EXECUTAVEL)
	@mkdir $(DIR_EXECUTAVEL)

limpar: limpar_obj limpar_bin

check:
	@echo "COMP = $(COMP)"
	@echo "ESTATICO = $(ESTATICO)"
	@echo "DINAMICO = $(DINAMICO)"
	@echo "DIR_BASE = $(DIR_BASE)"
	@echo "DIR_FONTES = $(DIR_FONTES)"
	@echo "DIR_OBJETOS = $(DIR_OBJETOS)"
	@echo "DIR_BIBLIOTECAS = $(DIR_BIBLIOTECAS)"
	@echo "DIR_EXECUTAVEL = $(DIR_EXECUTAVEL)"

	for t in $(DIR_FONTES); do \
		echo src $$t; \
		echo dst $$p; \
		p=$(subst *.c, *.o, $(t)); \
	done

# SCR_DIR = scr/*


# gen_obj:
# 	@echo "Gerando arquivos .o"
# 	g++ -c $(SCR_DIR)

# check:
# 	@echo "Checando estática"
# 	@echo ""
# 	cppcheck src/* --enable=warning,style,performance,portability,unusedFunction

# help:
# 	@echo "Usabilidade: make <comando> [opções]"
# 	@echo ""
# 	@echo "Comandos:"
# 	@echo "    help        Exibir essa mensagem"
