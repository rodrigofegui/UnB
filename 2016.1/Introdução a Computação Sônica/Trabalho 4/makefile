COMPILADOR = javac
EXECUTADOR = java
DOCUMENTADOR = javadoc

DIR_BASE = <nome diretório>/Trabalho\ 4/
DIR_FONTES = src/
DIR_BINARIO = bin/
DIR_DOCUMENTACAO = Javadoc/
DIR_EXTERN_JAR = <nome diretório>/sintese.jar

TAGS_DOCUMENTACAO = -author -version
TAGS_MEMORIA = -Xms1024M -Xmx1624M

ARQ_MELODIAS = melodias/BaseadoMidi
ARQ_MELODIAS_REGIS_T = $(DIR_DEFAULT)melodiasRegistradasTratadas.txt
ARQ_MELODIAS_REGIS_A = $(DIR_DEFAULT)melodiasRegistradasAbsolutas.txt
ARQ_MELODIAS_SRC = src/$(ARQ_MELODIAS).java
ARQ_MELODIAS_BIN = bin/$(ARQ_MELODIAS).class
ARQ_MELODIAS_DEF = $(DIR_DEFAULT)$(ARQ_MELODIAS).java
ARQ_PRINCIPAL = Principal

compilar:
	$(COMPILADOR) -d $(DIR_BINARIO) -cp $(DIR_EXTERN_JAR) -sourcepath $(DIR_FONTES):. $(DIR_FONTES)*.java -Xlint

compilarMelodias:
	$(COMPILADOR) -d $(DIR_BINARIO) -cp $(DIR_EXTERN_JAR) -sourcepath $(DIR_FONTES):. $(ARQ_MELODIAS_SRC) -Xlint
	
executar: clear_bin compilar
	$(EXECUTADOR) $(TAGS_MEMORIA) -cp $(DIR_BASE)$(DIR_BINARIO):$(DIR_EXTERN_JAR) $(ARQ_PRINCIPAL)

documentar: clear_doc compilar 
	$(DOCUMENTADOR) -d $(DIR_DOCUMENTACAO) -sourcepath $(DIR_FONTES):. $(DIR_FONTES)*/*.java  $(DIR_FONTES)*.java -docencoding UTF-8 $(TAGS_DOCUMENTACAO)

clear_all: clear_gerados clear_bin clear_doc
	clear

clear_bin:
	rm -rf $(DIR_BINARIO)
	mkdir $(DIR_BINARIO)
	clear

clear_doc:
	rm -rf $(DIR_DOCUMENTACAO)
	mkdir $(DIR_DOCUMENTACAO)
	clear

clear_gerados:
	rm $(ARQ_MELODIAS_REGIS_T)
	rm $(ARQ_MELODIAS_REGIS_A)
	touch $(ARQ_MELODIAS_REGIS_T)
	touch $(ARQ_MELODIAS_REGIS_A)
	cp $(ARQ_MELODIAS_DEF) $(DIR_FONTES)melodias
	rm $(ARQ_MELODIAS_BIN)

