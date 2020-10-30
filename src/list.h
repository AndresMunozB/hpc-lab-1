#ifndef LIST_HEADER
#define LIST_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <xmmintrin.h> /* SSE __m128 float */

typedef struct List
{
    int len;
    float *data;
} List;

void init(List *list);
void print_list(List *list);
void free_list(List *list);
void append(List *list, float new_element);
void pop(List *list);
void load(List *list, __m128 r1);

#endif