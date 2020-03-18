#ifndef _PILHA_
#define _PILHA_

typedef struct c{
    void* value;
    struct c* prox;
} t_Celula;

typedef struct sent{
    t_Celula* prim;
    t_Celula* ult;
} t_Sentinela;

t_Sentinela* init_stack();

void insert_stack(t_Sentinela* l, void* item);

void* remove_stack(t_Sentinela* l);

void print_stack(t_Sentinela* l);

void free_stack(t_Sentinela* l);

#endif