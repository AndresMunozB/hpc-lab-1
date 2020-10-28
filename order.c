#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
	int len;
	int* elements;
}Lista;


Lista* agregarNodo(Lista* list , int* aux)
{
    if(list->len == 0)
    {
    	list->elements = (int*)malloc(sizeof(int));
    	list->elements[0] = *aux;
    }
    else
    {
        list->elements = (int*)realloc(list->elements, (list->len + 1) * sizeof (int)); // Pedimos mas memoria para el arreglo creado
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
    	printf("El elemento es: %d \n", lista->elements[j]);
    }
}

int lenList(int* list){
	int longitud = sizeof(list) / sizeof(list[0]);
	return longitud;
}

int* cutList(int* aux){
	int* newList = (int*)malloc(sizeof(int));
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

	int* aux = (int*)malloc(sizeof(int));
	for (int i = 0; i < 16; i++)
	{
		aux[0] = 0;
		aux[1] = 1;
		aux[2] = 2;
		aux[3] = 3;
		agregarNodo(auxList,aux);
	}

	printf("%d\n",cutList(aux) );
	int* aux1 = (int*)malloc(sizeof(int));
	printf("%d\n",cutList(aux1) );

	printf("Largo de lista: %d\n", auxList->len);

	return 0;
}

