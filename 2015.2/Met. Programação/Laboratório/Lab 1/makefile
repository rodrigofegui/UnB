IDIR = ../include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = objetos
LDIR = ../lib

LIBS= -lm

_DEPS = Pilha.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Principal.o Pilha.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lab1: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
