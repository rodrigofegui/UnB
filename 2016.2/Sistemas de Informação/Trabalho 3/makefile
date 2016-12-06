###################
# Programas
###################
# Responsável por compilar a aplicação desenvolvida em Java
COMPILADOR = javac
# Responsável por criar o arquivo .jar da aplicação
CRIADORJaR = jar
# Responsável por executar a aplicação desenvolvida em Java
EXECUTADOR = java
# Responsável por documentar a aplicação desenvolvida em Java
DOCUMENTADOR = javadoc

###################
# Diretórios 
###################
# Atual, que contém todas as pastas necessárias
DIR_BASE = <diretório>
# Arquivos-fonte
DIR_FONTES_ = src/
DIR_FONTES = $(patsubst %,$(DIR_BASE)/%,$(DIR_FONTES_))
# Arquivos executáveis
DIR_BINARIO_ = bin/
DIR_BINARIO = $(patsubst %,$(DIR_BASE)/%,$(DIR_BINARIO_))
# Arquivos da documentação
DIR_DOCUMENTACAO_ = Javadoc/
DIR_DOCUMENTACAO = $(patsubst %,$(DIR_BASE)/%,$(DIR_DOCUMENTACAO_))
# Pacotes JAVA .jar
DIR_EXTERN_JAR = <diretório>/mysql-connector-java-5.1.40-bin.jar

###################
# Tags importantes
###################
TAGS_DOCUMENTACAO = -author -version
TAGS_MEMORIA = -Xms1024M -Xmx1624M

###################
# Arquivo com o método "main"
###################
# Arquivos .java a serem manipulados
ARQ_JAVA_MANI := $(DIR_FONTES)*/*.java
ARQ_JAVA_MANI += $(DIR_FONTES)*/*/*.java
# Arquivo .java a ser executado
ARQ_PRINCIPAL = principal.Principal
# Arquivo .jar a ser executado
ARQ_JAR = gerenciadorHolerite.jar


###################
# Regras
###################
help:
	@echo "Uso: make [opção]"
	@echo "Opções:"
	@echo "	compilar		Compilar todos os arquivos-fontes."
	@echo "	aplicar			Criação do arquivo .jar."
	@echo "	executar		Executa a aplicação, na versão mais recente"
	@echo "				da mesma: limpando o diretório 'bin' e recompilando."
	@echo "	documentar		Gera a documentação, atualizada, de todos os"
	@echo "				arquivos-fonte: limpando o diretório 'Javadoc' e"
	@echo "				recompilando."
	@echo "	clear_all		Limpeza dos diretório 'bin' e 'Javadoc'."
	@echo "	clear_bin		Limpeza do diretório 'bin'."
	@echo "	clear_doc		Limpeza do diretório 'Javadoc'."
	@echo "	help			Imprime esta mensagem e sai."

compilar:
	@clear
	@echo "Compilando arquivos em:"
	@echo "$(DIR_FONTES)\n"
	@$(COMPILADOR) -d $(DIR_BINARIO) -cp $(DIR_EXTERN_JAR) -sourcepath $(DIR_FONTES):. $(ARQ_JAVA_MANI) -Xlint
	@echo "Compilação concluída\n"
	

aplicar: clear_bin compilar
	@echo "Criando arquivo .jar da aplicação"
	@$(CRIADORJaR) cvf $(ARQ_JAR) -C $(DIR_BINARIO) .
	@echo "\nArquivo criado com sucesso!\n"

executar: aplicar
	@echo "A executar"
	@echo "$(ARQ_PRINCIPAL)\n"
	#@$(EXECUTADOR) $(TAGS_MEMORIA) -cp $(DIR_BINARIO):$(DIR_EXTERN_JAR) $(ARQ_PRINCIPAL)
	@$(EXECUTADOR) -classpath $(ARQ_JAR):$(DIR_EXTERN_JAR) $(ARQ_PRINCIPAL)
	@echo "\nAplicação finalizada\n"

documentar: clear_doc compilar
	@echo "Gerando a documentação\n"
	@$(DOCUMENTADOR) -d $(DIR_DOCUMENTACAO) -sourcepath $(DIR_FONTES):. $(ARQ_JAVA_MANI) -docencoding UTF-8 -charset UTF-8 $(TAGS_DOCUMENTACAO)
	@echo "\nDocumentação salva em"
	@echo "$(DIR_DOCUMENTACAO)\n"

clear_all: clear_bin clear_doc
	@clear

clear_bin:
	@echo "Excluindo todos os arquivos de:"
	@echo "$(DIR_BINARIO)\n"
	@rm -rf $(DIR_BINARIO)
	@mkdir $(DIR_BINARIO)
	@echo "Arquivos excluídos, pasta vazia\n"

clear_doc:
	@echo "Excluindo todos os arquivos de:"
	@echo "$(DIR_DOCUMENTACAO)\n"
	@rm -rf $(DIR_DOCUMENTACAO)
	@mkdir $(DIR_DOCUMENTACAO)
	@echo "Arquivos excluídos, pasta vazia\n"


