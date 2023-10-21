CC = g++
CFLAGS = -g

all: main

main: main.o BinaryTree.o
	$(CC) $(CFLAGS) main.cpp BinaryTree.cpp -o main

$.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
