#ifndef _JOSEFO_
#define _JOSEFO_

typedef struct cel{
    int pess;
    struct cel *prox;
    struct cel *ant;
    
} t_Celula;

typedef struct sent{
    t_Celula* prim;
    t_Celula* ult;
} t_Sentinela;

t_Sentinela* init_josefo(int n);

void remove_josefo(t_Sentinela* l, t_Celula* rm);

void print_josefo(t_Sentinela* l);

int select_josefo(t_Sentinela* l, int m);

void free_josefo(t_Sentinela* l);

#endif