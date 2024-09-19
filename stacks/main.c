#include "stack.h"
#include <stdio.h>

int main() {
    Stack stack;
    stack.top = -1;

    Item item1 = {.data = 10};
    Item item2 = {20};
    
    push(&stack, item1); 
    push(&stack, item2);
    
    printf("Top of stack: %d\n", peek(&stack).data); 
    
    printf("Popped item: %d\n", pop(&stack).data); 
    printf("Popped item: %d\n", pop(&stack).data);
    
    return 0;
}
