#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = lo + 1; i <= hi; i++){
        for(int j = hi; j >= i; j--){
            compexch(a[j - 1], a[j]);
        }
    }
}