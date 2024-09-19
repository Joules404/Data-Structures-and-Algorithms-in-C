#ifndef STACK_H
#define STACK_H

#include "item.h"

#define MAX_SIZE 100

typedef struct {
    Item items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, Item item);
Item pop(Stack *stack);
int isEmpty(Stack *stack);
Item peek(Stack *stack);

#endif
