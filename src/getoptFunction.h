# ifndef GETOPT_HEADER
# define GETOPT_HEADER

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>


//variables globales para recibir parametros de entrada.

void getoptFunction(int argc, char *argv[], char **i, char **o, int *N, int *d);

# endif 