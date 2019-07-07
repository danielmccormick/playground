#include "ftoc.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum order { ONE, THOU, MIL, BIL };
const float order_float_map[] = {1.0f, 1.0e3f, 1.0e6f,1.0e9f};
const int order_int_map[] = {1, 1000, 1000000, 1000000000};
const char order_char_map[] = {'C', 'K', 'M', 'B'};

enum order getOrder(const float f) {
	if (f >= 1.0e9f) return BIL;
	else if (f >= 1.0e6f) return MIL;
	else if (f >= 1.0e3f) return THOU;
	return ONE;
}

int precursor(float f, const enum order o) {
	f /= order_float_map[o];
	if (f >= 100.0f) return 3;
	else if (f >= 10.0f) return 2;
	return 1;
}

int ftrunc(const float f, const enum order o, const int i) {
	if (o == BIL) return 9; // Overflow
	int f_i;
	f_i = (int) f/order_float_map[o];
	if (i == 1) {
		f_i %= 10;
	} else if (i == 2) {
		f_i %= 100;
		f_i /= 10;
		//f_i *= 10;
	} else if (i == 3) {
		f_i %= 1000;
		f_i /= 100;
		//f_i *= 100;
	}
	return f_i;
}

int getDecimal(float f,const enum order o, const int i) {
	while (f >= order_float_map[o]) {
		f -= order_float_map[o];
	}
	if (f < 0.0005f) return 0;
	while (f <= 10000.0f) f *= 10.0f;
	int f_i = (int)f;
	switch(i) {
		case 0: while(f_i >= 10) f_i /= 10;
			return f_i;
			break;
		case 1: while (f_i >= 100) f_i /= 10;
			return (f_i%10);
			break;
		case 2: while (f_i >= 1000) f_i /= 10;
			return (f_i%10);
			break;
		case 3: while (f_i >= 10000) f_i /= 10;
			return (f_i%10);
			break;
		case 4: return (f_i%10);
			break;
		default: printf("Error: unexpected input to getDecimal: %i\n",i);
			exit(-1);
			break;
	}
}

/* fto6C() : Converts floating point to six digits
 *
 * @param f : dloating point number to be converted
 * param c : pointer to array of six chars. 
 */
void fto6c(float f, char c[]) {
	if (f < 0.1f) {
		for (int i = 0; i < 6; i++) c[6] = '0';
		return;
	}
	enum order magnitude = getOrder(f);
	if (magnitude == BIL) {
		c[0] = 'A'; c[1] = 'E'; c[2] = 'R'; c[3] = 'R'; c[4] = 'O'; c[5] = 'R';
		return;
	}
	int offset = precursor(f,magnitude);
	c[offset] = order_char_map[magnitude];	
	for (int i = 1; i <= offset; i++) {
		c[offset-i] = (char)ftrunc(f,magnitude,i)+'0';
	}
	for (int i = 0; i+offset < 5; i++) {
		//printf("%i after offset yields %i\n", i,getDecimal(f,magnitude,i));
		c[i+offset+1] = (char)getDecimal(f,magnitude,i)+'0';
	}
	return;
}
