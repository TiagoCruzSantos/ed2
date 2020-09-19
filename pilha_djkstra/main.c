#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// ./a.out "(" "5" "*" "7" ")"

int main(int argc, char *argv[]){
    t_Sentinela* numeros = init_stack();
    t_Sentinela* operadores = init_stack();
    for(int i = 1; i < argc; i++){
        switch (argv[i][0]){
            case ')': ; //statement vazio pq n pode ter declaração imediatamente apos case aparentemente
                double* result = malloc(sizeof(double));
                double* num1 = remove_stack(numeros);
                double* num2 = remove_stack(numeros);
                char* oper = remove_stack(operadores);

                //printf("%f %c %f\n", *num1, *oper, *num2);

                switch (*oper){
                    case '+':
                        *result = *num1 + *num2;
                        break;
                    case '-':
                        *result = *num1 - *num2;
                        break;
                    case '*':
                        *result = *num1 * *num2;
                        break;
                    case '/':
                        *result = *num1 / *num2;
                        break;
                    default:
                        break;
                }

                free(num1);
                free(num2);
                free(oper);
                insert_stack(numeros, result);
                break;
            case '(':
                break; 
            case '+': ;
                char* plus = malloc(sizeof(char));
                *plus = '+';
                insert_stack(operadores, plus);
                break;
            case '-': ;
                char* minus = malloc(sizeof(char));
                *minus = '-';
                insert_stack(operadores, minus);
                break;
            case '*': ;
                char* times = malloc(sizeof(char));
                *times = '*';
                insert_stack(operadores, times);
                break;
            case '/': ;
                char* div = malloc(sizeof(char));
                *div = '/';
                insert_stack(operadores, div);
                break;
            default: ;
                double* value = malloc(sizeof(double));
                *value = atof(argv[i]);
                insert_stack(numeros, value);
                break;
        }
    }
    double* res = remove_stack(numeros);
    printf("%f\n", *res);
    free(res);
    free_stack(numeros);
    free_stack(operadores);
}