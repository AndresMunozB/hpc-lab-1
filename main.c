#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hola mundo!\n");
    int c, size, debug;
	char* input_raw = (char*) malloc(sizeof(char) * 50);
	char* output_sequential = (char*) malloc(sizeof(char) * 50);
	char* output_simd = (char*) malloc(sizeof(char) * 50);
    
    char **ivalue;
    char **ovalue;
    int *nvalue
    int *dflag
    while ((c = getopt(argc, argv, "i:o:N:d:")) != -1)
    {
        switch (c)
        {
        case 'i':
            ival = optarg;
            break;
        case 'o':
            sval = optarg;
            break;
        case 'N':
            sscanf(optarg, "%i", &nval);
            break;
        case 'd':
            sscanf(optarg, "%i", &dval);
            break;
        case '?':
            if (optopt == 'i' || optopt == 'o' || optopt == 'N')
            {
                fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
                exit();
            }
            else if (isprint(optopt))
                fprintf(stderr, "Opcion desconocida `-%c'.\n", optopt);
            else
                fprintf(stderr,
                        "Opcion con caracter desconocido `\\x%x'.\n",
                        optopt);
            return 1;
        default:
            abort();
        }
    }
    return 1;
}