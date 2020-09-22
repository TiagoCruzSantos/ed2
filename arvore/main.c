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
    t_Base* l = init_tree();
    int v[10] = {6, 2, 7, 1, 4, 3, 5, 9, 8 , 10};
    for(int i = 0; i < 10; i++){
        insert_tree(l, v[i]);
    }
    printf("\n");
    tree_fila_levelOrder(l, printNode);
    free_tree(l);
}