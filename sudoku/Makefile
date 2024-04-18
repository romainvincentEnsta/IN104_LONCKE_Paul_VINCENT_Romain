CC=gcc
CFLAGS = -Wall -Werror
LFLAGS = -I ~/Git_Hub/IN104_Projet/sudoku/includes

all: main.x

main.x : solve.o safe.o sudoku.o afficher_sudoku.o remplir_case.o grille_pleine.o main.o tableau_plein.o
	$(CC) $(CFLAGS) -o $@ $^
tableau_plein.o : tableau_plein.c
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
