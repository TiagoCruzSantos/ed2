#include "josefo_rec.h"

// direto da wikipédia

int select_josefo(int n, int m){
    if(n == 1){
        return 1;
    }
    return (select_josefo(n - 1, m) + m - 1)%n + 1;
}