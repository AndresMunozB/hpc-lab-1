#include <stdio.h>
#include <stdlib.h>
#include <xmmintrin.h> /* SSE __m128 float */

void print_float_array(float *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%f ", array[i]);
}

void print_matrix_16(float *arg1, float *arg2, float *arg3, float *arg4)
{
    print_float_array(arg1, 4);
    printf("\n");
    print_float_array(arg2, 4);
    printf("\n");
    print_float_array(arg3, 4);
    printf("\n");
    print_float_array(arg4, 4);
    printf("\n");
}

int main()
{
    
    //ARREGLOS DE ENTRADA Y SALIDA
    float A1[4] __attribute__((aligned(16))) = {5.0, 6.0, 7.0, 8.0};
    float A2[4] __attribute__((aligned(16))) = {1.0, 2.0, 3.0, 4.0};
    
    

    //REGISTROS DE ENTRADA Y SALIDA
    __m128 r1, r2, r3, r4;

    //REGISTROS TEMPORALES
    __m128 t1,t2,t3,t4,t5,t6;

    //CARGAR REGISTROS
    r1 = _mm_load_ps(A1);
    r2 = _mm_load_ps(A2);

    

    t1 = _mm_shuffle_ps(r1, r1, _MM_SHUFFLE(3,1,2,0));
    t2 = _mm_shuffle_ps(r2, r2, _MM_SHUFFLE(0,2,1,3));

    t3 = _mm_max_ps(t1, t2);
    t4 = _mm_min_ps(t1, t2);

    t3 = _mm_shuffle_ps(t3, t3, _MM_SHUFFLE(3,1,2,0));
    t6 = _mm_shuffle_ps(r2, r2, _MM_SHUFFLE(0,2,1,3));

    t3 = _mm_max_ps(t1, t2);
    t4 = _mm_min_ps(t1, t2);

    //GUARDAR REGISTROS
    _mm_store_ps(A1, t3);
    _mm_store_ps(A2, t4);

    t5[0] = t3[0] 
    t5[1] = t4[0]
    t5[2] = t3[2]
    t5[3] = t4[2]

    t6[0] = t3[0] 
    t6[1] = t4[0]
    t6[2] = t3[2]
    t6[3] = t4[2]

    print_float_array(A1,4);
    printf("\n");
    print_float_array(A2,4);
    printf("\n");

    return 1;
}