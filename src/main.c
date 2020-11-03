#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    int NValue = 0;
    int dValue = 0;
    char *iValue = NULL;
    char *oValue = NULL;
    get_opt(argc, argv, &iValue, &oValue, &NValue, &dValue);
    printf("%s\n", iValue);
    printf("%s\n", oValue);
    printf("%d\n", NValue);
    printf("%d\n", dValue);

    float *values = (float *)aligned_alloc(16, sizeof(float) * NValue); // Reservar memoria para arreglo de valores
    //float *values = (float *)malloc(sizeof(float) * NValue); // Reservar memoria para arreglo de valores

    // LEER ARCHIVO
    read_file(iValue, values, NValue);

    for (int i = 0; i < NValue / 16; i++)
    {

        __m128 r1, r2, r3, r4;
        //CARGAR REGISTROS
        r1 = _mm_load_ps(values + (i * 16) + 0);
        r2 = _mm_load_ps(values + (i * 16) + 4);
        r3 = _mm_load_ps(values + (i * 16) + 8);
        r4 = _mm_load_ps(values + (i * 16) + 12);

        sort_in_register(&r1, &r2, &r3, &r4);
        bmn_network(&r1, &r2);
        bmn_network(&r3, &r4);
        merge_simd(&r1, &r2, &r3, &r4);

        float A[16] __attribute__((aligned(16)));
        //GUARDAR REGISTROS
        _mm_store_ps(A + 0, r1);
        _mm_store_ps(A + 4, r2);
        _mm_store_ps(A + 8, r3);
        _mm_store_ps(A + 12, r4);

        printf("Matriz\n");
        print_float_array(A, 16);
        printf("\n");
    }

    free(values);
    return 0;
}