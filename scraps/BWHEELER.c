// No idea if this is the correct form

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
int currStart;
char* BWI(char*, const int, const int);
void adjustLength(int,int);

int cmp_fcn(const void *a,const void *b) {
	return strcmp((*(char**)a)+currStart,(*(char**)b)+currStart);
}
// will use memcmp for qsortp

char *grid[1000];
char out_str[1000];
int main() {
	currStart =0;
	int currLength;
	int maxLength = 0;
	char Col[1000];
	int R;
	while (1) {
		scanf("%d",&R);
		if (R == 0) {
			return 0;
		}
		scanf("%s",Col);
		currLength = strlen(Col);
		if (currLength > maxLength) {
			adjustLength(maxLength,currLength);
			maxLength = currLength;	
		}

		struct timespec requestStart, requestEnd;
		clock_gettime(CLOCK_REALTIME, &requestStart);
		printf("%s\n",BWI(Col,R,currLength));
		clock_gettime(CLOCK_REALTIME, &requestEnd);
		printf("%li, %li\n",requestEnd.tv_sec-requestStart.tv_sec,requestEnd.tv_nsec-requestStart.tv_nsec);
		
	}
	// doesn't do GC for greater performance
	return 0;
}

void adjustLength(int curr, int updated) {
	for (int i = curr; i < updated; i++) {
		grid[i] = malloc(1000*sizeof(char));
	}
}

char* BWI(char *col, const int R, const int length) {
	//printf("BWI Called with %s,%d,%d\n", col,R,length);
	// will be clever for performance;
	for (int i = 0; i < length; i++) {
		memset(grid[i], ' ', length);
		grid[i][length] = '\0';
		grid[i][length-1] = col[i];
	}
	currStart = length-1;
	qsort(grid,length,sizeof(char *), cmp_fcn);
	for (int i = length-2; i >= 0; i--) {
		//printf("Last round : \n");
		for (int j = 0; j < length; j++) {
			//printf("%s\n",grid[j]);
			grid[j][i] = col[j];
		}
		currStart = i;
		qsort(grid,length,sizeof(char *),cmp_fcn);
	}
	return strcpy(out_str,grid[R-1]);
}
