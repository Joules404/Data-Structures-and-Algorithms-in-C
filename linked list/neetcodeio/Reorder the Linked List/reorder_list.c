#include "../../linked_list.h"
#include <stdio.h>
#include <stdlib.h>


void reorder(struct LinkedList* list){
    //linked list ===> 1 2 3 4 5 6
    //output      ===> 1 6 2 5 3 4
    struct ListNode* curr = (*list).head;
    if(curr == NULL) return;
    struct ListNode* fetcher = (*curr).next;
    while(curr != NULL && fetcher != NULL){
        fetcher = curr;
        while(fetcher->next->next != NULL){
            fetcher = (*fetcher).next;
        }
        struct ListNode* lastNode = (*fetcher).next;
        (*fetcher).next = NULL;
        (*lastNode).next = (*curr).next;
        (*curr).next = lastNode;
        curr = (*lastNode).next;
        // fetcher = curr;
    }


}

int main(int argc, char **argv){
    struct LinkedList list;
    list.head = NULL;
    list.tail = NULL;

    for (int i = 1; i < 6; i++) append_end(&list,i);
    view(&list);


    reorder(&list);

    view(&list);
    
    // FILE* fh_output;
    // fh_output = fopen("testcases.txt","w");
    // fclose(fh_output);
    // FILE* fh_read;
    // fh_read = fopen("testcases.txt","r");
    // int val = 0;
    // while(fscanf(fh_read,"%d",&val) != EOF){
    //     append_end(&list,val);
    // }
    // view(&list);
    // // fscanf(fh_read,"%d",&val);
    // // printf("found the value: %d\n",val);
    // fclose(fh_read);

    
    return 0;
}