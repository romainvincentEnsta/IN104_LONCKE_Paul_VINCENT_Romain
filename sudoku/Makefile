CC=gcc
CFLAGS= -Wall -Werror

all: main.x

main.x : solve.o safe.o sudoku.o afficher_sudoku.o
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c:
	$(CC) -o $@ -c $< $(CFLAGS) 

clean : 
	rm -f *~ *.o
realclean : 
	rm -f *.x
