#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

t_Sentinela* init_stack(){
    t_Sentinela* l = malloc(sizeof(t_Sentinela));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void insert_stack(t_Sentinela* l, void* item){
    t_Celula* c = malloc(sizeof(t_Celula));
    c->value = item;
    c->prox = NULL;
    if(l->ult == NULL){
        l->prim = c;
        l->ult = c;
        return;
    }
    c->prox = l->prim;
    l->prim = c;
    return;
}

void *remove_stack(t_Sentinela* l){
    t_Celula* c = l->prim;
    if(c == NULL){
        l->ult = NULL;
        return NULL;
    }
    l->prim = l->prim->prox;
    void * item = c->value;
    free(c);
    return item;
}

void free_stack(t_Sentinela* l){
    t_Celula* c = l->prim;
    t_Celula* ant = c;
    while(c != NULL){
        ant = c;
        c = c->prox;
        free(ant->value);
        free(ant);
    }
    free(l);
}