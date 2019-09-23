###################
# Programas
###################
# Responsável por compilar a aplicação desenvolvida em C/C++
COMP = gcc
#
COMP_FLAGS = -g
# Resposável pela análise estática do código C/C++
ESTATICO = cppcheck
# Flags para o estático
ESTATICO_FLAGS = --enable=warning,style,performance,portability,unusedFunction
# Responsável pela análise dinâmica do programa
DINAMICO = valgrind
#
DINAMICO_FLAGS = --tool=memcheck --leak-check=summary --show-leak-kinds=definite  --track-origins=yes

###################
# Diretórios
###################
# Raiz do projeto
DIR_BASE = `pwd`
# Arquivos-fonte .c
DIR_FONTES = `find . -type f -iname *.c -print |  sed -e ':a' -e 'N' -e '$!ba' -e 's/\n/ /g'`
# Diretório dos arquivos objetos
DIR_OBJETOS = obj/
# Arquivo executável
EXECUTAVEL = leitor.out

###################
# Constantes
###################
DESTAQUE = ************************************************

###################
# Regras
###################
limpar_obj:
	@echo "$(DESTAQUE)"
	@echo "A limpar o diretório de objetos..."

	@rm -rf $(DIR_OBJETOS)
	@mkdir $(DIR_OBJETOS)

	@echo "Limpeza concluída"
	@echo "$(DESTAQUE)\n"

limpar_bin:
	@echo "$(DESTAQUE)"
	@echo "A limpar o executável..."

	@rm -f $(EXECUTAVEL)

	@echo "Limpeza concluída"
	@echo "$(DESTAQUE)\n"

limpar: limpar_obj limpar_bin

estatico:
	@echo "${DESTAQUE}"
	@echo "Verificação estática sobre o diretório:"
	@echo "'${DIR_BASE}/'\n"

	@$(ESTATICO) $(DIR_BASE)/$(DIR_FONTE) $(ESTATICO_FLAGS)

	@echo "\n${DESTAQUE}\n"

objetos: estatico limpar_obj
	@echo "${DESTAQUE}"
	@echo "Gerando arquivos objetos a partir do diretorio:"
	@echo "'${DIR_FONTES}'"

	@$(COMP) -c $(DIR_FONTES) $(COMP_FLAGS)
	@mv *.o $(DIR_OBJETOS)

	@echo "\nTodos foram movidos para o diretório:"
	@echo "'${DIR_OBJETOS}'"
	@echo "${DESTAQUE}\n"


compilar: limpar_bin objetos
	@echo "${DESTAQUE}"
	@echo "Compilando o projeto a partir dos arquivos:"
	@echo "'${DIR_OBJETOS}'"

	@$(COMP) obj/* -o $(EXECUTAVEL)

	@echo "\nExecutável gerado:"
	@echo "'$(EXECUTAVEL)'"
	@echo "${DESTAQUE}\n"

executar: compilar
	@echo "${DESTAQUE}"
	@echo "Executando o arquivo:"
	@echo "'$(EXECUTAVEL)'"
	@echo "Com:"
	@echo "\t- Checagem de memória"
	@echo "\t- Busca de memória não liberada, relatório resumido"
	@echo "\t- Informe das perdas definitivas"
	@echo "\t- Busca pela origem de valores indefinido"
	@echo ""

	@$(DINAMICO) $(DINAMICO_FLAGS) ./$(EXECUTAVEL)

	@echo "\nAcabou a execução"
	@echo "${DESTAQUE}"
