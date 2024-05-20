CC=gcc
CFLAGS = -Wall -Werror
LFLAGS = -I./includes

all: main.x clean

<<<<<<< HEAD
main.x : safe.o sudoku.o afficher_sudoku.o remplir_case.o grille_pleine.o tableau_plein.o solve.o main.o
=======
main.x : solve.o safe.o sudoku.o afficher_sudoku.o remplir_case.o grille_pleine.o main.o tableau_nul.o
>>>>>>> 8aac325c2baa12c535e1e6df8c3e6175d2da689c
	$(CC) $(CFLAGS) -o $@ $^
sudoku.o  : sudoku.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
tableau_nul.o : tableau_nul.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
grille_pleine.o : grille_pleine.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
afficher_sudoku.o : afficher_sudoku.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
safe.o : safe.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
remplir_case.o : remplir_case.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
solve.o : solve.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
main.o : main.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
clean : 
	rm -f *~ *.o
realclean : 
	rm -f *.x
