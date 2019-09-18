COMPILADOR = g++
DIRINCLUDE = Bibliotecas
DIROBJETO = Objetos
DIRFONTES = Fontes
DIRSAIDA = Executaveis
SAIDA = t2_OA


CFLAGS = -I$(DIRINCLUDE)

_DEP = Arvore_A.hpp Basica_A.hpp
DEP = $(patsubst %,$(DIRINCLUDE)/%,$(_DEP))

_TRAB = Arvore_A.cpp Basica_A.cpp Principal_A.cpp
TRAB = $(patsubst %,$(DIRFONTES)/%,$(_TRAB))

_DEP_TRAB = Arvore_A.o Basica_A.o Principal_A.o
DEP_TRAB = $(patsubst %,$(DIROBJETO)/%,$(_DEP_TRAB))


trab2:
	clear	
	rm -rf $(DIROBJETO)
	rm -rf $(DIRSAIDA)
	mkdir $(DIROBJETO)
	mkdir $(DIRSAIDA)
	$(COMPILADOR) -c -g $(TRAB)
	mv *.o $(DIROBJETO)/
	$(COMPILADOR) -o $(SAIDA) $(DEP_TRAB)
	mv $(SAIDA) $(DIRSAIDA)/
	

run:
	clear
	./$(DIRSAIDA)/$(SAIDA)

valgrind:
	clear
	valgrind -v --tool=memcheck --leak-check=full --num-callers=40 --show-leak-kinds=all  --track-origins=yes ./$(DIRSAIDA)/$(SAIDA)

