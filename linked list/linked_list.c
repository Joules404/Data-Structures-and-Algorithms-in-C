/*
some important features about linked lists

access time -> O(n).....best case the node we want is the head O(1) and worse case its the last node O(n)....
to access a node you must traverse the entirety of the list

search time -> O(n)....in the worse case you may end up having to traverse the entire list 

insertion beginning -> O(1)....no traversing needed...just modifying pointers of the old head to the new head

insertion end -> O(n)...to insert a node to the end  you must traverse the entire list unless a tail pointer is kept

insertion at specific position -> O(n)...you must traverse to that specific position

deletion beginning, deletion end, and deletion at specific position follow the same time complexities as insertion funcs()

*/

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// struct LinkedList MyLinkedList = {NULL, NULL, 0};

void view(struct LinkedList* list) {
    struct ListNode* node = list->head;
    if (node == NULL) {
        printf("Empty list\n");
        return;
    }
    while (node != NULL) {
        printf("CURRENT NODE (val=%d) (prior=%p) (next=%p)\n", node->value, node->prior, node->next);
        node = node->next;
    }
}

void reverse(struct LinkedList* list) {
    struct ListNode* current = list->head;
    struct ListNode* temp = NULL;
    list->tail = current;

    while (current != NULL) {
        temp = current->prior;
        current->prior = current->next;
        current->next = temp;
        current = current->prior;
    }

    if (temp != NULL) {
        list->head = temp->prior;
    }
}

void append_beginning(struct LinkedList* list, int value) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->value = value;
    new_node->prior = NULL;
    new_node->next = list->head;

    if (list->head != NULL) {
        list->head->prior = new_node;
    }
    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

void append_end(struct LinkedList* list, int value) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prior = list->tail;

    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;

    if (list->head == NULL) {
        list->head = new_node;
    }
}

void remove_beginning(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct ListNode* to_remove = list->head;
    list->head = to_remove->next;

    if (list->head != NULL) {
        list->head->prior = NULL;
    } else {
        list->tail = NULL;
    }

    free(to_remove);
}

void remove_end(struct LinkedList* list) {
    if (list->tail == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct ListNode* to_remove = list->tail;
    list->tail = to_remove->prior;

    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    free(to_remove);
}

void display_menu() {
    printf("0. Exit the program\n");
    printf("1. View linked list\n");
    printf("2. Reverse linked list\n");
    printf("3. Append to beginning\n");
    printf("4. Append to end\n");
    printf("5. Remove from beginning\n");
    printf("6. Remove from end\n");
}
