#include "nr_caminho.h"

void tree_stack_inOrder(t_Base* l, void (*visit)(t_No*)){
    Stack* nodes = init_stack();
    t_No* node = l->base;
    while(nodes->top != NULL || node != NULL){
        if(node != NULL){
            push_stack(nodes, node);
            node = node->esq;
        }else{
            node = pop_stack(nodes);
            visit(node);
            node = node->dir;
        }
    }
    free_stack(nodes);
}

void tree_stack_preOrder(t_Base* l, void (*visit)(t_No*)){
    Stack* nodes = init_stack();
    push_stack(nodes, l->base);
    while(nodes->top != NULL){
        t_No* node = pop_stack(nodes);
        visit(node);
        push_stack(nodes, node->dir);
        push_stack(nodes, node->esq);
    }
    free_stack(nodes);
}

void tree_stack_postOrder(t_Base* l, void (*visit)(t_No*)){
    Stack* nodes = init_stack();
    t_No* ultVisit = NULL;
    t_No* node = l->base;
    while(nodes->top != NULL || node != NULL){
        if(node != NULL){
            push_stack(nodes, node);
            node = node->esq;
        }else{
            if(nodes->top->data->dir != NULL && ultVisit != nodes->top->data->dir){
                node = nodes->top->data->dir;
            }else{
                visit(nodes->top->data);
                ultVisit = pop_stack(nodes);
            }
        }
    }
    free_stack(nodes);
}

void tree_fila_levelOrder(t_Base* l, void (*visit)(t_No*)){
    Fila* fila = init_fila();
    insert_fila(fila, l->base);
    while(fila->prim != NULL){
        t_No* node = remove_fila(fila);
        if(node->esq != NULL){
            insert_fila(fila, node->esq);
        }
        if(node->dir != NULL){
            insert_fila(fila, node->dir);
        }
        visit(node);
    }
    free_fila(fila);
}