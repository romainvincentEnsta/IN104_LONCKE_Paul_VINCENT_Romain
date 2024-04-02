CC=gcc
CFLAGS= -Wall -Werror

all: main.x

main.x : main.o solve.o safe.o sudoku.o afficher_sudoku.o
	$(CC) $(CFLAGS) -o $@ -c $^
main.o : main.c 
	$(CC) $(CFLAGS) -o $@ 
solve.o : safe.c solve.c
	$(CC) $(CFLAGS) -o $@ -c $^
safe.o : safe.c
	$(CC) $(CFLAGS) -o $@ 
sudoku.o : sudoku.c
	$(CC) $(CFLAGS) -o $@ 
afficher_sudoku.o : afficher_sudoku.c
	$(CC) $(CFLAGS) -o $@ 
clean : 
	rm -f *~ *.o
realclean : 
	rm -f *.x
