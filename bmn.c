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

void bmn_network(__m128 *r1, __m128 *r2){
    __m128 t1,t2;

    // PRIMER PASO
    *r1 = _mm_shuffle_ps(*r1, *r1, _MM_SHUFFLE(3,1,2,0)); // INVERTIR AL MEDIO
    *r2 = _mm_shuffle_ps(*r2, *r2, _MM_SHUFFLE(0,2,1,3)); // INVERTIR LOS EXTREMOS

    t1 = _mm_max_ps(*r1, *r2); 
    t2 = _mm_min_ps(*r1, *r2);

    // SEGUNDO PASO
    *r1 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(2,0,2,0)); 
    *r2 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(3,1,3,1));
    *r1 = _mm_shuffle_ps(*r1, *r1, _MM_SHUFFLE(3,1,2,0)); // INVERTIR AL MEDIO
    *r2 = _mm_shuffle_ps(*r2, *r2, _MM_SHUFFLE(3,1,2,0)); // INVERTIR AL MEDIO

    t1 = _mm_max_ps(*r1, *r2);
    t2 = _mm_min_ps(*r1, *r2);
    
    // TERCER PASO
    *r1 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(1,0,1,0)); 
    *r2 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(3,2,3,2));
    *r1 = _mm_shuffle_ps(*r1, *r1, _MM_SHUFFLE(3,1,2,0)); // INVERTIR AL MEDIO
    *r2 = _mm_shuffle_ps(*r2, *r2, _MM_SHUFFLE(3,1,2,0)); // INVERTIR AL MEDIO

    t1 = _mm_max_ps(*r1, *r2);
    t2 = _mm_min_ps(*r1, *r2);

    // FINAL
    *r1 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(1,0,1,0)); 
    *r2 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(3,2,3,2));
    *r1 = _mm_shuffle_ps(*r1, *r1, _MM_SHUFFLE(3,1,2,0)); // INVERTIR AL MEDIO
    *r2 = _mm_shuffle_ps(*r2, *r2, _MM_SHUFFLE(3,1,2,0)); // INVERTIR AL MEDIO
}


int main()
{
    
    //ARREGLOS DE ENTRADA Y SALIDA
    float A1[4] __attribute__((aligned(16))) = {5.0, 6.0, 7.0, 8.0};
    float A2[4] __attribute__((aligned(16))) = {1.0, 2.0, 3.0, 4.0};

    print_float_array(A1,4);
    printf("\n");
    print_float_array(A2,4);
    printf("\n\n");

    

    //REGISTROS DE ENTRADA Y SALIDA
    __m128 r1, r2;

    //REGISTROS TEMPORALES
    __m128 t1,t2;

    //CARGAR REGISTROS
    r1 = _mm_load_ps(A1);
    r2 = _mm_load_ps(A2);

    // BMN NETWORK
    bmn_network(&r1,&r2);

    //GUARDAR REGISTROS
    _mm_store_ps(A1, r1);
    _mm_store_ps(A2, r2);

    print_float_array(A1,4);
    printf("\n");
    print_float_array(A2,4);
    printf("\n");

    return 1;
}