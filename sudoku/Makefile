CC=gcc
CFLAGS= -Wall -Werror

all: main.x

%.x : %.o 
	$(CC) $(CFLAGS) -o $@ -$<

%.o : %.c 
	$(CC) $(CFLAGS) -o $@ -c $<
clean : 
	rm -f *~ *.o
realclean : 
	rm -f *.x
