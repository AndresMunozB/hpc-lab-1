#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
	int len;
	float* elements;
}Lista;


Lista* agregarNodo(Lista* list , float* aux){
    if(list->len == 0)
    {
    	list->elements = (float*)malloc(sizeof(float));
    	list->elements[0] = *aux;
    }
    else
    {
        list->elements = (float*)realloc(list->elements, (list->len + 1) * sizeof (float)); // Pedimos mas memoria para el arreglo creado
        list->elements[list->len] = *aux; // Agregamos el nodo que se desea agregar, luego de haber solicitado memoria
    }
    list->len++; // aumnetamos el largo de la lista de arreglos
    return list;
}

void mostrarLista(Lista* lista)
{
	int j;
	for (j = 0; j < lista->len; j++)
    {
    	printf("El elemento es: %f \n", lista->elements[j]);
    }
}

int lenList(float* list){
	printf("Elemento 1: %f\n", list[0]);
	printf("Elemento 2: %f\n", list[1]);
	printf("Elemento 3: %f\n", list[2]);
	printf("Elemento 4: %f\n", list[3]);
	int longitud = sizeof(list) / sizeof(float) ;
	return longitud;
}

float* cutList(float* aux){
	float* newList = (float*)malloc(sizeof(float));
	int i;
	for (i = 1; i < lenList(aux); i++)
	{
		newList[i] = aux[i];
	}
	return newList;
}

int main(int argc, char const *argv[])
{
	Lista* finalList = (Lista*)malloc(sizeof(Lista));
	Lista* auxList = (Lista*)malloc(sizeof(Lista));

	for (int i = 0; i < 16; i++)
	{	
		float* aux = (float*)malloc(sizeof(float));
		aux[0] = (float)0.111;
		aux[1] = (float)0.112;
		aux[2] = (float)0.113;
		agregarNodo(auxList,aux);
		free(aux);
	}
	printf("%f\n", cutList(auxList[0].elements)[0]);

	printf("Largo de lista: %d\n", auxList->len);

	return 0;
}

