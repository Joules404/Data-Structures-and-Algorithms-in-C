#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int value;
    struct ListNode* prior;
    struct ListNode* next;
};

struct LinkedList{
    struct ListNode* head;
    struct ListNode* tail;
    int direction;
    int size;
    struct ListNode* current_node;
};

void getCurrentListNode(struct LinkedList* list){

}

void getNextListNode(struct LinkedList* list){

}

void changeDirection(struct LinkedList* list){
    if((*list).direction == 0){
        (*list).direction = 1;
    }else{
        (*list).direction = 0;
    }
}

void jump(struct LinkedList* list){
    if((*list).direction == 1){//move to the right
        if((*list).current_node->next == NULL){
            printf("Reached the last element of the linked list\n");
        }else{
            (*list).current_node  = (*list).current_node->next;
        }
    }else{//move to the left
        if((*list).current_node->prior == NULL){
            printf("Reached the first element of the linked list\n");
        }else{
            (*list).current_node = (*list).current_node->prior;
        }
    }
}


int getDirection(struct LinkedList* list){
    int curr_direction = (*list).direction;
    printf("-------------------RETRIEVING DIRECTION-------------------\n");
    if(curr_direction == 0){
        printf("Going backwards\n");
        return 0;
    }
    printf("Going forward\n");
    return 1;
}

int getSize(struct LinkedList* list){
    printf("-------------------RETRIEVING SIZE-------------------\n");
    printf("List has %d element(s)\n",(*list).size);
    return (*list).size;
}

void appendToBeginning(struct LinkedList* list,int value){
    printf("-------------------ADDING %d TO BEGINNING OF LIST-------------------\n",value);
    struct LinkedList* list_copy = list;
    struct ListNode* head = (*list).head;
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    (*newNode).value = value;
    (*newNode).next = NULL;
    (*newNode).prior = NULL;
    if(head == NULL){ 
        (*list).tail = newNode;
        (*list).current_node = newNode;
        
    }
    else {
        (*newNode).next = (*list).head;
        list->head->prior = newNode;
    }
    (*list).head = newNode;
    printf("Successfully added %d to beginning of the list\n",value);
    (*list).size+=1;
    getSize(list);
}

void appendToEnd(struct LinkedList* list, int value){
    printf("-------------------ADDING %d TO THE END OF LIST-------------------\n",value);
    struct LinkedList* list_copy = list;
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    (*new_node).value = value;
    (*new_node).next = NULL;
    (*new_node).prior = NULL;
    if((*list_copy).head == NULL){
        appendToBeginning(list,value);
        return;
    }
    struct ListNode* currentNode = (*list).head;
    while((*currentNode).next != NULL){
        currentNode = (*currentNode).next;
    }
    new_node->prior = currentNode;
    currentNode->next = new_node;
    (*list).tail = new_node;
    (*list).size+=1;
    getSize(list);

}

void traverse(struct LinkedList* list){
    printf("-------------------TRAVERSING LIST-------------------\n");
    struct LinkedList* list_copy = list;
    if((*list).head == NULL){
        printf("Empty list\n");
        return;
    }
    struct ListNode* node = list_copy->head;
    while(node != NULL){
        if(node->prior == NULL){
            printf("PRIOR: NULL\n");
        }else{
            printf("PRIOR: value -> %d address -> %p\n",node->prior->value,node->prior);
        }
        printf("PRESENT: value -> %d address -> %p\n",node->value,node);
        if(node->next == NULL){
            printf("FUTURE: NULL\n");
        }else{
            printf("FUTURE: value -> %d address -> %p\n",node->next->value, node->next);
        }
        printf("------------------------------\n");
        node = node->next;
    }
}

void display(struct LinkedList* list){
    struct ListNode* node = (*list).head;
    while(node!=NULL){
        printf("%d --> ",(*node).value);
        node = (*node).next;
    }
    printf("\n");
}

void reverse(struct LinkedList* list){
    struct ListNode* one = NULL;
    struct ListNode* two = (*list).head;
    struct ListNode* three;
    //1 --> 2 --> 3 --> 4 --> NULL
    // 
    while(two != NULL){
        three = (*two).next;
        (*two).next = one;
        one = two;
        two = three;
    }
    (*list).head = one;

}

