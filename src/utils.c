#include "utils.h"

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
