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
void write_file(char *file_name, float *array, int size)
{
    FILE *output_file = fopen(file_name, "wb"); // Abrir archivo
    fwrite(array, sizeof(float), size, output_file);
    fclose(output_file); //Cerrar archivo
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

// Descripción: Función que recibe los parámetros de entrada mediante el uso de getopt
// Entradas: argumentos ingresados por consola
// Salida: 0 en caso de éxito, 1 en caso de error.
void get_opt(int argc, char *argv[], char **i, char **o, int *n, int *d)
{
    int c;

    while ((c = getopt(argc, argv, "i:o:N:d:")) != -1)
    {
        switch (c)
        {
        case 'i':
            *i = optarg;
            break;
        case 'o':
            *o = optarg;
            break;
        case 'N':
            sscanf(optarg, "%i", n);
            break;
        case 'd':
            sscanf(optarg, "%i", d);
            break;
        case '?':
            if (optopt == 'i' || optopt == 'o' || optopt == 'N')
            {
                fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
                exit(EXIT_FAILURE);
            }
            else if (isprint(optopt))
                fprintf(stderr, "Opcion desconocida `-%c'.\n", optopt);
            else
                fprintf(stderr, "Opcion con caracter desconocido `\\x%x'.\n", optopt);
        default:
            abort();
        }
    }

    /*if(argc < 8){//si se ingresa un numero de argumentos menor a 3, se finaliza la ejecucion del programa
		//Debe ser 3, porque el nombre del programa se considera como un argumento, siendo -h y el valor que acompañe a -h los dos argumentos faltantes. No se considera -m (que seria el cuarto argumento) porque es un flag que puede ser especificado por el usuario o no
		printf("Se ingreso un numero incorrecto de argumentos\n");
		fprintf(stderr, "Uso correcto: %s [-i nombreImagen] [-s nombreSalidaSecuencial] [-s nombreSalidaParalelo] [-n numeroEntero] [-d]\n",
				   argv[0]);
		   exit(EXIT_FAILURE);
		}*/
}