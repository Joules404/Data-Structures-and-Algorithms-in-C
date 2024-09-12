#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct Node{
    int value;
    struct Node* next;
};

struct LinkedList{
    struct Node* head;
    struct Node* tail;
    int size;
};

bool isEmpty(struct LinkedList list){
    if(list.head == NULL) return true;
    return false;
}

void insertAtBeginning(struct LinkedList list,int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    (*new_node).value = data;
    (*new_node).next = NULL;
    if(new_node == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    (*new_node).next = list.head;
    list.head->next = new_node;
}
void insertAtEnd(int data);
void insertAtPosition(int position, int data);

void deleteFromBeginning();
void deleteFromEnd();
void deleteAtPosition(int position);
void deleteByValue(int data);

void traverse(struct LinkedList list){
    if(isEmpty(list) == 1) {
        printf("List is empty\n");
        return;
    }
    struct Node* head = list.head;
    while(head != NULL){
        printf("Current Node Value: %d, Current Node Address: %p, Current Node Next Address: %p", head->value,head,head->next);
        head = head->next;
    }

}   
void search(int data);

void updateAtPosition(int position,int new_data);
void updateByValue(int position, int new_data);


int getSize(struct LinkedList list){
    return list.size; 
}
void reverse();
void getFirst();
void getLast();
void clear();


int main(int argc, int* argv[]){
    struct LinkedList self_implementation;
    self_implementation.size = 0;
    printf("Head: %p\n",self_implementation.head);
    printf("Size: %d\n",self_implementation.size);
    printf("Tail: %p\n",self_implementation.tail);

    printf("Is Empty: %d\n",isEmpty(self_implementation));
    printf("Size: %d\n", getSize(self_implementation));

    insertAtBeginning(self_implementation,1);
    traverse(self_implementation);


    return 0;
}