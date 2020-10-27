#include <stdio.h>
#include <stdlib.h>

int main()
{

    char *input_file_name = "data/64floats.raw";
    char *output_file_name = "output.raw";
    int N = 64;
    int d = 0;
    float *values = (float *)malloc(sizeof(float) * N);
    float value;
    int i = 0;

    FILE *input_file = fopen(input_file_name,"rb");
    while (i != N)
    {
        fread(&value, sizeof(float), 1, input_file);
        values[i] = value;
        printf("%f\n",value);
        i++;
    }
    printf("%s\n", input_file_name);
    free(values);
    return 1;
}