#ifndef _CRIVO_
#define _CRIVO_
#include <stdlib.h>
#include <stdbool.h>

typedef struct cel{
    int label;
    bool mark;
}Celula;

Celula* init_crivo(int n);

void mark_prime_crivo(Celula* crivo, int n);

void print_prime_crivo(Celula* crivo, int n);

void free_crivo(Celula* crivo);

#endif