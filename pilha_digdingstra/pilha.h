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


#endif