// Random Process Example
// Will search through some array rrr, linearly, trying to find the first example in any case. 
// In practice a binary search would be more effective if possible, but it's still kinda neat.
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

inline void printFound(const size_t s) {
	printf("Target found at index %zd\n",s);
}

int parallel_search(const int const *arr,const size_t arr_size,const int target) {
	pid_t pid = fork(); 
	size_t iter;
	if (pid < 0) return -1;
	else if (pid == 0) {
		for (iter = (2*arr_size)/3; iter < arr_size; ++iter) {
			if (arr[iter] == target) {
				printFound(iter);
				return 0;
			}
		}
	} else {
		pid = fork();
		if (pid < 0) return -1;
		else if (pid == 0) {
			for (iter = arr_size/3; iter < (2*arr_size)/3; ++iter) {
				if (arr[iter] == target) {
					printFound(iter);
					return 0;
				}
			}
		} else {
			for (iter = 0; iter < arr_size/3; ++iter) {
				if (arr[iter] == target) {
					printFound(iter);
					return 0;
				}
			}
		}
	}
}
