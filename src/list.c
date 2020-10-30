#include "list.h"

void init(List *list)
{
    list->len = 0;
}

void print_list(List *list)
{
    for (int i = 0; i < list->len; i++)
    {
        printf("%f ", list->data[i]);
    }
    printf("\n");
}

void free_list(List *list)
{
    if (list->len != 0)
        free(list->data);
}

void append(List *list, float new_element)
{
    if (list->len == 0)
    {
        list->data = (float *)malloc(sizeof(float));
        list->data[0] = new_element;
    }
    else
    {
        list->data = (float *)realloc(list->data, (list->len + 1) * sizeof(float));
        list->data[list->len] = new_element;
    }
    list->len++;
}

void pop(List *list)
{
    float *new_data = (float *)malloc(sizeof(float) * (list->len - 1));
    for (int i = 1; i < list->len; i++)
    {
        new_data[i - 1] = list->data[i];
    }
    list->data = new_data;
    list->len--;
}

void load(List *list, __m128 r1)
{
    float aux[4] __attribute__((aligned(16))) = {0.0, 0.0, 0.0, 0.0};
    _mm_store_ps(aux, r1);
    for (int i = 0; i < 4; i++)
    {
        append(list, aux[i]);
    }
}

/*int main(){
    List list;
    init(&list); //Se debe inicializar la lista
    float A1[4] __attribute__((aligned(16))) = {12.0, 21.0, 4.0, 13.0}; 
    __m128 r1 = _mm_load_ps(A1);
    load(&list,r1);
    append(&list,1.1);
    append(&list,2.1);
    pop(&list);
    pop(&list);
    append(&list,3.1);
    print_list(&list);
    free_list(&list); // No se puede liberar una lista no inicializada
    return 0;
}*/