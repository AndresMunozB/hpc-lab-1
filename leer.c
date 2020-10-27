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
    float buffer;                              // Buffer de lectura
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
        printf("%f\n", array[i]);
}

int main()
{
    char *input_file_name = "data/64floats.raw";
    char *output_file_name = "output.raw";
    int size = 64;
    int d = 0;
    float *values = (float *)malloc(sizeof(float) * size); // Reservar memoria para arreglo de valores
    read_file(input_file_name, values, size);
    print_float_array(values, size);

    float A[4] __attribute__((aligned(16))) = {values[0], values[1], values[2], values[3]};
    float B[4] __attribute__((aligned(16))) = {values[4], values[5], values[6], values[7]};
    float C[4] __attribute__((aligned(16))) = {values[8], values[9], values[10], values[11]};
    float D[4] __attribute__((aligned(16))) = {values[12], values[13], values[14], values[15]};
    __m128 r1, r2, r3, r4;

    r1 = _mm_load_ps(A);
    r2 = _mm_load_ps(B);
    r3 = _mm_load_ps(C);
    r4 = _mm_load_ps(D);

    free(values);
    return 1;
}