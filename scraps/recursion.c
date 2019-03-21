#include <stdio.h>
#include <stdlib.h>
int egg(char *str, int start, int end, char c, unsigned long long int *x) {
  (*x) = (*x)+1;
  printf("#%d : Called with start = %d, end = %d\n", *x, start,end);
  int length = end - start + 1;
  int mid = start + (length - 1) / 2;
  int this = (str[mid] == c);
  if (length <= 1) {
    return this;
  }
  return this + egg(str, start, mid - 1, c,x) + egg(str, mid + 1, end, c,x);
}

int main() {
	//int x; 
	int foo;
	//char str[100009];
	char *str = malloc(1000002);
	//str[40] = 0;
	unsigned long long int x = 0;
	egg(str,0,7,'z',&x);
	printf("Total function calls is %d",x);
	for (int i = 900000; i <1000002; i++) {
		x = 0;
		foo = egg(str,0,i,'z',&x);
		printf("For input of %d, there are %llu function calls\n", i, x);
	}
	return 0;
}