#include "getoptFunction.h"

// Descripción: Función que recibe los parámetros de entrada mediante el uso de getopt
// Entradas: argumentos ingresados por consola
// Salida: 0 en caso de éxito, 1 en caso de error.
void getoptFunction(int argc, char *argv[], char **i, char **o, int *N, int *d)
{
    opterr = 0;
    int NValue, dValue, c;
    char *iValue = NULL;
    char *oValue = NULL;

    while ((c = getopt(argc, argv, "i:o:N:d:")) != -1)
    {
        switch (c)
        {
        case 'i':
            iValue = optarg;
            break;
        case 'o':
            oValue = optarg;
            break;
        case 'N':
            sscanf(optarg, "%i", &NValue);
            break;
        case 'd':
            sscanf(optarg, "%i", &dValue);
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
                fprintf(stderr,
                        "Opcion con caracter desconocido `\\x%x'.\n",
                        optopt);
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

    *i = iValue;
    *o = oValue;
    *N = NValue;
    *d = dValue;
}