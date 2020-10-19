#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = lo; i <= hi; i++){
        int lessIndex = i;
        for(int j = i; j <= hi; j++){
            if(less(a[j], a[lessIndex])){
                lessIndex = j;
            }
        }
        exch(a[lessIndex], a[i]);
    }
}