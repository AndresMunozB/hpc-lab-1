# include <stdio.h>
# include <stdlib.h>
# include "functions.h"
# include "utils.h"

int main(int argc, char *argv[])
{
    int NValue = 0;
    int dValue = 0;
    char* iValue = NULL;
    char* oValue = NULL;
    get_opt(argc,argv,&iValue,&oValue,&NValue,&dValue);
    //printf("%s\n",iValue);
    //printf("%s\n",oValue);
    //printf("%d\n",NValue);
    //printf("%d\n",dValue);

    char *input_file_name = "./data/64floats.raw";
    char *output_file_name = "output.raw";
    int size = 64;
    int d = 0;
    printf("%d\n",d);
    printf("%s\n",output_file_name);
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

    //CARGAR REGISTROS
    r1 = _mm_load_ps(A1);
    r2 = _mm_load_ps(A2);
    r3 = _mm_load_ps(A3);
    r4 = _mm_load_ps(A4);

    // **IMPORTANT** PRUEBAS DE SOR IN REGISTER 
    sort_in_register(&r1,&r2,&r3,&r4);

    //GUARDAR REGISTROS
    _mm_store_ps(A1, r1);
    _mm_store_ps(A2, r2);
    _mm_store_ps(A3, r3);
    _mm_store_ps(A4, r4);

    printf("traspuesta\n");
    print_matrix_16(A1, A2, A3, A4);

    // **IMPORNTANT** PRUEBAS DE BMN NETWORK
    bmn_network(&r1,&r2);

    //GUARDAR REGISTROS
    _mm_store_ps(A1, r1);
    _mm_store_ps(A2, r2);

    print_float_array(A1,4);
    printf("\n");
    print_float_array(A2,4);
    printf("\n");

    free(values);
    return 0;
}