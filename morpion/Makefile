CC=gcc
CFLAGS = -Wall -Werror
LFLAGS = -I ~/Git_Hub/IN104_Projet/morpion/includes

all: morpion.x

morpion.x : morpion.o afficher_grille.o a_gagné.o est_plein.o placer.o creation_grille.o
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^
clean : 
	rm -f *~ *.o
realclean : 
	rm -f *.x