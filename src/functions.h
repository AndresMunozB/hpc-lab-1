#ifndef FUNCTIONS_HEADER
#define FUNCTIONS_HEADER

#include <xmmintrin.h> /* SSE __m128 float */

void sort_in_register(__m128 *r1, __m128 *r2, __m128 *r3, __m128 *r4);
void bmn_network(__m128 *r1, __m128 *r2);

#endif
