#include "pilha.h"
#include <stdlib.h>

t_Sentinela* init_stack(){
    t_Sentinela* l = malloc(sizeof(t_Sentinela));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void insert_stack(t_Sentinela* l, void* item){
    if(l->prim == l->ult){

    }
}