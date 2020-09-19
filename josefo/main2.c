#include <stdio.h>
#include <stdlib.h>
#include "josefo_rec.h"

int main(int argc, char** argv){
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    select_josefo(N, M);
    //printf("%d\n", select_josefo(N, M));
}