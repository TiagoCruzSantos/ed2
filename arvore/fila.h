#ifndef __FILA__
#define __FILA__
#include "arvore.h"
#include <stdlib.h>

typedef struct fila_cel{
    t_No* data;
    struct fila_cel* ant;
    
} Fila_cel;


typedef struct fila_tree{
    Fila_cel* prim;
    Fila_cel* ult;
} Fila;

Fila* init_fila();

void insert_fila(Fila* fila, t_No* node);

t_No* remove_fila(Fila* fila);

void free_fila(Fila* fila);

#endif