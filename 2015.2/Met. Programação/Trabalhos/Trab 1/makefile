COMPILADOR = gcc
DIRINCLUDE = Bibliotecas
DIROBJETO = Objetos
DIRFONTES = Fontes
DIRSAIDA = Executaveis
ENCAD_OUT = trab1_enc.out
VETOR_OUT = trab1_vet.out


CFLAGS = -I$(DIRINCLUDE)

_DEP = Pilha.h
DEP = $(patsubst %,$(DIRINCLUDE)/%,$(_DEP))

_ENCAD = Principal_enc.c Pilha_enc.c
ENCAD = $(patsubst %,$(DIRFONTES)/%,$(_ENCAD))

_DEP_EN = Principal_enc.o Pilha_enc.o
DEP_EN = $(patsubst %,$(DIROBJETO)/%,$(_DEP_EN))

_VETOR = Principal_vet.c Pilha_vet.c
VETOR = $(patsubst %,$(DIRFONTES)/%,$(_VETOR))

_DEP_VT = Principal_vet.o Pilha_vet.o
DEP_VT = $(patsubst %,$(DIROBJETO)/%,$(_DEP_VT))


trab1:
	rm -rf $(DIROBJETO)
	rm -rf $(DIRSAIDA)
	mkdir $(DIROBJETO)
	mkdir $(DIRSAIDA)
	$(COMPILADOR) -c $(VETOR)
	$(COMPILADOR) -c $(ENCAD)
	mv *.o $(DIROBJETO)/
	$(COMPILADOR) -o $(VETOR_OUT) $(DEP_VT)
	$(COMPILADOR) -o $(ENCAD_OUT) $(DEP_EN)
	mv *.out $(DIRSAIDA)/
	clear
	./$(DIRSAIDA)/$(VETOR_OUT) 
	./$(DIRSAIDA)/$(ENCAD_OUT) 
