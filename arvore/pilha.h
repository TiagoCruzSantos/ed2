#ifndef __PILHA__
#define __PILHA__
#include <stdlib.h>
#include "arvore.h"

typedef struct stk_node{
    t_No* data;
    struct stk_node* below;
} Stack_node;

typedef struct stk{
    Stack_node* top;
} Stack;

Stack* init_stack();

void push_stack(Stack* stack, t_No* node);

t_No* pop_stack(Stack* stack);

void free_stack(Stack* stack);

#endif
