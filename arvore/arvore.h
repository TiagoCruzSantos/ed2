#ifndef _ARVORE_
#define _ARVORE_

typedef struct n{
    int a;
    struct n* esq;
    struct n* dir;
} t_No;

typedef struct base{
    t_No* base;
}t_Base;

t_Base* init_tree();

t_No* init_node(int n);

void insert_tree(t_Base* l, int n);

void tree_inOrder(t_Base* l, void (*visit)(t_No*));

void tree_preOrder(t_Base* l, void (*visit)(t_No*));

void tree_postOrder(t_Base* l, void (*visit)(t_No*));

int hight_tree(t_Base* l);

void free_tree(t_Base* l);

#endif