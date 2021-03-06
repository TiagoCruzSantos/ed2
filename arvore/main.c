#include "arvore.h"
#include "nr_caminho.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void printNode(t_No* node){
    printf("%d\n",node->a);
}

int main(int argc, char *argv[]){
    struct timeval t;
    gettimeofday(&t, NULL);
    srand(t.tv_usec);
    t_Base* tree = init_tree();
    int n = atoi(argv[1]);
    for(int i = 0; i < n; i++){
        insert_tree(tree, rand());
    }
    printf("Em ordem recursivo\n");
    print_tree_inOrder(tree);
    printf("Em ordem iterativo\n");
    print_tree_nonrecursive_inOrder(tree);
    free_tree(tree);
    /*
    struct timeval t;
    gettimeofday(&t, NULL);
    srand(t.tv_usec);
    t_Base* l = init_tree();
    int n = atoi(argv[1]);
    for(int i = 0; i < n; i++){
        insert_tree(l, rand()%1000);
    }
    printf("\n");
    tree_fila_levelOrder(l, printNode);
    free_tree(l);
    */
}