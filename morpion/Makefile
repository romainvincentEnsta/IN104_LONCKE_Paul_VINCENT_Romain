CC=gcc
CFLAGS = -Wall -Werror
LFLAGS = -I ~/Git_Hub/IN104_Projet/morpion/includes

all: morpion.x clean

morpion.x : morpion.o afficher_grille.o a_gagné.o est_plein.o placer.o creation_grille.o
	$(CC) $(CFLAGS) -o $@ $^

afficher_grille.o : afficher_grille.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
a_gagné.o : a_gagné.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
est_plein.o : est_plein.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
placer.o : placer.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
creation_grille.o : creation_grille.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
morpion.o : morpion.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
clean : 
	rm -f *~ *.o
realclean : 
	rm -f *.x