#include "arvore.h"
#include <stdio.h>

int main(){
    t_Base* l = init_tree();
    insert_tree(l, 50);
    insert_tree(l, 100);
    insert_tree(l, 30);
    insert_tree(l, 20);
    insert_tree(l, 40);
    insert_tree(l, 45);
    insert_tree(l, 35);
    insert_tree(l, 37);
    print_tree_inOrder(l);
    printf("\n");
    print_tree_preOrder(l);
    printf("\n");
    print_tree_postOrder(l);
    free_tree(l);
}