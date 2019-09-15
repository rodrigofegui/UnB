SCR_DIR = scr/*


gen_obj:
	@echo "Gerando arquivos .o"
	g++ -c $(SCR_DIR)

check:
	@echo "Checando estática"
	@echo ""
	cppcheck src/* --enable=warning,style,performance,portability,unusedFunction

help:
	@echo "Usabilidade: make <comando> [opções]"
	@echo ""
	@echo "Comandos:"
	@echo "    help        Exibir essa mensagem"
