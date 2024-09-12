#include "../../linked_list.h"
#include <stdio.h>

int halfway(struct LinkedList* list){
    struct ListNode* slow = (*list).head;
    struct ListNode* fast = (*list).head;

    while(fast != NULL && (*fast).next != NULL){
        slow = (*slow).next;
        fast = (*(*fast).next).next;
    }
    return (*slow).value;
}

int main(int argc, char** argv){
    struct LinkedList list;
    struct LinkedList list2;
    list.head=list.tail=NULL;
    list2.head=list2.tail=NULL;
    for (size_t i = 0; i < 10; i++) append_end(&list,i);
    for(int i = 0; i < 9; i++) append_end(&list2,i);

    int half = halfway(&list);
    int half2 = halfway(&list2);
    printf("Halfway Value: %d\n",half);
    printf("Halfway Value2: %d\n",half2);
    return 0;
}