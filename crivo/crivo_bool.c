#include "crivo.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct cel{
    bool mark;
}Celula;

Celula* init_crivo(int n){
    Celula* lista = malloc(sizeof(Celula) * (n - 1));
    for(int i = 2; i <= n; i++){
        lista[i - 2].mark = false;
    }
    return lista;
}

void mark_prime_crivo(Celula* crivo, int n){
    for(int i = 2; i <= n/2; i++){
        if(crivo[i - 2].mark){
            continue;
        }
        int count = 1;
        for(int j = i; j <= n ; j = i*count){
            count++;
            crivo[j - 2].mark = true;
        }
        crivo[i - 2].mark = false;
    }
}

void print_prime_crivo(Celula* crivo, int n){
    for(int i = 0; i <= n - 2; i++){
        if(!crivo[i].mark){
            printf("%d é primo\n", i + 2);
        }
    }
}

void free_crivo(Celula* crivo){
    free(crivo);
}