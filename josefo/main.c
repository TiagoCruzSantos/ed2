#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

int main(int argc, char** argv){
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    List* jsf = init_josefo(N);
    select_josefo(jsf, M);
    //printf("%d\n", select_josefo(jsf, M));
    clear_josefo(jsf);
}