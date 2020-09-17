#include "crivo.h"
#include <stdio.h>

typedef struct cel{
    u_int8_t* mark;
}Celula;

Celula* init_crivo(int n){
    Celula* lista = malloc(sizeof(Celula));
    lista->mark = calloc((n/8 + 1), sizeof(u_int8_t));
    return lista;
}

void mark_prime_crivo(Celula* crivo, int n){
    for(int i = 2; i <= n/2; i++){
        if((crivo->mark[((i - 2)/8)] >> (i - 2)%8) & 0x01){
            continue;
        }
        int count = 1;
        for(int j = i; j <= n ; j = i*count){
            count++;
            crivo->mark[((j - 2)/8)] |= 0x01 << (j - 2)%8;
        }
        crivo->mark[((i - 2)/8)] &= ~(0x01 << (i - 2)%8);
    }
}

void print_prime_crivo(Celula* crivo, int n){
    for(int i = 0; i <= n - 2; i++){
        if(!((crivo->mark[(i/8)] >> i%8) & 0x01)){
            printf("%d é primo\n", i + 2);
        }
    }
}

void free_crivo(Celula* crivo){
    free(crivo->mark);
    free(crivo);
}