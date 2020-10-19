#ifndef __CAMINHO__
#define __CAMINHO__
#include "arvore.h"
#include "pilha.h"
#include "fila.h"

void tree_stack_inOrder(t_Base* l, void (*visit)(t_No*));

void tree_stack_preOrder(t_Base* l, void (*visit)(t_No*));

void tree_stack_postOrder(t_Base* l, void (*visit)(t_No*));

void tree_fila_levelOrder(t_Base* l, void (*visit)(t_No*));

#endif