COMPILADOR = javac
EXECUTADOR = java
DIRFONTES = src
DIRSAIDA = bin
ARQ_PRINCIPAL = interFace.Principal

comp:
	rm -rf $(DIRSAIDA)/*
	$(COMPILADOR) -d $(DIRSAIDA)/ -cp $(DIRSAIDA)/:. -sourcepath $(DIRFONTES)/:. $(DIRFONTES)/*/*.java
	#javac -d bin/ -cp bin/:. -sourcepath src/:. src/*/*.java


run: comp
	clear
	$(EXECUTADOR) -cp $(DIRSAIDA)/:. $(ARQ_PRINCIPAL)


