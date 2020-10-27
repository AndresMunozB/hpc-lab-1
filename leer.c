#include <stdio.h>
#include <stdlib.h>
#include <xmmintrin.h> /* SSE __m128 float */

/**
 * read_file: Lectura de un archivo
 * Entrada:
 *      - file_name: Nombre de entrada del archivo
 *      - array: valor por referencia donde quedaran los elementos del archivo
 *      - size: Cantidad de elementos dentro del archivo
 * Salida: arreglo de float con valores del archivo.
*/
void read_file(char *file_name, float *array, int size)
{
    FILE *input_file = fopen(file_name, "rb"); // Abrir archivo
    fread(array, sizeof(float), size, input_file);
    fclose(input_file); //Cerrar archivo
}

/**
 * print_float_array: Imprime un arreglo de floats
 * Entrada:
 *      - values: arreglo de floats 
 *      - size: largo del arreglo
*/
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
    char *input_file_name = "data/64floats.raw";
    char *output_file_name = "output.raw";
    int size = 64;
    int d = 0;
    float *values = (float *)malloc(sizeof(float) * size); // Reservar memoria para arreglo de valores

    // LEER ARCHIVO
    read_file(input_file_name, values, size);

    //Arreglos de entrada
    /*float A1[4] __attribute__((aligned(16))) = {values[0], values[1], values[2], values[3]};
    float A2[4] __attribute__((aligned(16))) = {values[4], values[5], values[6], values[7]};
    float A3[4] __attribute__((aligned(16))) = {values[8], values[9], values[10], values[11]};
    float A4[4] __attribute__((aligned(16))) = {values[12], values[13], values[14], values[15]};*/

    //ARREGLOS DE ENTRADA Y SALIDA
    float A1[4] __attribute__((aligned(16))) = {12.0, 21.0, 4.0, 13.0};
    float A2[4] __attribute__((aligned(16))) = {9.0, 8.0, 6.0, 7.0};
    float A3[4] __attribute__((aligned(16))) = {1.0, 14.0, 3.0, 0.0};
    float A4[4] __attribute__((aligned(16))) = {5.0, 11.0, 15.0, 10.0};

    //REGISTROS DE ENTRADA Y SALIDA
    __m128 r1, r2, r3, r4;

    //REGISTROS TEMPORALES
    __m128 p11, p12, p13, p14, p22, p23;

    //CARGAR REGISTROS
    r1 = _mm_load_ps(A1);
    r2 = _mm_load_ps(A2);
    r3 = _mm_load_ps(A3);
    r4 = _mm_load_ps(A4);

    //PRIMERO PASO
    p11 = _mm_min_ps(r1, r3);
    p12 = _mm_min_ps(r2, r4);
    p13 = _mm_max_ps(r1, r3);
    p14 = _mm_max_ps(r2, r4);

    //SEGUNDO PASO
    r1 = _mm_min_ps(p11, p12); //FINAL
    p22 = _mm_max_ps(p11, p12);
    p23 = _mm_min_ps(p13, p14);
    r4 = _mm_max_ps(p13, p14); //FINAL

    //TERCER PASO
    r2 = _mm_min_ps(p22, p23); //FINAL
    r3 = _mm_max_ps(p22, p23); //FINAL

    //TRASPONER LA MATRIZ 
    _MM_TRANSPOSE4_PS(r1, r2, r3, r4);

    //GUARDAR REGISTROS
    _mm_store_ps(A1, r1);
    _mm_store_ps(A2, r2);
    _mm_store_ps(A3, r3);
    _mm_store_ps(A4, r4);

    printf("traspuesta\n");
    print_matrix_16(A1, A2, A3, A4);

    free(values);
    return 1;
}