/*
    this is part of for neetcode 150
    linked list merging 2 sorted lists
*/

struct LinkedList*  merge_lists_outer(struct LinkedList* list1, struct LinkedList* list2){
    struct LinkedList* new_list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    struct ListNode* node1 = (*list1).head;
    struct ListNode* node2 = (*list2).head;
    new_list->head = NULL;  // Initialize new_list properly
    new_list->tail = NULL;
    new_list->size = 0;
    new_list->direction = 1;
    new_list->current_node = NULL;

    while(node1 != NULL && node2 != NULL){
        if(node1->value <= node2->value){
            appendToEnd(new_list,node1->value);
            node1 = node1->next;
        }else{
            appendToEnd(new_list,node2->value);
            node2 = node2->next;
        }
    }

    while(node1 != NULL){
        appendToEnd(new_list,node1->value);
        node1 = node1->next;
    }
    while(node2 != NULL){
        appendToEnd(new_list,node2->value);
        node2 = node2->next;
    }
    return new_list;
}

/*
this is for neetcode 150
linked lists reordering lists

array represents linkedlist
numbers represent nodes
input: [1,2,3,4,5,6]
output: [1,6,2,5,3,4] 


*/

void reorder(struct LinkedList* list){
    struct LinkedList* list_copy = list;
    struct ListNode* slow = (*list_copy).head;
    struct ListNode* fast = slow; //in the beginning also equal to the head
    struct ListNode* temp;
    while((*slow).next != NULL){
        while(fast->next->next != NULL){//2nd to last element
            fast = fast->next;
        }
        temp = fast->next;
        (*temp).next = NULL;
        (*temp).next = slow->next;
        slow->next = temp;
        slow = slow->next->next;
    }
}


int main(int argc, char* argv[]){
    struct LinkedList list;
    struct LinkedList list1;
    list.direction = 1;
    list.head = NULL;
    list.tail = NULL;
    list.current_node = NULL;
    list.size = 0;
    list1.direction = 1;
    list1.head = NULL;
    list1.tail = NULL;
    list1.current_node = NULL;
    list1.size = 0;
    for(int i = 0; i < 4; i++){
        appendToEnd(&list,(i*5)); //0 1 10 15 
        appendToEnd(&list1,(i*3));//0 3 6 9
        
    }
    display(&list);
    display(&list1);

    struct LinkedList* merged = merge_lists_outer(&list,&list1);
    display(merged);
    reverse(merged);
    display(merged);

    reorder(merged);


    // printf("LinkedList Address: %p\n", &list);
    // // getDirection(&list);
    // // getSize(&list);
    // appendToBeginning(&list,1);
    // appendToBeginning(&list,0);
    // // traverse(&list);
    // appendToEnd(&list,100);
    // appendToEnd(&list,200);
    // traverse(&list);
    // printf("retrieving tail address: %p\n",list.tail);
    // printf("retrieving current node-> value: %d, address: %p\n",list.current_node->value,list.current_node);
    // printf("-------------------JUMPING---------------\n");
    // printf("Retrieving current list node---> value:%d,  address: %p\n",list.current_node->value,list.current_node);
    // jump(&list);
    // printf("Retrieving current list node---> value:%d,  address: %p\n",list.current_node->value,list.current_node);
    // jump(&list);
    // printf("Retrieving current list node---> value:%d,  address: %p\n",list.current_node->value,list.current_node);
    // jump(&list);
    // printf("Retrieving current list node---> value:%d,  address: %p\n",list.current_node->value,list.current_node);
    // changeDirection(&list);
    // jump(&list);
    // printf("Retrieving current list node---> value:%d,  address: %p\n",list.current_node->value,list.current_node);
    // jump(&list);
    // printf("Retrieving current list node---> value:%d,  address: %p\n",list.current_node->value,list.current_node);
    // jump(&list);
    // printf("Retrieving current list node---> value:%d,  address: %p\n",list.current_node->value,list.current_node);
    // jump(&list);
    // printf("Retrieving current list node---> value:%d,  address: %p\n",list.current_node->value,list.current_node);
    // display(&list);
    // reverse(&list);
    // display(&list);
    // reverse(&list);
    // display(&list);
    
    return 0;

}