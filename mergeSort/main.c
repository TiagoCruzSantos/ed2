#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char **argv){
    int N = atoi(argv[1]);
    Item *array = malloc(sizeof(Item) * N);
    for(int i = 0; i < N; i++){
        scanf("%d", &array[i]);
    }
    clock_t start = clock();
    sort(array, 0, N - 1);
    clock_t end = clock();
    double seconds = ((double) end - start) / CLOCKS_PER_SEC;
    printf("%lf", seconds);
    free(array);
}