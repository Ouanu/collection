main: main.o linklist.o
	gcc -o main main.o linklist.o

main.o: main.c
	gcc -o main.o -c main.c

linklist.o: linklist.c
	gcc -o linklist.o -c linklist.c