#include "ftoc.h"

#include <math.h>
#include <stdlib.h>

enum order { ONE, THOU, MIL, BIL };
const float order_float_map[] = {1.0f, 1.0e3f, 1.0e6f,1.0e9f};
const int order_int_map[] = {1, 1000, 1000000, 1000000000};
const char order_char_map[] = {'C', 'K', 'M', 'B'};

enum order getOrder(const float f) {
	if (f > 1.0e9f) return BIL;
	else if (f > 1.0e6f) return MIL;
	else if (f > 1.0e3f) return THOU;
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
		f_i *= 10;
	} else if (i == 3) {
		f_i %= 1000;
		f_i /= 100;
		f_i *= 100;
	}
	return f_i;
}

int getDecimal(float f,const enum order o, const int i) {
	while (f >= order_float_map[o]) f -= order_float_map[o];
	while (f <= 10000.0f) f *= 10.0f;
	int f_i = (int)f;
	switch(i) {
		case 1: while(f_i >= 10) f_i /= 10;
			return f_i;
			break;
		case 2: while (f_i >= 100) f_i /= 10;
			return (f_i%10);
			break;
		case 3: while (f_i >= 1000) f_i /= 10;
			return (f_i%10);
			break;
		case 4: while (f_i >= 10000) f_i /= 10;
			return (f_i%10);
			break;
		case 5: return (f_i%10);
			break;
		default: exit(-1);
			break;
	}
}

/* fto6C() : Converts floating point to six digits
 *
 * @param f : dloating point number to be converted
 * param c : pointer to array of six chars. 
 */
void fto6c(float f, char c[]) {
	enum order magnitude = getOrder(f);
	int offset = precursor(f,magnitude);
	c[offset] = order_char_map[offset];	
	for (int i = 1; i <= offset; i++) {
		c[offset-i] = (char)ftrunc(f,magnitude,i)+'0';
	}
	for (int i = 0; i+offset < 6; i++) {
		c[i+offset] = (char)getDecimal(f,magnitude,i)+'0';
	}
	return;
}
