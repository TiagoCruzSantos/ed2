#include "josefo.h"
#include <stdio.h>
int main(){
    t_Sentinela* josefo = init_josefo(9);
    print_josefo(josefo);
    printf("\n");
    select_josefo(josefo, 5);
    print_josefo(josefo);
    free_josefo(josefo);
}