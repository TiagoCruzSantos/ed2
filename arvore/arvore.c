#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

t_Base* init_tree(){
    t_Base* l = malloc(sizeof(t_Base));
    l->base = NULL;
    return l;
}

t_No* init_node(int n){
    t_No* no = malloc(sizeof(t_No));
    no->a = n;
    no->esq = NULL;
    no->dir = NULL;
}

void insert_tree(t_Base* l, int n){
    if(l->base == NULL){
        l->base = init_node(n);
        return;
    }
    t_No* ant_no = l->base;
    t_No* at_no = l->base;
    while(at_no != NULL){
        ant_no = at_no;
        if(n < at_no->a){
            at_no = at_no->esq;
        }else if(n > at_no->a){
            at_no = at_no->dir;
        }else{
            return;
        }
    }
    if(n < ant_no->a){
        ant_no->esq = init_node(n);
    }else{
        ant_no->dir = init_node(n);
    }
}

void print_tree_rec_inOrder(t_No* node){
    if(node->esq != NULL){
        print_tree_rec_inOrder(node->esq);
    }
    printf("%d\n", node->a);
    if(node->dir != NULL){
        print_tree_rec_inOrder(node->dir);
    }
}

void print_tree_rec_preOrder(t_No* node){
    printf("%d\n", node->a);
    if(node->esq != NULL){
        print_tree_rec_preOrder(node->esq);
    }
    if(node->dir != NULL){
        print_tree_rec_preOrder(node->dir);
    }
}

void print_tree_rec_postOrder(t_No* node){
    if(node->esq != NULL){
        print_tree_rec_postOrder(node->esq);
    }
    if(node->dir != NULL){
        print_tree_rec_postOrder(node->dir);
    }
    printf("%d\n", node->a);
}

void print_tree_inOrder(t_Base* l){
    print_tree_rec_inOrder(l->base);
}

void print_tree_preOrder(t_Base* l){
    print_tree_rec_preOrder(l->base);
}

void print_tree_postOrder(t_Base* l){
    print_tree_rec_postOrder(l->base);
}

int maior(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int hight_tree_node(t_No* no){
    int esq = 0;
    int dir = 0;
    if(no->dir != NULL){
        dir = hight_tree_node(no->dir);
    }
    if(no->esq != NULL){
        esq = hight_tree_node(no->esq);
    }
    return 1 + maior(esq, dir);
}

int hight_tree(t_Base* l){
    if(l->base == NULL){
        return -1;
    }
    return hight_tree_node(l->base) - 1;
}

void free_node(t_No* no){
    if(no->esq != NULL){
        free_node(no->esq);
    }
    if(no->dir != NULL){
        free_node(no->dir);
    }
    free(no);
}

void free_tree(t_Base* l){
    free_node(l->base);
    free(l);
}

void print_tree_nonrecursive_inOrder(t_Base* l){
    t_Sentinela* pilha = init_stack();
    t_No* node = l->base;
    if(node != NULL){
        insert_stack(pilha, node);
    }
    while (pilha->prim != NULL){
        node = remove_stack(pilha);
        if(node->esq != NULL){
            insert_stack(pilha, node);
            insert_stack(pilha, node->esq);
            continue;
        }else if(node->dir != NULL){
            printf("%d\n", node->a);
            insert_stack(pilha, node->dir);
            continue;
        }else{
            printf("%d\n", node->a);
            continue;
        }
    }
    free_stack(pilha);
}

void print_tree_nonrecursive_preOrder(t_Base* l){

}

void print_tree_nonrecursive_postOrder(t_Base* l){

}
