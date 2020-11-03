#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "utils.h"
#include "listlist.h"
#include "list.h"

int main(int argc, char *argv[])
{
    int NValue = 0;
    int dValue = 0;
    char *iValue = NULL;
    char *oValue = NULL;
    get_opt(argc, argv, &iValue, &oValue, &NValue, &dValue);

    float *values = (float *)aligned_alloc(16, sizeof(float) * NValue); // Reservar memoria para arreglo de valores

    // LEER ARCHIVO
    read_file(iValue, values, NValue);
    ListList *ll = ll_create();
    List *l2 = list_create();
    for (int i = 0; i < NValue / 16; i++)
    {

        __m128 r1, r2, r3, r4;
        //CARGAR REGISTROS
        r1 = _mm_load_ps(values + (i * 16) + 0);
        r2 = _mm_load_ps(values + (i * 16) + 4);
        r3 = _mm_load_ps(values + (i * 16) + 8);
        r4 = _mm_load_ps(values + (i * 16) + 12);

        sort_in_register(&r1, &r2, &r3, &r4);
        bmn_network(&r1, &r2);
        bmn_network(&r3, &r4);
        merge_simd(&r1, &r2, &r3, &r4);

        List *l1 = list_create();
        list_load(l1,r1);
        list_load(l1,r2);
        list_load(l1,r3);
        list_load(l1,r4);
        ll_append(ll,*l1);
    }

    ll_merge(ll,l2);
    //list_print(l2);
    write_file(oValue, l2->data, l2->len);


    // Liberar la memoria
    ll_free(ll);
    list_free(l2);
    free(values);
    return 0;
}