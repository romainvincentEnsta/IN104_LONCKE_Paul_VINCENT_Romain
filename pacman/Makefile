CC=gcc
CFLAGS = -Wall -Werror
LFLAGS = -I ./includes

all : main.x clean

main.x : initialisation.o is_still_alive.o move_ghost.o get_arrow.o move_pacman.o main.o
	$(CC) $(CFLAGS) -o $@ $^
main.o : main.c 
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c main.c
initialisation.o : initialisation.c
	$(CC) $(LFLAGS) $(CFLAGS) -o $@ -c $^*
move_ghost.o : move_ghost.c
	$(CC) $(LFLAGS) $(CFLAGS) -o $@ -c $^
get_arrow.o : get_arrow.c
	$(CC) $(LFLAGS) $(CFLAGS) -o $@ -c $^
is_still_alive.o : is_still_alive.c
	$(CC) $(LFLAGS) $(CFLAGS) -o $@ -c $^
move_pacman.o : move_pacman.c
	$(CC) $(LFLAGS) $(CFLAGS) -o $@ -c $^
clean : 
	rm -f *~ *.o
realclean :
	rm -f *~ *.x