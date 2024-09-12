#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ListNode {
    int value;
    struct ListNode* prior;
    struct ListNode* next;
};

struct LinkedList {
    struct ListNode* head;
    struct ListNode* tail;
    int direction;
};

void view(struct LinkedList* list);
void reverse(struct LinkedList* list);
void append_beginning(struct LinkedList* list, int value);
void append_end(struct LinkedList* list, int value);
void remove_beginning(struct LinkedList* list);
void remove_end(struct LinkedList* list);
void display_menu();

#endif // LINKED_LIST_H
