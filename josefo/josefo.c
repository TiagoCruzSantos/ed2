#include "josefo.h"

typedef struct cell{
    int person;
    struct cell* prev;
    struct cell* next;
} Cell;
typedef struct lst{
    Cell* frs;
} List;

List* init_josefo(int n){
    List* list = malloc(sizeof(List));
    Cell* ps = malloc(sizeof(Cell)); 
    ps->person = 1;
    list->frs = ps;
    Cell* ant = ps;
    for(int i = 1; i < n; i++){
        Cell* pso = malloc(sizeof(Cell));
        pso->person = i + 1;
        pso->prev = ant;
        ant->next = pso;
        ant = pso;
    }
    ant->next = ps;
    ps->prev = ant;
    return list;
}

void remove_cell(List* jsf, Cell* cell){
    cell->prev->next = cell->next;
    cell->next->prev = cell->prev;
    if(cell == jsf->frs){
        jsf->frs = cell->next;
    }
    if(cell->prev == cell){
        jsf->frs = NULL;
    }
    free(cell);
}

int select_josefo(List* jsf, int m){
    Cell* select = jsf->frs;
    while(jsf->frs->next != jsf->frs){
        for(int i = 0; i < m - 1; i++){
            select = select->next;
        }
        Cell* save = select->next;
        remove_cell(jsf, select);
        select = save;
    }
    return select->person;
}

void clear_josefo(List* jsf){
    Cell* clear = jsf->frs;
    Cell* nxt = jsf->frs;
    do{
        nxt = clear->next;
        remove_cell(jsf, clear);
        clear = nxt;
    }while(jsf->frs != NULL);
    free(jsf);
}

void print_josefo(List* lst){
    Cell* prt = lst->frs;
    do{
        printf("%d\n", prt->person);
        prt = prt->next;
    }while(prt != lst->frs);
}