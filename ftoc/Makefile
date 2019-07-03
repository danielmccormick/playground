FLAGS = -Wall -Wextra -O3

default: ftoc.o

ftoc.o: ftoc.c ftoc.h
	gcc ftoc.c $(FLAGS) -shared -fpic -o ftoc.o

.PHONY: clean
clean: 
	rm -f *.o 
