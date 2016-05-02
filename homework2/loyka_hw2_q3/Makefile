CC=gcc
CFLAGS=-c -Wall

all: main

main: loyka_hw2_q3_main.o loyka_hw2_q3_prime.o loyka_hw2_q3_sort_array.o loyka_hw2_q3_swap.o
	$(CC) loyka_hw2_q3_main.o loyka_hw2_q3_prime.o loyka_hw2_q3_sort_array.o loyka_hw2_q3_swap.o -o main

loyka_hw2_q3_main.o: loyka_hw2_q3_main.c loyka_hw2_q3_prime.o
	$(CC) $(CFLAGS) loyka_hw2_q3_main.c

loyka_hw2_q3_prime.o: loyka_hw2_q3_prime.c loyka_hw2_q3_prime.h loyka_hw2_q3_sort_array.o
	$(CC) $(CFLAGS) loyka_hw2_q3_prime.c

loyka_hw2_q3_sort_array.o: loyka_hw2_q3_sort_array.c loyka_hw2_q3_sort_array.h loyka_hw2_q3_swap.o
	$(CC) $(CFLAGS) loyka_hw2_q3_sort_array.c

loyka_hw2_q3_swap.o: loyka_hw2_q3_swap.c loyka_hw2_q3_swap.h
	$(CC) $(CFLAGS) loyka_hw2_q3_swap.c

clean:
	rm -f loyka_hw2_q3_main.o loyka_hw2_q3_prime.o loyka_hw2_q3_sort_array.o loyka_hw2_q3_swap.o main
