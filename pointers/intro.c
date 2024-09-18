#include <stdio.h>


struct Node{
    int value;
    struct Node* next;
};

void randomFunction(struct Node* node){
    printf("the argument node is stored in address %p\n",&node);
    printf("the argument node holds the address %p\n",&(*node));
    struct Node* newNode = node; //newNode will also hold address argument node stores
    printf("Pointer variable newNode is stored in %p\n",&newNode);
    printf("Pointer variable newNode holds the address: %p\n",newNode);
    struct Node** doublePtr = &newNode;
    printf("double ptr doublePtr stored in address  %p and holds address %p\n",&doublePtr,doublePtr);
}


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

    ////////////////////////////////////////////////////////////////////

    int age = 22;
    int* age_pointer = &age;

    printf("The variable age is stored in address %p and holds the value %d\n",&age,age);
    printf("The pointer variable age_pointer is stored in address %p and holds the value %p\n",&age_pointer,age_pointer);
    int** age_pointer_pointer = &age_pointer;
    printf("the varible age_pointer_pointer is stored in address %p and holds the value %p\n",&age_pointer_pointer,age_pointer_pointer);
    printf("when i dereference the double pointer i get the value %p\n",*age_pointer_pointer);
    //the above line should be the address age_pointer points to
    //when we dereference a pointer we get the value of the variable its pointing too

    struct Node randomNode;
    randomNode.next = NULL;
    randomNode.value = 8;
    printf("the variable randomNode is stored in %p\n",&randomNode);
    randomFunction(&randomNode);


    return 0;
}