#include <math.h>

enum order { ONE, THOU, MIL, BIL };
const float order_float_map[] = {1.0f, 1.0e3f, 1.0e6f,1.0e9f};
const int order_int_map[] = {1, 1000, 1000000, 1000000000};
const char order_char_map[] = {'C', 'K', 'M', 'B'};

/* getOrder : returns order of magnitude within bounds of enum
 *
 * @param f : floating point number input
 * @returns order of magnitude
 */
enum order getOrder(const float f); 

/* Precursor: returns number of precursor digits
 *
 * is for order ONE and number 999 returns 3. Returns 1 for 9.
 *
 * @param f: floating point number input
 * @param o: order of magnitude of number removing
 * @returns how many digits are relevant to be greater than or equal to order of magnitude
 */
int precursor(float f, const enum order o);

/* ftrunc returns truncated digit
 * 
 *
 *
 */
int ftrunc(const float f, const enum order o, const int i);


int getDecimal(float f,const enum order o, const int i);


/* fto6C() : Converts floating point to six digits
 *
 * @param f : dloating point number to be converted
 * param c : pointer to array of six chars. 
 */
static void fto6c(float f, char c[]);
