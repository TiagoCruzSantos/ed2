#include "fila.h"

Fila* init_fila(){
    Fila* fila = malloc(sizeof(Fila));
    fila->prim = NULL;
    fila->ult = NULL;
    return fila;
}

void insert_fila(Fila* fila, t_No* node){
    Fila_cel* cel = malloc(sizeof(Fila_cel));
    cel->data = node;
    cel->ant = NULL;
    if(fila->prim == NULL){
        fila->prim = fila->ult = cel;
    }else{
        fila->ult->ant = cel;
        fila->ult = cel;
    }
}

t_No* remove_fila(Fila* fila){
    if(fila->prim == NULL){
        return NULL;
    }
    Fila_cel* cel = fila->prim;
    t_No* node = cel->data;
    fila->prim = cel->ant;
    if(fila->prim == NULL){
        fila->ult = NULL;
    }
    free(cel);
    return node;
}

void free_fila(Fila* fila){
    while(fila->prim != NULL){
        remove_fila(fila);
    }
    free(fila);
}