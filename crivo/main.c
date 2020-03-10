#include "crivo.h"

int main(){
    int k = 10;
    Celula* lista = init_crivo(k);
    mark_prime_crivo(lista, k);
    print_prime_crivo(lista, k);
    free_crivo(lista);
}