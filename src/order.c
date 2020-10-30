#include <stdio.h>
#include <stdlib.h>
#include <xmmintrin.h> /* SSE __m128 float */

typedef struct TBlock
{
	int index; // Se inicializa en cero
	float *data;  // 16 floats
} TBlock;



typedef struct TList
{
	int len;
	TBlock *data;
} TList;

TBlock *tblock_create(__m128 *r1, __m128 *r2, __m128 *r3, __m128 *r4)
{
	TBlock *block = (TBlock *)malloc(sizeof(TBlock));
	block->data = (float *)malloc(sizeof(float) * 16);
	block->index = 0;
	float A1[4] __attribute__((aligned(16))) = {0.0, 0.0, 0.0, 0.0};
	float A2[4] __attribute__((aligned(16))) = {0.0, 0.0, 0.0, 0.0};
	float A3[4] __attribute__((aligned(16))) = {0.0, 0.0, 0.0, 0.0};
	float A4[4] __attribute__((aligned(16))) = {0.0, 0.0, 0.0, 0.0};
	_mm_store_ps(A1, *r1);
	_mm_store_ps(A2, *r2);
	_mm_store_ps(A3, *r3);
	_mm_store_ps(A4, *r4);
	for (int i=0; i < 4;i++){
		block->data[i] = A1[i];
		block->data[4 + i] = A2[i];
		block->data[8 + i] = A3[i];
		block->data[12 +i] = A4[i];
	}
	return block;
}

void print_tblock(TBlock *block){
	for(int i=0;i<16;i++){
		printf("%f ",block->data[i]);
	}
}

void print_tlist(TList *list){
	for (int i = 0;i<list->len; i++){
		print_tblock(&(list->data[i]));
		printf("\n");
	}
}

void tblock_free(TBlock *block){
	free(block->data);
	free(block);
}

void tlist_free(TList *list){
	tblock_free(list->data);
	free(list);
}

TList *tlist_create(){
	TList *list = (TList*) malloc(sizeof(TList));
	list->len = 0;
	list->data = NULL;
}

void tlist_append(TList *list,TBlock *block){
	TBlock *temporal_list = (TBlock*) malloc(sizeof(TBlock)* (list->len +1));
	for( int i=0;i<list->len;i++){
		temporal_list[i] = list->data[i];
	}
	temporal_list[list->len] = *block;
	free(list->data);
	list->data = temporal_list;
	list->len++;
}

TList* append_min(TList *list,TList *merged){
	
	int index = 0;
	float min; 

	for (int i=0;i<list->len;i++){
		if (list->data[i].index != 16){
			min = list->data[i].data[index];
			break;
		}
	}
	for (int i=0;i<list->len;i++){
		if (list->data[i].index != 16){
			if(min > list->data[i].data[list->data[i].index]){
				min = list->data[i].data[list->data[i].index];
				index = i;
			}
		}
	}
	tlist_append(merged, &list->data[index]);
	list->data[index].index++;
}


int main(int argc, char const *argv[])
{
	/*Lista* finalList = (Lista*)malloc(sizeof(Lista));
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

	printf("Largo de lista: %d\n", auxList->len);*/

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

	TBlock *block = tblock_create(&r1,&r2,&r3,&r4);
	TBlock *block2 = tblock_create(&r1,&r4,&r3,&r2);
	//print_tblock(block);
	TList *list = tlist_create();
	TList *merged = tlist_create();
	tlist_append(list,block);
	tlist_append(list,block2);
	append_min(list,merged);
	print_tlist(merged);
	tblock_free(block);
	tlist_free(list);

	return 0;
}
