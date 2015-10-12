CC=g++
CFLAGS=-c

all: main

main: main.o list.o bst.o graph.o
	$(CC) main.o list.o bst.o graph.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

list.o: list.cpp
	$(CC) $(CFLAGS) list.cpp

bst.o: bst.cpp
	$(CC) $(CFLAGS) bst.cpp

graph.o: graph.cpp
	$(CC) $(CFLAGS) graph.cpp

clean:
	rm *o main
