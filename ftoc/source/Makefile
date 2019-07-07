FLAGS = -Wall -Wextra -O3

default: ftoc

ftoc: ftoc.o main.c
	gcc main.c ftoc.o $(FLAGS) -o ftoc 

ftoc.o: lib/ftoc.c lib/ftoc.h
	gcc lib/ftoc.c $(FLAGS) -c -o ftoc.o

.PHONY: clean
clean: 
	rm -f ftoc ftoc.o
