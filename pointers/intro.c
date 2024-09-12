#include <stdio.h>


struct Node{
    int value;
    struct Node* next;
};


void change(int a){
    printf("a before: %d\n",a);
    printf("a after: %d\n",a);
    a = 10;
    printf("a after reassignment: %d\n",a);
}

void changeAgain(int* a){
    printf("a before (now in changeAgain): %d\n",*a);
    *a = 1000;
}


int main(){
    int a;
    int* p;

    a = 5;
    p = &a;

    printf("Address of a: %p Address of a from p: %p\n",&a,p);
    printf("Value of a: %d Value of a from p: %d\n",a,*p);
    printf("Address of p: %p\n",&p);

    change(a);
    printf("a after reassignment in change(no ptr) (now in main): %d\n",a);
    
    changeAgain(&a); //it takes an argument of int* a ---> i could pass it the address of a or the pointer variable with the address of a
    printf("a after reassignment in changeAgain(yes ptr) (now in main): %d\n",a);


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    struct Node sample;
    struct Node sample1;
    sample.value = 10;
    sample.next = &sample1;
    sample1.value = 20;
    printf("Value of sample value: %d\n",sample.value);
    printf("Value of sample next: %p\n",sample.next);
    printf("Value of sample 1 address: %p\n",&sample1);
    
    return 0;
}