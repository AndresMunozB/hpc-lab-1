#include <stdio.h>
#include <stdlib.h>

/**
 * read_file: Lectura de un archivo
 * Entrada:
 *      - file_name: Nombre de entrada del archivo
 *      - size: Cantidad de elementos dentro del archivo
 * Salida: arreglo de float con valores del archivo.
*/
void read_file(char *file_name, float* values, int size)
{
    FILE *input_file = fopen(file_name, "rb"); // Abrir archivo
    
    float buffer; // Buffer de lectura
    for (int i = 0; i < size; i++)
    {
        fread(&buffer, sizeof(float), 1, input_file); // Leer un valor desde el archivo
        values[i] = buffer; // Agregar el valor en el arreglo
    }
    fclose(input_file); //Cerrar archivo
}
/**
 * print_fa: 
 * Entrada:
 *      - values: arreglo de floats 
 *      - size: largo del arreglo
*/
void print_values(float* values, int size){
    for (int i=0;i<size;i++){
        printf("%f\n", values[i]);
    }
}
int main()
{
    char *input_file_name = "data/64floats.raw";
    char *output_file_name = "output.raw";
    int size = 64;
    int d = 0;
    float *values = (float *)malloc(sizeof(float) * size); // Reservar memoria para arreglo de valores
    read_file(input_file_name, values, size);
    print_values(values,size);
    free(values);
    return 1;
}