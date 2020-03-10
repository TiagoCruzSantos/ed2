#include "josefo.h"
#include <stdlib.h>
#include <stdio.h>

t_Sentinela* init_josefo(int n){
    t_Sentinela* l = malloc(sizeof(t_Sentinela));
    l->prim = NULL;
    l->ult = NULL;
    t_Celula* c;
    t_Celula* ant;
    c = malloc(sizeof(t_Celula));
    c->pess = 1;
    l->prim = c;
    for(int i = 1; i < n; i++){
        c->prox = malloc(sizeof(t_Celula));
        ant = c;
        c = c->prox;
        c->pess = i+1;
        c->ant = ant;
    }
    l->ult = c;
    c->prox = l->prim;
    l->prim->ant = c;
    return l;
}

void print_josefo(t_Sentinela* l){
    t_Celula* c = l->prim;
    while(c->prox != NULL){
        printf("%d\n", c->pess);
        c = c->ant;
    }
}

void remove_josefo(t_Sentinela* l, t_Celula* ant_rm){
    
}