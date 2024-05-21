CC=gcc
CFLAGS = -Wall -Werror
LFLAGS = -I./includes

all: main.x clean

main.x : main.o initialisation_grille.o afficher_grille.o placer_serpent.o placer_food.o initialisation_partie.o updateSnakePosition.o check_collision.o check_food.o moveSnakebody.o

main.o : main.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
initialisation_grille.o : initialisation_grille.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
afficher_grille.o : afficher_grille.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
placer_serpent.o : placer_serpent.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
placer_food.o : placer_food.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
initialisation_partie.o : initialisation_partie.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
updateSnakePosition.o : updateSnakePosition.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
check_collision.o : check_collision.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
check_food.o : check_food.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^
moveSnakebody.o : moveSnakebody.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $^

clean : 
	rm -f *~ *.o
realclean : 
	rm -f *.x