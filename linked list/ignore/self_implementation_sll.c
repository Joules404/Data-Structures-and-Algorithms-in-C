#include <stdio.h>
#include <stdlib.h>

/*
implementation of a singly integer one way linked list 
*/



struct Node{
    int value;
    struct Node* next;
};

void append(struct Node* head,int value){
    struct Node* current_node = head;
    // struct Node newNode; this wouldn't work because only local to append() body
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    if(head == NULL){
        printf("Empty list\n");
        return;
    }
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = newNode;

}
void pop(struct Node* head){
    struct Node* current_node = head;
    if(current_node == NULL) return;
    while(current_node->next->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = NULL;

}
int size(struct Node* head){
    int s = 0;
    struct Node* current_node = head;
    if(current_node == NULL) return s;
    if(current_node->next == NULL) return 1;
    while(current_node != NULL){
        s++;
        current_node = current_node->next;
    }
    return s;
}


void traverse(struct Node* head){
    struct Node* current_node = head; ///set to the address of the head of the linked list
    if(current_node == NULL){
        printf("Empty linked list");
        return;
    }
    while(current_node != NULL){
        printf("Current Node Value: %d Current Node Address: %p Current Node Next Address: %p\n", current_node->value,current_node,(*current_node).next);
        current_node = current_node->next;
    }

}

int main(){
    struct Node apple;
    struct Node banana;
    struct Node cherry;
    struct Node date;

    apple.value = 1;
    banana.value = 2;
    cherry.value = 3;
    date.value = 4;

    apple.next = &banana;
    banana.next = &cherry;
    cherry.next = &date;
    date.next = NULL;

    printf("MANUAL TRAVERSAL\n");
    printf("current.value: %d, current address: %p, current.next: %p\n",apple.value,&apple,apple.next);    
    printf("current.value: %d, current address: %p, current.next: %p\n",banana.value,&banana,banana.next);    
    printf("current.value: %d, current address: %p, current.next: %p\n",cherry.value,&cherry,cherry.next);    
    printf("current.value: %d, current address: %p, current.next: %p\n",date.value,&date,date.next);    

    printf("WHILE TRAVERSAL\n");
    traverse(&apple);

    printf("SIZE\n");
    printf("%d\n",size(&apple));

    printf("APPEND\n");
    append(&apple,5);
    traverse(&apple);
    printf("POP\n");
    pop(&apple);
    traverse(&apple);

    return 0;
}