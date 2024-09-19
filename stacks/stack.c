#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void push(Stack *stack, Item item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

Item pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);  
    }
    return stack->items[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

Item peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);  
    }
    return stack->items[stack->top];
}
