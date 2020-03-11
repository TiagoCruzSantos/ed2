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
    do{
        printf("%d\n", c->pess);
        c = c->prox;
    }while(c != l->prim);
}

void remove_josefo(t_Sentinela* l, t_Celula* rm){
    if(l->prim == l->ult){
        free(l->prim);
        l->prim = NULL;
        l->ult = NULL;
        return;
    }
    if(rm == l->prim){
        l->prim = rm->prox;
    }
    if(rm == l->ult){
        l->ult = l->ult->ant;
    }
    rm->ant->prox = rm->prox;
    rm->prox->ant = rm->ant;
    free(rm);
    return;
}

int select_josefo(t_Sentinela* l, int m){
    t_Celula* at = l->prim;
    while(l->prim != l->ult){
        for(int i = 0; i < m - 1; i++){
            at = at->prox;
        }
        t_Celula* del = at;
        at = at->prox;
        remove_josefo(l, del);
    }
    return l->prim->pess;
}

void free_josefo(t_Sentinela* l){
    l->ult->prox = NULL;
    t_Celula* at = l->prim;
    t_Celula* ant = at;
    while(at != NULL){
        ant = at;
        at = at->prox;
        free(ant);
    }
    free(l);
}