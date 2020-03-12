#include "pilha.h"

t_Sentinela* init_stack(){
    t_Sentinela* l = malloc(sizeof(t_Sentinela));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

