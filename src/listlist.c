#include "list.h"

typedef struct ListList{
    int len;
    List *data;
}ListList;

void init_ll(ListList *listlist){
    listlist->len=0;
}
void print_ll(ListList *listlist){
    for(int i=0;i<listlist->len;i++){
        print_list(&listlist->data[i]);
    }
    printf("\n");
}

void append_ll(ListList *listlist, List new_element){
    if (listlist->len == 0)
    {
        listlist->data = (List *)malloc(sizeof(List));
        listlist->data[0] = new_element;
    }
    else
    {
        listlist->data = (List *)realloc(listlist->data, (listlist->len + 1) * sizeof(List));
        listlist->data[listlist->len] = new_element;
    }
    listlist->len++;
} 

int main(){
    List list;
    init(&list);
    append(&list,1.2); 
    append(&list,1.2); 
    
    ListList ll;
    init_ll(&ll);
    append_ll(&ll,list);
    append_ll(&ll,list);
    print_ll(&ll);
    return 0;
}