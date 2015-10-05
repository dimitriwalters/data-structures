CC=gcc
CFLAGS=-c

all: main

main: main.o node.o bst.o
	$(CC) main.o node.o bst.o -o main

main.o: main.c
	$(CC) $(CFLAGS) main.c

node.o: node.c
	$(CC) $(CFLAGS) node.c

bst.o: bst.c
	$(CC) $(CFLAGS) bst.c

clean:
	rm *o main
