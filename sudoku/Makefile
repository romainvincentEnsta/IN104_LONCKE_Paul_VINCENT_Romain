CC=gcc
CFLAGS = -Wall -Werror
LFLAGS = -I ~/Git_Hub/IN104_Projet/sudoku/includes

all: main.x

main.x : solve.o safe.o sudoku.o afficher_sudoku.o
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^
clean : 
	rm -f *~ *.o
realclean : 
	rm -f *.x
