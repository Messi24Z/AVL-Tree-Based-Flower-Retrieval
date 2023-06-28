CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

all: main

main: main.o flower.o flowerTree.o
	$(CC) $(CFLAGS) main.o flower.o flowerTree.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

flower.o: flower.cpp flower.h
	$(CC) $(CFLAGS) -c flower.cpp

flowerTree.o: flowerTree.cpp flowerTree.h
	$(CC) $(CFLAGS) -c flowerTree.cpp

clean:
	rm -f *.o main
