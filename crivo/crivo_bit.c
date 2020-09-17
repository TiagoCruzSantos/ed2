#include "crivo.h"
#include <stdio.h>

typedef struct cel{
    int* label;
    u_int8_t* mark;
}Celula;

Celula* init_crivo(int n){
    Celula* lista = malloc(sizeof(Celula));
    lista->label = malloc(sizeof(int)  * (n - 1));
    for(int i = 2; i <= n; i++){
        lista->label[i - 2] = i;
    }
    lista->mark = calloc((n/8 + 1), sizeof(u_int8_t));
    return lista;
}

void mark_prime_crivo(Celula* crivo, int n){
    for(int i = 2; i <= n/2; i++){
        if((crivo->mark[((i - 2)/8)] >> (i - 2)%8) & 0x01){
            continue;
        }
        int count = 1;
        for(int j = crivo->label[i - 2]; j <= n ; j = crivo->label[i - 2]*count){
            count++;
            crivo->mark[((j - 2)/8)] |= 0x01 << (j - 2)%8;
        }
        crivo->mark[((i - 2)/8)] &= ~(0x01 << (i - 2)%8);
    }
}

void print_prime_crivo(Celula* crivo, int n){
    for(int i = 0; i <= n - 2; i++){
        if(!((crivo->mark[(i/8)] >> i%8) & 0x01)){
            printf("%d é primo\n", crivo->label[i]);
        }
    }
}

void free_crivo(Celula* crivo){
    free(crivo->label);
    free(crivo->mark);
    free(crivo);
}