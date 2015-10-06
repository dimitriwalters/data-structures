CC=gcc
CFLAGS=-c

all: main

main: main.o list.o bst.o
	$(CC) main.o list.o bst.o -o main

main.o: main.c
	$(CC) $(CFLAGS) main.c

list.o: list.c
	$(CC) $(CFLAGS) list.c

bst.o: bst.c
	$(CC) $(CFLAGS) bst.c

clean:
	rm *o main
