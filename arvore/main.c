#include "arvore.h"
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
    int n = atoi(argv[1]);
    for(int i = 0; i < n; i++){
        insert_tree(l, rand()%100);
    }
    printf("%d\n", hight_tree(l));
    //tree_inOrder(l, printNode);
    free_tree(l);
}