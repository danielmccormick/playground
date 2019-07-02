#include <math.h>

enum order { ONE, THOU, MIL, BIL };
float order_float_map[] = {1.0f, 1.0e3f, 1.0e6f,1.0e9f};
char order_char_map[] = {'C', 'K', 'M', 'B'};

/* getOrder : returns order of magnitude within bounds of enum
 *
 * @param f : floating point number input
 * @returns order of magnitude
 */
order getOrder(float f) {
	if (f > 1.0e9f) return BIL;
	else if (f > 1.0e6f) return MIL;
	else if (f > 1.0e3f) return THOU;
	return ONE;
}

int precursor(float f, order o) {
	f /= order_float_map[o];
	if (f >= 100.0f) return 3;
	else if (f >= 10.0f) return 2;
	return 1;
}

/* fto6C() : Converts floating point to six digits
 *
 * @param f : dloating point number to be converted
 * param c : pointer to array of six chars. 
 */
static void fto6c(float f, char c[]) {
	order magnitude = getOrder(f);
	int offset = prescursor(f,magnitude);
	c[offset] = order_char_map[offset];	
	for (int i = 1; i <= offset; i++) {
	}
}
