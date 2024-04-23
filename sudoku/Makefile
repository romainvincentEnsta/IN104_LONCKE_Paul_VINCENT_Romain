CC=gcc
CFLAGS = -Wall -Werror
LFLAGS = -I ~/in104/sudoku/includes

all: main.x

main.x : solve.o safe.o sudoku.o afficher_sudoku.o remplir_case.o
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^
clean : 
	rm -f *~ *.o
realclean : 
	rm -f *.x
