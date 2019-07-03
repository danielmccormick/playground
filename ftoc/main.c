#include "ftoc.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: ./atoc %%f\n");
		return 0;
	} 
	float f = atof(argv[1]);
	if (f == 0.0f) {
		printf("Invalid input. Please provide a valid floating point from 1.0 to 9999999\n");
		return 0;
	}
	char out_str[7] = {0};
	fto6c(f,out_str);
	printf("Converted %f to %s\n", (double)f,out_str);
	return 0;	
}
