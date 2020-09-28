#include "item.h"

void sort(Item *a, int lo, int hi){
    int count = 0;
    for(int i = lo; i <= hi/2; i++){
        for(int j = i; j <= hi - count; j++){
            compexch(a[j - 1], a[j]);
        }
        for(int j = hi - count; j >= lo; j--){
            compexch(a[j - 1], a[j]);
        }
        count++;
    }
}