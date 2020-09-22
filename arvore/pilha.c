#include "pilha.h"

Stack* init_stack(){
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push_stack(Stack* stack, t_No* node){
    if(node == NULL){
        return;
    }
    Stack_node* newNode = malloc(sizeof(Stack_node));
    newNode->data = node;
    newNode->below = stack->top;
    stack->top = newNode;
}

t_No* pop_stack(Stack* stack){
    Stack_node* stack_node = stack->top;
    if(stack_node == NULL){
        return NULL;
    }
    t_No* node = stack_node->data;
    stack->top = stack_node->below;
    free(stack_node);
    return node;
}

void free_stack(Stack* stack){
    while(stack->top != NULL){
        pop_stack(stack);
    }
    free(stack);
}