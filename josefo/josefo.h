#ifndef __JOSEFO__
#define __JOSEFO__
#include <stdlib.h>
#include <stdio.h>

typedef struct lst List;

List* init_josefo(int n);

int select_josefo(List* jsf, int m);

void clear_josefo(List* jsf);

void print_josefo(List* jsf);

#endif