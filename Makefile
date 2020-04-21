CC := gcc
FLAGS := -std=c11 -Wextra -Wall -Wshadow -g -O3 #-fsanitize=undefined -fsanitize=address

all: main

util.o: util.c util.h
	$(CC) $(FLAGS) util.c -c -o util.o

FIFO.o: FIFO.c FIFO.h
	$(CC) $(FLAGS) FIFO.c -c -o FIFO.o

RR.o: RR.c RR.h
	$(CC) $(FLAGS) RR.c -c -o RR.o

heap.o: heap.c heap.h
	$(CC) $(FLAGS) heap.c -c -o heap.o

SJF.o: SJF.c SJF.h
	$(CC) $(FLAGS) SJF.c -c -o SJF.o

PSJF.o: PSJF.c PSJF.h
	$(CC) $(FLAGS) PSJF.c -c -o PSJF.o

main:	main.c main.h util.o FIFO.o RR.o heap.o SJF.o PSJF.o
	$(CC) $(FLAGS) main.c util.o FIFO.o RR.o heap.o SJF.o PSJF.o -o main 

.PHONY: clean

clean:
	rm -rf util.o FIFO.o RR.o heap.o SJF.o PSJF.o
