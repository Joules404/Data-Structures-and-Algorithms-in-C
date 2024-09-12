#include <stdio.h>
#include "../../linked_list.h"

int totalNodes(struct LinkedList* list, int N){
    struct ListNode* slow = list->head;
    struct ListNode* fast = list->head;
    int totalNumberOfNodes;
    int index = 0;
    if(slow == NULL) return -1;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        index+=1;
        fast = fast -> next -> next;
    }
    if(fast == NULL) totalNumberOfNodes=index*2;
    else totalNumberOfNodes= index*2+1;
    int target  = totalNumberOfNodes - N;
    if(index < target){
        while(index+1 != target){
            slow = slow->next;
            index++;
        }
        slow->next = slow->next->next;
    }else{
        fast = list->head;
        int track = 0;
        while(track+1 != target){
            fast = fast->next;
            track++;
        }
        fast->next = fast->next->next;

    }
    return totalNumberOfNodes;
}

void removeNthEndNode(struct LinkedList* list,int N){
    struct ListNode* dummy = list->head;
    struct ListNode* left = dummy;
    struct ListNode* right = list->head;

    while(N > 0){
        right = right->next;
        N--;
    }
    while(right->next != NULL){
        left = left -> next;
        right = right -> next;
    }

    left->next = left->next->next;

    view(list);


}


int main(int argc, char** argv){
    struct LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    for (int i = 1; i <= 10; (i++)) append_end(&list,i);  view(&list);
    printf("there are %d elements in the list\n",totalNodes(&list,8));
    view(&list);
    removeNthEndNode(&list,3);
    return 0;
}