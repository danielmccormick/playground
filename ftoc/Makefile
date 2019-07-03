FLAGS = -Wall -Wextra -O3

default: ftoc

ftoc: ftoc.o main.c
	gcc main.c ftoc.o $(FLAGS) -o ftoc 

ftoc.o: ftoc.c ftoc.h
	gcc ftoc.c $(FLAGS) -c -o ftoc.o

.PHONY: clean
clean: 
	rm -f ftoc ftoc.o
