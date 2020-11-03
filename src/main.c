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
    //printf("%s\n",iValue);
    //printf("%s\n",oValue);
    //printf("%d\n",NValue);
    //printf("%d\n",dValue);

    char *input_file_name = "./data/65536floats.raw";
    char *output_file_name = "output.raw";
    int size = 65536;
    int d = 0;
    printf("%d\n", d);
    printf("%s\n", output_file_name);
    printf("%s\n", input_file_name);
    //float *values = (float *)aligned_alloc(16, sizeof(float) * size); // Reservar memoria para arreglo de valores
    float *values = (float *)malloc(sizeof(float) * size); // Reservar memoria para arreglo de valores

    // LEER ARCHIVO
    read_file(input_file_name, values, size);

    for (int i = 0; i < size / 16; i++)
    {
        float A1[4] __attribute__((aligned(16))) = {values[(i * 16) + 0], values[(i * 16) + 1], values[(i * 16) + 2], values[(i * 16) + 3]};
        float A2[4] __attribute__((aligned(16))) = {values[(i * 16) + 4], values[(i * 16) + 5], values[(i * 16) + 6], values[(i * 16) + 7]};
        float A3[4] __attribute__((aligned(16))) = {values[(i * 16) + 8], values[(i * 16) + 9], values[(i * 16) + 10], values[(i * 16) + 11]};
        float A4[4] __attribute__((aligned(16))) = {values[(i * 16) + 12], values[(i * 16) + 13], values[(i * 16) + 14], values[(i * 16) + 15]};
        __m128 r1, r2, r3, r4;

        //CARGAR REGISTROS
        //r1 = _mm_load_ps(values+0);
        //r2 = _mm_load_ps(values+4);
        //r3 = _mm_load_ps(values+8);
        //r4 = _mm_load_ps(values+12);
        r1 = _mm_load_ps(A1);
        r2 = _mm_load_ps(A2);
        r3 = _mm_load_ps(A3);
        r4 = _mm_load_ps(A4);

        sort_in_register(&r1, &r2, &r3, &r4);
        bmn_network(&r1, &r2);
        bmn_network(&r3, &r4);
        merge_simd(&r1, &r2, &r3, &r4);

        //GUARDAR REGISTROS
        _mm_store_ps(A1, r1);
        _mm_store_ps(A2, r2);
        _mm_store_ps(A3, r3);
        _mm_store_ps(A4, r4);

        printf("Matriz\n");
        print_matrix_16(A1, A2, A3, A4);
    }

    free(values);
    return 0;
}